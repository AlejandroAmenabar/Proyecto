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

void Sistema::AgregarComisaria(const string &direccion, vector<Oficial *> oficiales) {
    Comisaria *NuevaComisaria = new Comisaria(direccion, oficiales);
    Comisarias.emplace_back(NuevaComisaria);
}

void Sistema::MostrarDenuncias(Fecha &fecha) const {
    for (const auto &Denuncia: Denuncias) {
        if (Denuncia->GetFecha() - fecha == 0) {
            Denuncia->MostrarInformacion();
        }
    }
}

void Sistema::MostrarComisarias() const {

}

void Sistema::MostrarPersona(int dni) const {

}

void Sistema::RealizarDenuncia(Delito *delito, Persona *demandado, Persona *demandante, Oficial *oficialACargo) {
    int comisaria;
    cout << "Ingrese la comisaria\n";
    cin >> comisaria;

    fflush(stdin);
    int tipoDenuncia;
    cout << "Oral o escrita (0 - oral, 1 - escrita)\n";
    cin >> tipoDenuncia;

    fflush(stdin);
    string documentacion;
    cout << "Ingrese la documentacion\n";
    cin >> documentacion;

    fflush(stdin);
    string direccionDelito;
    cout << "Ingrese donde se cometio el delito\n";
    cin >> direccionDelito;

    Denuncia *NuevaDenuncia = nullptr;

    if (tipoDenuncia) {
        cout << "-- Denuncia Escrita --\n";

        fflush(stdin);
        string archivo;
        cout << "Ingrese el archivo\n";
        cin >> archivo;

        NuevaDenuncia = new DenunciaEscrita(documentacion, delito, archivo);
        NuevaDenuncia->AsignarPreambulo(Fecha{}, direccionDelito, oficialACargo, demandante, demandado);
        Denuncias.emplace_back(NuevaDenuncia);
    } else {
        cout << "-- Denuncia Oral --\n";

        fflush(stdin);
        string descripcion;
        cout << "Ingrese la descripcion\n";
        cin >> descripcion;

        NuevaDenuncia = new DenunciaOral(documentacion, delito, descripcion);
        Denuncias.emplace_back(NuevaDenuncia);
        NuevaDenuncia->AsignarPreambulo(Fecha{}, direccionDelito, oficialACargo, demandante, demandado);
    }


//    Denuncias.emplace_back(NuevaDenuncia); // Se agrega denuncia al vector de Denuncias del Sistema
//    Comisarias[comisaria]->AgregarDenuncia(NuevaDenuncia); // Se agrega denuncia al vector de Denuncias de la Comisaria
}