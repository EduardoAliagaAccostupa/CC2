#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include "Nodo.h"

using namespace std;

class Lista
{
    private:
        int tam;
        Nodo *cab;
    public:
        Lista();
        void insertar(int );
        void quitar();
        void mostrar();
        int mostTam();
        friend ostream& operator <<(ostream& o, const Lista& ls);

        ~Lista();
};

Lista::Lista(){
    this->tam=0;
    this->cab=NULL;
}

void Lista::insertar(int _valor){
    Nodo *aux=new Nodo(_valor);
    if (this->cab==NULL) { this->cab=aux;}
    else {
        Nodo *aux2=cab;
        while (aux2->mostSig()!=NULL){
            aux2=aux2->mostSig();
        }
        aux2->darSig(aux);
    }
    ++tam;
}

void Lista::quitar(){
    if (cab->mostSig()==NULL){
        Nodo *aux=cab;
        cab=NULL;
        delete aux;
    }
    else {
        Nodo *aux=cab, *aux2;
        for(int i=1; i<tam; i++) { aux=aux->mostSig();}
        aux2=aux->mostSig();
        delete aux2;
        aux->darSig(NULL);
    }
    --tam;
}

void Lista::mostrar(){
    Nodo *aux=cab;
    while(aux!=NULL){
        cout << aux->mostValor() << " -> ";
        aux=aux->mostSig();
    }
    cout << " FIN " << endl;
}

int Lista::mostTam(){
    return tam;
}

ostream& operator <<(ostream& o, const Lista& ls){
    Nodo *aux=ls.cab;
    for(int i=0; i<ls.tam; i++){
        o << aux->mostValor() << " -> ";
        aux=aux->mostSig();
    }
    o << " FIN ";
    return o;
}

Lista::~Lista(){
    Nodo *aux=cab;
    while(aux!=NULL){
        aux=aux->mostSig();
        delete cab;
        cab=aux;
    }
    cout << "lista borrada!" << endl;
}

#endif // LISTA_H

