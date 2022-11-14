/*
 * Dependencia.h
 *
 *  Created on: 14 nov. 2022
 *      Author: mlgir
 */

#ifndef DEPENDENCIA_H_
#define DEPENDENCIA_H_
#include <iostream>
#include "Oficial.h"
using namespace std;

class Dependencia {
private:
	int Codigo;
	string Nombre;
	Oficial OficialDeTurno;

public:
	Dependencia(int codigo, string nombre);
	virtual ~Dependencia();
	int GetCodigo();
	string GetNombre();
};

#endif /* DEPENDENCIA_H_ */
