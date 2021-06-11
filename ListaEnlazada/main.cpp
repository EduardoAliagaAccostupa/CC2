#include <iostream>
#include "Nodo.h"
#include "Lista.h"

using namespace std;

int main()
{
    Lista ls;

    ls.insertar(23);
    ls.insertar(131);
    ls.insertar(141);
    ls.insertar(134);
    ls.insertar(137);
    ls.insertar(134);
    ls.insertar(132);
    cout << "Tamaño: " << ls.mostTam() << endl;
    ls.mostrar();
    ls.quitar();
    ls.mostrar();
    ls.quitar(135);
    ls.mostrar();
    cout << "Tamaño: " << ls.mostTam() << endl;
    ls.quitar(1312);
    ls.mostrar();
    cout << "Tamaño: " << ls.mostTam() << endl;
    cout << "Sobrecarga: " << ls << endl;
    return 0;
}
