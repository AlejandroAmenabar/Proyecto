#ifndef PROYECTO_SISTEMA_H
#define PROYECTO_SISTEMA_H

#include <string>
#include <vector>
#include "Fecha.h"

class Persona;
class Comisaria;
class Denuncia;
class Delito;
class Oficial;

using namespace std;

class Sistema {

    int Codigo;

    string Nombre;

    vector<Comisaria *> Comisarias;

    vector<Denuncia *> Denuncias;

public:

    Sistema(int codigo, const string &nombre) : Codigo(codigo), Nombre(nombre) {}

    virtual ~Sistema();

    void AgregarComisaria(const string &direccion, const vector<Oficial *>& oficiales);

    void RealizarDenuncia(Delito* delito, Persona *demandado, Persona *demandante, Oficial *oficialACargo);

    void MostrarDenuncias(Fecha &fecha) const;

    void MostrarComisarias() const;

    void MostrarPersona(int dni) const;

    inline int GetCodigo() const { return Codigo; }

    inline const string &GetNombre() const { return Nombre; }

    inline const vector<Comisaria *> &GetComisarias() const { return Comisarias; }
};

#endif //PROYECTO_SISTEMA_H
