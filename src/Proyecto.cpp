#include <iostream>
#include <algorithm>
#include <vector>
#include "IExposicion.h"
#include "Comisaria.h"
#include "Delito.h"
#include "Denuncia.h"
#include "DenunciaOral.h"
#include "DenunciaEscrita.h"
#include "Dependencia.h"
#include "Oficial.h"
#include "Persona.h"
#include "Preambulo.h"

using namespace Cargos;
using namespace std;

void RegistrarComisariaEnSistema(vector<Comisaria *> &comisarias);

void RegistrarOficialEnSistema(vector<Comisaria *> &comisarias, vector<Oficial *> &oficiales);

void RegistrarPersonaEnSistema(vector<Persona *> &personas);

void RegistrarDenunciaEnSistema(const vector<Delito *> &delitos, const vector<Persona *> &personas,
                                const vector<Oficial *> &oficiales, const vector<Comisaria *> &comisarias,
                                vector<Denuncia *> &denuncias);

void MostrarDenunciasPorFecha(const vector<Denuncia *> &denuncias);

void MostrarDenunciasPorPersona(const vector<Persona *> &personas, const vector<Denuncia *> &denuncias);

void MostrarVector(const vector<IExposicion *> &objetos);

void BuscarPersonaPorDniEnSistema(const vector<Persona *> &personas);

void DerivarUltimaDenunciaEnComisaria(const vector<Comisaria *> &comisarias);

void DerivarUltimaDenunciaEnDependencia(const vector<Dependencia *> &dependencias);

InformacionDenuncia CrearInformacionDenuncia();

IExposicion *BuscarPorCodigo(int codigo, vector<IExposicion *> &vector);

int main() {
    bool EstaActivo = true;

#pragma region Inicialización de Dependencias

    Dependencia Fiscalia{"Fiscalia"};
    Dependencia Criminalistica{"Criminalistica"};
    Dependencia Fraude{"Fraude"};
    Dependencia Drogas{"Drogas"};

    vector<Denuncia *> Denuncias;
    vector<Comisaria *> Comisarias;
    vector<Persona *> Personas;
    vector<Oficial *> Oficiales;
    vector<Delito *> Delitos;
    vector<Dependencia *> Dependencias{&Fiscalia, &Criminalistica, &Fraude, &Drogas};

    Fecha FechaActual;

    vector<Dependencia *> DependenciaSexuales{&Criminalistica, &Fiscalia};
    vector<Dependencia *> DependenciaFraudes{&Fraude, &Fiscalia};

    Delito Sexual{0, Categorias::Categoria::DelitosSexuales, DependenciaSexuales};
    Delito Comercial{1, Categorias::Categoria::Robo, DependenciaSexuales};
    Delitos.emplace_back(&Sexual);
    Delitos.emplace_back(&Comercial);

#pragma endregion

#pragma region Ejecucion del Sistema

    while (EstaActivo) {
        cout << "\n---- Sistema Comisarias de Tucuman ----\n";
        cout << "0. Registrar nueva Comisara en el Sistema\n";
        cout << "1. Registrar nuevo Oficial en el Sistema\n";
        cout << "2. Registrar nueva Persona en el Sistema\n";
        cout << "3. Registrar nueva Denuncia en el Sistema\n";
        cout << "4. Mostrar Denuncias registradas por fecha\n";
        cout << "5. Mostrar las Denuncias de cierta Persona\n";
        cout << "6. Mostrar todas las Denuncias registradas del Sistema\n";
        cout << "7. Mostrar todas las Comisarias del Sistema\n";
        cout << "8. Mostrar todas las Personas del Sistema\n";
        cout << "9. Mostrar todas los Oficiales del Sistema\n";
        cout << "10. Buscar Persona por DNI en el Sistema\n";
        cout << "11. Derivar Denuncias en Comisarias\n";
        cout << "12. Derivar Denuncias en Dependencias\n";
        cout << "13. Salir del Sistema\n";

        int OpcionSeleccionada;
        cin >> OpcionSeleccionada;

        switch (OpcionSeleccionada) {
            case 0:
                RegistrarComisariaEnSistema(Comisarias);
                break;
            case 1:
                RegistrarOficialEnSistema(Comisarias, Oficiales);
                break;
            case 2:
                RegistrarPersonaEnSistema(Personas);
                break;
            case 3:
                RegistrarDenunciaEnSistema(Delitos, Personas, Oficiales, Comisarias, Denuncias);
                break;
            case 4:
                MostrarDenunciasPorFecha(Denuncias);
                break;
            case 5: {
                MostrarDenunciasPorPersona(Personas, Denuncias);
                break;
            }
            case 6: {
                vector<IExposicion *> IDenuncias(Denuncias.begin(), Denuncias.end());
                MostrarVector(IDenuncias);
                break;
            }
            case 7: {
                vector<IExposicion *> IComisarias(Comisarias.begin(), Comisarias.end());
                MostrarVector(IComisarias);
                break;
            }
            case 8: {
                vector<IExposicion *> IPersonas(Personas.begin(), Personas.end());
                MostrarVector(IPersonas);
                break;
            }
            case 9: {
                vector<IExposicion *> IOficiales(Oficiales.begin(), Oficiales.end());
                MostrarVector(IOficiales);
                break;
            }
            case 10:
                BuscarPersonaPorDniEnSistema(Personas);
                break;
            case 11:
                DerivarUltimaDenunciaEnComisaria(Comisarias);
                break;
            case 12:
                DerivarUltimaDenunciaEnDependencia(Dependencias);
                break;
            default:
                EstaActivo = false;
                break;
        }
    }

#pragma endregion

#pragma region Limpieza del Sistema

    for (const auto &Comisaria: Comisarias) {
        delete Comisaria;
    }

    for (const auto &Persona: Personas) {
        delete Persona;
    }

    for (const auto &Oficial: Oficiales) {
        delete Oficial;
    }

    for (const auto &Denuncia: Denuncias) {
        delete Denuncia;
    }

    for (const auto &Delito: Delitos) {
        delete Delito;
    }

#pragma endregion

    return 0;
}

