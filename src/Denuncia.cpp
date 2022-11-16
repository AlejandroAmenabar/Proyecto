#include <iostream>
#include "Delito.h"
#include "Denuncia.h"
#include "Fecha.h"
#include "Preambulo.h"
#include "Registro.h"
//#include "Registro.h"

int Denuncia::Cantidad = 0;

Denuncia::~Denuncia() {
    delete Preambulo;

    for(auto Registro : Registros){
        delete Registro;
    }
}

void Denuncia::MostrarInformacion() const {
    cout << "Codigo: " << Codigo << '\n';
    cout << "Descripcion: " << Descripcion << '\n';
    cout << "Firma del demandante: " << FirmaDemandante << '\n';
    cout << "Firma del oficial: " << FirmaOficial << '\n';
    Delito->MostrarInformacion();
    Preambulo->MostrarInfo();
}

void
Denuncia::AsignarPreambulo(const Fecha &fecha, const string &lugar, const Oficial *oficial, const Persona &demandante,
                           const Persona &demandado) {

    Preambulo = new class Preambulo(fecha, lugar);
}

void Denuncia::AgregarRegistro(const Fecha &fecha, const string &investigacion, Dependencia *dependencia) {
    auto NuevoRegistro = new Registro(fecha, investigacion, dependencia);
    Registros.emplace_back(NuevoRegistro);
}


