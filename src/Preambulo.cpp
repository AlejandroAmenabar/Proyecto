#include "Preambulo.h"
#include "Persona.h"
#include "Oficial.h"

void Preambulo::MostrarInformacion() const {
    cout << "-- Preambulo --\n";
    cout << "Fecha: " << FechaP << '\n';
    cout << "Lugar: " << Direccion << '\n';

    cout << "-- Demandante --\n";
    Demandante->MostrarInfo();

    cout << "-- Demandado --\n";
    Demandado->MostrarInfo();

    cout << "-- Oficial --\n";
    OficialACargo->MostrarInfo();
}

