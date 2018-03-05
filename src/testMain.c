#include <stdio.h>
#include <stdlib.h>
#include "LinkedListAPI.h"
#include "car.h"
#include "dummy2.h"

int main( int argc, char ** argv ) {

    List *list;
    List *list2;
    Car *c;
    Car *c2;
    Node *n;
    Node *n2;

    void (*printFunct)(void *toPrint);
    printFunct = &printList;

    void (*deleteFunct)(void *toDelete);
    deleteFunct = &deleteListNode;

    int (*compareFunct)(const void* a,const void* b);
    compareFunct = &compareIntegers;

    printf("Test 1: Test initialize list function\n");
    list = initializeList (printFunct, deleteFunct, compareFunct);
    printf("Test 1.1: Check if head pointer is NULL\n");
    printf("Expected Output: NULL\n");
	if(list->head ==  NULL) {
		printf("NULL\n");
	}
	else{
		printf("Test Failed.\n");
	}
	printf("Test 1.2: Check if tail pointer is NULL\n");
    printf("Expected Output: NULL\n");
	if(list->tail ==  NULL) {
		printf("NULL\n");
	}
	else{
		printf("Test Failed.\n");
	}

    printf("Test 2: Test initialize node fucntion\n");
    printf("Expected Output: N F 1\n");
    c = createCar('N','F',1);
    n = initializeNode(c);
    printf("%c %c %d\n",c->heading, c->direction, c->arrival);
    printf("Test 2.1: Test if next pointer is pointing to nothing\n");
    printf("Expected Output: NULL\n");
    if (n->next==NULL){
        printf("NULL\n");
    }
    else{
		printf("Test Failed.\n");
	}
    printf("Test 2.2: Test if previous pointer is pointing to nothing\n");
    printf("Expected Output: NULL\n");
    if (n->previous==NULL){
        printf("NULL\n");
    }
    else{
		printf("Test Failed.\n");
	}

    printf("Test 3: Test insert front fucntion\n");
    insertFront(list,n->data);
    printf("Expected output: N F 1\n");
    printList(n->data);


    printf("Test 4: Test insert back fucntion\n");
    c = createCar('S','F',2);
    n2 = initializeNode(c);
    insertBack(list,n2->data);
    printf("Expected output: S F 2\n");
    printList(n2->data);


    printf("Test 5: Test get from front fucntion\n");
    void *temp;
    c = createCar('W','R',10);
    n2 = initializeNode(c);
    insertFront(list,n2->data);
    temp = getFromFront(list);
    printf("Expected output: W R 10\n");
    printList(temp);
    printf("Test 5.1: Test if head node contains the same data\n");
    printf("Expected output: Head: W R 10\n");
    printf("Head: ");
    printList(list->head->data);

    printf("Test 6: Test get from back fucntion\n");
    c = createCar('E','R',13);
    n2 = initializeNode(c);
    insertBack(list,n2->data);
    temp = getFromFront(list);
    printf("Expected output: E R 13\n");
    printList(temp);
    printf("Test 6.1: Test if tail node contains the same data\n");
    printf("Expected output: Tail: E R 13\n");
    printf("Tail: ");
    printList(list->tail->data);

    printf("Test 7: Test print list forwards function\n");
    printf("Expected output: W R 10, N F 1, S F 2, E R 13\n");
    printForward(list);

    printf("Test 8: Test print list backwards fucntion\n");
    printf("Expected output: E R 13, S F 2, N F 1, W R 10\n");
    printBackwards(list);

    printf("Test 9: Test delete a node at nth position of list function\n");
    printf("Test 9.1: Test delete head node\n");
    printf("Expected output after deletion: N F 1, S F 2, E R 13\n");
    deleteNodeFromList(list,list->head->data);
    printf("Test 9.2: Test delete node from middle of list\n");
    printf("Expected output after deletion: N F 1, E R 13\n");
    deleteNodeFromList(list,list->head->next->data);
    printForward(list);
    printf("Test 9.3: Test delete tail node\n");
    printf("Expected output after deletion: N F 1\n");
    deleteNodeFromList(list,list->tail->data);
    printForward(list);

    printf("Test 10: Test delete entire list function\n");
    printf("Expected output after deletion: Empty List\n");
    deleteList(list);
    printForward(list);

}
