/*************************************************************************************************
* Author:                       Peter Moldenhauer
* Date Created:                 1/18/17
* Last Modification Date:       1/18/17
* Filename:                     stackapp.c
* Class:                        CS 261 - Data Structures
* Assignment:                   Assignment 2 - Part 3
*
* Overview:
*   This file demonstrates an application of a stack by checking whether an expression has balanced
*   parentheses, braces and brackets or not. For example, expressions with balanced parentheses are
*   (x+y), (x+(y+z)) and with unbalanced are (x+y, (x+(y+z).
*
* Input:
*   There is no user input in this program.
*
* Output:
*   This program prints to the screen whether or not a given string has balanced parentheses,
*   brackets or braces. Note: the string is hard coded into the main() function.
*************************************************************************************************/

/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string
	pre: s is not null
*/
char nextChar(char* s)
{
	static int i = -1;
	char c;
	++i;
	c = *(s+i);
	if ( c == '\0' )
		return '\0';
	else
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string
	pre: s is not null
	post:
*/
int isBalanced(char* s)
{
	/* FIXME: You will write this function */

    int capacity = 10;
    char c;

    /* create a dynamic array based stack */
    DynArr *theStack;
    theStack = newDynArr(capacity);

    /* loop through string */
    for (c = nextChar(s); c != '\0' ; c = nextChar(s)) {

        /* push parens to stack if appropriate */
        if (c == '(')
            pushDynArr(theStack, ')');
        else if (c == '{')
            pushDynArr(theStack, '}');
        else if (c == '[')
            pushDynArr(theStack, ']');

        /* no matching parens - return 0 */
        else if (c == ')' && (isEmptyDynArr(theStack) == 1 || topDynArr(theStack) != c)){
            deleteDynArr(theStack);
            return 0;
        }
        else if (c == '}' && (isEmptyDynArr(theStack) == 1 || topDynArr(theStack) != c)){
            deleteDynArr(theStack);
            return 0;
        }
        else if (c == ']' && (isEmptyDynArr(theStack) == 1 || topDynArr(theStack) != c)){
            deleteDynArr(theStack);
            return 0;
        }

        /* matching opening parenthesis - pop stack */
        else if (c == ')' || (c == '}') || (c == ']'))
            popDynArr(theStack);
    }

    /* stack not empty after loop through array - return 0 */
    if (isEmptyDynArr(theStack) == 0) {
        deleteDynArr(theStack);
        return 0;
    }

    /* all open parens matched closing parens in balanced order - return 1 */
    deleteDynArr(theStack);
    return 1;
}

int main(int argc, char* argv[]){

	//char* s=argv[1];  /* this was in the skeleton code but causes the program to crash */

	char* s = "a{b{de[f]g{h}i}jklm}";  /* this is a given string in place of line above, program works with this */

	int res;

	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else
		printf("The string %s is not balanced\n",s);

	return 0;
}

