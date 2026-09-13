#ifndef CURSO_H
#define CURSO_H

#include <string>
#include "Horario.h"
using namespace std;

class Curso {
private:
    string nombre;
    Horario horario;

public:
    Curso(string nombre, string dia, string hora);

    string getNombre() const;
    void setNombre(string nombre);

    Horario getHorario() const;
    void setHorario(Horario horario);

    string toString() const;
};

#endif
