#include <iostream>
#include "Nodo.h"
#include "Lista.h"

using namespace std;

int main()
{
    Lista ls;
    ls.insertar(1);
    ls.mostrar();
    ls.quitar();
    ls.mostrar();
    cout << "Tamaño: " << ls.mostTam() << endl;
    cout << ls << endl;
    return 0;
}
