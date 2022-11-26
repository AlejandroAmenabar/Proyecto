#ifndef PROYECTO_REGISTRO_H
#define PROYECTO_REGISTRO_H

#include <string>
#include "Fecha.h"

class Dependencia;

class Registro {

    Fecha Fecha;

    string Investigacion;

    string DependenciaSiguiente;

public:

    explicit Registro(const class Fecha &fecha, const string &dependenciaSig) : Fecha(fecha),
                                                                                DependenciaSiguiente(dependenciaSig) {}

    void MostrarInformacion() const;

    inline void AsignarInvestigacion(const string &investigacion) { Investigacion = investigacion; }

    inline const class Fecha &GetFecha() const { return Fecha; }

    inline const string &GetInvestigacion() const { return Investigacion; }

    inline const string &GetDepedenciaSiguiente() const { return DependenciaSiguiente; }

};


#endif //PROYECTO_REGISTRO_H
