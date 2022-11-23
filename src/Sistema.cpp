#include <algorithm>
#include "Sistema.h"
#include "Delito.h"
#include "Persona.h"
#include "Oficial.h"
#include "Comisaria.h"
#include "Dependencia.h"
#include "Registro.h"
#include "Preambulo.h"
#include "Denuncia.h"
#include "DenunciaEscrita.h"
#include "DenunciaOral.h"

Sistema::~Sistema() {
    for (const auto &Denuncia: Denuncias) {
        delete Denuncia;
    }

    for (const auto &Comisaria: Comisarias) {
        delete Comisaria;
    }
}

void Sistema::AgregarComisaria(const string &direccion) {
    Comisaria *NuevaComisaria = new Comisaria(direccion);
    Comisarias.emplace_back(NuevaComisaria);
}

void Sistema::AgregarOficialAComisaria(int codigoComisaria, Oficial *oficial) {
    Comisarias[codigoComisaria]->AgregarOficial(oficial);
}

void Sistema::MostrarDenuncias(const Fecha &fecha) const {
    for (const auto &Denuncia: Denuncias) {
        if (Denuncia->GetFecha() == fecha) {
            Denuncia->MostrarInformacion();
        }
    }
}

void Sistema::MostrarComisarias() const {
    for (const auto &Comisaria: Comisarias) {
        Comisaria->MostrarInformacion();
    }
}

void Sistema::MostrarPersona(int dni) const {
    const Persona *Temporal = nullptr;

    for (const auto &Denuncia: Denuncias) {
        if ((Temporal = Denuncia->BuscarPersona(dni)) != nullptr) {
            Temporal->MostrarInformacion();
            break;
        }
    }
}

void Sistema::RealizarDenuncia(const InformacionDenuncia &informacion, Delito *delito, Persona *demandado,
                               Persona *demandante, Oficial *oficialACargo) {

    Denuncia *NuevaDenuncia = nullptr;

    if (informacion.GetTipoDenuncia()) {
        NuevaDenuncia = new DenunciaEscrita(informacion.GetDocumentacion(), delito,
                                            informacion.GetAdicional());
        NuevaDenuncia->AsignarPreambulo(Fecha{}, informacion.GetDireccionDelito(), oficialACargo, demandante,
                                        demandado);
    } else {
        NuevaDenuncia = new DenunciaOral(informacion.GetDocumentacion(), delito,
                                         informacion.GetAdicional());
        NuevaDenuncia->AsignarPreambulo(Fecha{}, informacion.GetDireccionDelito(), oficialACargo, demandante,
                                        demandado);
    }

    NuevaDenuncia->MostrarInformacion();

    Denuncias.emplace_back(NuevaDenuncia); // Se agrega denuncia al vector de Denuncias del Sistema
    Comisarias[informacion.GetCodigoComisaria()]->AgregarDenuncia(
            NuevaDenuncia); // Se agrega denuncia al vector de Denuncias de la Comisaria
}

void Sistema::MostrarPersonas() const {

}

