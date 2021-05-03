#include <iostream>

using namespace std;

int long1(char a[]){
    int aux=0;
    for(int i=0; a[i]!='\0'; i++){ aux=aux+1;}
    return aux;
}

int long2(char a[]){
    if (a[0]=='\0') { return 0;}
    ++a;
    return 1+long2(a);
}

int main()
{
    char pal[]="pollito";
    int tam=long1(pal);
    cout << tam << endl;
    tam=long2(pal);
    cout << tam << endl;
}