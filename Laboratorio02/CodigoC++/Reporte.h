#ifndef REPORTE_H
#define REPORTE_H

#include <string>
#include "Estudiante.h"
using namespace std;

class Reporte {
public:
    void generarReporte(const Estudiante& estudiante);
    string toString() const;
};

#endif
