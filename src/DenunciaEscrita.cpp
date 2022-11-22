#include "Delito.h"
#include "DenunciaEscrita.h"
#include "Dependencia.h"
#include "Fecha.h"
#include "Registro.h"
#include "Oficial.h"
#include "Preambulo.h"

void DenunciaEscrita::Derivar(const string& investigacion, const Fecha &FechaD) {
    Dependencia *Dependencia = GetDelito()->ObtenerUltimaDependencia();
    Dependencia->AgregarDenuncia((Denuncia *) this);

    Registro *NuevoRegistro = new Registro(FechaD, Dependencia->GetNombre());
    AgregarRegistro(NuevoRegistro);
}

void DenunciaEscrita::MostrarInformacion() const {
    Denuncia::MostrarInformacion();
    cout << "Archivo: " << Archivo << '\n';
}

