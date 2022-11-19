#include <iostream>
#include "Oficial.h"
#include "Denuncia.h"

using namespace std;

Oficial::~Oficial(){}

void Oficial::MostrarInfo()
{
	Persona::MostrarInfo();
	cout<<"Cargo: "<< this->cargo[this->Car]<<endl;
}


