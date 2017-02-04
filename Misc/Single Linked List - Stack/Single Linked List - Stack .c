// LINKED LIST STACK
 
 
struct Link{
	TYPE val;
	struct Link *next;
};
 
 
struct LinkedList{
	struct Link *firstLink;
};


struct LinkedList * createLinkedList()
{
	struct LinkedList * newList = malloc(sizeof(struct LinkedList));
	
	initLinkedList(newList);
	
	return newList;
}


void initLinkedList(struct LinkedList *l)
{
	l->firstLink = NULL;
}


void _freeLinkedList(struct LinkedList *l)
{
	while(isEmptyLinkedList(l) != 1)
	{
		popLinkedList(l);
	}
}


void deleteLinkedList(struct LinkedList *l)
{
	_freeLinkedList(l);
	
	free(l);
}


void pushLinkedList(struct LinkedList *l, TYPE val)
{
	struct Link *link = malloc(sizeof(struct Link));
	
	link->next = l->firstLink;
	
	link->val = val; 
	
	l->firstLink = link; 
}


TYPE topLinkedList(struct LinkedList *l)
{
	assert(isEmptyLinkedList(l) != 1);
	
	return l->firstLink->val;
}


void popLinkedList(struct LinkedList *l)
{
	assert(isEmptyLinkedList(l) != 1);
	
	struct Link *temp = l->firstLink;
	
	l->firstLink = l->firstLink->next;
	
	free(temp);
}


int isEmptyLinkedList(struct LinkedList *l)
{
	if(l->firstLink == 0)
		return 1;
	else
		return 0; 
}