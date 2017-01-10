/*************************************************************************************************
* Author:                       Peter Moldenhauer
* Date Created:                 1/9/17
* Last Modification Date:       1/9/17
* Filename:                     Q2.c
* Class:                        CS 261 - Data Structures
* Assignment:                   Assignment 1 - Q. 2
*
* Overview:
*   This program uses the function foo to set and assign the values to various integers that are
*   declared in the main function. This demonstrates pass by value vs pass by reference.
*
* Input:
*   There is no user input in this program.
*
* Output:
*   The values of the declared integers in main are printed out before and after the function call
*************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a *= 2;

    /*Set b to half its original value*/
    *b /= 2;

    /*Assign a+b to c*/
    c = (*a) + (*b);

    /*Return c*/
    return c;
}

int main(){
    int returnedValue;

    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    int x = 5;
    int y = 6;
    int z = 7;

    /*Print the values of x, y and z*/
    printf("x: %d\n", x);
    printf("y: %d\n", y);
    printf("z: %d\n", z);

    /*Call foo() appropriately, passing x,y,z as parameters*/
    returnedValue = foo(&x, &y, z);

    /*Print the value returned by foo*/
    printf("Value returned by foo: %d\n", returnedValue);

    /*Print the values of x, y and z again*/
    printf("x: %d\n", x);
    printf("y: %d\n", y);
    printf("z: %d\n", z);

    /*Is the return value different than the value of z?  Why?*/

    /*Yes, this is because z was passed by value and NOT by reference to foo().
    Therefore, the value of z could not be changed from within foo(). The
    returned value is a different variable and its value did change inside of
    foo().
    */

    return 0;
}

