#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

int main()
{
    std::random_device semilla;
    std::mt19937 generador(semilla());
    std::uniform_int_distribution<int> distribucion(0, 99);
    std::vector<int> numeros(20);

    for (int &numero : numeros) {
        numero = distribucion(generador);
    }

    const auto cantidad = std::count_if(numeros.begin(), numeros.end(), [](int numero) {
        return numero % 2 != 0 && numero < 20;
    });

    std::cout << "Numeros generados: ";
    for (int numero : numeros) {
        std::cout << numero << ' ';
    }

    std::cout << "\nImpares menores de 20: " << cantidad << '\n';
    return 0;
}