void RegistrarComisariaEnSistema(vector<Comisaria *> &comisarias) {
    string Direccion;
    cout << "Ingrese la direccion de la nueva comisaria\n";
    cin.ignore();
    getline(cin, Direccion, '\n');

    Comisaria *NuevaComisaria = new Comisaria(Direccion);
    comisarias.emplace_back(NuevaComisaria);
}

void RegistrarOficialEnSistema(vector<Comisaria *> &comisarias, vector<Oficial *> &oficiales) {

    if (comisarias.empty()) {
        return;
    }

    int Dni;
    int CargoEntero;
    int CodigoComisaria;
    char Sexo;
    string Nombre;
    string Direccion;
    Fecha FechaNacimiento;

    vector<IExposicion *> IComisarias(comisarias.begin(), comisarias.end());
    MostrarVector(IComisarias);

    cout << "Ingrese el codigo de la comisaria donde desea registrar el oficial\n";
    cin >> CodigoComisaria;

    cout << "Ingrese el DNI de la persona\n";
    cin >> Dni;

    cout << "Ingrese el nombre\n";
    cin.ignore();
    getline(cin, Nombre);

    cout << "Ingrese la direccion\n";
    cin.ignore();
    getline(cin, Direccion);

    cout << "Ingrese el sexo (F - Femenino, M - Masculino)\n";
    cin >> Sexo;

    cout << "Ingrese el cargo\n";
    MostrarCargos();
    cin >> CargoEntero;
    auto CargoEnum = (Cargo) CargoEntero;

    if (Comisaria *ComisariaSeleccionada = dynamic_cast<Comisaria *>(BuscarPorCodigo(CodigoComisaria, IComisarias))) {
        Oficial *NuevoOficial = new Oficial(Dni, Nombre, FechaNacimiento, Direccion, Sexo, CargoEnum);
        ComisariaSeleccionada->AgregarOficial(NuevoOficial);
        oficiales.emplace_back(NuevoOficial);
    } else {
        cout << "No se encontró una comisaria con el codigo introducido\n";
    }
}

void RegistrarPersonaEnSistema(vector<Persona *> &personas) {
    int Dni;
    string Nombre;
    Fecha FechaNacimiento;
    string Direccion;
    char Sexo;

    cout << "Ingrese el DNI de la persona\n";
    cin >> Dni;

    cout << "Ingres el nombre\n";
    cin.ignore();
    getline(cin, Nombre);

    cout << "Ingrese la direccion\n";
    cin.ignore();
    getline(cin, Direccion);

    cout << "Ingres el sexo (F - Femenino, M - Masculino)\n";
    cin >> Sexo;

    Persona *NuevaPersona = new Persona(Dni, Nombre, FechaNacimiento, Direccion, Sexo);
    personas.emplace_back(NuevaPersona);
}

