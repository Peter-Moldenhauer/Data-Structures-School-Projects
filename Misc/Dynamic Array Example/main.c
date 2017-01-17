/*************************************************************************************************
* Author:                       Peter Moldenhauer
* Date Created:                 1/16/17
* Last Modification Date:       1/16/17
* Filename:                     main.c
* Class:                        CS 261 - Data Structures
* Assignment:                   [ assignment here ]
*
* Overview:
*   This program demonstrates code for a dynamic array.
*
* Input:
*   [ input here ]
*
* Output:
*   [ output here ]
*************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "dynarr.h"  // header file for function prototypes
#include <assert.h>  // for assert function

int main(){

    // Examples of how a user might use the dynamic array
    struct DynArr d;  // allocate enough space for a single dynamic array
    initDynArr(&d, 8);  // initialize the array to have a capacity of 8
    addDynArr(&d, 1);  // add the value 1 to the array

    return 0;
}

// Example of what the initDynArr() function looks like
void initDynArr(struct DynArr *v, int cap){
    v->data = malloc(cap * TYPE_SIZE);
    assert(v->data != 0); // assert that its not 0 to make sure the allocation succeeded
    v->size = 0;
    v->cap = cap;
}

// Example of what the freeDynArr() function looks like - this deallocates memory
void freeDynArr(struct DynArr *v){
    if(v->data != 0){ // check to make sure that the array has not already been freed
        free(v->data);
        v->data = 0;
    }
    v->cap = 0;
    v->size = 0;
}

