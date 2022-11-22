#include "Dependencia.h"
#include "Preambulo.h"
#include "Delito.h"
#include "Fecha.h"
#include "Registro.h"
#include "DenunciaOral.h"

void DenunciaOral::MostrarInformacion() const {
    Denuncia::MostrarInformacion();
    cout << "Descripcion: " << Descripcion << '\n';
}

void DenunciaOral::Derivar(const string &investigacion, const Fecha &FechaD) {
    Registro *NuevoRegistro = nullptr;
    Dependencia *DependenciaSiguiente = nullptr;

    if (GetRegistros().empty()) {
        string PrimeraDependencia = GetDelito()->ObtenerPrimeraDependencia()->GetNombre();
        NuevoRegistro = new Registro(Fecha{}, PrimeraDependencia);
        DependenciaSiguiente = GetDelito()->ObtenerPrimeraDependencia();
    } else {
        string DependenciaActual = GetRegistros().back()->GetDepedenciaSiguiente();
        DependenciaSiguiente = GetDelito()->ObtenerSiguienteDependencia(DependenciaActual);
        NuevoRegistro = new Registro(FechaD, DependenciaSiguiente->GetNombre());
    }

    NuevoRegistro->AsignarInvestigacion(investigacion);
    DependenciaSiguiente->AgregarDenuncia(this);
    AgregarRegistro(NuevoRegistro);
}
