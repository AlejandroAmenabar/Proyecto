#include <iostream>
#include <vector>
#include "Delito.h"
#include "Preambulo.h"
#include "Comisaria.h"
#include "Dependencia.h"
#include "Sistema.h"
#include "Persona.h"
#include "Oficial.h"

using namespace std;

int main() {
    bool EstaActivo = true;

    /*
     * Creación de Sistema de Tucumán
     */
#pragma region Sistema
    Sistema Tucuman{234, "Tucumán"};
    Fecha FechaActual;

#pragma endregion Sistema

    /*
     * Creación de Dependencias a las que se derivarán las Denuncias
     */
#pragma region Dependencias
    Dependencia Fiscalia{0, "Fiscalia"};
    Dependencia Criminalistica{1, "Criminalistica"};
    Dependencia Fraude{2, "Fraude"};
    Dependencia Drogas{3, "Drogas"};
#pragma endregion Dependencias

    /*
     * Creación de vector deDependencias según los Delitos
     */
#pragma region Vector de Depencencias
    vector<Dependencia *> DepedenciasCriminesSexuales{&Criminalistica, &Fraude, &Fiscalia};
#pragma endregion Vector de Dependencias

    /*
     * Creación de los Delitos
     */
#pragma region Delitos
    Delito Sexual{0, Categoria::DelitosSexuales, DepedenciasCriminesSexuales};
#pragma endregion Delitos

    while (EstaActivo) {
        cout << "---- Sistema Comisarias de Tucumán ----\n";
        cout << "0. Registrar Demandante\n";
        cout << "1. Registrar Demandado\n";
        cout << "1. Crear Denuncia\n";
        cout << "2. Mostrar Denuncias\n";
        cout << "3. Crear Oficial\n";
        cout << "4. Crear Denuncia\n";
        cout << "5. Buscar Persona por id\n";
        cout << "?. Salir del sistema\n";

        int OpcionIngresada;
        cin >> OpcionIngresada;

        switch (OpcionIngresada) {
            case 0:
                break;
            case 1:
                break;
            case 2:
                break;
            case 5:
//                Sistema.Buscarpersona();
                break;
            default:
                EstaActivo = false;
                break;
        }
    }


    Persona Demandado(43321142, "ale", FechaActual, "españa 4455", 'M');
    Demandado.MostrarInformacion();

    Persona Demandante(2341234, "mariano", FechaActual, "chile 4455", 'M');
    Demandante.MostrarInformacion();

    Oficial Ector(321423, "Ector Lavo", FechaActual, "rivadavia", 'M', Cargo::Cadete);
    Oficial Wereniski(142, "wereniski", FechaActual, "chile", 'F', Cargo::Cadete);
    Oficial Luchoni(324, "luchoni", FechaActual, "chile234", 'F', Cargo::Cadete);
    Oficial obstrichy(324, "obstrychi", FechaActual, "asdklfjñas", 'F', Cargo::Cadete);

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
