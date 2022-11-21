#ifndef PROYECTO_DENUNCIA_H
#define PROYECTO_DENUNCIA_H

#include <string>
#include <vector>
#include "IDatos.h"

class Fecha;

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

    Preambulo *PreambuloD;

public:

    Denuncia(const string &documentacion, Delito *delito);

    virtual ~Denuncia();

    virtual void MostrarInformacion() const override;

    void AsignarPreambulo(const Fecha &fecha, const string &direccion, Oficial *oficial, Persona *demandante,
                          Persona *demandado);

    virtual void Derivar(const Fecha &fecha) = 0;
    
//    void AgregarInvestigacion(const string &investigacion);

    void AgregarRegistro(Registro* registro);

    Persona *BuscarPersona(int dni) const;

    Persona *GetDemandante() const;

    Persona *GetDemandado() const;

    Fecha &GetFecha() const;

    inline Delito *GetDelito() const { return DelitoCometido; }

    inline const Preambulo *GetPreambulo() const { return PreambuloD; }

    inline const vector<Registro *>& GetRegistros() const { return Registros; }
};

#endif //PROYECTO_DENUNCIA_H
