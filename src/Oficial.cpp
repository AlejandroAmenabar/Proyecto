/*
 * Oficial.cpp
 *
 *  Created on: 14 nov. 2022
 *      Author: Alejandro
 */

#include "Oficial.h"
#include <iostream>
using namespace std;

Oficial::~Oficial(){}

void Oficial::MostrarInfo()
{
	Persona::MostrarInfo();
	cout<<"Cargo: "<< this->cargo[this->Car]<<endl;
}


