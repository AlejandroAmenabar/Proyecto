#include "Fecha.h"
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

Fecha::Fecha() {
    SetFechaActual();
}


void Fecha::SetFechaActual() {
    struct tm const *ptr;
    time_t sec;

    time(&sec);
    ptr = localtime(&sec);
    Dia = (short) ptr->tm_mday;
    Mes = (short) (ptr->tm_mon + 1);
    Anio = (short) (ptr->tm_year + 1900);
}

void Fecha::SetFecha(const short dia, const short mes, const short anio) {
    Dia = dia;
    Mes = mes;
    Anio = anio;
    if (!EsAnioValido() || !EsMesValido() || !EsDiaValido()) {
        SetFechaActual();
    }
}

void Fecha::SetFecha(const short dia, const short mes, const short anio, const short hora, const short minuto) {
    Dia = dia;
    Mes = mes;
    Anio = anio;
    this->Hora = hora;
    this->Minuto = minuto;
    if (!EsAnioValido() || !EsMesValido() || !EsDiaValido()) {
        SetFechaActual();
    }
}

bool Fecha::EsAnioValido() const {
    return (Anio > 0);
}

bool Fecha::EsMesValido() const {
    return (Mes >= 1 && Mes <= 12);
}

bool Fecha::EsDiaValido() const {
    return (Dia >= 1 && Dia <= DiasEnMes(Mes));
}

short Fecha::DiasEnMes(const short mes) const {
    short cantidadDias = 0;
    switch (mes) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            cantidadDias = 31;
            break;
        case 2:
            if (EsAnioBisiesto()) {
                cantidadDias = 29;
            } else {
                cantidadDias = 28;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            cantidadDias = 30;
            break;
        default:
            cantidadDias = 0;
            break;
    }
    return cantidadDias;
}

bool Fecha::EsAnioBisiesto() const {
    return ((Anio % 4 == 0 && Anio % 100 != 0) || Anio % 400 == 0);
}

long int Fecha::CantidadDiasDelAnio() const {
    long int cantidadDias = 0;
    int febrero = 28 + EsAnioBisiesto();
    switch (Mes) {
        case 1:
            cantidadDias = Dia;
            break;
        case 2:
            cantidadDias = 31 + Dia;
            break;
        case 3:
            cantidadDias = 31 + febrero + Dia;
            break;
        case 4:
            cantidadDias = 31 + febrero + 31 + Dia;
            break;
        case 5:
            cantidadDias = 31 + febrero + 31 + 30 + Dia;
            break;
        case 6:
            cantidadDias = 31 + febrero + 31 + 30 + 31 + Dia;
            break;
        case 7:
            cantidadDias = 31 + febrero + 31 + 30 + 31 + 30 + Dia;
            break;
        case 8:
            cantidadDias = 31 + febrero + 31 + 30 + 31 + 30 + 31 + Dia;
            break;
        case 9:
            cantidadDias = 31 + febrero + 31 + 30 + 31 + 30 + 31 + 31 + Dia;
            break;
        case 10:
            cantidadDias = 31 + febrero + 31 + 30 + 31 + 30 + 31 + 31 + 30 + Dia;
            break;
        case 11:
            cantidadDias = 31 + febrero + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + Dia;
            break;
        case 12:
            cantidadDias = 31 + febrero + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + Dia;
            break;
        default:
            cantidadDias = 0;
    }
    return cantidadDias;
}

bool esAnioBisiesto(int anio) {
    return ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0);
}

long int cantidadDiasAniosCompletos(int anioBase, int anio) {

    long int dias = 0;
    if (anioBase < anio) {
        for (int i = anioBase; i < anio; i++) {
            if (esAnioBisiesto(i))
                dias += 366;
            else
                dias += 365;
        }
    }
    return dias;
}

bool operator>=(const Fecha &lhs, const Fecha &rhs) {
    return ((lhs.Anio > rhs.Anio) || (lhs.Anio == rhs.Anio && (lhs.Mes > rhs.Mes ||
                                                               (lhs.Mes == rhs.Mes &&
                                                                lhs.Dia >= rhs.Dia))));
}

long int operator-(const Fecha &lhs, const Fecha &rhs) {
    long int dif = 0;
    if (lhs >= rhs) {
        long int diasAnios = cantidadDiasAniosCompletos(rhs.GetAnio(), lhs.GetAnio());
        long int dias2 = rhs.CantidadDiasDelAnio();
        long int dias1 = lhs.CantidadDiasDelAnio() + diasAnios;
        dif = dias1 - dias2;
    }
    return dif;
}

bool operator==(const Fecha &lhs, const Fecha &rhs) {
    return lhs.Dia == rhs.Dia && lhs.Mes == rhs.Mes && lhs.Anio == rhs.Anio;
}

ostream &operator<<(ostream &os, const Fecha &fecha) { os.fill('0');
    os << setw(2) << fecha.GetDia() << "/" << setw(2) << fecha.GetMes() << "/" << setw(4)
       << fecha.GetAnio();
    return os;
}

istream &operator>>(istream &is, Fecha &fecha) {
    is >> fecha.Dia >> fecha.Mes >> fecha.Anio;
    return is;
}
