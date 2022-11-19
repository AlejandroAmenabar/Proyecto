#include "Delito.h"
#include "DenunciaEscrita.h"
#include "Dependencia.h"
#include "Fecha.h"
#include "Registro.h"
#include "Oficial.h"
#include "Preambulo.h"

void DenunciaEscrita::Derivar(const Fecha &FechaD) const {
    Dependencia *Dependencia = GetDelito()->ObtenerUltimaDependencia();
    Dependencia->AgregarDenuncia((Denuncia *) this);

    Registro *NuevoRegistro = new Registro(FechaD, Dependencia->GetNombre());
    GetRegistros().emplace_back(NuevoRegistro);
}

