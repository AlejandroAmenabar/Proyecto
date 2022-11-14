
#include "Persona.h"
#include <iostream>

Persona::~Persona(){}

void Persona::MostrarInfo()
{
	cout<<"Dni: "<<this->Dni<<endl;
	cout<<"Nombre: "<<this->Nombre<<endl;
	cout<<"Nacimiento: "<<this->FecNacimiento<<endl;
	cout<<"Direccion: "<<this->Direccion<<endl;
	cout<<"Sexo: "<<this->Sexo<<endl;
}



