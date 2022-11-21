#include <iostream>
#include "Oficial.h"
#include "Denuncia.h"

using namespace std;

Oficial::~Oficial(){}

void Oficial::MostrarInformacion()
{
    Persona::MostrarInformacion();
	cout<<"Cargo: "<< this->cargo[this->Car]<<endl;
}


