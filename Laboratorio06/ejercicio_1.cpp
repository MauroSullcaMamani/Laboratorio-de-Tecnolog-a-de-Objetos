#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Lista {
private:
    struct Nodo {
        T valor;
        Nodo* siguiente;
        Nodo(T v) : valor(v), siguiente(nullptr) {}
    };

    Nodo* cabeza;

public:
    Lista() : cabeza(nullptr) {}

    ~Lista() {
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            Nodo* siguiente = actual->siguiente;
            delete actual;
            actual = siguiente;
        }
    }

    void insertar(T valor) {
        Nodo* nuevo = new Nodo(valor);
        if (cabeza == nullptr) {
            cabeza = nuevo;
            return;
        }
        Nodo* actual = cabeza;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }

    void mostrar() const {
        for (Nodo* actual = cabeza; actual != nullptr; actual = actual->siguiente) {
            cout << actual->valor << " -> ";
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Lista<int> edades;
    edades.insertar(18);
    edades.insertar(21);
    edades.insertar(25);
    edades.insertar(30);

    cout << "Secuencia de edades: ";
    edades.mostrar();

    Lista<string> palabras;
    palabras.insertar("plantilla");
    palabras.insertar("clase");
    palabras.insertar("lista");
    palabras.insertar("enlazada");

    cout << "Secuencia de palabras: ";
    palabras.mostrar();
    return 0;
}
