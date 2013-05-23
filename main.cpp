#include <iostream>
#include <string>
#include "dl_list.h"

using namespace std;

/**
void* pointDexter = &myData[4];
int* pointDexter = &myData[0];

just to print the value of pointDexter
int* pd = static_cast<int*>(pointDexter);
int valOfPD = *pd;
cout << "*pointDexter is " << valOfPD <<endl;
*/


void testValue(void* val){
    int* rv = static_cast<int*>(val);
    int real_value = *rv;
    cout << "The value tested is: " << real_value << endl;
}


int main(){

int mds = 32;
int myData[mds];
void* pointDexter[mds];
dll_node nodes[mds];

//Initialize everything including the nodes
for(int i=0; i<mds; i++){
    myData[i] = i + 1;
    //cout << "myData[" << i << "] " << myData[i] << endl;
    pointDexter[i] = &myData[i];
    nodes[i].setDataType(INT); //The Nodes will be of Type INT.
    nodes[i].setVal(pointDexter[i]);
}


//This just prints out the values to make sure pointDexter copied correctly.
/**
for(int i=0; i<mds; i++){
    int* rv = static_cast<int*>(pointDexter[i]);
    int real_value = *rv;
    cout << "*pointDexter[" << i << "] " << real_value << endl;
}
**/

dl_list myDll = dl_list(pointDexter[0], pointDexter[1], INT); //Type INT same as Nodes
myDll.moveToLast();
//testValue(myDll.getCurrentValue());


for(int i=2; i<mds; i++){
    myDll.insertAfter(&nodes[i]);
    //cout << "Made it through loop " << i << "...  ";
    myDll.moveForward();
}


//Test the values to make sure it all worked...
myDll.moveToFirst();
for(int i=0; i<100; i++){
    testValue(myDll.getCurrentValue());
    myDll.moveForward();
}



//myDll.getCurrentValue();
return 0;
}
