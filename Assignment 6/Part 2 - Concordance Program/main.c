/*************************************************************************************************
* Author:                       Peter Moldenhauer
* Date Created:                 3/6/17
* Last Modification Date:       3/6/17
* Filename:                     main.c
* Class:                        CS 261 - Data Structures
* Assignment:                   Assignment 6
*
* Overview:
*   This file is an implementation of a concordance program. The concordance counts how many times
*   each word occurs in a document.
*
* Input:
*   The user should give a file name as a command line argument when running this program. If no
*   file name is provided then the default file "input1.txt will be used as default.
*
* Output:
*   This program outputs the number of times each word occurs in a given document.
*************************************************************************************************/

#include "hashMap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <assert.h>

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
    const char* fileName = "input1.txt";
    if (argc > 1)
    {
        fileName = argv[1];
    }
    printf("Opening file: %s\n", fileName);

    clock_t timer = clock();

    HashMap* map = hashMapNew(10);

    // --- Concordance code begins here ---
    // Be sure to free the word after you are done with it here.

    // 1. Get the next word with nextWord
    // 2. If the word is already in the hash map, then increment its number of occurrences
    // 3. Otherwise, put the word in the hash map with a count of 1
    // 4. Free the word



    FILE* file = fopen(fileName, "r");
    char* word = NULL;
    int* value;
    int i;

    // if the file exists
    if(file != NULL){

        // while there are still words in the file
        while((word = nextWord(file)) != NULL){
            // if the word is already in the hash map
            if(hashMapContainsKey(map, word) == 1){
                // increment the word's number of occurrences
                value = hashMapGet(map, word);
                (*value)++;
            }
            // otherwise put the word in hash map with count of 1
            else {
                hashMapPut(map, word, 1);
            }
        }

        // close the file
        fclose(file);
    }
    // if the file does not exist
    else {
        printf("That file does not exist!\n");
    }

    // free the word
    free(word);

    // Print the words and occurrence counts in the hash map
    for(i = 0; i < map->capacity; i++){
        HashLink* link = map->table[i];
        if(link != NULL){
            printf("%s: %d \n", link->key, link->value);
            link = link->next;
        }
        free(link);
    }
    printf("\n\n");

    // --- Concordance code ends here ---

    hashMapPrint(map);

    timer = clock() - timer;
    printf("\nRan in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
    printf("Empty buckets: %d\n", hashMapEmptyBuckets(map));
    printf("Number of links: %d\n", hashMapSize(map));
    printf("Number of buckets: %d\n", hashMapCapacity(map));
    printf("Table load: %f\n", hashMapTableLoad(map));

    hashMapDelete(map);
    return 0;
}
