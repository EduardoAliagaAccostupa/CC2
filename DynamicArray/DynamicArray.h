#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H


class DynamicArray
{
    public:
        DynamicArray();
        DynamicArray(const int *ptr, int size);
        DynamicArray(const DynamicArray &o);
        ~DynamicArray();
        int getSize() const{ return size;}
        void print() const;
        void push_back(int elem);
        void insert(int elem, int pos);
        void remove(int pos);

    protected:

    private:
        int size;
        int *arr;
};

#endif // DYNAMICARRAY_H