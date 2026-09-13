#ifndef PERSONA_H
#define PERSONA_H

#include <string>
using namespace std;

class Persona {
private:
    string nombre;
    int edad;

public:
    Persona(string nombre, int edad);

    string getNombre() const;
    void setNombre(string nombre);

    int getEdad() const;
    void setEdad(int edad);

    virtual string toString() const;
};

#endif
