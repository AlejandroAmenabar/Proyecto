/*
 * Dependencia.cpp
 *
 *  Created on: 14 nov. 2022
 *      Author: mlgir
 */

#include "Dependencia.h"

Dependencia::Dependencia(int codigo, string nombre, Oficial oficial){
	this->Codigo=codigo;
	this->Nombre=nombre;
}

Dependencia::~Dependencia() {
	// TODO Auto-generated destructor stub
}

int Dependencia::GetCodigo(){
	return this->Codigo;
}

string Dependencia::GetNombre(){
	return this->Nombre;
}

Oficial Dependencia::GetOficial(){
	return this->OficialDeTurno;
}
