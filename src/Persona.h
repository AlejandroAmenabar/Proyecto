#ifndef PERSONA_H_
#define PERSONA_H_

#include <iostream>
#include "IExposicion.h"
#include "Fecha.h"

using namespace std;

class Persona : public IExposicion {

    static int Indice;

    int Codigo = Indice++;

    int Dni;

    string Nombre;

    Fecha FecNacimiento;

    string Direccion;

    char Sexo;

public:

    Persona(int dni, const string &nombre, const Fecha &fecNacimiento, const string &direccion, char sexo)
            : Dni(dni), Nombre(nombre), FecNacimiento(fecNacimiento), Direccion(direccion), Sexo(sexo) {}

    virtual ~Persona() = default;

    virtual void MostrarInformacion() const override;

    inline int GetDni() const { return Dni; }

    inline string GetNombre() const { return Nombre; }
};


#endif /* PERSONA_H_ */
