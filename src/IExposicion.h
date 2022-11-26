#ifndef PROYECTO_IEXPOSICION_H
#define PROYECTO_IEXPOSICION_H

class IExposicion{

public:
    virtual void MostrarInformacion() const = 0;

    virtual int GetCodigo() const = 0;
};

#endif //PROYECTO_IEXPOSICION_H
