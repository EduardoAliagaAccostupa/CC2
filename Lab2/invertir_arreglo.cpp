#include <iostream>

using namespace std;

void inv1(int a[], long int tam){
    for (long int i=0; i<tam/2; i++){
        a[i]=a[i]+a[tam-1-i];
        a[tam-1-i]=a[i]-a[tam-1-i];
        a[i]=a[i]-a[tam-1-i];
    }
}

void inv2(int a[]; long int tam){
    
}

int main()
{
    long int c=1000000;
    int *arreglo= new int[c];
    for (long int i=0; i<c; i++){
        arreglo[i]=i;
    }
    inv1(arreglo, c);
    for (long int i=0; i<c; i++){
        cout << arreglo[i] << endl;
    }
    delete[] arreglo;
    return 0;
}