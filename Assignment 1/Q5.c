/*************************************************************************************************
* Author:                       Peter Moldenhauer
* Date Created:                 1/10/17
* Last Modification Date:       1/10/17
* Filename:                     Q5.c
* Class:                        CS 261 - Data Structures
* Assignment:                   Assignment 1 - Q. 5
*
* Overview:
*   This program takes a word that the user inputs and modifies the word so that the word then
*   appears with "sticky caps".
*
* Input:
*   The user enters a word to be modified.
*
* Output:
*   The modified word in "sticky caps" is printed to the screen. An example of sticky caps is:
*   StiCkY cApS - start with upper case and alternate with lower case.
*************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

/************************************************************************************
*   Entry:  Accepts a character array.
*
*   Exit:   This function does not return anything.
*
* Purpose:  This function takes the character array as an argument and converts the
*           array into "sticky caps".
*************************************************************************************/
void sticky(char* word){
    int i;

     /*Convert to sticky caps*/
     for(i = 0; i < 20; i++){

        // exit function if end of the word array is reached
        if(word[i] == '\0')
            return;

        // change the even array index letters to upper case
        if(!(i % 2) && word[i] >= 'a' && word[i] <= 'z')
            word[i] = toupper(word[i]);

        // change the odd array index letters to lower case
        else if((i % 2) && word[i] >= 'A' && word[i] <= 'Z')
            word[i] = tolower(word[i]);
     }

     //Another option to do this would be to use if statements with isupper() and islower() to check the current case
     //then based on what case it is, switch the appropriate letters.
}

int main(){
    /*Read word from the keyboard using scanf*/
    char theWord[20];

    printf("Enter a word here: ");
    scanf("%s", theWord);

    /*Call sticky*/
    sticky(theWord);

    /*Print the new word*/
    printf("Sticky Case: %s\n", theWord);

    return 0;
}

