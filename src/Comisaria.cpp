#include "Comisaria.h"
#include "Denuncia.h"

int Comisaria::Indice = 0;

void Comisaria::AgregarOficial(Persona *oficial) {
    Oficiales.emplace_back(oficial);
}

void Comisaria::MostrarDenuncias(const Fecha& fecha) const {
    for(auto Denuncia : Denuncias){
        if(Denuncia->get)
        Denuncia->MostrarInformacion();
    }
}
