#include <iostream>
#include <vector>
#include "Comisaria.h"
#include "Delito.h"
#include "Dependencia.h"
#include "Oficial.h"
#include "Persona.h"
#include "Sistema.h"

InformacionDenuncia RegistrarInformacionDenuncia();

void CrearPersona(Persona *&NuevaPersona);

void CrearOficial(Oficial *&NuevoOficial);

void MostrarPersonas(const vector<Persona *> &Personas);

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
        cout << "0. Registrar nueva Comisara en el Sistema\n";
        cout << "1. Registrar nuevo Oficial en el Sistema\n";
        cout << "2. Registrar nueva Persona en el Sistema\n";
        cout << "3. Registrar nueva Denuncia en el Sistema\n";
        cout << "4. Mostrar Denuncias registradas por fecha\n";
        cout << "5. Mostrar todas las Comisarias del Sistema\n";
        cout << "7. Buscar Persona por DNI en el Sistema\n";
        cout << "7. Salir del Sistema\n";

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
            case 1: {
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
            case 2: {
                Persona *NuevaPersona = nullptr;
                CrearPersona(NuevaPersona);
                Personas.emplace_back(NuevaPersona);
                break;
            }
            case 3: {
                if (Personas.size() < 2) {
                    cout << "Deben haber por lo menos dos (2) Personas registradas para poder realizar Denuncias\n";
                } else {
                    int CodigoDemandado;
                    int CodigoDemandante;
                    MostrarPersonas(Personas);

                    cout << "Ingrese el codigo del demandado\n";
                    cin >> CodigoDemandado;

                    cout << "Ingrese el codigo del demandante\n";
                    cin >> CodigoDemandado;
                }
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

void MostrarPersonas(const vector<Persona *> &Personas) {
    for (const auto &Persona: Personas) {
        Persona->MostrarInformacion();
    }
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

InformacionDenuncia RegistrarInformacionDenuncia() {
    int CodigoComisaria;
    cout << "Ingrese la comisaria(0- Alberdi, 1 - Las Talitas, 2 - Alderetes)\n";
    cin >> CodigoComisaria;

    int TipoDenuncia;
    cout << "Oral o escrita (0 - oral, 1 - escrita)\n";
    cin >> TipoDenuncia;

    string Documentacion;
    cout << "Ingrese la documentacion\n";
    cin >> Documentacion;

    string DireccionDelito;
    cout << "Ingrese donde se cometio el delito\n";
    cin >> DireccionDelito;

    string Adicional;

    if (TipoDenuncia) {
        cout << "-- Denuncia Escrita --\n";
        cout << "Ingrese el archivo\n";
        cin >> Adicional;
    } else {
        cout << "-- Denuncia Oral --\n";
        cout << "Ingrese la descripcion\n";
        cin >> Adicional;
    }

    return InformacionDenuncia(CodigoComisaria, TipoDenuncia, Documentacion, DireccionDelito, Adicional);
}