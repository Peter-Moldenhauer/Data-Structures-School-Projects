/*************************************************************************************************
* Author:                       Peter Moldenhauer
* Date Created:                 1/10/17
* Last Modification Date:       1/10/17
* Filename:                     Q4.c
* Class:                        CS 261 - Data Structures
* Assignment:                   Assignment 1 - Q. 4
*
* Overview:
*   This program uses a sort() function to sort an array of n student structures based on their
*   scores in ascending order.
*
* Input:
*   There is no user input in this program.
*
* Output:
*   The contents of the array of n student structures is printed to the screen before and after
*   being sorted.
*************************************************************************************************/

#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

/************************************************************************************
*   Entry:  Accepts an array of student structs and int n (length of array).
*
*   Exit:   This function does not return anything.
*
* Purpose:  This function sorts the array of n students based on their scores in
*           ascending order.
*************************************************************************************/
void sort(struct student* students, int n){
     int i;
     struct student temp;
     int swapped;

     /*Sort the n students based on their score*/
     while(1){

        swapped = 0; // when swapped = 0 at the end that means the list is sorted

        //main sorting algorithm
        for(i=0; i<n-1; i++){

            if(students[i].score > students[i+1].score){
                temp = students[i];
                students[i] = students[i+1];
                students[i+1] = temp;
                swapped = 1;   // whenever you swap a number it means that the list is not in order yet, so do it again
            }

        }

        // break out of infinite loop if array is completely sorted
        if(swapped == 0){
            break;
        }
    }
}

int main(){
    int i;
    int temp;
    int swapIndex;

    /*Declare an integer n and assign it a value.*/
    int n = 10;

    /*Allocate memory for n students using malloc.*/
    struct student *theStudents = malloc(n * sizeof(struct student));

    /*Generate random and unique IDs and random scores for the n students, using rand().*/
    for(i = 0; i < n; i++){
        theStudents[i].id = i + 1;
        theStudents[i].score = rand() % 101;
     }

     /*Mix up the ID numbers */
     for(i = 0; i < n; i++){
        swapIndex = rand() % (i + 1);

        /*Swap the initial student ID at index i with the student ID at position swapIndex */
        temp = theStudents[i].id;
        theStudents[i].id = theStudents[swapIndex].id;
        theStudents[swapIndex].id = temp;
     }

    /*Print the contents of the array of n students.*/
    for(i = 0; i < n; i++){
        printf("ID:%d Score:%d\n", theStudents[i].id, theStudents[i].score);
    }
    printf("\n");

    /*Pass this array along with n to the sort() function*/
    sort(theStudents, n);

    /*Print the contents of the array of n students.*/
    for(i = 0; i < n; i++){
        printf("ID:%d Score:%d\n", theStudents[i].id, theStudents[i].score);
    }
    printf("\n");

    free(theStudents);

    return 0;
}
