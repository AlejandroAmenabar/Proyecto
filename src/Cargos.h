#ifndef PROYECTO_CARGOS_H
#define PROYECTO_CARGOS_H

#include <string>

namespace Cargos {

    enum class Cargo {
        Cadete,
        General,
        Administrativo,
        Comisario,
        Tecnico
    };

    static std::string ToString (const Cargo& cargo) {
        std::string Salida;

        switch (cargo) {
            case Cargo::Cadete:
                Salida = "Cadete";
                break;
            case Cargo::General:
                Salida = "General";
                break;
            case Cargo::Administrativo:
                Salida = "Administrativo";
                break;
            case Cargo::Comisario:
                Salida = "Comisario";
                break;
            case Cargo::Tecnico:
                Salida = "Tecnico";
                break;
            default:
                Salida = "Desconocido";
                break;
        }

        return Salida;
    }
}

#endif //PROYECTO_CARGOS_H
