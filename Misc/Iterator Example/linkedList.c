#include "linkedList.h"
#include "assert.h"
#include <stdlib.h>
#include <stdio.h>


/************************************************************************************************
********  IGNORE THIS TOP PORTION OF EMPTY FUNCTIONS, SEE BOTTOM FOR ITERATOR FUNCTIONS *********
*************************************************************************************************/

/* Double Link*/
struct DLink {
	TYPE value;
	struct DLink * next;
	struct DLink * prev;
};

/* Double Linked List with Head and Tail Sentinels  */

struct linkedList{
	int size;
	struct DLink *frontSentinel;
	struct DLink *backSentinel;
};


/* prototypes */
void _removeLink(struct linkedList *lst, struct DLink *l);


/*
	initList
	param lst the linkedList
	pre: lst is not null
	post: lst size is 0
*/

void _initList (struct linkedList *lst) {
   /* create the sentinels */
  }

/*
 createList
 param: none
 pre: none
 post: frontSentinel and backSentinel reference sentinels
 */

struct linkedList *createLinkedList()
{
	struct linkedList *newList = malloc(sizeof(struct linkedList));
	_initList(newList);
	return(newList);
}

/*freeLinkedList
 * param: lst the linkedList
 * pre: lst is not null
 * post: All data-bound links are freed
 */

void _freeLinkedList(struct linkedList *lst)
{
	struct DLink *cur = lst->frontSentinel->next;
	while(cur != lst->backSentinel)
	{
		_removeLink(lst,cur);
	}
}
/*
 * deleteList
 * param: lst the linkedList
 * pre: lst is not null
 * post: the memory used by frontSent, backSent, and lst is freed
 */

void deleteLinkedList(struct linkedList *lst)
{
	/* Fix me */ }
/*
	_addLinkBeforeBefore
	param: lst the linkedList
	param: l the  link to add before
	param: v the value to add
	pre: lst is not null
	pre: l is not null
	post: lst is not empty
*/

/* Adds Before the provided link, l */

void _addLinkBefore(struct linkedList *lst, struct DLink *l, TYPE v)
{
   /* Fix me */ }


/*
	addFrontList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/

void addFrontList(struct linkedList *lst, TYPE e)
{

	/* Fix me */ 
}

/*
	addBackList
	param: lst the linkedList
	pre: lst is not null
	post: lst is not empty
*/

void addBackList(struct linkedList *lst, TYPE e) {
  
  /* Fix me */ 
}

/*
	frontList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: none
*/

TYPE frontList (struct linkedList *lst) {
   /* Fix me */ }

/*
	backList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: lst is not empty
*/

TYPE backList(struct linkedList *lst)
{
	/* Fix me */ 
}

/*
	_removeLink
	param: lst the linkedList
	param: l the linke to be removed
	pre: lst is not null
	pre: l is not null
	post: lst size is reduced by 1
*/

void _removeLink(struct linkedList *lst, struct DLink *l)
{

	/* Fix me */ 
}

/*
	removeFrontList
	param: lst the linkedList
	pre:lst is not null
	pre: lst is not empty
	post: size is reduced by 1
*/

void removeFrontList(struct linkedList *lst) {
   /* Fix me */ 
}

/*
	removeBackList
	param: lst the linkedList
	pre: lst is not null
	pre:lst is not empty
	post: size reduced by 1
*/

void removeBackList(struct linkedList *lst)
{	
	/* Fix me */ 

}
/*
	isEmptyList
	param: lst the linkedList
	pre: lst is not null
	post: none
*/

int isEmptyList(struct linkedList *lst) {
  /* Fix me */ 
}


/* Function to print list
 Pre: lst is not null
 */
void _printList(struct linkedList* lst)
{
	/* Fix me */ 
}

/* Iterative implementation of contains() 
 Pre: lst is not null
 */

void addList(struct linkedList *lst, TYPE v)
{
	assert(lst != 0);
	addBackList(lst, v);
}

/* Iterative implementation of contains() 
 Pre: lst is not null
 pre: list is not empty
 */
int containsList (struct linkedList *lst, TYPE e) {
	/* Fix me */ 
}

/* Iterative implementation of remove() 
 Pre: lst is not null
 pre: lst is not empty
 */
void removeList (struct linkedList *lst, TYPE e) {
	/* Fix me */ 
}

/**************************************************************************
******************* ITERATOR FUNCTIONS BELOW ******************************
**************************************************************************/

/* Iterator Interface - an iterator abstract data type defines an interface that provides methods for writing loops. 
	In other words, an iterator ADT simply defines a set of behaviors that works on a collection. */

struct linkedListIter {
	struct DLink *cur;
	struct linkedList *lst;
};

/* Initialize the iterator */
void  initlinkedListIter (struct linkedList *lst, struct linkedListIter *itr) {
	
	// initialize the iterator fileds (cur and lst)
	itr->lst = lst;  // assign the lst that was passed in 
	itr->cur = itr->lst->frontSentinel;  // initialize to one before the first element in lst 
}

/* create a new linked list iterator structure and return it back to the user */
struct linkedListIter *createlinkedListIter(struct linkedList *lst){
	
	// Allocate a new iterator structure 
	struct linkedListIter *newItr = malloc(sizeof(struct linkedListIter));
	assert(newItr != 0);
	
	// initialize the iterator 
	initlinkedListIter(lst, newItr);
	
	// return iterator to user 
	return(newItr);
}

 /* Determines if there are more values in the collection and if so, returns true.  It also
  * sets up for the subsequent call to 'next' by making cur point to the next value in the collection.*/
int hasNextlinkedListIter (struct linkedListIter *itr) {

	// since iterator cur was initialized to the front sentinel, we can determine if there are any more elements to traverse by looking at cur->next
	if(itr->cur->next != itr->lst->backSentinel) // if this is true then there are more elements to traverse
	{
		// move current to the first value
		itr->cur = itr->cur->next;
		return(1);  // return true 
	}
	else 
		return(0);  // return false; 
}

/* returns the next value in the collection */
TYPE nextlinkedListIter (struct linkedListIter *itr) {
	
	// return a value, since this function is called right after the hasNextlinkedListIter function, cur already points to 
	// the value we want so just return the value of cur 
	return (itr->cur->value); 
}

/* removes the last value returned by 'next'
 * Notice that we use a tmp to ensure that the following
 * calls to hasNext and next are correct after removal of the current link.*/
void removelinkedListIter (struct linkedListIter *itr) {
	
	// create a temp link 
	struct DLink *tmp = itr->cur;

	// update cur 
	itr->cur = itr->cur->prev; 
	
	// remove temp 
	_removeLink(itr->lst, tmp); 
}





///*Bag Wrapper Interface*/
//struct bag *createBag()
//{
//	struct bag *myBag = malloc(sizeof(struct bag));
//	myBag->lst = createLinkedList();
//	return myBag;
//}
//void addToBag(struct bag* b, TYPE val)
//{
//	addList(b->lst, val);
//}
//void removeFromBag(struct bag* b, TYPE val)
//{
//	removeList(b->lst, val);
//}
//int containsBag(struct bag* b, TYPE val)
//{
//	return(containsList(b->lst, val));
//}
//int isEmptyBag(struct bag* b)
//{
//	return(isEmptyList(b->lst));
//}
//
//void printBag(struct bag *b)
//{
//	_printList(b->lst);
//}
