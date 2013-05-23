#ifndef DLL_NODE_H
#define DLL_NODE_H
#include "DataType.h"


struct dll_node{
    public:
        dll_node(void* v, dll_node* p, dll_node* n);

        void* getVal();
        dll_node* getNext();
        dll_node* getPrev();

        void setVal(void* v);
        void setNext(dll_node* n);
        void setPrev(dll_node* p);

    private:
        void* val;
        dll_node *next;
        dll_node *prev;
        DataType nodeType;
};

#endif // DLL_NODE_H
