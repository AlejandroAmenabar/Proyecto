#ifndef PROYECTO_COMISARIA_H
#define PROYECTO_COMISARIA_H

#include <string>
#include <vector>
#include "Fecha.h"
#include "Ente.h"

class Denuncia;

class Oficial;

using namespace std;

class Comisaria : public Ente {

    string Direccion;

    vector<Denuncia *> Denuncias;

    vector<Oficial *> Oficiales;

public:

    explicit Comisaria(const string &direccion) : Direccion(direccion) {}

    virtual void MostrarInformacion() const override;

    void AgregarOficial(Oficial *oficial);

    inline string GetDireccion() const { return Direccion; }
};


#endif //PROYECTO_COMISARIA_H
