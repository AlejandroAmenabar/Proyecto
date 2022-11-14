/*
 * Preambulo.cpp
 *
 *  Created on: 14 nov. 2022
 *      Author: mlgir
 */

#include "Preambulo.h"

Preambulo::Preambulo(Fecha fecha, int hora, string lugar) {
	this->Fecha=fecha;
	this->Hora=hora;
	this->Lugar=lugar;
}

Preambulo::~Preambulo() {
	// TODO Auto-generated destructor stub
}

Fecha Preambulo::GetFecha(){
	return this->Fecha;
}

