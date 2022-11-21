#include "Sistema.h"
#include "Delito.h"
#include "Persona.h"
#include "Oficial.h"
#include "Comisaria.h"
#include "Dependencia.h"
#include "Registro.h"
#include "Preambulo.h"
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

void Sistema::AgregarComisaria(const string &direccion, const vector<Oficial *>& oficiales) {
    Comisaria *NuevaComisaria = new Comisaria(direccion, oficiales);
    Comisarias.emplace_back(NuevaComisaria);
}

void Sistema::MostrarDenuncias(Fecha &fecha) const {
    for (const auto &Denuncia: Denuncias) {
        if (Denuncia->GetFecha() == fecha) {
            Denuncia->MostrarInformacion();
        }
    }
}

void Sistema::MostrarComisarias() const {

}

void Sistema::MostrarPersona(int dni) const {

}

void Sistema::RealizarDenuncia(Delito *delito, Persona *demandado, Persona *demandante, Oficial *oficialACargo) {
    int Comisaria;
    cout << "Ingrese la comisaria(0- Alberdi, 1 - Las Talitas, 2 - Alderetes)\n";
    cin >> Comisaria;

    int TipoDenuncia;
    cout << "Oral o escrita (0 - oral, 1 - escrita)\n";
    cin >> TipoDenuncia;

    string Documentacion;
    cout << "Ingrese la documentacion\n";
    cin >> Documentacion;

    string DireccionDelito;
    cout << "Ingrese donde se cometio el delito\n";
    cin >> DireccionDelito;

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