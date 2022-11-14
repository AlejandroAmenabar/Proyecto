//============================================================================
// Name        : Proyecto.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Persona.h"
using namespace std;

int main() {
	Fecha F;
	Persona P(43321142,"ale",F,"españa 4455",'M');
	P.MostrarInfo();


	return 0;
}
