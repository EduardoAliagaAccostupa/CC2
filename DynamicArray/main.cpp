#include <iostream>
#include "DynamicArray.h"

using namespace std;

int main()
{
    DynamicArray a;
    cout << a.getSize() << endl;

    int arreglo[]={1,2,3,6,5,4,8,9};
    int tam=sizeof(arreglo)/sizeof(arreglo[0]);
    DynamicArray b(arreglo, tam);
    cout << b.getSize() << endl;

    DynamicArray c=b;
    cout << c.getSize() << endl;
    c.print();

    b.push_back(15);            //
    b.print();                  //
    b.insert(7, 3);             //  FUNCIONES PUSH_BACK,
    b.print();                  //  INSERT Y REMOVE
    b.remove(5);                //
    b.print();                  //
    return 0;
}
