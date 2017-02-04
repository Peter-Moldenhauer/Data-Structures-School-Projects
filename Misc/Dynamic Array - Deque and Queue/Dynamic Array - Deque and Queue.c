// DYNAMIC ARRAY DEQUE AND QUEUE 

struct deque{
	TYPE * data;
	int capacity;
	int size;
	int beg;
};


void dequeInit(struct deque *d, int capacity)
{
	d->data = malloc(sizeof(TYPE) * capacity);
	
	d->size = 0;
	
	d->beg = 0; 
	
	d->capacity = capacity;
}


void dequeFree(struct deque *d)
{
	free(d->data)
	
	d->size = 0
	
	d->capacity = 0;
}


int dequeSize(struct deque *d)
{
	return d->size; 
}


void _dequeSetCapacity(struct deque *d, int newCap)
{
	TYPE *newData = malloc(sizeof(TYPE) * newCap);
	
	int i;
	int j = d->beg; 
	for (i = 0, i < d->size, i++)
	{
		newData[i] = d->data[j];
		j = j + 1; 
		if(j >= d->capacity)
			j = 0; 
	}
	
	free(d->data);
	
	d->data = newData;
	d->capacity = newCap;
	d->beg = 0; 
}


void dequeAddFront(struct deque *d, TYPE val)
{
	if(d->size >= d->capacity)
		_dequeSetCapacity(d, d->capacity * 2);
		
	if(d->beg == 0)
	{
		d->beg = d->capacity - 1;
	}
	else
	{
		d->beg = d->beg - 1;
	}
	
	d->data[d->beg] = val;
	
	d->size++;
}


void dequeAddBack(struct *d, TYPE val)
{
	if(d->size >= d->capacity)
		_dequeSetCapacity(d, d->capacity * 2);
		
	d->data[(d->beg + d->size) % d->capacity] = val;
	
	d->size++;
}


TYPE dequeFront(struct deque *d)
{
	return d->data[d->beg];
}


TYPE dequeBack(struct deque *d)
{
	return d->data[(d->beg + d->size - 1) % d->capacity];
}


void dequeRemoveFront(struct deque *d)
{
	assert(d->size > 0);
	
	d->beg = (d->beg +1) % d->capacity;
	
	d->size--; 
}


void dequeRemoveBack(struct deque *d)
{
	assert(d->size > 0);
	
	d->size--; 
}

