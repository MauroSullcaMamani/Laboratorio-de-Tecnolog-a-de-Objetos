#include "Reporte.h"

#include <iostream>
#include <string>
using namespace std;

void Reporte::generarReporte(const Estudiante& estudiante) {
    cout << "REPORTE DEL ESTUDIANTE" << endl;
    cout << "Nombre: " << estudiante.getNombre() << endl;
    cout << "Edad: " << estudiante.getEdad() << endl;
    cout << endl;
}

string Reporte::toString() const {
    return "Reporte{}";
}
