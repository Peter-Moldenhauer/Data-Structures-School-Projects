/*************************************************************************************************
* Author:                       Peter Moldenhauer
* Date Created:                 2/26/17
* Last Modification Date:       2/26/17
* Filename:                     task.c
* Class:                        CS 261 - Data Structures
* Assignment:                   Assignment 5
*
* Overview:
*   This file contains various functions needed to complete the application logic in other 
*	heap-based priority queue programs. 
*
* Input:
*   There is no user input in this program - only functions.
*
* Output:
*   There is no output - only functions.  
*************************************************************************************************/

#include "task.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Creates a new task with the given priority and name.
 * @param priority
 * @param name
 * @return  The new task.
 */
Task* taskNew(int priority, char* name)
{
    // FIXME: implement

    Task* newTask = malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    return newTask;
}

/**
 * Frees a dynamically allocated task.
 * @param task
 */
void taskDelete(Task* task)
{
    free(task);
}

/**
 * Casts left and right to Task pointers and returns
 * -1 if left's priority < right's priority,
 *  1 if left's priority > right's priority,
 *  0 if left's priority == right's priority.
 * @param left  Task pointer.
 * @param right  Task pointer.
 * @return
 */
int taskCompare(void* left, void* right)
{
    // FIXME: implement

    if(((Task*)left)->priority <((Task*)right)->priority)
    {
        return -1;
    }
    else if(((Task*)left)->priority >((Task*)right)->priority)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * Prints a task as a (priority, name) pair.
 * @param value  Task pointer.
 */
void taskPrint(void* value)
{
    Task* task = (Task*)value;
    printf("(%d, %s)", task->priority, task->name);
}


