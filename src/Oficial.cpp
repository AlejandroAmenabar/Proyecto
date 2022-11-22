#include <iostream>
#include "Oficial.h"

using namespace std;

void Oficial::MostrarInformacion() const {
    Persona::MostrarInformacion();
    cout << "Cargo: " << Cargos::ToString(CargoOficial) << '\n';
}