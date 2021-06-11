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
        void quitar(int);
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
        if (_valor <= cab->mostValor()){
            if (_valor == cab->mostValor()) {
                cout << "Numero repetido!" << endl;
                --tam;
            }
            else {
                aux->darSig(cab);
                this->cab=aux;
            }
        }
        else{
            Nodo *aux2=cab->mostSig();
            Nodo *aux3=cab;
            while (aux2!=NULL && _valor > aux2->mostValor()){
                aux2=aux2->mostSig();
                aux3=aux3->mostSig();
            }
            if (aux2==NULL){ aux3->darSig(aux);}
            else{
                if (aux2->mostValor() == _valor){
                    cout << "Numero repetido!" << endl;
                    --tam;
                }
                else{
                    aux3->darSig(aux);
                    aux->darSig(aux2);
                }
            }
        }
    }
    ++tam;
}

void Lista::quitar(){
    if (cab==NULL) {
        cout << "ERROR!!!" << endl;
        ++tam;
    }
    else if (cab->mostSig()==NULL){
        Nodo *aux=cab;
        cab=NULL;
        delete aux;
    }
    else {
        Nodo *aux=cab, *aux2;
        for(int i=1; i<tam-1; i++) {
            aux=aux->mostSig();
        }
        aux2=aux->mostSig();
        delete aux2;
        aux->darSig(NULL);
    }
    --tam;
}

void Lista::quitar(int _valor){
    if (cab==NULL) {
        cout << "ERROR!!!" << endl;
        ++tam;
    }
    else if (_valor <= cab->mostValor()){
        if (_valor < cab->mostValor()){
            cout << "Numero no existente!" << endl;
            ++tam;
        }
        else {
            Nodo *aux=cab;
            cab=cab->mostSig();
            delete aux;
        }
    }
    else{
        Nodo *aux=cab->mostSig();
        Nodo *aux2=cab;
        while (aux!=NULL && (_valor > aux->mostValor())){
            aux=aux->mostSig();
            aux2=aux2->mostSig();
        }
        if (aux==NULL){
            cout << "Numero no existente!" << endl;
            ++tam;
        }
        else if (aux->mostValor() == _valor){
            aux2->darSig(aux->mostSig());
            delete aux;
        }
        else {
            cout << "Numero no existente!" << endl;
            ++tam;
        }
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
    cout << "Lista borrada!" << endl;
}

#endif // LISTA_H

