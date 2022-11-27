#include "Delito.h"
#include "DenunciaEscrita.h"
#include "Dependencia.h"
#include "Fecha.h"
#include "Registro.h"
#include "Oficial.h"
#include "Preambulo.h"

void DenunciaEscrita::Derivar(const string &investigacion, const Fecha &FechaD) {
    Dependencia *DependenciaUltima = GetDelito()->ObtenerUltimaDependencia();
    Registro *NuevoRegistro = new Registro(FechaD, DependenciaUltima->GetNombre());

    NuevoRegistro->AsignarInvestigacion(investigacion);
    DependenciaUltima->AgregarDenuncia(this);
    AgregarRegistro(NuevoRegistro);
}

void DenunciaEscrita::MostrarInformacion() const {
    Denuncia::MostrarInformacion();
    cout << "Archivo: " << Archivo << '\n';
}

