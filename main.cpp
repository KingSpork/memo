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


for(int i=0; i<mds; i++){
    myData[i] = i + 1;
    cout << "myData[" << i << "] " << myData[i] << endl;
    pointDexter[i] = &myData[i];
    nodes[i].setVal(pointDexter[i]);
}



for(int i=0; i<mds; i++){
    int* rv = static_cast<int*>(pointDexter[i]);
    int real_value = *rv;
    cout << "*pointDexter[" << i << "] " << real_value << endl;
}


dl_list myDll = dl_list(pointDexter[0], pointDexter[1]);
myDll.moveToLast();
testValue(myDll.getCurrentValue());

///**
for(int i=2; i<mds; i++){
    myDll.insertAfter(&nodes[i]);
    cout << "Made it through loop " << i << "...  ";
    myDll.moveForward();
}
//**/

myDll.moveToFirst();


for(int i=0; i<mds; i++){
    testValue(myDll.getCurrentValue());
    myDll.moveForward();
}










//myDll.getCurrentValue();
return 0;
}



