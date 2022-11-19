#ifndef PROYECTO_DENUNCIAORAL_H
#define PROYECTO_DENUNCIAORAL_H

#include "Denuncia.h"
#include <string>

class Preambulo;

using namespace std;

class DenunciaOral : public Denuncia {

    string Descripcion;

public:

    DenunciaOral(const string &documentacion, Delito *delito, const string &descripcion) : Denuncia(
            documentacion, delito), Descripcion(descripcion) {}

    ~DenunciaOral() override = default;

    void Derivar(const Fecha &FechaD) override;
};


#endif //PROYECTO_DENUNCIAORAL_H
