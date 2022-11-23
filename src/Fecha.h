#ifndef FECHA_H_
#define FECHA_H_

#include <iostream>

using namespace std;

class Fecha {

    short Hora;

    short Minuto;

    short Dia;

    short Mes;

    short Anio;

    bool EsDiaValido() const;

    bool EsMesValido() const;

    bool EsAnioValido() const;

    short DiasEnMes(short mes) const;

public:

    Fecha();

    Fecha(short int dia, short int mes, short int anio) : Hora(0), Minuto(0), Dia(dia), Mes(mes), Anio(anio) {}

    Fecha(const short dia, const short mes, const short anio, const short hora, const short minuto) : Hora(hora),
                                                                                                      Minuto(minuto),
                                                                                                      Dia(dia),
                                                                                                      Mes(mes),
                                                                                                      Anio(anio) {}

    Fecha(const Fecha &fecha) = default;

    void SetFechaActual();

    void SetFecha(short dia, short mes, short anio);

    void SetFecha(short dia, short mes, short anio, short hora, short minuto);

    inline short GetHora() const { return Hora; }

    inline short GetMinuto() const { return Minuto; }

    inline short GetDia() const { return Dia; }

    inline short GetMes() const { return Mes; }

    inline short GetAnio() const { return Anio; }

    bool EsAnioBisiesto() const;

    long int CantidadDiasDelAnio() const;

    friend bool operator>=(const Fecha &lhs, const Fecha &rhs);

    friend long int operator-(const Fecha &lhs, const Fecha &rhs);

    friend bool operator==(const Fecha &lhs, const Fecha &rhs);

    friend ostream &operator<<(ostream &os, const Fecha &fecha);

    friend istream& operator>>(istream& is, Fecha& fecha);
};


#endif /* FECHA_H_ */
