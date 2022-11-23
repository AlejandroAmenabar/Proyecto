#ifndef PROYECTO_COMISARIA_H
#define PROYECTO_COMISARIA_H

#include <string>
#include <vector>
#include "Fecha.h"

class Denuncia;

class Oficial;

using namespace std;

class Comisaria {

    static int Indice;

    int Codigo = Indice++;

    string Direccion;

    vector<Denuncia *> Denuncias;

    vector<Oficial *> Oficiales;

public:

    explicit Comisaria(const string &direccion) : Direccion(direccion) {}

    void DerivarDenuncia();

    void MostrarInformacion() const;

    void MostrarDenuncias(Fecha fecha) const;

    void AgregarDenuncia(Denuncia *denuncia);

    void AgregarOficial(Oficial *oficial);

    inline int GetCodigo() const { return Codigo; }

    inline string GetDireccion() const { return Direccion; }
};


#endif //PROYECTO_COMISARIA_H
