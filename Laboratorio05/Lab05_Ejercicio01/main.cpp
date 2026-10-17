#include <QCoreApplication>
#include <QVector>
#include <QRandomGenerator>
#include <QDebug>
#include <algorithm>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVector<int> numeros;

    for (int i = 0; i < 20; ++i) {
        int numero = QRandomGenerator::global()->bounded(1, 51);
        numeros.append(numero);
    }

    qDebug() << "Vector generado:" << numeros;

    int cantidad = std::count_if(
        numeros.begin(),
        numeros.end(),
        [](int numero) {
            return numero % 2 != 0 && numero < 20;
        }
        );

    qDebug() << "Cantidad de numeros impares menores que 20:"
             << cantidad;

    return 0;
}

