#include "Preambulo.h"
#include "Oficial.h"

void Preambulo::MostrarInformacion() const {
    cout << "-- Preambulo --\n";
    cout << "Fecha: " << FechaP << '\n';
    cout << "Lugar: " << Direccion << '\n';

    cout << "-- Demandante --\n";
    Demandante->MostrarInformacion();

    cout << "-- Demandado --\n";
    Demandado->MostrarInformacion();

    OficialACargo->MostrarInformacion();
}

