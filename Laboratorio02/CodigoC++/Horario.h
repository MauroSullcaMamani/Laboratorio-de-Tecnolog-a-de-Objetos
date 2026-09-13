#ifndef HORARIO_H
#define HORARIO_H

#include <string>
using namespace std;

class Horario {
private:
    string dia;
    string hora;

public:
    Horario(string dia, string hora);

    string getDia() const;
    void setDia(string dia);

    string getHora() const;
    void setHora(string hora);

    string toString() const;
};

#endif
