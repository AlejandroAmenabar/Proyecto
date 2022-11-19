#include "Comisaria.h"
#include "Oficial.h"
#include "Denuncia.h"

int Comisaria::Indice = 0;

Comisaria::Comisaria(const string &direccion, const vector<Oficial *> &oficiales) : Direccion(direccion),
                                                                                    Oficiales(oficiales) {
    Codigo = Indice++;
}

void Comisaria::MostrarInformacion() const {
    cout << "-- Comisaria --\n";
    cout << "Codigo: " << Codigo << '\n';
    cout << "Direccion: " << Direccion << '\n';
}

void Comisaria::AgregarOficial(Oficial *oficial) {
    Oficiales.emplace_back(oficial);
}

void Comisaria::MostrarDenuncias(Fecha fecha) const {
    for (const auto &Denuncia: Denuncias) {
        if (Denuncia->GetFecha() - fecha == 0) {
            Denuncia->MostrarInformacion();
        }
    }
}

void Comisaria::AgregarDenuncia(Denuncia *denuncia) {
    Denuncias.emplace_back(denuncia);
}
