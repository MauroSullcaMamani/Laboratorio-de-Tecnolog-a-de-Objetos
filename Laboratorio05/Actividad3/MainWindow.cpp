#include "MainWindow.h"

#include <QLabel>
#include <QListWidget>
#include <QMap>
#include <QStringList>
#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      listaPaises(new QListWidget(this)),
      detallePais(new QLabel("Selecciona un país.", this))
{
    auto *contenedor = new QWidget(this);
    auto *layout = new QVBoxLayout(contenedor);

    listaPaises->addItems({"Argentina", "Brasil", "Chile", "Francia", "Perú"});
    detallePais->setWordWrap(true);
    layout->addWidget(listaPaises);
    layout->addWidget(detallePais);

    setCentralWidget(contenedor);
    setWindowTitle("Países, capitales e idiomas");
    resize(360, 300);

    connect(listaPaises, &QListWidget::currentTextChanged,
            this, &MainWindow::mostrarDatos);
}

void MainWindow::mostrarDatos(const QString &pais)
{
    static const QMap<QString, QString> datos = {
        {"Argentina", "Capital: Buenos Aires\nIdioma: español"},
        {"Brasil", "Capital: Brasilia\nIdioma: portugués"},
        {"Chile", "Capital: Santiago\nIdioma: español"},
        {"Francia", "Capital: París\nIdioma: francés"},
        {"Perú", "Capital: Lima\nIdioma: español"}
    };

    detallePais->setText(datos.value(pais, "Selecciona un país."));
}
