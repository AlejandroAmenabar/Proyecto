#ifndef PROYECTO_ENTE_H
#define PROYECTO_ENTE_H

#include <vector>
#include "IExposicion.h"

using namespace std;

class Denuncia;

class Ente : public IExposicion {

    static int Indice;

    int Codigo = Indice++;

    vector<Denuncia *> Denuncias;

public:

    virtual ~Ente() = default;

    virtual void DerivarDenuncia() = 0;

    virtual void MostrarInformacion() const override = 0;

    inline virtual void AgregarDenuncia(Denuncia *denuncia) { Denuncias.emplace_back(denuncia); };

    inline int GetCodigo() const override { return Codigo; }
};

#endif //PROYECTO_ENTE_H
