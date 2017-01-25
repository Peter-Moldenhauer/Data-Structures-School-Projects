/*************************************************************************
* Description: This file tests the linkedList.c and linkedList.h files
*************************************************************************/

#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>


int main(){

    struct LinkedList * list = linkedListCreate();

    linkedListAddBack(list, (TYPE)1);
    linkedListAddBack(list, (TYPE)2);
    linkedListAddBack(list, (TYPE)3);
    linkedListAddFront(list, (TYPE)4);
    linkedListAddFront(list, (TYPE)5);
    linkedListAddFront(list, (TYPE)6);

    linkedListPrint(list);

    printf("Front of List: %d\n", linkedListFront(list));
    printf("Back of List: %d\n", linkedListBack(list));

    printf("Removing front and back links from list..\n");

    linkedListRemoveFront(list);
    linkedListRemoveBack(list);

    linkedListPrint(list);

    linkedListDestroy(list);

    return 0;
}
