#include <iostream>
#include <string>
#include "dl_list.h"

using namespace std;

int main()
{

int mds = 32;

int myData[mds];

for(int i=0; i<mds; i++){
    myData[i] = i + 1;
}

for(int i=0; i<mds; i++){
    cout << myData[i] << endl;
}

dl_list myDll = dl_list();

void* pointDexter = &myData[4];
//int* pointDexter = &myData[0];

//just to print the value of pointDexter
int* pd = static_cast<int*>(pointDexter);
int valOfPD = *pd;
cout << "*pointDexter is " << valOfPD <<endl;

myDll.setCurrentValue(pointDexter);

void* value = myDll.getCurrentValue();

int* rv = static_cast<int*>(value);

int real_value = *rv;

cout << "The value tested is: " << real_value << endl;



//myDll.getCurrentValue();

return 0;
}
