#include "Universidad.h"

#include <string>
#include <vector>
using namespace std;

Universidad::Universidad(string nombre) : nombre(nombre) {}

string Universidad::getNombre() const {
    return nombre;
}

void Universidad::setNombre(string nombre) {
    this->nombre = nombre;
}

vector<Curso> Universidad::getCursos() const {
    return cursos;
}

void Universidad::setCursos(vector<Curso> cursos) {
    this->cursos = cursos;
}

void Universidad::agregarCurso(Curso curso) {
    cursos.push_back(curso);
}

string Universidad::toString() const {
    string resultado = "Universidad: " + nombre + " , cursos: [";
    for (size_t i = 0; i < cursos.size(); ++i) {
        if (i > 0) {
            resultado += ", ";
        }
        resultado += cursos[i].toString();
    }
    resultado += "]";
    return resultado;
}
