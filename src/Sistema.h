#ifndef PROYECTO_SISTEMA_H
#define PROYECTO_SISTEMA_H

#include <string>
#include <vector>
#include "Fecha.h"

class Comisaria;
class Denuncia;

using namespace std;

class Sistema {

    int Codigo;

    string Nombre;

    vector<Comisaria> Comisarias;

    vector<Denuncia*> Denuncias;

public:

    void MostrarDenuncias(cosnt Fecha& fecha) const;

    void MostrarComisarias() const;

    void MostrarPersona(int dni) const;
};


#endif //PROYECTO_SISTEMA_H
