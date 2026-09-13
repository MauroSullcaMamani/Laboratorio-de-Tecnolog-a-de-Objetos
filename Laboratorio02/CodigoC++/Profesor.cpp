#include "Profesor.h"

#include <string>
using namespace std;

Profesor::Profesor(string nombre, int edad) : Persona(nombre, edad) {}

string Profesor::toString() const {
    return "Profesor: " + getNombre() + " ; edad: " + to_string(getEdad());
}
