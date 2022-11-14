#ifndef PROYECTO_DENUNCIAESCRITA_H
#define PROYECTO_DENUNCIAESCRITA_H

#include "Denuncia.h"

class Archivo;

class DenunciaEscrita : public Denuncia {

    Archivo *Fotocopia;

public:

    DenunciaEscrita(int codigo, const string &descripcion, Imagen *firmaDemandante, Imagen *firmaOficial,
                    Archivo *fotocopia) : Denuncia(codigo, descripcion, firmaDemandante, firmaOficial),
                                          Fotocopia(fotocopia) {}

    virtual ~DenunciaEscrita();

    virtual void Derivar(Fecha fecha, const string &investigacion) const override;

};


#endif //PROYECTO_DENUNCIAESCRITA_H
