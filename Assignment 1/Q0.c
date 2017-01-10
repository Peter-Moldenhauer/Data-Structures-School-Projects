/*************************************************************************************************
* Author:                       Peter Moldenhauer
* Date Created:                 1/9/17
* Last Modification Date:       1/9/17
* Filename:                     Q0.c
* Class:                        CS 261 - Data Structures
* Assignment:                   Assignment 1 - Q. 0
*
* Overview:
*   In the main function, an integer x is declared. The address of x is printed and x is
*   then passed as an argument to a function. The function is then called and inside of the
*   function, the value of the integer pointed to b iptr is printed along with the address
*   pointed to by iptr and the address of iptr. After the function call in main, the value
*   of x is printed.
*
* Input:
*   There is no user input in this program.
*
* Output:
*   Address of x is printed, he value of the integer pointed to b iptr is printed along with
*   the address pointed to by iptr and the address of iptr. Lastly, the value of x is printed
*************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>


/************************************************************************************
*   Entry:  Accepts the address of integer x - passed by reference
*
*   Exit:   Function does not return anything, just prints values/addresses
*
* Purpose:  The value of the integer pointed to b iptr is printed along with the
*           address pointed to by iptr and the address of iptr
*************************************************************************************/
void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
     printf("The value pointed to by iptr is: %d\n\n", *iptr);

     /*Print the address pointed to by iptr*/
     printf("The address pointed to by iptr is: %p\n\n", iptr);

     /*Print the address of iptr itself*/
     printf("The address of iptr itself is: %p\n\n", &iptr);
}

int main(){

    /*declare an integer x*/
    int x = 99;

    /*print the address of x*/
    printf("The address of x is: %p\n\n", &x);

    /*Call fooA() with the address of x*/
    fooA(&x);

    /*print the value of x*/
    printf("The value of x is: %d\n", x);

    return 0;
}
