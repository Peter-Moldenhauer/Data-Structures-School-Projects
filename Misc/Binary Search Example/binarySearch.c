// This demonstrates a Binary Search algorithm using an array as the container

// Binary search requires that the container 1) have random access so that the search can look
// at any particular value in the collection in constant time and 2) have the elements in the 
// container already be in sorted order. For these reasons, we use an array because binary search 
// can run on an array. 

// Binary search return value:
// If the value is found, the index of the value in the array is returned 
// If not found, the index of array where the value COULD be inserted without violating ordering
// is returned - Note: this returned index can be larger than a leagal index 

// Binary search arguments:
// 1) Takes the array of values (of TYPE)
// 2) Takes the size of that array
// 3) Takes the value that we are looking for (value of TYPE) 
	
int _binarySearch(TYPE * data, int size, TYPE val)
{
	int low = 0;        // initialize low to index[0]
	int high = size;    // initialize high to index[size] Note: this is one after the last element in the array 
	int mid; 
	
	while (low < high)
	{
		mid = (low + high) / 2;   // initialize mid to the middle of the array 
		if (data[mid] < val)
			low = mid + 1;
		else 
			high = mid;
	}
	return low; 
}