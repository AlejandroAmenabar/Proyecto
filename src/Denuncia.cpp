#include "Denuncia.h"
#include "Fecha.h"
#include "Preambulo.h"
#include "Fecha.h"

Denuncia::~Denuncia() {
    delete PreambuloDenuncia;
}

void Denuncia::MostrarInformacion() const {

}

void Denuncia::AgregarPreambulo(const Fecha& fecha, const string &lugar) {
    PreambuloDenuncia = new Preambulo(fecha, lugar);
}
