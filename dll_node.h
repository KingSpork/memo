#ifndef DLL_NODE_H
#define DLL_NODE_H
#include <cstddef>
#include "DataType.h"


struct dll_node{
    public:
        dll_node(void* v=NULL, dll_node* p=NULL, dll_node* n=NULL);

        void* getVal();
        dll_node* getNext();
        dll_node* getPrev();
        DataType getDataType();

        void setVal(void* v);
        void setNext(dll_node* n);
        void setPrev(dll_node* p);
        void setDataType(DataType t=NONE);

    private:
        void* val;
        dll_node *next;
        dll_node *prev;
        bool isDataTypeSet = false;
        DataType nodeType = NONE;
};

#endif // DLL_NODE_H
