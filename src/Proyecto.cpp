#include <iostream>
#include <vector>
#include "Delito.h"
#include "Preambulo.h"
#include "Comisaria.h"
#include "Dependencia.h"
#include "Registro.h"
#include "Sistema.h"
#include "Persona.h"
#include "Oficial.h"

using namespace std;

int main() {
    bool EstaActivo = true;

//    while(EstaActivo){
//        cout << "---- Sistema Comisaría ----\n";
//        cout << "1. Crear Denuncia\n";
//        cout << "2. Mostrar Denuncias\n";
//        cout << "3. Crear Oficial\n";
//        cout << "4. Crear Denuncia\n";
//        cout << "5. Buscar Persona por id\n";
//        cout << "?. Salir del sistema\n";
//
//        int OpcionIngresada;
//        cin >> OpcionIngresada;
//
//        switch (OpcionIngresada){
//            case 0:
//                break;
//            case 1:
//                break;
//            case 2:
//                break;
//            case 5:
////                Sistema.Buscarpersona();
//                break;
//            default:
//                EstaActivo = false;
//                break;
//        }
//    }

    Sistema Tucuman{234, "Tucumán"};
    Fecha F;

    Dependencia Fiscalia {0, "Fiscalia"};
    Dependencia Criminalistica {1, "Criminalistica"};
    Dependencia Fraude {2, "Fraude"};
    Dependencia Drogas {3, "Drogas"};

    vector<Dependencia*> DepedenciasCriminesSexuales {&Criminalistica, &Fraude, &Fiscalia};
    Delito Sexual {0, Categoria::DelitosSexuales, DepedenciasCriminesSexuales};
//    std::cout << Sexual.ObtenerPrimeraDependencia()->GetNombre() << '\n';

    Persona Demandado(43321142, "ale", F, "españa 4455", 'M');
    Demandado.MostrarInfo();

    Persona Demandante(2341234, "mariano", F, "chile 4455", 'M');
    Demandante.MostrarInfo();

    Oficial Ector(321423, "Ector Lavo", F, "rivadavia", 'M', Cargo::Cadete);
    Oficial Wereniski(142, "wereniski", F, "chile", 'F', Cargo::Cadete);
    Oficial Luchoni(324, "luchoni", F, "chile234", 'F', Cargo::Cadete);
    Oficial obstrichy(324, "obstrychi", F, "asdklfjñas", 'F', Cargo::Cadete);

    vector<Oficial *> Oficiales1{&Ector, &Wereniski, &Luchoni, &obstrichy};
    vector<Oficial *> Oficiales2{&Wereniski, &Luchoni, &obstrichy};
    vector<Oficial *> Oficiales3{&Luchoni, &obstrichy};

    Tucuman.AgregarComisaria("Alberdi", Oficiales1);
    Tucuman.AgregarComisaria("Las Talitas", Oficiales2);
    Tucuman.AgregarComisaria("Alderetes", Oficiales3);
    Tucuman.RealizarDenuncia(&Sexual, &Demandado, &Demandante, &Ector);
    Tucuman.GetComisarias()[0]->DerivarDenuncia();
    Criminalistica.DerivarDenuncia();
    return 0;
}
