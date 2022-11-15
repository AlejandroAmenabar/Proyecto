#ifndef PROYECTO_REGISTRO_H
#define PROYECTO_REGISTRO_H

#include <string>
#include "Fecha.h"

class Dependencia;

class Registro {

    Fecha Fecha;

    string Investigacion;

    Dependencia *Dependencia;

public:

    Registro(const class Fecha &fecha, const string &investigacion, class Dependencia *dependencia) : Fecha(fecha),
                                                                                                      Investigacion(investigacion),
                                                                                                      Dependencia(dependencia) {}

    void MostrarInformacion() const;

    inline class Dependencia *ObtenerDependencia() const { return Dependencia; }

};


#endif //PROYECTO_REGISTRO_H
