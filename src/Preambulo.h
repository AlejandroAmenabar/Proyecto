

#ifndef PREAMBULO_H_
#define PREAMBULO_H_
#include <iostream>
#include "Fecha.h"
using namespace std;

class Preambulo {
private:
	Fecha FechaP;
	string Lugar;

public:
	Preambulo(Fecha fecha, string lugar);
	Fecha GetFecha();
	int GetHora();
	string GetLugar();
	virtual ~Preambulo();
};

#endif /* PREAMBULO_H_ */
