#ifndef PROYECTO_SISTEMA_H
#define PROYECTO_SISTEMA_H

#include <string>
#include <vector>
#include "Fecha.h"

class Comisaria;
class Denuncia;
class Oficial;

using namespace std;

class Sistema {

    int Codigo;

    string Nombre;

    vector<Comisaria*> Comisarias;

    vector<Denuncia*> Denuncias;

public:

    Sistema(int codigo, const string& nombre) : Codigo(codigo), Nombre(nombre) {}

    virtual ~Sistema();

    void AgregarComisaria(int codigo, const string& direccion, vector<Oficial*> oficiales);

    void MostrarDenuncias(const Fecha& fecha) const;

    void MostrarComisarias() const;

    void MostrarPersona(int dni) const;

    inline int GetCodigo() const { return Codigo; }

    inline const string& GetNombre() const { return Nombre; }
};


#endif //PROYECTO_SISTEMA_H
