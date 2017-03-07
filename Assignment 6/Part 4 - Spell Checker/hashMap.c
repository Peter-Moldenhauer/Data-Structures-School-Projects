/*************************************************************************************************
* Author:                       Peter Moldenhauer
* Date Created:                 3/6/17
* Last Modification Date:       3/6/17
* Filename:                     hashMap.c
* Class:                        CS 261 - Data Structures
* Assignment:                   Assignment 6
*
* Overview:
*   This file is an implementation of a hash map.
*
* Input:
*   There is no user input in this program.
*
* Output:
*   This program outputs various messages to the screen that notifies the user if various test
*   cases are passed or failed. A test suite, using the CuTest library is provided in this
*	program that runs these tests.
*************************************************************************************************/

#include "hashMap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

int hashFunction1(const char* key)
{
    int i;
    int r = 0;
    for (i = 0; key[i] != '\0'; i++)
    {
        r += key[i];
    }
    return r;
}

int hashFunction2(const char* key)
{
    int i;
    int r = 0;
    for (i = 0; key[i] != '\0'; i++)
    {
        r += (i + 1) * key[i];
    }
    return r;
}

/**
 * Creates a new hash table link with a copy of the key string.
 * @param key Key string to copy in the link.
 * @param value Value to set in the link.
 * @param next Pointer to set as the link's next.
 * @return Hash table link allocated on the heap.
 */
HashLink* hashLinkNew(const char* key, int value, HashLink* next)
{
    HashLink* link = malloc(sizeof(HashLink));
    link->key = malloc(sizeof(char) * (strlen(key) + 1));
    strcpy(link->key, key);
    link->value = value;
    link->next = next;
    return link;
}

/**
 * Free the allocated memory for a hash table link created with hashLinkNew.
 * @param link
 */
static void hashLinkDelete(HashLink* link)
{
    free(link->key);
    free(link);
}

/**
 * Initializes a hash table map, allocating memory for a link pointer table with
 * the given number of buckets.
 * @param map
 * @param capacity The number of table buckets.
 */
void hashMapInit(HashMap* map, int capacity)
{
    int i;
    map->capacity = capacity;
    map->size = 0;
    map->table = malloc(sizeof(HashLink*) * capacity);
    for (i = 0; i < capacity; i++)
    {
        map->table[i] = NULL;
    }
}

/**
 * Removes all links in the map and frees all allocated memory. You can use
 * hashLinkDelete to free the links.
 * @param map
 */
void hashMapCleanUp(HashMap* map)
{
    // FIXME: implement

    HashLink *cur;
    HashLink *temp;
    int i;

    // iterate through the table
    for(i = 0; i < map->capacity; i++){
        cur = map->table[i];
        // iterate though the links in linked list bucket
        while(cur != NULL){
            temp = cur;
            cur = temp->next;
            //hashLinkDelete(cur);
            free(cur);
        }
        map->table[i] = NULL;
    }
    //hashLinkDelete(cur);
    free(cur);
    // free the table
    free(map->table);
    // defensive programming
    map->table = NULL;
}

/**
 * Creates a hash table map, allocating memory for a link pointer table with
 * the given number of buckets.
 * @param capacity The number of buckets.
 * @return The allocated map.
 */
HashMap* hashMapNew(int capacity)
{
    HashMap* map = malloc(sizeof(HashMap));
    hashMapInit(map, capacity);
    return map;
}

/**
 * Removes all links in the map and frees all allocated memory, including the
 * map itself.
 * @param map
 */
void hashMapDelete(HashMap* map)
{
    hashMapCleanUp(map);
    free(map);
}

/**
 * Returns a pointer to the value of the link with the given key. Returns NULL
 * if no link with that key is in the table.
 *
 * Use HASH_FUNCTION(key) and the map's capacity to find the index of the
 * correct linked list bucket. Also make sure to search the entire list.
 *
 * @param map
 * @param key
 * @return Link value or NULL if no matching link.
 */
int* hashMapGet(HashMap* map, const char* key)
{
    // FIXME: implement

    int idx;
    // find the index of the correct linked list bucket
    idx = HASH_FUNCTION(key) % map->capacity;

    struct HashLink* cur = map->table[idx];

    // iterate though the linked list
    while(cur != NULL){
        // if keys are equal then return pointer to the value of the link
        if(strcmp(cur->key, key) == 0){
            return &(cur->value);
        }
        // if keys not equal, move on to next link
        else {
            cur = cur->next;
        }
    }
    // if no link is found with that key then return NULL
    return NULL;
}

/**
 * Resizes the hash table to have a number of buckets equal to the given
 * capacity. After allocating the new table, all of the links need to be
 * rehashed into it because the capacity has changed.
 *
 * Remember to free the old table and any old links if you use hashMapPut to
 * rehash them.
 *
 * @param map
 * @param capacity The new number of buckets.
 */
