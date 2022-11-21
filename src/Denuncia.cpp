#include <iostream>
#include "Delito.h"
#include "Denuncia.h"
#include "Fecha.h"
#include "Preambulo.h"
#include "Registro.h"

int Denuncia::Indice = 0;

Denuncia::Denuncia(const string &documentacion, Delito *delito) : Documentacion(documentacion), DelitoCometido(delito) {
    Codigo = Indice++;
}

Denuncia::~Denuncia() {
    delete PreambuloD;

    for (const auto& Registro: Registros) {
        delete Registro;
    }
}

void Denuncia::MostrarInformacion() const {
    cout << "Codigo: " << Codigo << '\n';
    cout << "Documentacion: " << Documentacion << '\n';
    DelitoCometido->MostrarInformacion();
    PreambuloD->MostrarInformacion();
}

//void Denuncia::AgregarInvestigacion(const string &investigacion) {
//    Registros.back()->AsignarInvestigacion(investigacion);
//}

void Denuncia::AsignarPreambulo(const Fecha &fecha, const string &direccion, Oficial *oficial, Persona *demandante, Persona *demandado) {
    PreambuloD = new class Preambulo(fecha, direccion, demandante, demandado, oficial);
}

Persona *Denuncia::BuscarPersona(int dni) const {
    return nullptr;
}

Fecha &Denuncia::GetFecha() const {
    return PreambuloD->GetFecha();
}

Persona *Denuncia::GetDemandante() const {
    // TODO
    return nullptr;
}

Persona *Denuncia::GetDemandado() const {
    // TODO
    return nullptr;
}

void Denuncia::AgregarRegistro(Registro* registro) {
    Registros.emplace_back(registro);
}
