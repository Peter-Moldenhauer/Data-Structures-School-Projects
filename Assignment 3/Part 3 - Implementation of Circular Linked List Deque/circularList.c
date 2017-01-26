/*************************************************************************************************
* Author:                       Peter Moldenhauer
* Date Created:                 1/26/17
* Last Modification Date:       1/26/17
* Filename:                     circularList.c
* Class:                        CS 261 - Data Structures
* Assignment:                   Assignment 3 - Part 3
*
* Overview:
*   This file demonstrates a circularly linked list and the circularly linked list-based
*   implementation of a Deque.
*
* Input:
*   There is no user input in this program.
*
* Output:
*   When run with circularList.h and circularListMain.c, information will be printed to the screen
*   informing the user that the circularList.c file is working correctly.
*************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "circularList.h"

// Double link
struct Link
{
	TYPE value;
	struct Link * next;
	struct Link * prev;
};

struct CircularList
{
	int size;
	struct Link* sentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinel's next and prev should point to the sentinel itself.
 */
static void init(struct CircularList* list)
{
	// FIXME: you must write this

	// assert that list is not NULL
	assert(list != NULL);

	// allocate memory for the sentinel
	list->sentinel = (struct Link *)malloc(sizeof(struct Link));

	// assert that sentinel has been allocated
	assert(list->sentinel != NULL);

	// set the sentinel next and previous to itself since there is only one sentinel
	list->sentinel->next = list->sentinel;
	list->sentinel->prev = list->sentinel;

	// initialize size to 0
	list->size = 0;
}

/**
 * Creates a link with the given value and NULL next and prev pointers.
 */
static struct Link* createLink(TYPE value)
{
	// FIXME: you must write this

	// allocate memory for a new link
	struct Link *newLink = (struct Link *)malloc(sizeof(struct Link));

	// assert that new link is not NULL
	assert(newLink != NULL);

	// initialize new link value with value parameter
	newLink->value = value;

	// return new link
	return newLink;
}

/**
 * Adds a new link with the given value after the given link and
 * increments the list's size.
 */
static void addLinkAfter(struct CircularList* list, struct Link* link, TYPE value)
{
	// FIXME: you must write this

	// assert that list is not NULL
	assert(list != NULL);

	// assert that link is not NULL
	assert(link != NULL);

	// assert that link is in list
	assert(link->next != NULL);
	assert(link->prev != NULL);

	// allocate memory for a new link with the value "value" parameter
	struct Link *newLink = createLink(value);

	// update link in front of insertion link to point back to inserted link
	link->next->prev = newLink;

	// set new link next to link in front of it
	newLink->next = link->next;

	// set link before to point to inserted link
	link->next = newLink;

	// set the previous from new link to point back to the link you inserted after
    newLink->prev = link;

    // update the List size
    list->size++;
}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct CircularList* list, struct Link* link)
{
	// FIXME: you must write this

	// assert that list is not NULL
	assert(list != NULL);

	// assert that link is not NULL
	assert(link != NULL);

	// assert that link is in list
	assert(link->next != NULL);
	assert(link->prev != NULL);

	// adjust pointers to fill in the gap in the chain
	link->prev->next = link->next;
	link->next->prev = link->prev;

	// free the specified link
	free(link);

	// decrement the side of List
	list->size--;
}

/**
 * Allocates and initializes a list.
 */
struct CircularList* circularListCreate()
{
	struct CircularList* list = malloc(sizeof(struct CircularList));
	init(list);
	return list;
}

/**
 * Deallocates every link in the list and frees the list pointer.
 */
void circularListDestroy(struct CircularList* list)
{
	// FIXME: you must write this

	// assert that list is not NULL
	assert(list != NULL);

    //free every link by looping through list until list size is 0
    while(list->size != 0){
        circularListRemoveFront(list);
    }

    //free the sentinel
    free(list->sentinel);

    //free the list itself
    free(list);

    //defensive programming
    list = NULL;
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void circularListAddFront(struct CircularList* list, TYPE value)
{
	// FIXME: you must write this

	// assert that list is not NULL
	assert(list != NULL);

	// add link to the front of the list by adding it after the sentinel
	addLinkAfter(list, list->sentinel, value);
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void circularListAddBack(struct CircularList* list, TYPE value)
{
	// FIXME: you must write this

    // assert that list is not NULL
    assert(list != NULL);

    // add link to the back of list by adding it to the left of the sentinel accessed by prev
    addLinkAfter(list, list->sentinel->prev, value);
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE circularListFront(struct CircularList* list)
{
	// FIXME: you must write this

	// assert that list is not NULL
	assert(list != NULL);

	// make sure list is not empty
	assert(circularListIsEmpty(list) != 1);

	// return value of first link
	return list->sentinel->next->value;
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE circularListBack(struct CircularList* list)
{
	// FIXME: you must write this

	// assert that list is not NULL
	assert(list != NULL);

	// make sure list is not empty
	assert(circularListIsEmpty(list) != 1);

	// return value of last link
	return list->sentinel->prev->value;
}

/**
 * Removes the link at the front of the deque.
 */
void circularListRemoveFront(struct CircularList* list)
{
	// FIXME: you must write this

	// assert that list is not NULL
	assert(list != NULL);

	// make sure list is not empty
	assert(circularListIsEmpty(list) != 1);

	// remove first link
	removeLink(list, list->sentinel->next);
}

/**
 * Removes the link at the back of the deque.
 */
void circularListRemoveBack(struct CircularList* list)
{
	// FIXME: you must write this

	// assert that list is not NULL
	assert(list != NULL);

	// make sure list is not empty
	assert(circularListIsEmpty(list) != 1);

	// remove last link
	removeLink(list, list->sentinel->prev);
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int circularListIsEmpty(struct CircularList* list)
{
	// FIXME: you must write this

	// assert that list is not NULL
	assert(list != NULL);

	//return 1 or 0 based on the value of size
	if (list->size == 0)
        return 1;
    else
        return 0;
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void circularListPrint(struct CircularList* list)
{
	// FIXME: you must write this

	// assert that list is not NULL
	assert(list != NULL);

	// assert that list is not empty
	assert(circularListIsEmpty(list) != 1);

	// create an iterator to use for in the loop
	struct Link *current = list->sentinel->next;

	// keep looping while iterator is not equal to the sentinel
	while(current != list->sentinel){
        // print the value of the link
        printf("%g ", current->value);
        // update the link to the next one
        current = current->next;
	}
	printf("\n");
}

/**
 * Reverses the deque.
 */
void circularListReverse(struct CircularList* list)
{
	// FIXME: you must write this

	// assert that list is not NULL
	assert(list != NULL);

	// assert that the list is not empty
	assert(circularListIsEmpty(list) != 1);

	// create an iterator to loop through list
	struct Link *current = list->sentinel->next;

	// create a temp link to hold a link when reversing all of the links
	struct Link *temp = NULL;

	// loop through links and reverse the next and prev pointers
	while(current != list->sentinel){
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        // update current to the next link
        current = current->prev;
	}

	// update sentinel to change its first and next
	temp = list->sentinel->next;
	list->sentinel->next = list->sentinel->prev;
	list->sentinel->prev = temp;
}

