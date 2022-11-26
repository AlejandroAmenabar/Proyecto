#include <iostream>
#include "Ente.h"

int Ente::Indice = 0;

void Ente::MostrarInformacion() const{
    cout << "Codigo: " << Codigo << '\n';
}