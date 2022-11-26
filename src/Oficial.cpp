#include <iostream>
#include "Oficial.h"

void Oficial::MostrarInformacion() const {
    cout << "--- Oficial ---\n";
    Persona::MostrarInformacion();
    cout << "Cargo: " << Cargos::ToString(CargoOficial) << '\n';
    cout << '\n';
}