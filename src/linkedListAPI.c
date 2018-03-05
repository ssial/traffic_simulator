#include <stdio.h>
#include <stdlib.h>
#include "LinkedListAPI.h"
#include "dummy2.h"

List *initializeList(void (*printFunction)(void *toBePrinted),void (*deleteFunction)(void *toBeDeleted),int (*compareFunction)(const void *first,const void *second)) {
    List *list1 = malloc(sizeof (List));
    list1->head = NULL;
    list1->tail = NULL;
    list1->printNode = printFunction;
    list1->compare = compareFunction;
    list1->deleteNode = deleteFunction;
    return list1;
}

Node *initializeNode(void *data) {
    if (data==NULL) {
        return;
    }
    else {
       	Node *n = (Node*)malloc(sizeof(Node));
        n->data = data;
        n->previous = NULL;
        n->next = NULL;
        return n;
    }
}

void insertFront(List* list, void* toBeAdded){
    Node *temp = initializeNode(toBeAdded);
    if(list==NULL){//if list doesn't exist
		return;
	}
    else if(list->head == NULL){//if there's no head
		list->head = temp; //set temp equal to the new head
		list->tail = list->head; //also set the tail equal to the head because there's only one node
	}
	else{
		list->head->previous = temp;
		temp->next = list->head;
		list->head = temp;
	}
}

void insertBack(List *list, void *toBeAdded) {
    Node *temp = initializeNode(toBeAdded);
    if(list==NULL){
		return;
	}
    else if(list->tail == NULL){
		list->tail = temp;
		list->head = list->tail;
	}
	else {
        list->tail->next = temp;
        temp->previous = list->tail;
        list->tail = temp;
	}
}

void deleteList(List *list) {
    Node *temp1 = list->head;
    Node *temp2;
    while(temp1!=NULL) {
        temp2 = temp1->next;
        free(temp1);
        temp1 = temp2;
    }
    list->head = NULL;
    list->tail = NULL;
}

void *getFromFront(List *list) {
    void *headData;
    Node *temp = list->head;
    if (list->head==NULL) {
        return;
    }
    else {
        headData = temp->data;
        return headData;
    }
}

void *getFromBack(List *list){
    void *tailData;
    Node *temp = list->tail;
    if (list->head==NULL) {
        return;
    }
    else {
        tailData = temp->data;
        return tailData;
    }
}

void printForward(List *list) {
    Node *temp1 = list->head;
    if (list->head==NULL) {
        printf("Empty list\n");
        return;
    }
    else {
        while(temp1!=NULL) {
            printList(temp1->data);
            temp1 = temp1->next;
        }
    }

}

void printBackwards(List *list) {
    Node *temp1 = list->tail;
    if (list->head==NULL) {
        printf("Empty list\n");
        return;
    }
    else {
        while(temp1!=NULL) {
            printList(temp1->data);
            temp1 = temp1->previous;
        }
    }

}


int deleteNodeFromList(List *list, void *toBeDeleted) {
    Node *temp = list->head;
	Node *temp2;
	Node *temp4 = list->tail;
    if (list==NULL) {
		return EXIT_FAILURE;
	}
	else if (getArrival(temp->data)==getArrival(toBeDeleted)) {
        temp2 = temp->next;
        list->head = temp2;
        free(temp);
        return EXIT_SUCCESS;
	}

	else if (getArrival(temp4->data)==getArrival(toBeDeleted)) {
        temp2 = temp4->previous;
        temp2->next = NULL;
        list->tail = temp2;
        free(temp4);
        return EXIT_SUCCESS;
	}
	else {
        Node *temp3 = list->head;
        Node *store_next;
        Node *store_prev;
        while (getArrival(temp3->data)!=getArrival(toBeDeleted)) {
            temp3 = temp3->next;
        }
        store_next = temp3->next;
        store_prev = temp3->previous;
        store_next->previous = store_prev;
        store_prev->next = store_next;
        free(temp3);
        return EXIT_SUCCESS;
	}
}
