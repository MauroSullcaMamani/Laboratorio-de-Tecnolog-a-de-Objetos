#include <iostream>
using namespace std;

template <class T>
class Contenedor {
    T elemento;

public:
    Contenedor(T arg) { elemento = arg; }
    T add() { return ++elemento; }
};

template <>
class Contenedor<char> {
    char elemento;

public:
    Contenedor(char arg) { elemento = arg; }
    char uppercase() {
        if ((elemento >= 'a') && (elemento <= 'z')) {
            elemento += 'A' - 'a';
        }
        return elemento;
    }
};

int main() {
    Contenedor<int> cint(5);
    Contenedor<char> cchar('t');
    cout << "add(): " << cint.add() << endl;
    cout << "uppercase(): " << cchar.uppercase() << endl;
    return 0;
}
