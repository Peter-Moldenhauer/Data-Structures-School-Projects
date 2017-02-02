// ARRAY ABSTRACT DATA TYPE (ADT) 


struct arrayBagStack {
	TYPE data [100];
	int count;
};


struct arrayBagStack * createArray()
{
	struct arrayBagStack * b = malloc(sizeof(stuct arrayBagStack));
	
	return b;
}


void initArray(struct arrayBagStack * b)
{
	b->count = 0; 
}


// ***** BAG FUNCTIONS *****

void addArray(struct arrayBagStack *b, TYPE v)
{
	b->data[b->count] = v;
	b->count++; 
}


int containsArray(struct arrayBagStack * b, TYPE v)
{
	int i;
	for (i = 0; i < b->count; i++)
	{
		if (b->data[i] == v)
			return 1;
	}
	return 0; 
}


void removeArray(struct arrayBagStack * b, TYPE v)                              // 1) assert contains function with v 2) find the index of v 3) shift all elements after v up 4) update count 
{
	assert(containsArray(b, v));
	
	int i = 0;
	int j; 
	
	while (b->data[i] != v)
	{
		i = i + 1;
	}
	
	for (j = i; j < b->count - 1; j++)
	{
		b->data[j] = b->data[j+1];
	}
	
	b->count = b->count - 1; 
}


int sizeArray(struct arrayBagStack * b)
{
	return b->count; 
}


// ***** STACK FUNCTIONS ***** 

void pushArray(struct arrayBagStack * b, TYPE v)
{
	addArray(b, v);
}


TYPE topArray(struct arrayBagStack * b)
{
	assert(isEmptyArray(b) != 1);
	
	return b->data[b->count - 1]; 
}


void popArray(struct arrayBagStack * b)
{
	assert(isEmptyArray(b) != 1);
	
	b->count--;
}


int isEmptyArray(struct arrayBagStack * b)
{
	if (b->count == 0)
		return 1;
	else 
		return 0;
}


void printArray(struct arrayBagStack * b)
{
	int i;
	for (i = 0; i < b->count; i++)
		printf("Array [i] = %d\n", b->data[i]);
}





