#include "Inventory.h"

// This is all copied from my L6B and modified for what I want it to be



//---------------------------------------------------------




Inventory::Inventory() {
  // set size to zero
    _size=0;
  // set head to be a nullptr
    _pHead = nullptr;
  // set tail to be a nullptr
    _pTail = nullptr;
}

Inventory::~Inventory() {
    // remove each node in the list
        Node* index = _pHead;
        Node* nextNode =  nullptr;
        while (index!=nullptr){
            nextNode = index->pNext;
            delete index;
            index = nextNode;
        }
}




int Inventory::size() const {
    return _size;
}

Item* Inventory::get_item(const int POS) const {
    // if POS is out of range, throw std::out_of_range(); exception
        if(POS<0 || POS>=_size){throw std::out_of_range("POS out of Linked list range");}
    // set current node to head
        Node* index = _pHead;
    // advance current node to POS
        for (int i=0; i<POS; i++){
            index = index->pNext;
        }
    // return value of current node
    return (index->value);
}
int Inventory::get_quantity(const int POS) const {
    // if POS is out of range, throw std::out_of_range(); exception
        if(POS<0 || POS>=_size){throw std::out_of_range("POS out of Linked list range");}
    // set current node to head
        Node* index = _pHead;
    // advance current node to POS
        for (int i=0; i<POS; i++){
            index = index->pNext;
        }
    // return value of current node
    return (index->quantity);
} 

void Inventory::set(const int POS, Item* VALUE, const int Q) {
  // if POS is out of range, throw std::out_of_range(); exception
    if(POS<0||POS>=_size){throw std::out_of_range("POS out of linked list range");}
  // set current node to head
    Node* index = _pHead;
  // advance current node to POS
    for (int i=0; i<POS; i++){
        index = index->pNext;
    }
  // set value of current node   
    index->value = VALUE;
    index->quantity = Q;
}

void Inventory::insert(const int POS, Item* VALUE, const int Q) {
    // if POS is before zero, clamp to zero
    int index = POS;
        if(POS<0){index=0;}
    // if POS is after size, clamp to size
        if(POS>=_size){index=_size;}
    // create pointer to new node
        Node * pNew = new Node;
    // set value to be VALUE
        pNew->value = VALUE;
        pNew->quantity = Q;
    // set previous pointer to nullptr
        pNew->pPrev = nullptr;
    // set next pointer to nullptr
        pNew->pNext = nullptr;
    // if list is currently empty
    if (_size==0){
            // set head and tail to new node
            _pHead = pNew;
            _pTail = pNew;
        }
    
    // otherwise
    else{
        // if position is before head
        if(index==0){
    
            // set new node next to be head
            pNew->pNext=_pHead;
            // set head previous to be new node
            _pHead->pPrev = pNew;
            // set head to be new node
            _pHead = pNew;
        }
        else if(index>=_size){
        // else if position is after tail
            
            // set new node previous to be tail
                pNew->pPrev=_pTail;
            // set tail next to be new node
                _pTail->pNext=pNew;
            // set tail to be new ndoe
                _pTail = pNew;
        }
        // otherwise
        else{
            // set current node to head
                Node* pCurrent = _pHead;
            // advance current node to pos
                for(int i=0; i<index; i++){
                    pCurrent = pCurrent->pNext;
                }
            // link new node into current list
                pNew->pNext = pCurrent;
                pNew->pPrev = pCurrent->pPrev;
                
            // link current list to new node
                pCurrent->pPrev->pNext = pNew;
                pCurrent->pPrev = pNew;
        }
    
    // increment size
    }
_size++;
}

void Inventory::remove(const int POS) {
    Node* pRemove = nullptr;
    // if array is empty, throw std::out_of_range(); exception
        if(_size==0){throw std::out_of_range("Out of Linked List range");}
    // if POS is before zero, clamp to zero
        int index = POS;
        if(POS<0){index=0;}
    // if POS is after size, clamp to size
        if(POS>_size){index=_size;}
    // if list has one element
        if(_size==1){
        // set node to delete to head
            pRemove = _pHead;
        // set head and tail to be nullptr
            _pHead=nullptr;
            _pTail=nullptr;
        }
    // otherwise
        else{
        // if deleting head
            if(index==0){
            // set node to delete to head
                pRemove = _pHead;
            // advance head to next
                 _pHead = pRemove->pNext;
            // set head previous to nullptr
                _pHead->pPrev = nullptr;
            }
        // else if deleting tail
            else if(index>=_size-1){
            // set node to delete to tail
                pRemove = _pTail;
            // step tail to previous
                _pTail = pRemove->pPrev;
            // set tail next to nullptr
                _pTail->pNext=nullptr;
            }
        // otherwise
            else{
            // set current node to head
                Node* pindex = _pHead;
            // advance current node to space before position
                for(int i=0; i<index-1; i++){
                    pindex = pindex->pNext;
                }
            // set node to delete to the current node's next node
                pRemove = pindex->pNext;
            // unlink node to delete
                Node* nextNode = pRemove->pNext;
                Node* priorNode = pRemove->pPrev;
                priorNode->pNext = nextNode;
                nextNode->pPrev = priorNode;
            }
        }
    // delete node
    delete pRemove;

    // decrement size
    _size--;
    
}


int Inventory::find(const Item* VALUE) const {
    // search for first occurrence of VALUE
        Node* pindex = _pHead;
        for (int i = 0; i<_size; i++){
            if(pindex->value==VALUE){return i;}
            pindex = pindex->pNext;
        }
    // return index of first occurrence if found

    // otherwise return -1
    return -1;
}

