#include "Preambulo.h"

Preambulo::Preambulo(Fecha fecha, string lugar) {
	this->FechaP=fecha;
	this->Lugar=lugar;
}

Preambulo::~Preambulo() {
}

Fecha Preambulo::GetFecha(){
	return this->FechaP;
}

string Preambulo::GetLugar(){
	return this->Lugar;
}

void Preambulo::MostrarInfo(){
	cout << "Fecha: " << FechaP << endl;
	cout << "Lugar: " << Lugar << endl;
}
