/*
 * Delito.h
 *
 *  Created on: 14 nov. 2022
 *      Author: mlgir
 */

#ifndef DELITO_H_
#define DELITO_H_
#include <iostream>
#include "Dependencia.h"
#include <vector>
using namespace std;

class Delito {
private:
	int Codigo;
	string Nombre;
	vector<Dependencia> Dependencias;
public:
	Delito(int codigo, string nombre, vector<Dependencia>);
	virtual ~Delito();
	Dependencia ObtenerDependencia();
	Dependencia ObtenerDependenciaSig(); //Implementar en el cpp
	int GetCodigo();
	string GetNombre();
};

#endif /* DELITO_H_ */
