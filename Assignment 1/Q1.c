/*************************************************************************************************
* Author:                       Peter Moldenhauer
* Date Created:                 1/9/17
* Last Modification Date:       1/9/17
* Filename:                     Q1.c
* Class:                        CS 261 - Data Structures
* Assignment:                   Assignment 1 - Q. 1
*
* Overview:
*   This program allocates memory for 10 student structures. Random IDs and scores are then
*   generated for each of the 10 students. The IDs and scores of each student is then printed
*   to the screen. The minimum score, maximum score and average score is then also printed to
*   the screen. Finally, the memory allocated for the 10 student structures is freed.
*
* Input:
*   There is no user input in this program.
*
* Output:
*   IDs and scores of each of the 10 students is printed to the screen along with the minimum
*   score, maximum score and average score.
*************************************************************************************************/

#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
     struct student *theStudents = malloc(10 * sizeof(struct student));

     /*return the pointer*/
     return theStudents;
}

void generate(struct student* students){
     int i;
     int temp;
     int swapIndex;

     /*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
     for(i = 0; i < 10; i++){
        students[i].id = i + 1;
        students[i].score = rand() % 101;
     }

     /*Mix up the ID numbers */
     for(i = 0; i < 10; i++){
        swapIndex = rand() % (i + 1);

        /*Swap the initial student ID at index i with the student ID at position swapIndex */
        temp = students[i].id;
        students[i].id = students[swapIndex].id;
        students[swapIndex].id = temp;
     }

}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/

    int i;

    for(i = 0; i < 10; i++){
        printf("ID:%d Score:%d\n", students[i].id, students[i].score);
    }
    printf("\n");
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
     int i;
     int min = 100;
     int max = 0;
     int total = 0;
     float average;

     for(i = 0; i < 10; i++){
        /*calculate sum of all scores */
        total += students[i].score;

        /*calculate min core */
        if(students[i].score < min){
            min = students[i].score;
        }

        /*calculate max core */
        if(students[i].score > max){
            max = students[i].score;
        }
     }

     /*calculate average score */
     average = total / (float)10;

     /*print results*/
     printf("Minimum Score: %d\n", min);
     printf("Maximum Score: %d\n", max);
     printf("Average Score: %.2f\n", average);

}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
     if(stud != NULL)
        free(stud);
}

int main(){
    struct student* stud = NULL;

    /*call allocate*/
    stud = allocate();

    /*call generate*/
    generate(stud);

    /*call output*/
    output(stud);

    /*call summary*/
    summary(stud);

    /*call deallocate*/
    deallocate(stud);

    return 0;
}
