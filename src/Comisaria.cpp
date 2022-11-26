#include <algorithm>
#include "Comisaria.h"
#include "Oficial.h"
#include "Denuncia.h"
#include "Dependencia.h"
#include "Registro.h"
#include "Delito.h"

void Comisaria::MostrarInformacion() const {
    cout << "-- Comisaria --\n";
    Ente::MostrarInformacion();
    cout << "Direccion: " << Direccion << '\n';
    cout << '\n';
}

void Comisaria::AgregarOficial(Oficial *oficial) {
    if (std::find(Oficiales.begin(), Oficiales.end(), oficial) == Oficiales.end()) {
        Oficiales.emplace_back(oficial);
    }
}