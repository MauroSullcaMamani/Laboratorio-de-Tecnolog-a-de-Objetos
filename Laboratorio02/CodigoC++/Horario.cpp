#include "Horario.h"

#include <string>
using namespace std;

Horario::Horario(string dia, string hora) : dia(dia), hora(hora) {}

string Horario::getDia() const {
    return dia;
}

void Horario::setDia(string dia) {
    this->dia = dia;
}

string Horario::getHora() const {
    return hora;
}

void Horario::setHora(string hora) {
    this->hora = hora;
}

string Horario::toString() const {
    return "Horario:  dia: " + dia + " , hora: " + hora;
}
