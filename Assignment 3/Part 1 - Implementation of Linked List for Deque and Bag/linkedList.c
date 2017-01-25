/*************************************************************************************************
* Author:                       Peter Moldenhauer
* Date Created:                 1/25/17
* Last Modification Date:       1/25/17
* Filename:                     linkedList.c
* Class:                        CS 261 - Data Structures
* Assignment:                   Assignment 3 - Part 1
*
* Overview:
*   This file demonstrates a linked list and the linked list-based implementation of a Deque
*   and a bag. Combined with this file, the files linkedList.h and testLinkedList.c are used to
*   test the implementation code in this file.
*
* Input:
*   There is no user input in this program.
*
* Output:
*   When run with testLinkedList.c, various output messages are printed to the screen informing
*   the user that various values were added and removed from the list successfully.
*
*   NOTE: Disregard the linkedListMain.c file. This file is included for another school assignment
*   that uses the linkedList.c and linkedList.h files.
*************************************************************************************************/

#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

// Double link
struct Link
{
	TYPE value;
	struct Link* next;
	struct Link* prev;
};

// Double linked list with front and back sentinels
struct LinkedList
{
	int size;
	struct Link* frontSentinel;
	struct Link* backSentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinels' next and prev should point to eachother or NULL
 * as appropriate.
 */
static void init(struct LinkedList* list) {
	// FIXME: you must write this

	// assert list is not null
	assert(list != NULL);

	// create front sentinel node
	list->frontSentinel = malloc(sizeof(struct Link));
	assert(list->frontSentinel != NULL);

	// create back sentinel node
	list->backSentinel = malloc(sizeof(struct Link));
	assert(list->backSentinel != NULL);

	// set front sentinel previous to NULL and next to back sentinel
	list->frontSentinel->prev = NULL;
	list->frontSentinel->next = list->backSentinel;

	// set back sentinel previous to front sentinel and next to nULL
	list->backSentinel->prev = list->frontSentinel;
	list->backSentinel->next = NULL;

	// initialize size to 0
	list->size = 0;
}

/**
 * Adds a new link with the given value before the given link and
 * increments the list's size.
 */
static void addLinkBefore(struct LinkedList* list, struct Link* link, TYPE value)
{
	// FIXME: you must write this

	// assert that list and link are not NULL
	assert(list != NULL);
	assert(link != NULL);

	// allocate a new node
	struct Link *newLink = (struct Link *)malloc(sizeof(struct Link));
	assert(newLink != NULL);

	// fill new node's value with parameter v
	newLink->value = value;

	// set the new node's previous to the provided before link's previous
	newLink->prev = link->prev;

	// set the new node's next to point to the provided before link
	newLink->next = link;

	// update the node before the inserted link to point to the new link
	link->prev->next = newLink;

	// set previous of provided before link to now point towards the new node (point back)
	link->prev = newLink;

	// update size of the linked list
	list->size++;
	assert(list->size != 0);
}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct LinkedList* list, struct Link* link)
{
	// FIXME: you must write this

	// assert that list and link are not equal to NULL
	assert(list != NULL);
	assert(link != NULL);

	// make sure the link behind next points to the correct link
	link->prev->next = link->next;

	// make sure the link before previous points to the correct link
	link->next->prev = link->prev;

	// now that its "unlinked"
	free(link);

	// update the size
	list->size--;
}

/**
 * Allocates and initializes a list.
 */
struct LinkedList* linkedListCreate()
{
	struct LinkedList* newDeque = malloc(sizeof(struct LinkedList));
	init(newDeque);
	return newDeque;
}

/**
 * Deallocates every link in the list including the sentinels,
 * and frees the list itself.
 */
