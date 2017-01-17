#ifndef _DYNARR_H
#define _DYNARR_H

#define TYPE int  // TYPE is an int
#define TYPE_SIZE sizeof(TYPE)

// The underlying struct for the data structure
struct DynArr {
    TYPE *data; // Pointer to data array, this is an array of type TYPE
    int size;   // Number of elements in collection, when size equals capacity you need to resize the array
    int cap;    // Capacity of array, total number that can be stored in the array
};

//Dynamic Array Functions - in all of these cases you have to pass the dynamic array in, gets passed as a pointer because we want to modify the array
void initDynArr(struct DynArr *v, int cap);  // initialize array
void freeDynArr(struct DynArr *v);           // free, or deallocate memory
int sizeDynArr(struct DynArr *v);            // return the size of the dynamic array
void addDynArr(struct DynArr *v, TYPE e);    // add, pass in the element that you want to add
TYPE getDynArr(struct DynArr *v, int pos);    // get, pass in the index that you want to get the value at
void putDynArr(struct DynArr *v, int pos, TYPE val); // put

#endif // _DYNARR_H
