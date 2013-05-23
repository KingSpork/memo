#ifndef DL_LIST_H
#define DL_LIST_H
#include <cstddef>
#include "dll_node.h"
#include "DataType.h"



struct dl_list
{
    public:
        dl_list(dll_node* f=NULL, dll_node* l=NULL);
        void moveForward(int n);
        void moveBack(int n);
        void moveToFirst();
        void moveToLast();

        dll_node* getCurrent();
        dll_node* getFirst();
        dll_node* getLast();

        void* getCurrentValue();
        void setCurrentValue(void* val);

        void insertAfter(dll_node* i);
        void insertBefore(dll_node* i);
        dll_node popCurrent();

    private:
        dll_node* current;
        dll_node* first;
        dll_node* last;

        DataType listType;

        void createBlankList(dll_node** c, dll_node** f, dll_node** l);
};

#endif // DL_LIST_H
