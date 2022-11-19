#include <iostream>
#include <vector>
#include "Sistema.h"
#include "Persona.h"
#include "Oficial.h"

using namespace std;

int main() {
    Sistema Tucuman {234, "Tucumán"};
	Fecha F;

	Persona Ale(43321142, "ale", F, "españa 4455", 'M');
	Ale.MostrarInfo();

    Persona Mariano(2341234, "mariano", F, "chile 4455", 'M');
    Mariano.MostrarInfo();

	cout<<endl;

    Oficial Ector(321423,"Ector Lavo",F,"rivadavia",'M',Cargo::Cadete);
    Oficial Wereniski(142,"wereniski",F,"chile",'F',Cargo::Cadete);
    Oficial Luchoni(324,"luchoni",F,"chile234",'F',Cargo::Cadete);
    Oficial obstrichy(324,"obstrychi",F,"asdklfjñas",'F',Cargo::Cadete);

    vector<Oficial*> Oficiales {&Ector, &Wereniski, &Luchoni, &obstrichy};

	return 0;
}
