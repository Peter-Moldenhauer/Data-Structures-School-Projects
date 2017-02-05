// SINGLE LINKED LIST QUEUE

struct link {
	TYPE value;
	struct link *next;
};


struct listQueue {
	struct link *firstLink;
	struct link *lastLink;
};


void listQueueInit(struct listQueue *q)
{
	struct link *lnk = malloc(sizeof(struct link));
	assert(lnk != 0);
	
	link->next = 0;
	
	q->firstlink = q->lastLink = link;
}


void listQueueAddBack(struct listQueue *q, TYPE e)
{
	struct link *lnk = malloc(sizeof(struct link));
	
	lnk->next = 0;
	lnk->value = e;
	
	q->lastLink->next = lnk;
	q->lastLink = lnk;
}


TYPE listQueueFront(struct listQueue *q)
{
	assert(listQueueIsEmpty(q) != 1);
	
	return q->firstlink->next->value;
}


void listQueueRemoveFront(struct listQueue *q)
{
	assert(listQueueIsEmpty(q) != 1);
	
	struct link *temp = q->firstLink->next;
	
	q->firstLink->next = temp->next;
	
	if(q->firstLink->next == 0)
		q->lastLink = q->firstLink;
	
	free(temp); 
}


int listQueueIsEmpty(struct listQueue *q)
{
	return q->firstLink == q->lastLink; 
}