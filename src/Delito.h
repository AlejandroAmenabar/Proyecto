#ifndef DELITO_H_
#define DELITO_H_

#include <iostream>
#include <vector>

class Dependencia;

using namespace std;

enum class Categoria {
    DelitosSexuales,
    Criminales,
    OrdenPublico,
    Homicidio,
    Femicidio,
    DIGEDROP,
    Robo,
    Violencia
};

class Delito {

    int Codigo;

    Categoria CategoriaDelito;

    vector<Dependencia *> Dependencias;

public:

    Delito(int codigo, Categoria categoriaDelito, const vector<Dependencia *> &dependencias) : Codigo(codigo),
                                                                                               CategoriaDelito(
                                                                                                       categoriaDelito),
                                                                                               Dependencias(
                                                                                                       dependencias) {}

    Dependencia *ObtenerSiguienteDependencia(const string &Dependencia);

	Dependencia* ObtenerUltimaDependencia();

    inline int GetCodigo() const { return Codigo; }

    inline const Categoria &GetCategoria() const { return CategoriaDelito; }
};

#endif /* DELITO_H_ */
