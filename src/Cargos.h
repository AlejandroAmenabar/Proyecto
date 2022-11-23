#ifndef PROYECTO_CARGOS_H
#define PROYECTO_CARGOS_H

#include <string>
#include <iostream>

namespace Cargos {

    enum class Cargo {
        Cadete,
        General,
        Administrativo,
        Comisario,
        Tecnico
    };

    static const char* ToString (const Cargo& cargo) {
        switch (cargo) {
            case Cargo::Cadete: return "Cadete";
            case Cargo::General: return "General";
            case Cargo::Administrativo: return "Administrativo";
            case Cargo::Comisario: return "Comisario";
            case Cargo::Tecnico: return "Tecnico";
            default: return "Desconocido";
        }
    }

    static void MostrarCargos(){
        std::cout << "Cadete (0) - General(1) - Administrativo(2) - Comisario(3) - Tecnico(4)\n";
    }
}

#endif //PROYECTO_CARGOS_H
