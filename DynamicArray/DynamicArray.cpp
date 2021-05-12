#include "DynamicArray.h"
#include <iostream>

using namespace std;

DynamicArray::DynamicArray()
{
    size=0;
    arr=new int[0];
}

DynamicArray::DynamicArray(const DynamicArray &o){
    this->size=o.size;
    this->arr=new int[o.size];

    for(int i=0; i<size; i++) { arr[i]=o.arr[i];}
}

DynamicArray::DynamicArray(const int *ptr, int size){
    this->size=size;
    this->arr=new int[size];

    for(int i=0; i<size; i++) { arr[i]=ptr[i];}
}

void DynamicArray::print() const{
    for(int i=0; i<size; i++) { std::cout << arr[i] << " ";}
    std::cout << std::endl;
}

void DynamicArray::push_back(int elem){
    int *tmp=new int [size+1];
    for(int i=0; i<size; i++) { tmp[i]=arr[i];}
    tmp[size]=elem;
    size+=1;
    delete []arr;
    arr=tmp;
}

void DynamicArray::insert(int elem, int pos){
    int *tmp=new int [size+1];
    for(int i=0; i<pos-1; i++) { tmp[i]=arr[i];}
    tmp[pos-1]=elem;
    for(int i=pos-1; i<size; i++) { tmp[i+1]=arr[i];}
    size+=1;
    delete []arr;
    arr=tmp;
}

void DynamicArray::remove(int pos){
    int *tmp=new int [size+1];
    for(int i=0; i<pos-1; i++) { tmp[i]=arr[i];}
    for(int i=pos; i<size; i++) { tmp[i-1]=arr[i];}
    size-=1;
    delete []arr;
    arr=tmp;
}

DynamicArray::~DynamicArray()
{
    delete []arr;
}