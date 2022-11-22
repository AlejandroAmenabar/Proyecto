#include <string>
#include <algorithm>
#include "Delito.h"
#include "Dependencia.h"

Dependencia *Delito::ObtenerSiguienteDependencia(const string &nombre) const {
    for (auto i = 0; i < Dependencias.size(); i++) {
        if (Dependencias[i]->GetNombre() == nombre) {
            return Dependencias[i + 1];
        }
    }

    return nullptr;
}

Dependencia *Delito::ObtenerUltimaDependencia() const{
    return Dependencias.back();
}

void Delito::MostrarInformacion() const {
    cout << "-- Delito --\n";
    cout << "Codigo: " << Codigo << '\n';
    cout << "Categoria: " << Categorias::ToString(CategoriaDelito) << '\n';

    for (auto i = 0; i < Dependencias.size(); i++){
        cout << "Dependencia " << i << ": " << Dependencias[i]->GetNombre() << '\n';
    }
}

Dependencia *Delito::ObtenerPrimeraDependencia() const {
    return Dependencias.front();
}


