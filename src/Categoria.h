#ifndef PROYECTO_CATEGORIA_H
#define PROYECTO_CATEGORIA_H

namespace Categorias{

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

    static const char* ToString(const Categoria& categoria){
        switch (categoria){
            case Categoria::DelitosSexuales: return "Delitos Sexuales";
            case Categoria::Criminales: return "Criminales";
            case Categoria::OrdenPublico: return "Orden Publico";
            case Categoria::Homicidio: return "Homicidio";
            case Categoria::Femicidio: return "Feimicidio";
            case Categoria::DIGEDROP: return "DIGEDROP";
            case Categoria::Robo: return "Robo";
            case Categoria::Violencia: return "Violencia";
            default: return "Desconocido";
        }
    }
}
#endif //PROYECTO_CATEGORIA_H
