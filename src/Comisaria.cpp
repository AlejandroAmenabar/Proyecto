#include "Comisaria.h"
#include "Oficial.h"
#include "Denuncia.h"
#include "Dependencia.h"
#include "Registro.h"
#include "Delito.h"

int Comisaria::Indice = 0;

Comisaria::Comisaria(const string &direccion, const vector<Oficial *> &oficiales) : Direccion(direccion),
                                                                                    Oficiales(oficiales) {
    Codigo = Indice++;
}

void Comisaria::MostrarInformacion() const {
    cout << "-- Comisaria --\n";
    cout << "Codigo: " << Codigo << '\n';
    cout << "Direccion: " << Direccion << '\n';
}

void Comisaria::AgregarOficial(Oficial *oficial) {
    Oficiales.emplace_back(oficial);
}

void Comisaria::MostrarDenuncias(Fecha fecha) const {
    for (const auto &Denuncia: Denuncias) {
        if (Denuncia->GetFecha() - fecha == 0) {
            Denuncia->MostrarInformacion();
        }
    }
}

void Comisaria::AgregarDenuncia(Denuncia *denuncia) {
    Denuncias.emplace_back(denuncia);
}

void Comisaria::DerivarDenuncia() {
//    string Declaracion;
//    cout << "Ingrese declaracion inicial de la denuncia: \n"; // Se guarda en la variable Investigación de Registro
//    cin >> Declaracion;

//    string PrimeraDependencia = Denuncias.back()->GetDelito()->ObtenerPrimeraDependencia()->GetNombre();
//    Registro* RegistroInicial = new Registro(Fecha{}, PrimeraDependencia);
//    Denuncias.back()->AgregarRegistro(RegistroInicial);
//    Denuncias.back()->AgregarInvestigacion(Declaracion);
    Denuncias.back()->Derivar(Fecha{});
    Denuncias.pop_back();
}
