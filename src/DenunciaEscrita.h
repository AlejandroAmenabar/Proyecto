#ifndef PROYECTO_DENUNCIAESCRITA_H
#define PROYECTO_DENUNCIAESCRITA_H

#include "Denuncia.h"
#include <string>

using namespace std;

class DenunciaEscrita : public Denuncia {

    string Archivo;

public:

    DenunciaEscrita(const string &documentacion, Delito *delito,
                    const string &archivo) : Denuncia(documentacion, delito), Archivo(archivo) {}

    ~DenunciaEscrita() override = default;

    void Derivar(const string& investigacion, const Fecha &FechaD) override;
};


#endif //PROYECTO_DENUNCIAESCRITA_H
