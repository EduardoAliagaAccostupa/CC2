#ifndef NODO_H
#define NODO_H
#include <iostream>

using namespace std;

class Nodo
{
    private:
        int valor;
        Nodo *sig;

    public:
        Nodo(int);
        void darValor(int);
        int mostValor();
        void darSig(Nodo*);
        Nodo *mostSig();
        ~Nodo();
};

Nodo::Nodo(int _valor){
    this->valor=_valor;
    this->sig=NULL;
}

void Nodo::darValor(int _valor){
    this->valor=_valor;
}

int Nodo::mostValor(){
    return valor;
}

void Nodo::darSig(Nodo *_sig){
    this->sig=_sig;
}

Nodo* Nodo::mostSig(){
    return sig;
}

Nodo::~Nodo(){
    //
}

#endif // NODO_H
