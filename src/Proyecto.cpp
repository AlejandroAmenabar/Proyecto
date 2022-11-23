#include <iostream>
#include <vector>
#include "Delito.h"
#include "Preambulo.h"
#include "Comisaria.h"
#include "Dependencia.h"
#include "Sistema.h"
#include "Persona.h"
#include "Oficial.h"

void CrearPersona(Persona *&NuevaPersona);

void CrearOficial(Oficial *&NuevoOficial);

using namespace std;

int main() {
    bool EstaActivo = true;

#pragma region Inicialización de Depencencias

    vector<Persona *> Personas;
    vector<Oficial *> Oficiales;

    Fecha FechaActual;

    Sistema Tucuman{234, "Tucumán"};

    Dependencia Fiscalia{0, "Fiscalia"};
    Dependencia Criminalistica{1, "Criminalistica"};
    Dependencia Fraude{2, "Fraude"};
    Dependencia Drogas{3, "Drogas"};

    vector<Dependencia *> DependenciaSexuales{&Criminalistica, &Fraude, &Fiscalia};
    Delito Sexual{0, Categorias::Categoria::DelitosSexuales, DependenciaSexuales};


#pragma endregion

#pragma region Ejecucion del Sistema

    while (EstaActivo) {
        cout << "---- Sistema Comisarias de Tucumán ----\n";
        cout << "0. Registrar nueva comisara\n";
        cout << "2. Registrar Oficial\n";
        cout << "1. Registrar Demandado\n";
        cout << "3. Registrar Denuncia\n";
        cout << "4. Mostrar Denuncias registradas por fecha\n";
        cout << "4. Mostrar Comisarias\n";
        cout << "5. Realizar Denuncia\n";
        cout << "6. Buscar Persona por DNI\n";
        cout << "7. Salir del sistema\n";

        int OpcionIngresada;
        cin >> OpcionIngresada;

        switch (OpcionIngresada) {
            case 0: {
                string Direccion;
                cout << "Ingrese la dirección de la nueva comisaria\n";
                cin >> Direccion;
                Tucuman.AgregarComisaria(Direccion);
                break;
            }
            case 1:{

                break;
            }
            case 8: {
                Persona *NuevaPersona = nullptr;
                CrearPersona(NuevaPersona);
                Personas.emplace_back(NuevaPersona);
                break;
            }
            case 2: {
                int CodigoComisaria;
                Oficial *NuevoOficial = nullptr;
                CrearOficial(NuevoOficial);
                Oficiales.emplace_back(NuevoOficial);

                Tucuman.MostrarComisarias();
                cout << "Ingrese el codigo de la comisaria donde desea registrar el oficial\n";
                cin >> CodigoComisaria;
                Tucuman.AgregarOficialAComisaria(CodigoComisaria, NuevoOficial);
                break;
            }
            case 4: {
                Fecha Fecha;
                cout << "Ingrese la fecha de las denuncias que desea buscar\n";
                cin >> Fecha;
                Tucuman.MostrarDenuncias(Fecha);
                break;
            }
            case 5:
                Tucuman.MostrarComisarias();
                break;
            case 6:
                int Dni;
                cout << "Ingrese el dni de la persona que desea buscar\n";
                cin >> Dni;
                Tucuman.MostrarPersona(Dni);
                break;
            default:
                EstaActivo = false;
                break;
        }
    }

#pragma endregion

#pragma region Limpieza Sistema

    for (const auto &Persona: Personas) {
        delete Persona;
    }

#pragma endregion

    return 0;
}

void CrearPersona(Persona *&NuevaPersona) {
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

void CrearOficial(Oficial *&NuevoOficial) {
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

    NuevoOficial = new Oficial(Dni, Nombre, FechaNacimiento, Direccion, Sexo, CargoEnum);
}