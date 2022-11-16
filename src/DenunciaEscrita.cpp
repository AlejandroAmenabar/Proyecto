#include "Delito.h"
#include "DenunciaEscrita.h"
#include "Dependencia.h"
#include "Fecha.h"
#include "Registro.h"

void DenunciaEscrita::Derivar(Fecha fecha, const string &investigacion) const {
//    string DependenciaActual = GetRegistros().back()->GetDepedenciaSig();
    Dependencia *Dependencia = GetDelito()->ObtenerUltimaDependencia();
    Dependencia->AgregarDenuncia((Denuncia *) this);

    Registro *NuevoRegistro = new Registro(fecha, Dependencia->GetNombre());
    GetRegistros().emplace_back(NuevoRegistro);
}



