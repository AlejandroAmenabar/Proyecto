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
    for(const auto& Oficial : Oficiales){
        Oficial->MostrarInformacion();
    }
}

void Comisaria::AgregarOficial(Oficial *oficial) {
    if (std::find(Oficiales.begin(), Oficiales.end(), oficial) == Oficiales.end()) {
        Oficiales.emplace_back(oficial);
    }
}

void Comisaria::MostrarDenuncias(Fecha fecha) const {
    for (const auto &Denuncia: Denuncias) {
        if (Denuncia->GetFecha() == fecha) {
            Denuncia->MostrarInformacion();
        }
    }
}

void Comisaria::DerivarDenuncia() {
    string InvestigacionComisaria;
    cout << "Ingrese declaracion inicial de la denuncia: \n"; // Se guarda en la variable Investigación de Registro
    cin >> InvestigacionComisaria;

    Denuncias.back()->Derivar(InvestigacionComisaria, Fecha{});
    Denuncias.pop_back();
}