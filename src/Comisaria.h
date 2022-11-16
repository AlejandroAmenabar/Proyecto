#ifndef PROYECTO_COMISARIA_H
#define PROYECTO_COMISARIA_H

#include <string>
#include <vector>
#include "Fecha.h"

class Denuncia;
class Persona;

using namespace std;

class Comisaria {

    static int Indice;

    int Codigo;

    string Direccion;

    vector<Denuncia *> Denuncias;

    vector<Persona *> Oficiales;

public:

    Comisaria(int codigo, const string &direccion, const vector<Denuncia *> &denuncias,
              const vector<Persona *> &oficiales) : Codigo(codigo), Direccion(direccion), Denuncias(denuncias),
                                                    Oficiales(oficiales) {}

    void MostrarDenuncias(const Fecha& fecha) const;

    void AgregarOficial(Persona *oficial);

    inline int GetCodigo() const { return Codigo; }

    inline string GetDireccion() const { return Direccion; }
};


#endif //PROYECTO_COMISARIA_H
