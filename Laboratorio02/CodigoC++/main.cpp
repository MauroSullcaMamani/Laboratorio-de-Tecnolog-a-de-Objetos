#include <iostream>

#include "Profesor.h"
#include "Estudiante.h"
#include "Curso.h"
#include "Universidad.h"
#include "Reporte.h"

using namespace std;

int main() {
    Profesor profesor1("Marco Aedo", 45);
    Profesor profesor2("Roni Apaza", 38);

    Estudiante estudiante1("Mauro Sullca", 20);
    Estudiante estudiante2("Pepe Cruz", 21);
    Estudiante estudiante3("Kenji Gonzalez", 19);

    Curso curso1("Programacion Orientada a Objetos", "Lunes", "08:00 - 10:00");
    Curso curso2("Sistemas Operativos", "Miercoles", "10:00 - 12:00");

    Universidad universidad("Universidad Nacional de San Agustin");

    universidad.agregarCurso(curso1);
    universidad.agregarCurso(curso2);

    cout << "PROFESORES" << endl;
    cout << profesor1.toString() << endl;
    cout << profesor2.toString() << endl;

    cout << "\nESTUDIANTES" << endl;
    cout << estudiante1.toString() << endl;
    cout << estudiante2.toString() << endl;
    cout << estudiante3.toString() << endl;

    cout << "\nCURSOS" << endl;
    cout << curso1.toString() << endl;
    cout << curso2.toString() << endl;

    cout << "\nUNIVERSIDAD" << endl;
    cout << universidad.toString() << endl;

    cout << endl;
    Reporte reporte;
    reporte.generarReporte(estudiante1);

    return 0;
}
