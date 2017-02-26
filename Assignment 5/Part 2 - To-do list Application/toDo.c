/*************************************************************************************************
* Author:                       Peter Moldenhauer
* Date Created:                 2/26/17
* Last Modification Date:       2/26/17
* Filename:                     toDo.c
* Class:                        CS 261 - Data Structures
* Assignment:                   Assignment 5
*
* Overview:
*   This file uses a priority queue to implement a to-do list application. This interactive 
*	application allows the user to manage a prioritized to-do list by adding new tasks, 
*	viewing the highest priority task, removing the highest priority task, saving the list to 
*	a file, and loading the list from a file.   
*
* Input:
*   The user is provided a menu in which various characters can be entered to control what 
*	action to perform with the to-do list application. 
*
* Output:
*   This program outputs a menu option to the user and the result of each menu selection that 
*	the user performs. 
*************************************************************************************************/

#include "dynamicArray.h"
#include "task.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Loads into heap a list from a file with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listLoad(DynamicArray* heap, FILE* file)
{
    const int FORMAT_LENGTH = 256;
    char format[FORMAT_LENGTH];
    snprintf(format, FORMAT_LENGTH, "%%d, %%%d[^\n]", TASK_NAME_SIZE);

    Task temp;
    while (fscanf(file, format, &temp.priority, &temp.name) == 2)
    {
        dyHeapAdd(heap, taskNew(temp.priority, temp.name), taskCompare);
    }
}

/**
 * Writes to a file all tasks in heap with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listSave(DynamicArray* heap, FILE* file)
{
    int i;
    for (i = 0; i < dySize(heap); i++)
    {
        Task* task = dyGet(heap, i);
        fprintf(file, "%d, %s\n", task->priority, task->name);
    }
}

/**
 * Prints every task in heap.
 * @param heap
 */
void listPrint(DynamicArray* heap)
{
    DynamicArray* temp = dyNew(1);
    dyCopy(heap, temp);
     while (dySize(temp) > 0)
    {
        Task* task = dyHeapGetMin(temp);
        printf("\n");
        taskPrint(task);
        printf("\n");
        dyHeapRemoveMin(temp, taskCompare);
    }
    dyDelete(temp);
}

/**
 * Handles the given command.
 * @param list
 * @param command
 */
void handleCommand(DynamicArray* list, char command)
{
    // FIXME: Implement

    char fileName[100];
    char taskName[100];
    int priority = 0;
    FILE *file = NULL;
    Task *newTask, *tempTask;

    if(command == 'l')
    {
        printf("Enter the name of the list that you would like to load: ");
        scanf("%s", fileName);
        while(getchar() != '\n');
        file = fopen(fileName, "r");

        if(file == NULL)
        {
            printf("Error: That file does not exist.\n\n");
        }
        else
        {
            listLoad(list, file);
            fclose(file);
            printf("The file is now loaded!\n\n");
        }
    }

    else if(command == 's')
    {
        printf("Enter a name to save the to-do list: ");
        scanf("%s", fileName);
        while(getchar() != '\n');
        file = fopen(fileName, "w");

        if(file == NULL)
        {
            printf("File does not exist\n\n");
        }
        else
        {
            listSave(list, file);
            fclose(file);
            printf("File saved\n\n");
        }
    }

    else if(command == 'a')
    {
        printf("Enter the name of the task to add: ");
        fgets(taskName, sizeof(taskName), stdin);

        //Remove the \n character that is stored in name with fgets()
        if(taskName[strlen(taskName) - 1] == '\n')
        {
            taskName[strlen(taskName) - 1] = '\0';
        }

        printf("Enter the priority: ");
        scanf("%d", &priority);
        while(getchar() != '\n');
        newTask = taskNew(priority, taskName);
        dyHeapAdd(list, newTask, taskCompare);
        printf("\n");
    }

    else if(command == 'g')
    {
        if(dySize(list) > 0)
        {
            tempTask = dyHeapGetMin(list);
            printf("First task to complete: %s\n\n", tempTask->name);
        }
        else
        {
            printf("The list is empty!\n\n");
        }
    }

    else if(command == 'r')
    {
        if(dySize(list) > 0)
        {
            tempTask = dyHeapGetMin(list);
            printf("Task just completed: %s\n\n", tempTask->name);
            dyHeapRemoveMin(list, taskCompare);
        }
        else
        {
            printf("The list is empty!\n\n");
        }
    }

    else if(command == 'p')
    {
        if(dySize(list) > 0)
        {
            printf("Printing List...\n");
            listPrint(list);
            printf("\n");
        }
        else
        {
            printf("List is empty!\n\n");
        }
    }

    else if(command == 'e')
    {
        printf("Exiting program...\n\n");
    }

    else
    {
        printf("Error: Please enter a valid command!\n\n");
    }
}

int main()
{
    // Implement
    printf("\n\n** TO-DO LIST APPLICATION **\n\n");
    DynamicArray* list = dyNew(8);
    char command = ' ';
    do
    {
        printf("Press:\n"
               "'l' to load to-do list from a file\n"
               "'s' to save to-do list to a file\n"
               "'a' to add a new task\n"
               "'g' to get the first task\n"
               "'r' to remove the first task\n"
               "'p' to print the list\n"
               "'e' to exit the program\n"
        );
        command = getchar();
        // Eat newlines
        while (getchar() != '\n');
        handleCommand(list, command);
    }
    while (command != 'e');
 /* free dynamically allocated List pointers in array to avoid memory leaks */
         /* Fix it */

    dyDelete(list);

    return 0;
}
