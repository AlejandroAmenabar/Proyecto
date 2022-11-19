#include <iostream>
#include <vector>
#include "Delito.h"
#include "Preambulo.h"
#include "Comisaria.h"
#include "Dependencia.h"
#include "Registro.h"
#include "Sistema.h"
#include "Persona.h"
#include "Oficial.h"

using namespace std;

int main() {
    Sistema Tucuman{234, "Tucumán"};
    Fecha F;

    Dependencia Fiscalia {0, "Fiscalia"};
    Dependencia Criminalistica {1, "Criminalistica"};
    Dependencia Fraude {2, "Fraude"};
    Dependencia Drogas {3, "Drogas"};

    vector<Dependencia*> DepedenciasCriminesSexuales {&Fiscalia, &Criminalistica, &Fraude};
    Delito Sexual {0, Categoria::DelitosSexuales, DepedenciasCriminesSexuales};

    Persona Demandado(43321142, "ale", F, "españa 4455", 'M');
    Demandado.MostrarInfo();

    Persona Demandante(2341234, "mariano", F, "chile 4455", 'M');
    Demandante.MostrarInfo();

    Oficial Ector(321423, "Ector Lavo", F, "rivadavia", 'M', Cargo::Cadete);
    Oficial Wereniski(142, "wereniski", F, "chile", 'F', Cargo::Cadete);
    Oficial Luchoni(324, "luchoni", F, "chile234", 'F', Cargo::Cadete);
    Oficial obstrichy(324, "obstrychi", F, "asdklfjñas", 'F', Cargo::Cadete);

    vector<Oficial *> Oficiales1{&Ector, &Wereniski, &Luchoni, &obstrichy};
    vector<Oficial *> Oficiales2{&Wereniski, &Luchoni, &obstrichy};
    vector<Oficial *> Oficiales3{&Luchoni, &obstrichy};

    Tucuman.AgregarComisaria("Alberdi", Oficiales1);
    Tucuman.AgregarComisaria("Las Talitas", Oficiales2);
    Tucuman.AgregarComisaria("Alderetes", Oficiales3);
    Tucuman.RealizarDenuncia(&Sexual, &Demandado, &Demandante, &Ector);
    return 0;
}
