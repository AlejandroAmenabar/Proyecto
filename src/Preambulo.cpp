#include "Preambulo.h"
#include "Persona.h"
#include "Oficial.h"

void Preambulo::MostrarInformacion() const {
    cout << "-- Preambulo --\n";
    cout << "Fecha: " << FechaP << '\n';
    cout << "Lugar: " << Direccion << '\n';
    Demandado->MostrarInfo();
    Demandante->MostrarInfo();
    OficialACargo->MostrarInfo();
}

