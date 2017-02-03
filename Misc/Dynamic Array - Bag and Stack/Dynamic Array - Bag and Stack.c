// Dynamic Array - Stack and Bag


// ***** DYNAMIC ARRAY FUNCTIONS ***** 

struct DynArr
{
	TYPE * data;
	int size;
	int capacity;
};


struct DynArr * createDynArr()
{
	struct DynArr * v = malloc(sizeof(struct DynArr));
	
	return v; 
}


void initDynArr(struct DynArr *v, int capacity)
{
	v->data = malloc(sizeof(TYPE) * capacity);
	
	v->size = 0;
	v->capacity = capacity;
}


void freeDynArr(struct DynArr *v)
{
	if (v->data != 0)
	{
		free(v->data);
		v->data = 0;
	}
	v->size = 0;
	v->capacity = 0;
}


int sizeDynArr(struct DynArr *v)
{
	return v->size; 
}


void _setCapacityDynArr(struct DynArr *v, int newCap)
{
	int i;
	
	TYPE *newData = malloc(sizeof(TYPE) * newCap);
	
	for (i = 0; i < v->capacity; i++)
	{
		newData[i] = v->data[i]; 
	}
	
	free(v->data);
	
	v->data = newData;
	v->capacity = newCap; 
}


void addDynArr(struct DynArr *v, TYPE val)
{
	if (v->size >= v->capacity)
		_setCapacityDynArr(v, v->capacity * 2);
		
	v->data[v->size] = val;
	
	v->size++; 
}


TYPE getDynArr(struct DynArr *v, int position)
{
	assert((position >= 0) && (position < v->size));
	
	return v->data[position]; 
}


void putDynArr(struct DynArr *v, int position, TYPE value)
{
	assert((position >= 0) && (position < v->size));
	
	v->data[position] = value;
}


void removeAtDynArr(struct DynArr *v, int position)
{
	assert((position >= 0) && (position < v->size));
	
	while (position < v->size - 1)
	{
		v->data[position] = v->data[position + 1];
		position++;
	}
	
	v->size--;
}


void swapDynArr(struct DynArr *v, int i, int j)
{
	assert((i >= 0) && (i < v->size));
	assert((j >= 0) && (j < v->size)); 
	
	TYPE temp;
	
	temp = v->data[i];
	v->data[i] = v->data[j];
	v->data[j] = temp;
}


// ***** STACK FUNCTIONS *****

void pushDynArr(struct DynArr *v, TYPE value)
{
	
	addDynArr(v, value);
}


TYPE topDynArr(struct DynArr *v)
{
	assert(isEmptyDynArr(v) != 1);
	
	return v->data[v-size - 1];
}


void popDynArr(struct dynArr *v)
{
	assert(isEmptyDynArr(v) != 1);
	
	v->size--;
}


int isEmptyDynArr(struct DynArr *v)
{
	if (v->size == 0)
		return 1;
	else
		return 0;
}


// ***** BAG FUNCTIONS *****

void removeDynArr(struct DynArr *v, TYPE value)
{
	int i;
	
	for (i = 0; i < v->size; i++)
	{
		if (v->data[i] == value)
		{
			removeAtDynArr(v, value);
			return; 
		}	
	}
}


int containsDynArr(struct DynArr *v, TYPE value)
{
	int i;
	
	for (i = 0; i < v->size; i++)
	{
		if (v->data[i] == value)
			return 1;
	}
	return 0; 
}




















