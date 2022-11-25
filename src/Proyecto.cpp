#include <iostream>
#include "IExposicion.h"
#include <vector>
#include "Comisaria.h"
#include "Delito.h"
#include "Dependencia.h"
#include "Oficial.h"
#include "Persona.h"
#include "Sistema.h"

using namespace Cargos;

void RegistrarDenunciaEnSistema(Sistema &sistema, const vector<IExposicion *> &delitos,
                                const vector<IExposicion *> &personas, const vector<IExposicion *> &oficiales);

void BuscarPersonaPorDniEnSistema(const Sistema &sistema);

void RegistrarOficialEnSistema(Sistema &sistema, Oficial *&NuevoOficial);

InformacionDenuncia CrearInformacionDenuncia();

void MostrarVector(const vector<IExposicion *> &objetos);

void CrearPersona(Persona *&NuevaPersona);

using namespace std;

void RegistrarComisariaEnSistema(Sistema &sistema);

int main() {
    bool EstaActivo = true;

#pragma region Inicialización de Depencencias

    vector<IExposicion *> Personas;
    vector<IExposicion *> Oficiales;
    vector<IExposicion *> Delitos;

    Fecha FechaActual;

    Sistema Tucuman{234, "Tucumán"};

    Dependencia Fiscalia{0, "Fiscalia"};
    Dependencia Criminalistica{1, "Criminalistica"};
    Dependencia Fraude{2, "Fraude"};
    Dependencia Drogas{3, "Drogas"};

    vector<Dependencia *> DependenciaSexuales{&Criminalistica, &Fraude, &Fiscalia};
    Delito Sexual{0, Categorias::Categoria::DelitosSexuales, DependenciaSexuales};
    Delitos.emplace_back(&Sexual);

#pragma endregion

#pragma region Ejecucion del Sistema

    while (EstaActivo) {
        cout << "\n---- Sistema Comisarias de Tucuman ----\n";
        cout << "0. Registrar nueva Comisara en el Sistema\n";
        cout << "1. Registrar nuevo Oficial en el Sistema\n";
        cout << "2. Registrar nueva Persona en el Sistema\n";
        cout << "3. Registrar nueva Denuncia en el Sistema\n";
        cout << "4. Mostrar Denuncias registradas por fecha\n";
        cout << "5. Mostrar todas las Comisarias del Sistema\n";
        cout << "6. Mostrar todas las Personas del Sistema\n";
        cout << "7. Buscar Persona por DNI en el Sistema\n";
        cout << "8. Salir del Sistema\n";

        int Opcion;
        cin >> Opcion;

        switch (Opcion) {
            case 0:
                RegistrarComisariaEnSistema(Tucuman);
                break;
            case 1: {
                Oficial *NuevoOficial = nullptr;
                RegistrarOficialEnSistema(Tucuman, NuevoOficial);
                Oficiales.emplace_back(NuevoOficial);
                break;
            }
            case 2: {
                Persona *NuevaPersona = nullptr;
                CrearPersona(NuevaPersona);
                Personas.emplace_back(NuevaPersona);
                break;
            }
            case 3:
                RegistrarDenunciaEnSistema(Tucuman, Delitos, Personas, Oficiales);
                break;
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
                MostrarVector(Personas);
                break;
            case 7:
                BuscarPersonaPorDniEnSistema(Tucuman);
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

    for (const auto &Oficial: Oficiales) {
        delete Oficial;
    }

#pragma endregion

    return 0;
}

void RegistrarComisariaEnSistema(Sistema &sistema) {
    string Direccion;
    cout << "Ingrese la direccion de la nueva comisaria\n";
    getline(cin, Direccion);
    sistema.AgregarComisaria(Direccion);
}

void BuscarPersonaPorDniEnSistema(const Sistema &sistema) {

    int Dni;
    cout << "Ingrese el dni de la persona que desea buscar\n";
    cin >> Dni;
    sistema.MostrarPersona(Dni);
}

void RegistrarDenunciaEnSistema(Sistema &sistema, const vector<IExposicion *> &delitos,
                                const vector<IExposicion *> &personas, const vector<IExposicion *> &oficiales) {
    if (personas.size() < 2) {
        cout << "Deben haber por lo menos dos (2) Personas registradas para poder realizar Denuncias\n";
        return;
    }

    if (oficiales.empty()) {
        cout << "Debe haber por lo menos un (1) Oficial registrado para poder realizar Denuncias\n";
        return;
    }

    if (!sistema.ExistenComisarias()) {
        cout << "Debe haber por lo menos una (1) Comisaria registrado para poder realizar Denuncias\n";
        return;
    }

    int CodigoDemandado;
    int CodigoDemandante;
    int CodigoOficial;
    int CodigoDelito;

    MostrarVector(personas);

    cout << "Ingrese el codigo del demandado\n";
    cin >> CodigoDemandado;

    cout << "Ingrese el codigo del demandante\n";
    cin >> CodigoDemandante;

    MostrarVector(oficiales);

    cout << "Ingrese el codigo del oficial a cargo\n";
    cin >> CodigoOficial;

    MostrarVector(delitos);

    cout << "Ingrese el codigo del delito cometido\n";
    cin >> CodigoDelito;

    Delito *DelitoSeleccionado = dynamic_cast<Delito *>(delitos[CodigoDelito]);
    Persona *Demandante = dynamic_cast<Persona *>(personas[CodigoDemandante]);
    Persona *Demandado = dynamic_cast<Persona *>(personas[CodigoDemandado]);
    Oficial *OficialACargo = dynamic_cast<Oficial *>(oficiales[CodigoOficial]);

    InformacionDenuncia NuevaInformacion = CrearInformacionDenuncia();
    sistema.RealizarDenuncia(NuevaInformacion, DelitoSeleccionado, Demandado, Demandante,
                             OficialACargo);
}

void MostrarVector(const vector<IExposicion *> &objetos) {
    for (const auto &Objeto: objetos) {
        Objeto->MostrarInformacion();
        cout << '\n';
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
    getline(cin, Nombre);

    cout << "Ingrese la direccion\n";
    getline(cin, Direccion);

    cout << "Ingres el sexo (F - Femenino, M - Masculino)\n";
    cin >> Sexo;

    NuevaPersona = new Persona(Dni, Nombre, FechaNacimiento, Direccion, Sexo);
}

void RegistrarOficialEnSistema(Sistema &sistema, Oficial *&NuevoOficial) {
    int Dni;
    int CargoEntero;
    int CodigoComisaria;
    char Sexo;
    string Nombre;
    string Direccion;
    Fecha FechaNacimiento;

    sistema.MostrarComisarias();

    cout << "Ingrese el codigo de la comisaria donde desea registrar el oficial\n";
    cin >> CodigoComisaria;

    cout << "Ingrese el DNI de la persona\n";
    cin >> Dni;

    cout << "Ingres el nombre\n";
    getline(cin, Nombre);

    cout << "Ingrese la direccion\n";
    getline(cin, Direccion);

    cout << "Ingres el sexo (F - Femenino, M - Masculino)\n";
    cin >> Sexo;

    cout << "Ingrese el cargo\n";
    MostrarCargos();
    cin >> CargoEntero;
    auto CargoEnum = (Cargo) CargoEntero;

    NuevoOficial = new Oficial(Dni, Nombre, FechaNacimiento, Direccion, Sexo, CargoEnum);
    sistema.AgregarOficialAComisaria(CodigoComisaria, NuevoOficial);
}

InformacionDenuncia CrearInformacionDenuncia() {
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

    return {CodigoComisaria, TipoDenuncia, Documentacion, DireccionDelito, Adicional};
}