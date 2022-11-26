#include <iostream>
#include <algorithm>
#include "Delito.h"
#include "Denuncia.h"
#include "Fecha.h"
#include "Preambulo.h"
#include "Persona.h"
#include "Registro.h"

int Denuncia::Indice = 0;

Denuncia::Denuncia(const string &documentacion, Delito *delito) : Documentacion(documentacion), DelitoCometido(delito) {
    Codigo = Indice++;
}

Denuncia::~Denuncia() {
    delete PreambuloD;

    for (const auto &Registro: Registros) {
        delete Registro;
    }
}

void Denuncia::MostrarInformacion() const {
    cout << "Codigo: " << Codigo << '\n';
    cout << "Documentacion: " << Documentacion << '\n';
    DelitoCometido->MostrarInformacion();
    PreambuloD->MostrarInformacion();
    cout << '\n';
}

void Denuncia::AsignarPreambulo(const Fecha &fecha, const string &direccion, Oficial *oficial, Persona *demandante,
                                Persona *demandado) {
    PreambuloD = new class Preambulo(fecha, direccion, demandante, demandado, oficial);
}

Persona *Denuncia::BuscarPersona(int dni) const {
    if (GetDemandante()->GetDni() == dni) {
        return GetDemandante();
    } else if (GetDemandado()->GetDni() == dni) {
        return GetDemandado();
    }

    return nullptr;
}

Fecha &Denuncia::GetFecha() const {
    return PreambuloD->GetFecha();
}

Persona *Denuncia::GetDemandante() const {
    return PreambuloD->GetDemandante();
}

Persona *Denuncia::GetDemandado() const {
    return PreambuloD->GetDemandado();
}

void Denuncia::AgregarRegistro(Registro *registro) {
    Registros.emplace_back(registro);
}
