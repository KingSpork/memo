#include <cstddef>
#include "dll_node.h"
#include "DataType.h"

dll_node::dll_node(void* v, dll_node* p, dll_node* n){
    val = v;
    prev = p;
    next = n;
}

//Get functions
void* dll_node::getVal(){
    return val;
}

dll_node* dll_node::getPrev(){
    return prev;
}

dll_node* dll_node::getNext(){
    return next;
}

DataType dll_node::getDataType(){
    return nodeType;
}

//Set functions
void dll_node::setVal(void* v){
    val = v;
}

void dll_node::setNext(dll_node* n){
    next = n;
}

void dll_node::setPrev(dll_node* p){
    prev = p;
}

void dll_node::setDataType(DataType t){
    if(isDataTypeSet == false){
        nodeType = t;
        isDataTypeSet = true;
    }
}
