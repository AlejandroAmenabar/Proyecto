#ifndef PROYECTO_DENUNCIAORAL_H
#define PROYECTO_DENUNCIAORAL_H

#include "Denuncia.h"
#include <string>

using namespace std;

class DenunciaOral : public Denuncia {

    string Descripcion;

public:

    DenunciaOral(int codigo, const string &descripcion, const string &firmaDemandante,
                 const string &firmaOficial, class Delito *delito, class Preambulo *preambuloDenuncia,
                 const vector<Registro *> &registros, const string &descripcion1) : Denuncia(codigo,
                                                                                             descripcion,
                                                                                             firmaDemandante,
                                                                                             firmaOficial,
                                                                                             delito,
                                                                                             preambuloDenuncia,
                                                                                             registros),
                                                                                    Descripcion(descripcion1) {}

    ~DenunciaOral() override = default;

    void Derivar(Fecha fecha) const override;
};


#endif //PROYECTO_DENUNCIAORAL_H
