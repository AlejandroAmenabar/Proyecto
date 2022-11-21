#include "Dependencia.h"
#include "Preambulo.h"
#include "Delito.h"
#include "Fecha.h"
#include "Registro.h"
#include "DenunciaOral.h"

void DenunciaOral::Derivar(const Fecha &FechaD) {
    Registro *NuevoRegistro = nullptr;

    if (GetRegistros().empty()) {
        string InvestigacionComisaria;
        cout << "Ingrese declaracion inicial de la denuncia: \n"; // Se guarda en la variable Investigación de Registro
        cin >> InvestigacionComisaria;

        string PrimeraDependencia = GetDelito()->ObtenerPrimeraDependencia()->GetNombre();
        NuevoRegistro = new Registro(Fecha{}, PrimeraDependencia);
        NuevoRegistro->AsignarInvestigacion(InvestigacionComisaria);

        Dependencia *DependenciaInicial = GetDelito()->ObtenerPrimeraDependencia();
        DependenciaInicial->AgregarDenuncia(this);
    } else {
        string InvestigacionDependencia;
        cout << "Ingrese la investigacion de la dependencia: \n";
        cin >> InvestigacionDependencia;

        // Obtiene el nombre de la dependencia actual desde el último Registro
        string DependenciaActual = GetRegistros().back()->GetDepedenciaSig();

        // Obtiene el objeto Dependencia siguiente del arreglo en Delito
        Dependencia *DependenciaSiguiente = GetDelito()->ObtenerSiguienteDependencia(DependenciaActual);

        // Crea un nuevo registro con la siguiente Dependencia
        NuevoRegistro = new Registro(FechaD, DependenciaSiguiente->GetNombre());
        NuevoRegistro->AsignarInvestigacion(InvestigacionDependencia);
        DependenciaSiguiente->AgregarDenuncia(this);
    }

    AgregarRegistro(NuevoRegistro);
}