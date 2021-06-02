#ifndef __DYNAMICARRAY_H__
#define __DYNAMICARRAY_H__

#include <string>
#include <iostream>
#include "Estudiante.h"

using namespace std;

template <typename T>
class DynamicArray {
        int size;
        T *arr;
        void resize(int newSize);
    public:
        DynamicArray();
        DynamicArray(const T* ptr, int size);
        DynamicArray(const DynamicArray &o);

        void push_back(T elem);

        void insert(T elem, int pos);
        void remove(int pos);

        void clear();

        int getSize() const {
            return size;
        }
        void print() const;

        /*template <typename U>*/
        friend ostream& operator << (ostream &o, const DynamicArray/*<U>*/ &p){
            for(int i=0; i < p.size; i++)
                o << p.arr[i] << '\n';
            o << endl;
            return o;
        }

        ~DynamicArray();
};

template <typename T>
DynamicArray<T>::DynamicArray() {
    size = 0;
    arr = new T[0];
}

template <typename T>
DynamicArray<T>::DynamicArray(const T* ptr, int size) {
    this->size = size;
    this->arr = new T[size];

    for(int i = 0; i < size; i++)
        arr[i] = ptr[i];
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T> &o) {
    this->size = o.size;
    this->arr = new T[o.size];

    for(int i = 0; i < size; i++)
        arr[i] = o.arr[i];
}

template <typename T>
void DynamicArray<T>::resize(int newSize) {
    int *tmp = new T[newSize];
    int minSize = (newSize > size) ? size : newSize;
    for(int i = 0; i < minSize; i++)
        tmp[i] = arr[i];
    delete[] arr;
    size = newSize;
    arr = tmp;
}

template <typename T>
void DynamicArray<T>::push_back(T elem) {
    resize(size+1);
    arr[size-1] = elem;
}

// Cesar Carpio && Jesus Vilca
template <typename T>
void DynamicArray<T>::remove(int pos){
    if(pos < 0 || pos > size)
        return;
    for(int i = pos; i < size; i++)
        arr[i] = arr[i +1];
    resize(size-1);
}

    // Eduardo Aliaga
// pos representa el indice del arreglo
template <typename T>
void DynamicArray<T>::insert(T elem, int pos){
    if(pos < 0 || pos > size)
        return;
    resize(size+1);
    for (int i = size-1; i > pos; i--){
        arr[i]=arr[i-1];
    }
    arr[pos]=elem;
}

template <typename T>
void DynamicArray<T>::clear() {
    resize(0);
}

template <typename T>
void DynamicArray<T>::print() const {
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

/*template <typename T>
ostream& operator << (ostream &o, const DynamicArray<T> &p){
    for(int i=0; i < p.size; i++)
        o << p.arr[i] << '\n';
    o << endl;
    return o;
}*/

template <typename T>
DynamicArray<T>::~DynamicArray() {
    delete []arr;
}

#endif
