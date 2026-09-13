#ifndef UNIVERSIDAD_H
#define UNIVERSIDAD_H

#include <string>
#include <vector>
#include "Curso.h"
using namespace std;

class Universidad {
private:
    string nombre;
    vector<Curso> cursos;

public:
    Universidad(string nombre);

    string getNombre() const;
    void setNombre(string nombre);

    vector<Curso> getCursos() const;
    void setCursos(vector<Curso> cursos);

    void agregarCurso(Curso curso);
    string toString() const;
};

#endif
