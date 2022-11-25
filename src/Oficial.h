#ifndef OFICIAL_H_
#define OFICIAL_H_

#include <iostream>
#include "Cargos.h"
#include "Persona.h"

using namespace std;
using namespace Cargos;

class Oficial : public Persona {

    Cargo CargoOficial;

public:

    Oficial(int dni, const string &nombre, const Fecha &fecNacimiento, const string &direccion, char sexo,
            const Cargo& cargoOficial) : Persona(dni, nombre, fecNacimiento, direccion, sexo),
                                          CargoOficial(cargoOficial) {}

    virtual ~Oficial() override = default;

    virtual void MostrarInformacion() const override;
};


#endif /* OFICIAL_H_ */
