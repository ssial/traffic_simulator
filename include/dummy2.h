#ifndef DUMMY2_H_INCLUDED
#define DUMMY2_H_INCLUDED

typedef struct car {
    char heading;
    char direction;
    int arrival;
} Car;

Car* createCar( char heading, char direction, int arrival);
void printList (void *toBePrinted);
int compareIntegers (const void *first,const void *second);
void deleteListNode(void *toBeDeleted);
int getArrival (void *toBeDeleted);
char getDirection (void *toBeDeleted);
char getHeading (void *toBeDeleted);

#endif // DUMMY2_H_INCLUDED
