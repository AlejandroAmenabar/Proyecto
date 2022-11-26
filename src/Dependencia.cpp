#include "Dependencia.h"
#include "Denuncia.h"
#include "Oficial.h"

void Dependencia::MostrarInformacion() const {
    cout << "-- Dependencia --\n";
    Ente::MostrarInformacion();
    cout << "Nombre: " << Nombre << '\n';
}