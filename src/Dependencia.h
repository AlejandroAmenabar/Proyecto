#ifndef DEPENDENCIA_H_
#define DEPENDENCIA_H_

#include <iostream>
#include <vector>

class Oficial;
class Denuncia;

using namespace std;

class Dependencia {

	int Codigo;

	string Nombre;

	Oficial* OficialDeTurno;

    vector<Denuncia*> Denuncias;

public:

	Dependencia(int codigo, const string& nombre) : Codigo(codigo), Nombre(nombre) {}

    void MostrarInformacion() const;

    void DerivarDenuncia();

    void AgregarDenuncia(Denuncia* denuncia);

	inline int GetCodigo() const { return Codigo; }

	inline const string& GetNombre() const { return Nombre; }

	inline const Oficial* GetOficial() const { return OficialDeTurno; }
};

#endif /* DEPENDENCIA_H_ */
