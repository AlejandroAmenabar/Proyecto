enum  Cargo {
//enum class Cargo : unsigned int {
    Cadete,
    General,
	Administrativo,
	Comisario,
	Tecnico
};

#ifndef OFICIAL_H_
#define OFICIAL_H_
#include "Persona.h"
#include <iostream>
using namespace std;

class Oficial : public Persona {
private:
	string cargo[5] = {"Cadete","General","Administrativo","Comisario","Tecnico"};
	Cargo Car;
public:
	Oficial(int dni,string nom,Fecha fec,string direc,char sex,Cargo C): Persona(dni,nom,fec,direc,sex),Car(C){}
	virtual ~Oficial();
	void MostrarInfo();
};




#endif /* OFICIAL_H_ */
