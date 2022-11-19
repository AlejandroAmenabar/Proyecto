#include "Dependencia.h"
#include "Preambulo.h"
#include "Delito.h"
#include "Fecha.h"
#include "Registro.h"
#include "DenunciaOral.h"

void DenunciaOral::Derivar(const Fecha &FechaD) {
    string DependenciaActual = GetRegistros().back()->GetDepedenciaSig();
    Dependencia *DependenciaSiguiente = GetDelito()->ObtenerSiguienteDependencia(DependenciaActual);
    DependenciaSiguiente->AgregarDenuncia((Denuncia *) this);

    Registro *NuevoRegistro = new Registro(FechaD, DependenciaSiguiente->GetNombre());
    GetRegistros().emplace_back(NuevoRegistro);
}