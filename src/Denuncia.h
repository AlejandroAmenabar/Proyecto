#ifndef PROYECTO_DENUNCIA_H
#define PROYECTO_DENUNCIA_H

#include <string>
#include <vector>
#include "IDatos.h"

class Fecha;

class Comisaria;

class Delito;

class Oficial;

class Persona;

class Preambulo;

class Registro;

using namespace std;

class Denuncia : public IDatos {

    static int Indice;

    int Codigo;

    string Documentacion;

    Delito *DelitoCometido; //puntero, porque copiamos la referencia del main.

    vector<Registro *> Registros;

protected:

    Preambulo *PreambuloD;

public:

    Denuncia(const string &documentacion, Delito *delito);

    virtual ~Denuncia();

    virtual void MostrarInformacion() const override;

    void AsignarPreambulo(const Fecha &fecha, const string &direccion, Oficial *oficial, Persona *demandante,
                          Persona *demandado);

    virtual void Derivar(const Fecha &fecha) const = 0;

    void AgregarInvestigacion(const string &investigacion);

    Persona *BuscarPersona(int dni) const;

    inline Delito *GetDelito() const { return DelitoCometido; }

    vector<Registro *> GetRegistros() const { return Registros; }

    Persona *GetDemandante() const;

    Persona *GetDemandado() const;

    Fecha &GetFecha() const;
};


#endif //PROYECTO_DENUNCIA_H
