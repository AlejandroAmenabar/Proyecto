#include <iostream>
#include "Oficial.h"

void Oficial::MostrarInformacion() const {
    Persona::MostrarInformacion();
    cout << "Cargo: " << Cargos::ToString(CargoOficial) << '\n';
}