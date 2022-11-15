#ifndef PROYECTO_DENUNCIAESCRITA_H
#define PROYECTO_DENUNCIAESCRITA_H

#include "Denuncia.h"
#include <string>

using namespace std;

class DenunciaEscrita : public Denuncia {

    string Archivo;

public:

    DenunciaEscrita(int codigo, const string &descripcion, const string &firmaDemandante,
                    const string &firmaOficial, class Delito *delito, class Preambulo *preambuloDenuncia,
                    const vector<Registro *> &registros, const string &archivo) : Denuncia(codigo,
                                                                                           descripcion,
                                                                                           firmaDemandante,
                                                                                           firmaOficial,
                                                                                           delito,
                                                                                           preambuloDenuncia,
                                                                                           registros),
                                                                                  Archivo(archivo) {}

    ~DenunciaEscrita() override = default;

    virtual void Derivar(Fecha fecha, const string &investigacion) const override;

};


#endif //PROYECTO_DENUNCIAESCRITA_H
