#ifndef FECHA_H_
#define FECHA_H_

#include <iostream>

using namespace std;

class Fecha {
private:

    short hora;

    short minuto;

    short segundo;

	short dia;

	short mes;

	short anio;

	bool esDiaValido() const;

	bool esMesValido() const;

	bool esAnioValido() const;

	short diasEnMes(const short mes) const;

public:

	//Constructores
	Fecha();

	Fecha(const short d, const short m, const short a);

    Fecha(const short d, const short m, const short a, const short hora, const short minuto, const short segundo);

	Fecha(const Fecha &f);

	//Setters
	void setFechaActual(void);

	void setFecha(const short d, const short m, const short a);

	//Getters
	inline short getDia() const { return dia; }

	inline short getMes() const { return mes; }

	inline short getAnio() const { return anio; }

	bool esAnioBisiesto(void) const;

	long int cantidadDiasDelAnio();

	//Sobrecarga de operadores
	friend bool operator>=(Fecha fecha1, Fecha fecha2);
	friend long int operator-(Fecha &fecha1, Fecha &fecha2);//Retorna la diferencia de d�as entre 2 fechas

};

ostream& operator<<(ostream &salida,const Fecha &f);

#endif /* FECHA_H_ */
