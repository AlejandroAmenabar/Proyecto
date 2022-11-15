//============================================================================
// Name        : Proyecto.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Persona.h"
#include "Oficial.h"
using namespace std;

int main() {
	Fecha F;
	Persona P(43321142,"ale",F,"españa 4455",'M');
	P.MostrarInfo();

	cout<<endl;

	Oficial Gutierrez(43321142,"ale",F,"españa 4455",'M',Cargo::Cadete);
	Gutierrez.MostrarInfo();


	return 0;
}