void resizeTable(HashMap* map, int capacity)
{
    // FIXME: implement

    // allocate a new table
    HashLink** newTable = malloc(sizeof(HashLink*) * capacity);

    HashLink* cur;
    HashLink* temp;
    int idx;
    int i;

    // initialize each of the buckets in the new table to NULL
    for(i = 0; i < capacity; i++){
        newTable[i] = NULL;
    }

    // rehash links from old table into new table
    for(i = 0; i < map->capacity; i++){
        cur = map->table[i];
        while(cur != NULL){
            idx = HASH_FUNCTION(cur->key) % capacity;
            temp = cur;
            cur = cur->next;
            temp->next = newTable[idx];
            newTable[idx] = temp;
        }
    }

    // free old table and reassign new table
    free(map->table);
    map->table = newTable;
    map->capacity = capacity;
}

/**
 * Updates the given key-value pair in the hash table. If a link with the given
 * key already exists, this will just update the value. Otherwise, it will
 * create a new link with the given key and value and add it to the table
 * bucket's linked list. You can use hashLinkNew to create the link.
 *
 * Use HASH_FUNCTION(key) and the map's capacity to find the index of the
 * correct linked list bucket. Also make sure to search the entire list.
 *
 * @param map
 * @param key
 * @param value
 */
void hashMapPut(HashMap* map, const char* key, int value)
{
    // FIXME: implement

    // find the index
    int idx = HASH_FUNCTION(key) % map->capacity;
    struct HashLink *cur = map->table[idx];
    struct HashLink *prev = map->table[idx];

    // if a link with this key does not exist then create a new link with the given key
    if(cur == NULL){
        map->table[idx] = hashLinkNew(key, value, NULL);
        map->size++;
    }
    // otherwise update the value of the link with the given key
    else {
        while(cur != NULL){
            if(strcmp(cur->key, key) != 0){
                prev = cur;
                cur = cur->next;
            }
            else {
                cur->value = value;
                return;
            }
        }
        cur = hashLinkNew(key, value, NULL);
        prev->next = cur;
        map->size++;
    }

    if (hashMapTableLoad(map) >= MAX_TABLE_LOAD){
        resizeTable(map, map->capacity * 2);
    }
}

/**
 * Removes and frees the link with the given key from the table. If no such link
 * exists, this does nothing. Remember to search the entire linked list at the
 * bucket. You can use hashLinkDelete to free the link.
 * @param map
 * @param key
 */
void hashMapRemove(HashMap* map, const char* key)
{
    // FIXME: implement

    int idx;
    idx = HASH_FUNCTION(key) % map->capacity;
    struct HashLink *cur = map->table[idx];
    struct HashLink *prev = NULL;

    while(cur != NULL){
        if(strcmp(cur->key, key) == 0){
            if(prev == NULL){
                struct HashLink *temp = cur;
                map->table[idx] = temp->next;
                map->size--;
                hashLinkDelete(temp);
                return;
            }
            else {
                prev->next = cur->next;
                map->size--;
                return;
            }
        }

        prev = cur;
        cur = cur->next;
    }
    hashLinkDelete(cur);
    hashLinkDelete(prev);
}

/**
 * Returns 1 if a link with the given key is in the table and 0 otherwise.
 *
 * Use HASH_FUNCTION(key) and the map's capacity to find the index of the
 * correct linked list bucket. Also make sure to search the entire list.
 *
 * @param map
 * @param key
 * @return 1 if the key is found, 0 otherwise.
 */
int hashMapContainsKey(HashMap* map, const char* key)
{
    // FIXME: implement

    int idx;
    idx = HASH_FUNCTION(key) % map->capacity;
    HashLink* cur = map->table[idx];

    while(cur != NULL){
        if(strcmp(cur->key, key) == 0){
            return 1;
        }
        cur = cur->next;
    }
    return 0;
}

/**
 * Returns the number of links in the table.
 * @param map
 * @return Number of links in the table.
 */
int hashMapSize(HashMap* map)
{
    // FIXME: implement

    return map->size;
}

/**
 * Returns the number of buckets in the table.
 * @param map
 * @return Number of buckets in the table.
 */
int hashMapCapacity(HashMap* map)
{
    // FIXME: implement

    return map->capacity;
}

/**
 * Returns the number of table buckets without any links.
 * @param map
 * @return Number of empty buckets.
 */
int hashMapEmptyBuckets(HashMap* map)
{
    // FIXME: implement

    int i;
    int buckets = 0;

    for(i = 0; i < map->capacity; i++){
        HashLink *cur = map->table[i];
        if(cur == NULL){
            buckets++;
        }
    }
    return buckets;
}

/**
 * Returns the ratio of (number of links) / (number of buckets) in the table.
 * Remember that the buckets are linked lists, so this ratio tells you nothing
 * about the number of empty buckets. Remember also that the load is a floating
 * point number, so don't do integer division.
 * @param map
 * @return Table load.
 */
float hashMapTableLoad(HashMap* map)
{
    // FIXME: implement

    return (float)hashMapSize(map) / (float)hashMapCapacity(map);
}

/**
 * Prints all the links in each of the buckets in the table.
 * @param map
 */
void hashMapPrint(HashMap* map)
{
    int i;
    for (i = 0; i < map->capacity; i++)
    {
        HashLink* link = map->table[i];
        if (link != NULL)
        {
            printf("\nBucket %i ->", i);
            while (link != NULL)
            {
                printf(" (%s, %d) ->", link->key, link->value);
                link = link->next;
            }
        }
    }
    printf("\n");
}


