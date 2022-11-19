#include "Oficial.h"
#include <iostream>

using namespace std;

Oficial::~Oficial(){}

void Oficial::MostrarInfo()
{
	Persona::MostrarInfo();
	cout<<"Cargo: "<< this->cargo[this->Car]<<endl;
}


