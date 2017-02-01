#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int main (int argc, const char * argv[]) {

    struct linkedList *myStack;

	myStack =  createLinkedList(3);

	addBackList(myStack, 0);
	addBackList(myStack, 1);
	addBackList(myStack, 2);
	addBackList(myStack, 3);

	struct linkedListIter *myIter;
	myIter = createlinkedListIter(myStack);

	while(hasNextlinkedListIter(myIter))
		{
			TYPE val = nextlinkedListIter(myIter);
			if(val != 2)
				printf("The next value in the stack is: %d\n", val);
			else {
				printf("The next value in the stack is: %d\n", val);
				removelinkedListIter(myIter);
			}
		}

	printf("After removing 2 \n");
	initlinkedListIter(myStack, myIter);

	while(hasNextlinkedListIter(myIter))
		printf("The next value in the stack is: %d\n", nextlinkedListIter(myIter));


	return(0);

}
