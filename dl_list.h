#ifndef DL_LIST_H
#define DL_LIST_H
#include <cstddef>
#include "dll_node.h"
#include "DataType.h"



struct dl_list
{
    public:
        dl_list(dll_node* f=NULL, dll_node* l=NULL);
        dl_list(void* val1, void* val2, DataType t=NONE);
        void moveForward(int n=1);
        void moveBack(int n=1);
        void moveToFirst();
        void moveToLast();

        dll_node* getCurrent();
        dll_node* getFirst();
        dll_node* getLast();
        DataType getDataType();

        void* getCurrentValue();
        void setCurrentValue(void* val);
        void setDataType(DataType t);

        void insertAfter(dll_node* i);
        void insertBefore(dll_node* i);
        dll_node popCurrent();

    private:
        dll_node* current;
        dll_node* first;
        dll_node* last;
        bool isDataTypeSet = false;
        DataType listType = NONE;

        void createBlankList(dll_node** c, dll_node** f, dll_node** l);
};

#endif // DL_LIST_H
