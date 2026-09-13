#include "Curso.h"

#include <string>
using namespace std;

Curso::Curso(string nombre, string dia, string hora) : nombre(nombre), horario(dia, hora) {}

string Curso::getNombre() const {
    return nombre;
}

void Curso::setNombre(string nombre) {
    this->nombre = nombre;
}

Horario Curso::getHorario() const {
    return horario;
}

void Curso::setHorario(Horario horario) {
    this->horario = horario;
}

string Curso::toString() const {
    return "Curso: " + nombre + " , horario: " + horario.toString();
}
