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

class Denuncia : public IDatos{

    static int Indice;

    int Codigo;

    string Documentacion;

    Delito *DelitoCometido; //puntero, porque copiamos la referencia del main.

    Preambulo *Preambulo;

    vector<Registro *> Registros;

public:

    Denuncia(int codigo, const string &documentacion, const string &firmaDemandante, const string &firmaOficial,
             Delito *delito, class Preambulo *preambulo, const vector<Registro *> &registros) : Codigo(codigo),
                                                                                                      Documentacion(documentacion),
                                                                                                      DelitoCometido(delito),
                                                                                                      Preambulo(preambulo),
                                                                                                      Registros(registros) {}

    virtual ~Denuncia();

    virtual void MostrarInformacion() const override;

    void AsignarPreambulo(const Fecha &fecha, const string &direccion, const Oficial *oficial, const Persona &demandante,
                          const Persona &demandado);

    virtual void Derivar(Fecha fecha) const = 0;

    void AgregarInvestigacion(const string& investigacion);

    const Persona* BuscarPersona(int dni) const;

//    void AgregarRegistro(const Fecha& fecha, const string& investigacion, DependenciaSiguiente* dependencia);

//    inline const class Preambulo *GetPreambulo() const { return Preambulo; };

    inline Delito* GetDelito() const { return DelitoCometido; }

    vector<Registro*> GetRegistros() const { return Registros; }

    const Persona* GetDemandante() const;

    const Persona* GetDemandado() const;

    const Fecha& GetFecha() const;
};


#endif //PROYECTO_DENUNCIA_H
