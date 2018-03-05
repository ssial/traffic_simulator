#include <stdio.h>
#include <stdlib.h>
#include "LinkedListAPI.h"
#include "car.h"
#include "dummy2.h"

int main( int argc, const char* argv[] ) {

    FILE *file;
    List *listN;
    List *listS;
    List *listE;
    List *listW;
    Car *c;
    Node *n;
    Node *s;
    Node *e;
    Node *w;
    char carH;
    char carD;
    int arrive = 0;
    char line[100];
    double clock = 1;

    if(argv[1]==NULL) {
        printf("Error: file not found!\n");
    }
    else if (argc<2) {
        printf("Incorrect number of parameters\n");
    }

    void (*printFunct)(void *toPrint);
    printFunct = &printList;

    void (*deleteFunct)(void *toDelete);
    deleteFunct = &deleteListNode;

    int (*compareFunct)(const void* a,const void* b);
    compareFunct = &compareIntegers;

    listN = initializeList (printFunct, deleteFunct, compareFunct);
    listE = initializeList (printFunct, deleteFunct, compareFunct);
    listS = initializeList (printFunct, deleteFunct, compareFunct);
    listW = initializeList (printFunct, deleteFunct, compareFunct);

    file = fopen(argv[1], "r");
    if(file == NULL)
    {
        printf("ERROR: could not open file\n");
        exit(1);
    }
    int counter = 0;;
    while( fgets(line,100,file) != NULL )
    {
        sscanf(line,"%c %c %d", &carH, &carD, &arrive);
        c = createCar(carH,carD,arrive);
        if (carH=='N') {
            n = initializeNode(c);
            insertBack(listN,n->data);
        }
        else if(carH=='E') {
            e = initializeNode(c);
            insertBack(listE,e->data);
        }
        else if(carH=='S') {
            s = initializeNode(c);
            insertBack(listS,s->data);
        }
        else {
            w = initializeNode(c);
            insertBack(listW,w->data);
        }
    }

    printf("Initial Vehicle Information   Intersection Arrival Time   Completed at Time\n");
    while(1) {
        if ((listN->head==NULL) && (listE->head==NULL) && (listS->head==NULL) && (listW->head==NULL)) {
            break;
        }
        moveCars(listN,clock);
        clock = clock + 14;
        moveCars(listE,clock);
        clock = clock + 14;
        moveCars(listS,clock);
        clock = clock + 14;
        moveCars(listW,clock);
        clock = clock + 14;
    }
    fclose(file);
    return 0;

}

/*Car* createCar( char carHeading, char carDirection, int arrivalTime) {
    Car* c = malloc(sizeof(Car));
    c->arrival  = arrivalTime;
    c->heading  = carHeading;
    c->direction  = carDirection;
    return c;
}*/

int signalCheck (double check, char direct, double *greenLight) {
    double yellow = *greenLight + 10;
    double red = yellow + 4;

    if (check<yellow) {
        return 0;
    }
    else if ((check>=yellow) && (check<red-1) && (direct=='L')) {
        return 0;
    }
    else {
        return -1;
    }
}

double turn (char direct2) {
    if (direct2=='F') {
        return 2;
    }
    else if (direct2=='R') {
        return 1;
    }
    else if (direct2=='L') {
        return 2.5;
    }
}

void moveCars (List *l, double clockTime) {

   Node *tempHead;
   tempHead = l->head;
   double arrival = 0;
   double initialArrival = 0;
   double *green;
   int flag = 0;
   double completed;
   char direction;
   char heading;
   green = &clockTime;

   if (tempHead==NULL) {
    return;
   }

   while(tempHead!=NULL) {
        arrival = getArrival(tempHead->data);
        initialArrival = arrival;
        direction = getDirection(tempHead->data);
        heading = getHeading(tempHead->data);

        if (arrival>clockTime) {
            flag = signalCheck(arrival,direction,green);
            if (flag==0) {
                clockTime = arrival;
            }
        }
        if (clockTime>arrival) {
            flag = signalCheck(clockTime,direction,green);
            if (flag==0) {
                arrival = clockTime;
            }
        }
        if (flag==-1) {
            break;
        }

        completed = arrival + turn(direction);
        printf("%c %c %.1lf                         %.2lf                           %.2lf\n",heading,direction,initialArrival,arrival,completed);
        deleteNodeFromList(l,tempHead->data);
        clockTime = completed;
        tempHead = tempHead->next;

    }

}
