#ifndef DELITO_H_
#define DELITO_H_

#include <iostream>
#include <vector>
#include "Categoria.h"

class Dependencia;

using namespace std;

class Delito {

    int Codigo;

    Categorias::Categoria CategoriaDelito;

    vector<Dependencia *> Dependencias;

public:

    Delito(int codigo, Categorias::Categoria categoriaDelito, const vector<Dependencia *> &dependencias) : Codigo(
            codigo), CategoriaDelito(categoriaDelito), Dependencias(dependencias) {}

    void MostrarInformacion() const;

    Dependencia *ObtenerPrimeraDependencia() const; // Para derivar desde la Comisaría

    Dependencia *ObtenerSiguienteDependencia(const string &Dependencia) const; // Para derivar desde Dependencia

    Dependencia *ObtenerUltimaDependencia() const; // Para las Denuncias Escritas, va directo a la Fiscalía

    inline int GetCodigo() const { return Codigo; }

    inline const Categorias::Categoria &GetCategoria() const { return CategoriaDelito; }
};

#endif /* DELITO_H_ */
