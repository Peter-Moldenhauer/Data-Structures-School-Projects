/*******************************************************************************************
* Author:                       Peter Moldenhauer
* Date Created:                 1/5/17
* Last Modification Date:       1/5/17
* Filename:                     main.c
* Class:                        CS 261 - Data Structures
* Assignment:                   Assignment 0
*
* Overview:
*   This program will allow the user to either convert inches to centimeters or centimeters
*   to inches. If the user wishes to make both conversions, the program will need to be run
*   more than once.
*
* Input:
*   The input will consist of the user first entering in either a 1 or 2 to determine which
*   conversion to take place. Note: no data validation takes place so user must enter in
*   exactly a 1 or 2. Next, the user will enter in either a number of inches to convert or a
*   number of centimeters to convert (based on the initial choice of 1 or 2).
*
* Output:
*   The output of the program will be the final conversion of inches or centimeters based on
*   the users initial choice of what to convert.
*
*   Example output:
*   20.25 inches is equal to 51.54 centimeters.
********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// This function converts an input inches value and prints the corresponding centimeter value
void convertToCM(float in);

// This function converts an input centimeter value and prints the corresponding inch value
void convertToIN(float cm);

int main(){

    float inches, centimeters; // for user input of inches or centimeters to convert
    int choice;  // for user input to select which conversion to conduct

    printf("Please enter 1 or 2:\n1) Convert inches to centimeters \n2) Convert centimeters to inches\nEnter here: ");
    scanf("%d", &choice);

    // user wants to convert inches to centimeters
    if(choice == 1){
        printf("\nEnter the number of inches you want to convert: ");
        scanf("%f", &inches);
        convertToCM(inches);
    }

    // user want to convert centimeters to inches
    if(choice == 2){
        printf("\nEnter the number of centimeters you want to convert: ");
        scanf("%f", &centimeters);
        convertToIN(centimeters);
    }

    return 0;
}

/************************************************************************************
*   Entry:  in is the user input of the number of inches to convert to centimeters
*
*   Exit:   Conversion takes place and the result is printed to the screen
*
* Purpose:  This function accepts a value in inches and converts to centimeters
*************************************************************************************/
void convertToCM(float in){
    float answer = in * 2.54;  // answer stores the result of the calculation
    printf("%.2f inches is equal to %.2f centimeters.\n", in, answer);
    return;
}

/************************************************************************************
*   Entry:  cm is the user input of the number of centimeters to convert to inches
*
*   Exit:   Conversion takes place and the result is printed to the screen
*
* Purpose:  This function accepts a value in centimeters and converts to inches
*************************************************************************************/
void convertToIN(float cm){
    float answer = cm / 2.54;  // answer stores the result of the calculation
    printf("%.2f centimeters is equal to %.2f inches.\n", cm, answer);
    return;
}
