#ifndef PROYECTO_DENUNCIA_H
#define PROYECTO_DENUNCIA_H

#include <string>

class Preambulo;
class Delito;
class Fecha;

using namespace std;

class Denuncia {

    int Codigo;

    string Descripcion;

    string FirmaDemandante;

    string FirmaOficial;

    Delito *Delito;

    Preambulo *PreambuloDenuncia;

public:

    Denuncia(int codigo, const string &descripcion, const string &firmaDemandante, const string &firmaOficial,
             class Delito *delito) : Codigo(codigo), Descripcion(descripcion),
                                     FirmaDemandante(firmaDemandante),
                                     FirmaOficial(firmaOficial), Delito(delito) {}

    virtual ~Denuncia();

    void MostrarInformacion() const;

    void AgregarPreambulo(const Fecha& fecha, const string &lugar);

    virtual void Derivar(Fecha fecha, const string &investigacion) const = 0;

    inline const Preambulo *GetPreambulo() const { return PreambuloDenuncia; };
};


#endif //PROYECTO_DENUNCIA_H
