#include "Dependencia.h"
#include "Denuncia.h"
#include "Oficial.h"

void Dependencia::MostrarInformacion() const {
    cout << "-- Dependencia --\n";
    Ente::MostrarInformacion();
    cout << "Nombre: " << Nombre << '\n';
//    cout << "Categoria: " <<
}

//void Dependencia::DerivarDenuncia() {
//    string InvestigacionDependencia;
//    cout << "Ingrese la investigacion de la dependencia: \n";
//    cin >> InvestigacionDependencia;
//
//    Denuncias.back()->Derivar(InvestigacionDependencia, Fecha{});
//    Denuncias.pop_back();
//}