// Sorted Dynamic Array - Ordered Bag

// uses functions from dynamic array Bag 


void orderedArrayAdd(struct dynArr *dy, TYPE val){
	int index = _binarySearch(dy->data, dy->size, val);
	
	dynArrAddAt(dy, index, val);
}


int orderedArrayContains(struct dynArr *dy, TYPE val){
	int index = _binarySearch(dy->data, dy->size, val);
	
	if(index < dy->size){
		if(dy->data[index] == val)
			return 1;
	}
	return 0;
}


void orderedArrayRemove(struct dynArr *dy, TYPE val){
	int index = _binarySearch(dy->data, dy->size, val);
	
	if(index < dy->size){
		if(dy->data[index] == val)
			dyArrRemoveAt(dy, index);
	}
}



// Binary Search Algorithm:

int _binarySearch(TYPE *data, int size, TYPE value){
	int low = 0;
	int high = size;
	int med;
	
	while(low < high){
		mid = (low + high) / 2;
		if(data[mid] < value)
			low = mid + 1;
		else
			high = mid;
	}
	return low; 
}