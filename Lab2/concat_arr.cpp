#include <iostream>

using namespace std;

void concat(int a[], int b[], int tam1, int tam2){
    int aux[tam2-tam1];
    for(int i = 0; i < tam2-tam1; i++){
        aux[i]=b[i];
    }
    for(int j=0; j<tam1; j++){
        b[j]=a[j];
    }
    for(int k=tam1; k<tam2; k++){
        b[k]=aux[k-tam1];
    }
}

int main()
{
    int tam1=6, tam2=14;
    int arreglo1[tam1]={2,5,12,6,8,43};
    int arreglo2[tam2]={3,7,8,0,1,22,1,90};
    concat(arreglo1, arreglo2, tam1, tam2);
    for(int i=0; i<tam2; i++){
        cout << arreglo2[i] << endl;
    }
    return 0;
}
