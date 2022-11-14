#ifndef PROYECTO_DENUNCIAESCRITA_H
#define PROYECTO_DENUNCIAESCRITA_H

#include "Denuncia.h"
#include <string>

using namespace std;

class DenunciaEscrita : public Denuncia {

    string Archivo;

public:

    DenunciaEscrita(int codigo, const string &descripcion, const string &firmaDemandante,
                    const string &firmaOficial, class Delito *delito, const string &archivo) : Denuncia(codigo,
                                                                                                        descripcion,
                                                                                                        firmaDemandante,
                                                                                                        firmaOficial,
                                                                                                        delito),
                                                                                               Archivo(archivo) {}

    ~DenunciaEscrita() override = 0;

    virtual void Derivar(Fecha fecha, const string &investigacion) const override;

};


#endif //PROYECTO_DENUNCIAESCRITA_H
