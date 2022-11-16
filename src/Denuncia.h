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

    static int Cantidad;

    int Codigo;

    string Descripcion;

    string FirmaDemandante;

    string FirmaOficial;

    Delito *Delito; //puntero, porque copiamos la referencia del main.

    Preambulo *Preambulo;

    vector<Registro *> Registros;

public:

    Denuncia(int codigo, const string &descripcion, const string &firmaDemandante, const string &firmaOficial,
             class Delito *delito, class Preambulo *preambulo, const vector<Registro *> &registros) : Codigo(codigo),
                                                                                                      Descripcion(
                                                                                                              descripcion),
                                                                                                      FirmaDemandante(
                                                                                                              firmaDemandante),
                                                                                                      FirmaOficial(
                                                                                                              firmaOficial),
                                                                                                      Delito(delito),
                                                                                                      Preambulo(
                                                                                                              preambulo),
                                                                                                      Registros(
                                                                                                              registros) {}

    virtual ~Denuncia();

    virtual void MostrarInformacion() const override;

    void AsignarPreambulo(const Fecha &fecha, const string &lugar, const Oficial *oficial, const Persona &demandante,
                          const Persona &demandado);

    void AgregarRegistro(const Fecha& fecha, const string& investigacion, Dependencia* dependencia);

    virtual void Derivar(Fecha fecha, const string &investigacion) const = 0;

    inline const class Preambulo *GetPreambulo() const { return Preambulo; };
};


#endif //PROYECTO_DENUNCIA_H