void RegistrarDenunciaEnSistema(const vector<Delito *> &delitos, const vector<Persona *> &personas,
                                const vector<Oficial *> &oficiales, const vector<Comisaria *> &comisarias,
                                vector<Denuncia *> &denuncias) {
    /*
     * Realiza los controles que hayan suficientes elementos para poder crear una nueva denuncia
     */
    if (personas.size() < 2) {
        cout << "Deben haber por lo menos dos (2) Personas registradas para poder realizar Denuncias\n";
        return;
    }

    if (oficiales.empty()) {
        cout << "Debe haber por lo menos un (1) Oficial registrado para poder realizar Denuncias\n";
        return;
    }

    if (comisarias.empty()) {
        cout << "Debe haber por lo menos una (1) Comisaria registrado para poder realizar Denuncias\n";
        return;
    }

    int CodigoDemandado;
    int CodigoDemandante;
    int CodigoOficial;
    int CodigoDelito;
    int CodigoComisaria;

    /*
     * Pide al usuario ingresar los códigos del demandado, demandante, oficial y delito
     */
    vector<IExposicion *> IPersonas(personas.begin(), personas.end());
    MostrarVector(IPersonas);
    cout << "Ingrese el codigo del demandado\n";
    cin >> CodigoDemandado;
    cout << "Ingrese el codigo del demandante\n";
    cin >> CodigoDemandante;

    vector<IExposicion *> IOficiales(oficiales.begin(), oficiales.end());
    MostrarVector(IOficiales);
    cout << "Ingrese el codigo del oficial a cargo\n";
    cin >> CodigoOficial;

    vector<IExposicion *> IDelitos(delitos.begin(), delitos.end());
    MostrarVector(IDelitos);
    cout << "Ingrese el codigo del delito cometido\n";
    cin >> CodigoDelito;

    vector<IExposicion *> IComisarias(comisarias.begin(), comisarias.end());
    MostrarVector(IComisarias);
    cout << "Ingrese el codigo de la comisaria\n";
    cin >> CodigoComisaria;

    /*
     * Busca a los objetos de los códigos seleccionados por el usuario en los vectores del sistema
     */
    Comisaria *ComisariaBuscada = dynamic_cast<Comisaria *>(BuscarPorCodigo(CodigoComisaria, IComisarias));
    Delito *DelitoSeleccionado = dynamic_cast<Delito *>(BuscarPorCodigo(CodigoDelito, IDelitos));
    Persona *Demandante = dynamic_cast<Persona *>(BuscarPorCodigo(CodigoDemandante, IPersonas));
    Persona *Demandado = dynamic_cast<Persona *>(BuscarPorCodigo(CodigoDemandado, IPersonas));
    Oficial *OficialACargo = dynamic_cast<Oficial *>(BuscarPorCodigo(CodigoOficial, IOficiales));

    if (!ComisariaBuscada) {
        cout << "No se encontró una comisaria el codigo introducido\n";
        return;
    }

    if (!DelitoSeleccionado) {
        cout << "No se encontró un delito con el codigo introducido\n";
        return;
    }

    if (!Demandante) {
        cout << "No se encontró un demandante con el codigo introducido\n";
        return;
    }

    if (!Demandado) {
        cout << "No se encontró un demandado con el codigo introducido\n";
        return;
    }

    if (!OficialACargo) {
        cout << "No se encontró un oficial con el codigo introducido\n";
        return;
    }

    /*
     * Crea una nueva información para la denuncia
     */
    InformacionDenuncia Informacion = CrearInformacionDenuncia();
    Denuncia *NuevaDenuncia = nullptr;

    if (Informacion.GetTipoDenuncia()) {
        NuevaDenuncia = new DenunciaEscrita(Informacion.GetDocumentacion(), DelitoSeleccionado,
                                            Informacion.GetAdicional());
    } else {
        NuevaDenuncia = new DenunciaOral(Informacion.GetDocumentacion(), DelitoSeleccionado,
                                         Informacion.GetAdicional());
    }

    NuevaDenuncia->AsignarPreambulo(Fecha{}, Informacion.GetDireccionDelito(), OficialACargo, Demandante, Demandado);
    NuevaDenuncia->MostrarInformacion();
    ComisariaBuscada->AgregarDenuncia(NuevaDenuncia);
    denuncias.emplace_back(NuevaDenuncia);
}

void MostrarDenunciasPorFecha(const vector<Denuncia *> &denuncias) {
    Fecha Fecha;
    cout << "Ingrese la fecha de las denuncias que desea buscar\n";
    cin >> Fecha;

    for (const auto &Denuncia: denuncias) {

        if (Denuncia->GetFecha() == Fecha) {
            Denuncia->MostrarInformacion();
        }
    }
}

