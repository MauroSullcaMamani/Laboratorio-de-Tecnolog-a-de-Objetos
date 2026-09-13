#include "Estudiante.h"

#include <string>
using namespace std;

Estudiante::Estudiante(string nombre, int edad) : Persona(nombre, edad) {}

string Estudiante::toString() const {
    return "Estudiante: " + getNombre() + " ; edad: " + to_string(getEdad());
}
