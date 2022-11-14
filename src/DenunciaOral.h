#ifndef PROYECTO_DENUNCIAORAL_H
#define PROYECTO_DENUNCIAORAL_H

#include "Denuncia.h"
#include <string>

using namespace std;

class DenunciaOral : public Denuncia {

    string Descripcion;

public:

    DenunciaOral(int codigo, const string &descripcion, Imagen *firmaDemandante, Imagen *firmaOficial,
                 string descripcion1) : Denuncia(codigo, descripcion, firmaDemandante, firmaOficial),
                                               Descripcion(std::move(descripcion1)) {}

    ~DenunciaOral() override = 0;

    void Derivar(Fecha fecha, const string &investigacion) const override;
};


#endif //PROYECTO_DENUNCIAORAL_H
