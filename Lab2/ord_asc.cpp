#include <iostream>

using namespace std;

void ord_asc(int a[], long int tam){
    int aux;
    for(long int i = 0; i < tam-1; i++){
        for(long int x = i+1; x < tam; x++){
            if(a[i] > a[x]){
                aux = a[x];
                a[x] = a[i];
                a[i] = aux;
            }
        }
    }
}

int main()
{
    long int c=1000000;
    int *arreglo= new int[c];
    for (long int i=0; i<c; i++){
        arreglo[i]=c-i;
    }
    for (long int i=0; i<c; i++){
        cout << arreglo[i] << endl;
    }
    ord_asc(arreglo, c);
    for (long int i=0; i<c; i++){
        cout << arreglo[i] << endl;
    }
    delete[] arreglo;
    return 0;
}
