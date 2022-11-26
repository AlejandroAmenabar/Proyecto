#include <iostream>
#include <algorithm>
#include "Denuncia.h"
#include "Ente.h"
#include "Fecha.h"

int Ente::Indice = 0;

void Ente::MostrarInformacion() const{
    cout << "Codigo: " << Codigo << '\n';
}

void Ente::DerivarDenuncia() {
    if(Denuncias.empty()){
        cout << "Debe haber por lo menos una (1) Denuncia registrado para poder derivarla\n";
        return;
    }

    string InvestigacionDependencia;
    cout << "Ingrese la investigacion realidad: \n";
    cin.ignore();
    getline(cin, InvestigacionDependencia);

    Denuncias.back()->Derivar(InvestigacionDependencia, Fecha{});
    Denuncias.pop_back();
}

void Ente::MostrarDenuncias() const {
    for (const auto &Denuncia: Denuncias) {
        Denuncia->MostrarInformacion();
    }
}
