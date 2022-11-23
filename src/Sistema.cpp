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

void Sistema::RealizarDenuncia(Delito *delito, Persona *demandado, Persona *demandante, Oficial *oficialACargo) {

    Denuncia *NuevaDenuncia = nullptr;

    if (TipoDenuncia) {
        string Archivo;
        cout << "-- Denuncia Escrita --\n";
        cout << "Ingrese el archivo\n";
        cin >> Archivo;

        NuevaDenuncia = new DenunciaEscrita(Documentacion, delito, Archivo);
        NuevaDenuncia->AsignarPreambulo(Fecha{}, DireccionDelito, oficialACargo, demandante, demandado);
    } else {
        string Descripcion;
        cout << "-- Denuncia Oral --\n";
        cout << "Ingrese la descripcion\n";
        cin >> Descripcion;

        NuevaDenuncia = new DenunciaOral(Documentacion, delito, Descripcion);
        NuevaDenuncia->AsignarPreambulo(Fecha{}, DireccionDelito, oficialACargo, demandante, demandado);
    }

    NuevaDenuncia->MostrarInformacion();

    Denuncias.emplace_back(NuevaDenuncia); // Se agrega denuncia al vector de Denuncias del Sistema
    Comisarias[Comisaria]->AgregarDenuncia(NuevaDenuncia); // Se agrega denuncia al vector de Denuncias de la Comisaria
}

void Sistema::MostrarPersonas() const {

}

