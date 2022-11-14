#ifndef PROYECTO_DENUNCIA_H
#define PROYECTO_DENUNCIA_H

#include <string>
#include <utility>

class Preambulo;
class Delito;
class Imagen;
class Fecha;
class Hora;

using namespace std;

class Denuncia {

    int Codigo;

    string Descripcion;

    Imagen* FirmaDemandante;

    Imagen* FirmaOficial;

    Delito* Delito;

    Preambulo* PreambuloDenuncia;

public:

    Denuncia(int codigo, string descripcion, Imagen *firmaDemandante, Imagen *firmaOficial) : Codigo(
            codigo), Descripcion(std::move(descripcion)), FirmaDemandante(firmaDemandante), FirmaOficial(firmaOficial) {}

    virtual ~Denuncia();

    void MostrarInformacion() const;

    void AgregarPreambulo(Fecha fecha, Hora hora, const string& lugar);

    virtual void Derivar(Fecha fecha, const string& investigacion) const = 0;

    inline const Preambulo* GetPreambulo() const { return PreambuloDenuncia; };
};


#endif //PROYECTO_DENUNCIA_H
