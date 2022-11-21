#include <iostream>
#include "Persona.h"

void Persona::MostrarInformacion() const {
    cout << "Dni: " << this->Dni << endl;
    cout << "Categoria Delito: " << this->Nombre << endl;
    cout << "Nacimiento: " << this->FecNacimiento << endl;
    cout << "Direccion: " << this->Direccion << endl;
    cout << "Sexo: " << this->Sexo << endl;
}



