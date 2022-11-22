#include <iostream>
#include <vector>
#include "Delito.h"
#include "Preambulo.h"
#include "Comisaria.h"
#include "Dependencia.h"
#include "Sistema.h"
#include "Persona.h"
#include "Oficial.h"

void RegistrarPersonaEnSistema(Persona*& NuevaPersona);
void RegistrarOficialEnSistema(Oficial*& NuevoOficial);

using namespace std;

int main() {
    bool EstaActivo = true;

#pragma region Inicialización de Depencencias para el Programa
    /*
     * Creación de Sistema de Tucumán
     */
    Sistema Tucuman{234, "Tucumán"};
    Fecha FechaActual;


    /*
     * Creación de Dependencias a las que se derivarán las Denuncias
     */
    Dependencia Fiscalia{0, "Fiscalia"};
    Dependencia Criminalistica{1, "Criminalistica"};
    Dependencia Fraude{2, "Fraude"};
    Dependencia Drogas{3, "Drogas"};

    /*
     * Creación de vector deDependencias según los Delitos
     */
    vector<Dependencia *> DepedenciasCriminesSexuales{&Criminalistica, &Fraude, &Fiscalia};

    /*
     * Creación de los Delitos
     */
    Delito Sexual{0, Categorias::Categoria::DelitosSexuales, DepedenciasCriminesSexuales};

    /*
     * Vector de Personas, include Demandados y Demandantes (Por ahora)
     * Vector de Oficiales
     */
    vector<Persona*> Personas;
    vector<Oficial*> Oficiales;

#pragma endregion

    while (EstaActivo) {
        cout << "---- Sistema Comisarias de Tucumán ----\n";
        cout << "0. Registrar Demandante\n";
        cout << "1. Registrar Demandado\n";
        cout << "2. Registrar Oficial\n";
        cout << "3. Registrar Denuncia\n";
        cout << "4. Mostrar Denuncias\n";
        cout << "5. Crear Denuncia\n";
        cout << "6. Buscar Persona por id\n";
        cout << "7. Salir del sistema\n";

        int OpcionIngresada;
        cin >> OpcionIngresada;

        switch (OpcionIngresada) {
            /*
             * Crear demandante y demandado es lo mismo, por ahora todo se guarda en un vector Personas.
             * Se podría crear un vector Demandantes y Demandados y guardarlos en su vector correspondiente
             */
            case 0:
            case 1:
                Persona* NuevaPersona;
                RegistrarPersonaEnSistema(NuevaPersona);
                Personas.emplace_back(NuevaPersona);
                break;
            case 2:
                Oficial* NuevoOficial;
                RegistrarOficialEnSistema(NuevoOficial);
                Oficiales.emplace_back(NuevoOficial);
                break;
            case 5:
//                Sistema.Buscarpersona();
                break;
            default:
                EstaActivo = false;
                break;
        }
    }

#pragma region Falta Acomodar
    Persona Demandado(43321142, "ale", FechaActual, "españa 4455", 'M');
    Demandado.MostrarInformacion();

    Persona Demandante(2341234, "mariano", FechaActual, "chile 4455", 'M');
    Demandante.MostrarInformacion();

    Oficial Ector(321423, "Ector Lavo", FechaActual, "rivadavia", 'M', Cargos::Cargo::Cadete);
    Oficial Wereniski(142, "wereniski", FechaActual, "chile", 'F', Cargos::Cargo::Cadete);
    Oficial Luchoni(324, "luchoni", FechaActual, "chile234", 'F', Cargos::Cargo::Cadete);
    Oficial obstrichy(324, "obstrychi", FechaActual, "asdklfjñas", 'F', Cargos::Cargo::Cadete);

    vector<Oficial *> Oficiales1{&Ector, &Wereniski, &Luchoni, &obstrichy};
    vector<Oficial *> Oficiales2{&Wereniski, &Luchoni, &obstrichy};
    vector<Oficial *> Oficiales3{&Luchoni, &obstrichy};

    Tucuman.AgregarComisaria("Alberdi", Oficiales1);
    Tucuman.AgregarComisaria("Las Talitas", Oficiales2);
    Tucuman.AgregarComisaria("Alderetes", Oficiales3);
    Tucuman.RealizarDenuncia(&Sexual, &Demandado, &Demandante, &Ector);
    Tucuman.GetComisarias()[0]->DerivarDenuncia();
    Criminalistica.DerivarDenuncia();
#pragma endregion

#pragma region Limpieza Sistema

    for(const auto& Persona : Personas){
        delete Persona;
    }

#pragma endregion

    return 0;
}

void RegistrarPersonaEnSistema(Persona*& NuevaPersona){
    int Dni;
    string Nombre;
    Fecha FechaNacimiento;
    string Direccion;
    char Sexo;

    cout << "Ingrese el DNI de la persona\n";
    cin >> Dni;

    cout << "Ingres el nombre\n";
    cin >> Nombre;

    cout << "Ingrese la direccion\n";
    cin >> Direccion;

    cout << "Ingres el sexo (F - Femenino, M - Masculino)\n";
    cin >> Sexo;

    NuevaPersona = new Persona(Dni, Nombre, FechaNacimiento, Direccion, Sexo);
}

void RegistrarOficialEnSistema(Oficial*& NuevoOficial){
    int Dni;
    string Nombre;
    Fecha FechaNacimiento;
    string Direccion;
    char Sexo;
    int CargoEntero;

    cout << "Ingrese el DNI de la persona\n";
    cin >> Dni;

    cout << "Ingres el nombre\n";
    cin >> Nombre;

    cout << "Ingrese la direccion\n";
    cin >> Direccion;

    cout << "Ingres el sexo (F - Femenino, M - Masculino)\n";
    cin >> Sexo;

    cout << "Ingrese el cargo\n";
    Cargos::MostrarCargos();
    cin >> CargoEntero;
    auto CargoEnum = (Cargos::Cargo) CargoEntero;

    NuevoOficial= new Oficial(Dni, Nombre, FechaNacimiento, Direccion, Sexo, CargoEnum);
}