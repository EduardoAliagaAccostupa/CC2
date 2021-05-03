#include <iostream>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

ZZ suma1(int a[], long int tam){
    ZZ suma; suma=0;
    for (long int i=0; i<tam; i++){
        suma=suma+a[i];
    }
    return suma;
}

ZZ suma2(int a[], long int tam){
    if ((tam-1)<=0){
        ZZ suma; suma=a[tam-1];
        return suma;
    }
    ZZ suma; suma=a[tam-1];
    return suma+suma2(a,tam-1);
}

int main()
{
    long int c=1000000;
    int *arreglo= new int[c];
    for (long int i=0; i<c; i++){
        arreglo[i]=1;
    }
    ZZ s1, s2;
    s1=suma1(arreglo, c); cout << s1 << endl;
    s2=suma2(arreglo, c); cout << s2 << endl;
    delete[] arreglo;
    return 0;
}