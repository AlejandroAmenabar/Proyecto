#include <iostream>
#include "Delito.h"
#include "Denuncia.h"
#include "Fecha.h"
#include "Preambulo.h"
#include "Registro.h"
//#include "Registro.h"

int Denuncia::Indice = 0;

Denuncia::~Denuncia() {
    delete Preambulo;

    for(auto Registro : Registros){
        delete Registro;
    }
}

void Denuncia::MostrarInformacion() const {
    cout << "Codigo: " << Codigo << '\n';
    cout << "Documentacion: " << Documentacion << '\n';
    cout << "Firma del demandante: " << FirmaDemandante << '\n';
    cout << "Firma del oficial: " << FirmaOficial << '\n';
    DelitoCometido->MostrarInformacion();
    Preambulo->MostrarInfo();
}

void Denuncia::AgregarInvestigacion(const string &investigacion) {
    Registros.back()->SetInvestigacion(investigacion);
}

void
Denuncia::AsignarPreambulo(const Fecha &fecha, const string &direccion, const Oficial *oficial, const Persona &demandante,
                           const Persona &demandado) {

    Preambulo = new class Preambulo(fecha, direccion);
}


