#include "Registro.h"

void Registro::MostrarInformacion() const {
    cout << "-- Registro --\n";
    cout << "Fecha: " << Fecha << '\n';
    cout << "Investigacion: " << Investigacion << '\n';
}
