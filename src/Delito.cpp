#include <string>
#include <algorithm>
#include "Delito.h"
#include "Dependencia.h"

Dependencia *Delito::ObtenerSiguienteDependencia(const string &nombre) {
    return *(std::find_if(Dependencias.begin(), Dependencias.end(),
                          [&nombre](const auto Dependencia) { return Dependencia->GetNombre() == nombre; }));
//    for (auto i = 0; i < Dependencias.size(); i++) {
//        if (Dependencias[i]->GetNombre() == nombre) {
//            return Dependencias[i + 1];
//        }
//    }
//
//    return nullptr;
}

Dependencia *Delito::ObtenerUltimaDependencia() {
    return Dependencias.back();
}

void Delito::MostrarInformacion() const {
    cout << "-- Delito --\n";
    cout << "Codigo: " << Codigo << '\n';
    cout << "Categoria: " << Categorias[CategoriaDelito] << '\n';

    for(const auto& Dependencia : Dependencias){
        Dependencia->MostrarInformacion();
    }
}


