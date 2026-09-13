#include "Persona.h"

#include <string>
using namespace std;

Persona::Persona(string nombre, int edad) : nombre(nombre), edad(edad) {}

string Persona::getNombre() const {
    return nombre;
}

void Persona::setNombre(string nombre) {
    this->nombre = nombre;
}

int Persona::getEdad() const {
    return edad;
}

void Persona::setEdad(int edad) {
    this->edad = edad;
}

string Persona::toString() const {
    return "Persona: " + nombre + " ; edad: " + to_string(edad);
}
