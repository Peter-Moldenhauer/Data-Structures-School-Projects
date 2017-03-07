/*************************************************************************************************
* Author:                       Peter Moldenhauer
* Date Created:                 3/7/17
* Last Modification Date:       3/7/17
* Filename:                     spellChecker.c
* Class:                        CS 261 - Data Structures
* Assignment:                   Assignment 6
*
* Overview:
*   This file is an implementation of a spell checker program using a hash map.
*
* Input:
*   This program uses the dictionary.txt file as input to run this program. When the program starts,
*   the user then types in words as input.
*
* Output:
*   After the user enters a word and hits enter, the program outputs to the user whether or not
*   that word is spelled correctly.
*************************************************************************************************/

#include "hashMap.h"
#include <assert.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Allocates a string for the next word in the file and returns it. This string
 * is null terminated. Returns NULL after reaching the end of the file.
 * @param file
 * @return Allocated string or NULL.
 */
char* nextWord(FILE* file)
{
    int maxLength = 16;
    int length = 0;
    char* word = malloc(sizeof(char) * maxLength);
    while (1)
    {
        char c = fgetc(file);
        if ((c >= '0' && c <= '9') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            c == '\'')
        {
            if (length + 1 >= maxLength)
            {
                maxLength *= 2;
                word = realloc(word, maxLength);
            }
            word[length] = c;
            length++;
        }
        else if (length > 0 || c == EOF)
        {
            break;
        }
    }
    if (length == 0)
    {
        free(word);
        return NULL;
    }
    word[length] = '\0';
    return word;
}

/**
 * Loads the contents of the file into the hash map.
 * @param file
 * @param map
 */
void loadDictionary(FILE* file, HashMap* map)
{
    // FIXME: implement

    assert(map != NULL);

    char* word = nextWord(file);

    // if file exists
    if(file != NULL){
        //while there are words in the file
        while(word != NULL){
            // put the word into the hash
            hashMapPut(map, word, 0);
            free(word);
            word = nextWord(file);
        }
    }
    // if the file does not exist
    else {
        printf("That file does not exist!\n\n");
    }
}

/**
 * Prints the concordance of the given file and performance information. Uses
 * the file input1.txt by default or a file name specified as a command line
 * argument.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, const char** argv)
{
    // FIXME: implement
    HashMap* map = hashMapNew(1000);

    FILE* file = fopen("dictionary.txt", "r");
    clock_t timer = clock();
    loadDictionary(file, map);
    timer = clock() - timer;
    printf("Dictionary loaded in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
    fclose(file);

    char inputBuffer[256];
    int quit = 0;
    while (!quit)
    {
        printf("Enter a word or \"quit\" to quit: ");
        scanf("%s", inputBuffer);

        // Implement the spell checker code here..

        // if the word is in the dictionary
        if(hashMapContainsKey(map, inputBuffer)){
            printf("Word spelled correctly!\n");
        }
        // if word is not in the dictionary
        else {
            printf("Word NOT spelled correctly!\n");
        }

        if (strcmp(inputBuffer, "quit") == 0)
        {
            quit = 1;
        }
    }

    hashMapDelete(map);
    return 0;
}
