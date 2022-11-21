#ifndef DELITO_H_
#define DELITO_H_

#include <iostream>
#include <vector>

class Dependencia;

using namespace std;

enum Categoria {
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

    string Categorias[8] = {"Delitos Sexuales", "Criminales", "Orden Público", "Homicidio", "Femicidio", "DIGEDROP",
                            "Robo", "Violencia"};

public:

    Delito(int codigo, Categoria categoriaDelito, const vector<Dependencia *> &dependencias) : Codigo(codigo),
                                                                                               CategoriaDelito(
                                                                                                       categoriaDelito),
                                                                                               Dependencias(
                                                                                                       dependencias) {}

    void MostrarInformacion() const;

    Dependencia* ObtenerPrimeraDependencia() const; // Para derivar desde la Comisaría

    Dependencia *ObtenerSiguienteDependencia(const string &Dependencia) const; // Para derivar desde Dependencia

    Dependencia *ObtenerUltimaDependencia() const; // Para las Denuncias Escritas, va directo a la Fiscalía

    inline int GetCodigo() const { return Codigo; }

    inline const Categoria &GetCategoria() const { return CategoriaDelito; }
};

#endif /* DELITO_H_ */
