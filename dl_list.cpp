#include "dl_list.h"
#include "DataType.h"

dl_list::dl_list(dll_node* f, dll_node* l){
    if(f==NULL || l==NULL){
        createBlankList(&current, &first, &last);
    }
    else{
        current = f;
        first = f;
        last = l;
    }
}

dl_list::dl_list(void* val1, void* val2){
    createBlankList(&current, &first, &last);
    first->setVal(val1);
    last->setVal(val2);
}


void dl_list::moveForward(int n){
    for(int i=0; i < n; i++){
        current = current->getNext();
    }
}


void dl_list::moveBack(int n){
    for(int i=0; i < n; i++){
        current = current->getPrev();
    }
}

void dl_list::moveToFirst(){
    current = first;
}

void dl_list::moveToLast(){
    current = last;
}

dll_node* dl_list::getCurrent(){
    return current;
}

dll_node* dl_list::getFirst(){
    return first;
}

dll_node* dl_list::getLast(){
    return last;
}

void* dl_list::getCurrentValue(){
    void* val = current->getVal();
    return val;
}

void dl_list::insertAfter(dll_node* i){
    dll_node* temp = current->getNext();
    if(temp == first){
        last = i;
    }
    //establish link between next and i
    temp->setPrev(i);
    i->setNext(temp);

    //establish link between current and i
    current->setNext(i);
    i->setPrev(current);

}

void dl_list::setCurrentValue(void* val){
    current->setVal(val);
}

void dl_list::insertBefore(dll_node* i){
    dll_node* temp = current->getPrev();
    if(temp == last){
        first = i;
    }
    //establish link between prev and i
    temp->setNext(i);
    i->setPrev(temp);

    //establish link between current and i
    current->setPrev(i);
    i->setNext(current);
}

dll_node dl_list::popCurrent(){
    dll_node* temp1 = current->getPrev();
    dll_node* temp2 = current->getNext();
    temp1->setNext(temp2);
    temp2->setPrev(temp1);
    current->setNext(NULL);
    current->setPrev(NULL);
    return *current;
}

void dl_list::createBlankList(dll_node** c, dll_node** f, dll_node** l){
    dll_node* nodeFirst = new dll_node(NULL, NULL, NULL);
    dll_node* nodeLast = new dll_node(NULL, nodeFirst, nodeFirst);

    nodeFirst->setNext(nodeLast);
    nodeFirst->setPrev(nodeLast);

    *c = nodeFirst;
    *f = nodeFirst;
    *l = nodeLast;
}
