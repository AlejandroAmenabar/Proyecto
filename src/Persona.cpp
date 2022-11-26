#include <iostream>
#include "Persona.h"

int Persona::Indice = 0;

void Persona::MostrarInformacion() const {
    cout << "--- Persona ---\n";
    cout << "Codigo: " << Codigo << '\n';
    cout << "Dni: " << Dni << '\n';
    cout << "Nombre: " << Nombre << '\n';
    cout << "Nacimiento: " << FecNacimiento << '\n';
    cout << "Direccion: " << Direccion << '\n';
    cout << "Sexo: " << Sexo << '\n';
    cout << '\n';
}