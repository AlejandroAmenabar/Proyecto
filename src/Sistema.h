#ifndef PROYECTO_SISTEMA_H
#define PROYECTO_SISTEMA_H

#include <string>
#include <vector>
#include "Fecha.h"

class Persona;

class Comisaria;

class Denuncia;

class Delito;

class Oficial;

using namespace std;

struct InformacionDenuncia {
    int CodigoComisaria;
    int TipoDenuncia;
    string Documentacion;
    string DireccionDelito;
    string Adicional;

    InformacionDenuncia(int codigoComisaria, int tipoDenuncia, const string &documentacion, const string &direccionDelito,
                        const string &adicional) : CodigoComisaria(codigoComisaria), TipoDenuncia(tipoDenuncia),
                                                Documentacion(documentacion), DireccionDelito(direccionDelito),
                                                Adicional(adicional) {}

    inline int GetCodigoComisaria() const { return CodigoComisaria; }

    inline int GetTipoDenuncia() const { return TipoDenuncia; }

    inline const string &GetDocumentacion() const { return Documentacion; }

    inline const string &GetDireccionDelito() const { return DireccionDelito; }

    inline const string &GetAdicional() const { return Adicional; }
};

class Sistema {

    int Codigo;

    string Nombre;

    vector<Comisaria *> Comisarias;

    vector<Denuncia *> Denuncias;

public:

    Sistema(int codigo, const string &nombre) : Codigo(codigo), Nombre(nombre) {}

    virtual ~Sistema();

    void AgregarComisaria(const string &direccion);

    void AgregarOficialAComisaria(int codigoComisaria, Oficial *oficial);

    void RealizarDenuncia(Delito *delito, Persona *demandado, Persona *demandante, Oficial *oficialACargo);

    void MostrarDenuncias(const Fecha &fecha) const;

    void MostrarComisarias() const;

    void MostrarPersona(int dni) const;

    void MostrarPersonas() const;

    inline bool ExistenComisarias() const { return !Comisarias.empty(); }

};

#endif //PROYECTO_SISTEMA_H
