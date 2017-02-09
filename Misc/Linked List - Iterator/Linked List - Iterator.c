// Linked List - Iterator


struct linkedListIter {
	struct dLink *cur;
	struct linkedList *lst;
};


void initLinkedListIter( struct linkedList *lst, struct linkedListIter *itr){
	itr->lst = lst;
	itr->cur = lst->frontSentinel->next;
}


struct linkedListIter *createLinkedListIter(struct linkedList *lst){
	struct linkedListIter *newItr *newItr = malloc(sizeof(struct linkedListIter));
	
	initLinkedListIter(lst, newItr);
	
	return newItr;
}


int hasNextLinkedListIter (struct linkedListIter *itr){
	if(itr->cur != itr->lst->backSentinel){
		itr->cur = itr->cur->next;
		return 1;
	}
	else
		return 0; 
}


TYPE nextlinkedListIter (struct linkedListIter *itr){
	return itr->cur->prev->value;
}


void removeLinkedListIter(struct linkedListIter *itr){
	struct dLink *temp = itr->cur;
	itr->cur = itr->cur->prev;
	_removeLink(itr->lst, temp);
}












