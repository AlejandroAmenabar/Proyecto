#include <algorithm>
#include "Comisaria.h"
#include "Oficial.h"
#include "Denuncia.h"
#include "Dependencia.h"
#include "Registro.h"
#include "Delito.h"

int Comisaria::Indice = 0;

void Comisaria::MostrarInformacion() const {
    cout << "-- Comisaria --\n";
    cout << "Codigo: " << Codigo << '\n';
    cout << "Direccion: " << Direccion << '\n';
}

void Comisaria::AgregarOficial(Oficial *oficial) {
    // Agrego el oficial solo si no se encuentra ya en el vector de oficiales
    if (std::find(Oficiales.begin(), Oficiales.end(), oficial) != Oficiales.end()) {
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

void Comisaria::AgregarDenuncia(Denuncia *denuncia) {
    Denuncias.emplace_back(denuncia);
}

void Comisaria::DerivarDenuncia() {
    string InvestigacionComisaria;
    cout << "Ingrese declaracion inicial de la denuncia: \n"; // Se guarda en la variable Investigación de Registro
    cin >> InvestigacionComisaria;

    Denuncias.back()->Derivar(InvestigacionComisaria, Fecha{});
    Denuncias.pop_back();
}
