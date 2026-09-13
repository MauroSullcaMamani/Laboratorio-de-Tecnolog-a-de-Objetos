#ifndef PROFESOR_H
#define PROFESOR_H

#include "Persona.h"

class Profesor : public Persona {
public:
    Profesor(string nombre, int edad);
    string toString() const override;
};

#endif
