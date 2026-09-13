#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "Persona.h"

class Estudiante : public Persona {
public:
    Estudiante(string nombre, int edad);
    string toString() const override;
};

#endif
