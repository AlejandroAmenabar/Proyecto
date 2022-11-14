/*
 * Persona.h
 *
 *  Created on: 14 nov. 2022
 *      Author: Alejandro
 */

#ifndef PERSONA_H_
#define PERSONA_H_

#include <iostream>
#include "Fecha.h"
using namespace std;

class Persona {
	private:
		int Dni;
		string Nombre;
		Fecha FecNacimiento;
		string Direccion;
		char Sexo;
	public:
		Persona(int dni,string nom,Fecha fec,string direc,char sex):Dni(dni),Nombre(nom),FecNacimiento(fec),Direccion(direc),Sexo(sex) {}
		virtual ~Persona();
		virtual void MostrarInfo();

};



#endif /* PERSONA_H_ */
