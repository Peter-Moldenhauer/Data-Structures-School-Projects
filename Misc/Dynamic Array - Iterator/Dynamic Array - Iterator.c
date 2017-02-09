// Dynamic Array - Iterator

void initDynArrIter(dyn, itr){
	itr->dyn = dyn;
	itr->curIndex = 0;
}


int hasNextDynArrIter(itr){
	if(itr->curIndex < itr->dyn->size){
		itr->curIndex = itr->curIndex++;
		return 1;
	}
	else
		return 0;
}


TYPE nextDynArrIter(itr){
	return itr->dyn->data[itr->curIndex - 1];
}


void removeDynArrIter(itr){
	_dynArrRemoveAt(itr->dyn, itr->curIndex);
	itr->curIndex = itr->curIndex - 1; 
}
