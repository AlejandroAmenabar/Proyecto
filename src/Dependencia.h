#ifndef DEPENDENCIA_H_
#define DEPENDENCIA_H_

#include <iostream>
#include <vector>
#include "Ente.h"

class Oficial;

class Denuncia;

using namespace std;

class Dependencia : public Ente {

    string Nombre;

    Oficial *OficialDeTurno;

    vector<Denuncia *> Denuncias;

public:

    explicit Dependencia(const string &nombre) : Nombre(nombre) {}

    virtual void MostrarInformacion() const override;

    virtual void DerivarDenuncia() override;

    inline const string &GetNombre() const { return Nombre; }

    inline const Oficial *GetOficial() const { return OficialDeTurno; }
};

#endif /* DEPENDENCIA_H_ */
