/*************************************************************************************************
* Author:                       Peter Moldenhauer
* Date Created:                 1/9/17
* Last Modification Date:       1/9/17
* Filename:                     Q3.c
* Class:                        CS 261 - Data Structures
* Assignment:                   Assignment 1 - Q. 3
*
* Overview:
*   This program uses the function sort() to sort a given array of n integers in ascending order.
*
* Input:
*   There is no user input in this program.
*
* Output:
*   The contents of the sorted array following the call to sort() is printed to the screen.
*************************************************************************************************/

#include <stdio.h>
#include<stdlib.h>
#include<math.h>


void sort(int* number, int n){
     /*Sort the given array number , of length n*/
     int i;
     int temp;
     int swapped;

     while(1){

        swapped = 0; // when swapped = 0 at the end that means the list is sorted

        //main sorting algorithm
        for(i=0; i<n-1; i++){

            if(number[i] > number[i+1]){
                temp = number[i];
                number[i] = number[i+1];
                number[i+1] = temp;
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

    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;

    /*Allocate memory for an array of n integers using malloc.*/
    int *theArray = (int *) malloc(n * sizeof(int));

    /*Fill this array with random numbers, using rand().*/
    for(i = 0; i < n; i++){
        theArray[i] = (rand()%100) + 1;
    }

    /*Print the contents of the array.*/
    for(i = 0; i < n; i++){
        printf("%d ", theArray[i]);
    }

    printf("\n");

    /*Pass this array along with n to the sort() function of part a.*/
    sort(theArray, n);

    /*Print the contents of the array.*/
    for(i = 0; i < n; i++){
        printf("%d ", theArray[i]);
    }

    printf("\n");

    return 0;
}
