// Double Linked List - DEQUE

struct dlink {
	TYPE value;
	struct dlink *next;
	struct dlink *prev;
}

struct linkedList (
	int size;
	struct dlink *frontSentinel;
	struct dlink *backSentinel;
)


void linkedListInit(struct linkedList *q){
	q->frontSentinel = malloc(sizeof(struct dlink));
	q->backSentinel = malloc(sizeof(struct dlink));
	
	q->frontSentinel->next = q->backSentinel;
	q->backSentinel->prev = q->frontSentinel;
	
	q->size = 0; 
}


void linkedListFree(struct linkedList *q){
	while(q->size > 0){
		linkedListRemoveFront(q);
	}
	free(q->frontSentinel);
	free(q->backSentinel);
	q->frontSentinel = q->backSentinel = 0; 
}

void linkedListAddFront(struct linkedList *q, TYPE val){
	_addBefore(q, q->frontSentinel->next), val);
}

void linkedListAddBack(struct linkedLIst *q, TYPE val){
	_addBefore(q, q->backSentinel, val);
}

void linkedListRemoveFront(struct linkedLIst *q){
	assert(linkedListIsEmpty(q) != 1);
	_removeLink(q, q->frontSentinel->next);
}

void linkedLIstRemoveBack(struct linkedList *q){
	assert(linkedListIsEmpty(q) != 1);
	_removeLink(q, q->backSentinel->prev); 
}

int linkedListIsEmpty(struct linkedLIst *q){
	if(q->size == 0)
		return 1;
	else
		return 0; 
}


void _addBefore(struct linkedLIst *q, struct dlink *lnk, TYPE val){
	struct dlink *newLink = malloc(sizeof(struct dlink));
	
	newLink->next = lnk;
	newLink->value = val;
	newLink->prev = lnk->prev;
	
	lnk->prev->next = newLink;
	lnk->prev = newLink;
	
	q->size++; 
}

void _removeLink(struct linkedLIst *q, struct dlink *lnk){
	lnk->prev->next = lnk->next; 
	lnk->next->prev = lnk->prev;
	
	free(lnk);
	q->size--; 
}


TYPE linkedListFront(struct linkedLIst *q){
	assert(linkedListIsEmpty(q) != 1);
	return q->frontSentinel->next->value; 
}


TYPE linkedListBack(struct linkedLIst *q){
	assert(linkedListIsEmpty(q) != 1);
	return q->backSentinel->prev->val; 
}







