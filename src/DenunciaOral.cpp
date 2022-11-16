#include "DenunciaOral.h"
#include "Dependencia.h"
#include "Delito.h"
#include "Fecha.h"
#include "Registro.h"

void DenunciaOral::Derivar(Fecha fecha) const {
    string DependenciaActual = GetRegistros().back()->GetDepedenciaSig();
    Dependencia* DependenciaSiguiente = GetDelito()->ObtenerSiguienteDependencia(DependenciaActual);
    DependenciaSiguiente->AgregarDenuncia((Denuncia *) this);

    Registro* NuevoRegistro = new Registro (fecha, DependenciaSiguiente->GetNombre());
    GetRegistros().emplace_back(NuevoRegistro);
}
