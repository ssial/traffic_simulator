#include <stdio.h>
#include <stdlib.h>
#include "LinkedListAPI.h"
#include "dummy2.h"
#include "car.h"

void printList (void *toBePrinted) {
    printf("%c %c %d\n",((Car*)(toBePrinted))->heading, ((Car*)(toBePrinted))->direction, ((Car*)(toBePrinted))->arrival);
}

int compareIntegers (const void *first,const void *second) {
    Car* car1 = (Car*)first;
    Car* car2 = (Car*)second;
    if (car1->arrival > car2->arrival) {
        return 1;
    }
    else if (car1->arrival < car2->arrival) {
        return -1;
    }
    else {
        return 0;
    }
}

void deleteListNode(void *toBeDeleted) {
    printf("DELETE LIST!\n");
}

int getArrival (void *toBeDeleted) {

    return ((Car*)(toBeDeleted))->arrival;
}

char getDirection (void *toBeDeleted) {
    return ((Car*)(toBeDeleted))->direction;
}

char getHeading (void *toBeDeleted) {
    return ((Car*)(toBeDeleted))->heading;
}

Car* createCar( char carHeading, char carDirection, int arrivalTime) {
    Car* c = malloc(sizeof(Car));
    c->arrival  = arrivalTime;
    c->heading  = carHeading;
    c->direction  = carDirection;
    return c;
}