void linkedListDestroy(struct LinkedList* list)
{
	while (!linkedListIsEmpty(list))
	{
		linkedListRemoveFront(list);
	}
	free(list->frontSentinel);
	free(list->backSentinel);
	free(list);
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void linkedListAddFront(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this

	// assert that list is not NULL
	assert(list != NULL);

	// adds to front of the list by adding a link next to the front sentinel
	addLinkBefore(list, list->frontSentinel->next, value);
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void linkedListAddBack(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this

	// assert that list is not NULL
	assert(list != NULL);

	// adds to back of the list by adding a link before the back sentinel
	addLinkBefore(list, list->backSentinel, value);
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE linkedListFront(struct LinkedList* list)
{
	// FIXME: you must write this

    // assert that list is not NULL
    assert(list != NULL);

    // assert that the list is not empty
    assert(linkedListIsEmpty(list) != 1);

    return list->frontSentinel->next->value;
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE linkedListBack(struct LinkedList* list)
{
	// FIXME: you must write this

	// assert that list is not NULL
    assert(list != NULL);

    // assert that the list is not empty
    assert(linkedListIsEmpty(list) != 1);

    return list->backSentinel->prev->value;
}

/**
 * Removes the link at the front of the deque.
 */
void linkedListRemoveFront(struct LinkedList* list)
{
	// FIXME: you must write this

	// assert that list is not NULL
	assert(list != NULL);

    // assert that the list is not empty
    assert(linkedListIsEmpty(list) != 1);

    // remove the link next to the front sentinel
    removeLink(list, list->frontSentinel->next);
}

/**
 * Removes the link at the back of the deque.
 */
void linkedListRemoveBack(struct LinkedList* list)
{
	// FIXME: you must write this

	// assert that list is not NULL
	assert(list != NULL);

    // assert that the list is not empty
    assert(linkedListIsEmpty(list) != 1);

    // remove the link next to the front sentinel
    removeLink(list, list->backSentinel->prev);
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int linkedListIsEmpty(struct LinkedList* list)
{
	// FIXME: you must write this

	// assert list is not NULL
	assert(list != NULL);

	// return 0 if list is not empty and 1 if list is empty
	if (list->size > 0)
        return 0;
    else
        return 1;
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void linkedListPrint(struct LinkedList* list)
{
	// FIXME: you must write this

	// assert that list is not NULL
	assert(list != NULL);

	struct Link *currentLink;

	currentLink = list->frontSentinel->next;

	// loop through all of the links
	while(currentLink != list->backSentinel){
        printf("%d ", currentLink->value);
        currentLink = currentLink->next;
	}
	printf("\n");
}

/**
 * Adds a link with the given value to the bag.
 */
void linkedListAdd(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this

	// assert that list is not NULL
	assert(list != NULL);

    // since this is a bag it does not matter where to add the link, just add to the front
    linkedListAddFront(list, value);
}

/**
 * Returns 1 if a link with the value is in the bag and 0 otherwise.
 */
int linkedListContains(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this

	// assert that list is not NULL
	assert(list != 0);

	// assert that the list is not empty
	assert(linkedListIsEmpty(list) != 1);

	// create a pointer for iterating
	struct Link *currentLink;

	// initialize new pointer to the first link in the list
	currentLink = list->frontSentinel->next;

	// loop while the current link has not reached the end of the linked list
	while(currentLink != list->backSentinel){
        // check if the value of that link is the value we are searching for
        if(currentLink->value == value){
            // if value is in this link then return 1
            return 1;
        }
        // update the current link to loop though the next link's value
        currentLink = currentLink->next;
	}

	// if value was not found in the linked list then return 0
	return 0;
}

/**
 * Removes the first occurrence of a link with the given value.
 */
void linkedListRemove(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this

	// assert list is not NULL
	assert(list != NULL);

	// assert that the list is not empty
	assert(linkedListIsEmpty(list) != 1);

	// create a pointer for iterating
	struct Link *currentLink;

	// initialize new pointer to the first link in the list
	currentLink = list->frontSentinel->next;

	// loop through the entire list to find and remove the specified value
	while(currentLink != list->backSentinel){
        // if the value is found that you want to remove...
        if(currentLink->value == value){
            // remove link
            removeLink(list, currentLink);
            // break the loop so we only remove one instance of it
            break;
        }
        // update the current link to check the next link in the list
        currentLink = currentLink->next;
	}
}