void MostrarDenunciasPorPersona(const vector<Persona *> &personas, const vector<Denuncia *> &denuncias) {
    vector<IExposicion *> IPersonas(personas.begin(), personas.end());
    MostrarVector(IPersonas);

    int CodigoPersona;
    cout << "Ingrese el código de la persona de la cual desea buscar las denuncias\n";
    cin >> CodigoPersona;

    for (const auto &Denuncia: denuncias) {

        if (Denuncia->BuscarPersona(CodigoPersona)) {
            Denuncia->MostrarInformacion();
        }
    }
}

void MostrarVector(const vector<IExposicion *> &objetos) {
    for (const auto &Objeto: objetos) {
        Objeto->MostrarInformacion();
        cout << '\n';
    }
}

void BuscarPersonaPorDniEnSistema(const vector<Persona *> &personas) {
    int Dni;
    cout << "Ingrese el dni de la persona que desea buscar\n";
    cin >> Dni;

    for (const auto &Persona: personas) {
        if (Persona->GetDni() == Dni) {
            Persona->MostrarInformacion();
            break;
        }
    }
}

void DerivarUltimaDenunciaEnComisaria(const vector<Comisaria *> &comisarias) {
    int CodigoComisaria;

    vector<IExposicion *> IComisarias(comisarias.begin(), comisarias.end());
    MostrarVector(IComisarias);

    cout << "Ingrese el codigo de la comisaria donde desea derivar la denuncia\n";
    cin >> CodigoComisaria;

    Comisaria *ComisariaBuscada = dynamic_cast<Comisaria *>(BuscarPorCodigo(CodigoComisaria, IComisarias));

    if (!ComisariaBuscada) {
        cout << "No se encontró una comisaria con el codigo introducido\n";
        return;
    }

    ComisariaBuscada->DerivarDenuncia();
}

void DerivarUltimaDenunciaEnDependencia(const vector<Dependencia *> &dependencias) {
    int CodigoDependencia;

    vector<IExposicion *> IDependencias(dependencias.begin(), dependencias.end());
    MostrarVector(IDependencias);

    cout << "Ingrese el codigo de la dependnecia donde desea derivar la denuncia\n";
    cin >> CodigoDependencia;

    Dependencia *DependenciaBuscada = dynamic_cast<Dependencia *>(BuscarPorCodigo(CodigoDependencia, IDependencias));

    if (!DependenciaBuscada) {
        cout << "No se encontró una dependencia con el codigo introducido\n";
        return;
    }

    DependenciaBuscada->DerivarDenuncia();
}

template<typename T>
void DerivarUltimaDenunciaEnEnte(const vector<T *> &entes) {
    int CodigoDependencia;

    vector<IExposicion *> IEntes(entes.begin(), entes.end());
    MostrarVector(IEntes);

    cout << "Ingrese el codigo de la dependnecia donde desea derivar la denuncia\n";
    cin >> CodigoDependencia;

    T *EnteBuscado = dynamic_cast<T *>(BuscarPorCodigo(CodigoDependencia, IEntes));

    if (!EnteBuscado) {
        cout << "No se encontró un ente con el codigo introducido\n";
        return;
    }

    EnteBuscado->DerivarDenuncia();
}

InformacionDenuncia CrearInformacionDenuncia() {

    int TipoDenuncia;
    cout << "Oral o escrita (0 - Oral, 1 - Escrita)\n";
    cin >> TipoDenuncia;

    string Documentacion;
    cout << "Ingrese la documentacion\n";
    cin.ignore();
    getline(cin, Documentacion);

    string DireccionDelito;
    cout << "Ingrese donde se cometio el delito\n";
    cin.ignore();
    getline(cin, DireccionDelito);

    string Adicional;

    if (TipoDenuncia) {
        cout << "-- Denuncia Escrita --\n";
        cout << "Ingrese el archivo\n";
    } else {
        cout << "-- Denuncia Oral --\n";
        cout << "Ingrese la descripcion\n";
    }
    cin.ignore();
    getline(cin, Adicional);

    return {TipoDenuncia, Documentacion, DireccionDelito, Adicional};
}

IExposicion *BuscarPorCodigo(int codigo, vector<IExposicion *> &vector) {
    auto Iterador = find_if(vector.begin(), vector.end(),
                            [&codigo](const IExposicion *objeto) { return objeto->GetCodigo() == codigo; });

    if (Iterador != end(vector)) {
        return *Iterador;
    }

    return nullptr;
}
