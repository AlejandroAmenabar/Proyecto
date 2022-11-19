#ifndef PREAMBULO_H_
#define PREAMBULO_H_

#include <iostream>
#include "Fecha.h"

class Persona;

class Oficial;

using namespace std;

class Preambulo {

    Fecha FechaP;

    string Direccion;

    Persona *Demandante;

    Persona *Demandado;

    Oficial *OficialACargo;

public:

    Preambulo(const Fecha &fechaP, const string &direccion, Persona *demandante, Persona *demandado,
              Oficial *oficialACargo) : FechaP(fechaP), Direccion(direccion), Demandante(demandante),
                                        Demandado(demandado), OficialACargo(oficialACargo) {}

    void MostrarInformacion() const;

    inline const Fecha &GetFecha() const { return FechaP; }

    inline const string &GetDireccion() const { return Direccion; }

    inline Persona* GetDemandante() const { return Demandante; }

    inline Persona* GetDemandado() const { return Demandado; }

//    inline Oficial* GetOficialACargo() const { return OficialACargo; }
};

#endif /* PREAMBULO_H_ */
