#include "Dependencia.h"
#include "Denuncia.h"
#include "Oficial.h"

void Dependencia::MostrarInformacion() const {
    cout << "-- Dependencia --\n";
    cout << "Codigo:" << Codigo << '\n';
    cout << "Nombre: " << Nombre << '\n';
}

void Dependencia::DerivarDenuncia() {
//    string Investigacion;
//    cout << "Ingrese la investigacion: \n";
//    cin >> Investigacion;

    // TODO crear registro antes

//    Denuncias.back()->AgregarInvestigacion(Investigacion);
    Denuncias.back()->Derivar(Fecha{});
    Denuncias.pop_back();
}

void Dependencia::AgregarDenuncia(Denuncia *denuncia) {
    Denuncias.emplace_back(denuncia);
}
