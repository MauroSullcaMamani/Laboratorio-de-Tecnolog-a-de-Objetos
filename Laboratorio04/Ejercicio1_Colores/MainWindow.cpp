#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->listaColores->addItem("Rojo");
    ui->listaColores->addItem("Azul");
    ui->listaColores->addItem("Verde");
    ui->listaColores->addItem("Amarillo");
    ui->listaColores->addItem("Naranja");
    ui->listaColores->addItem("Morado");

    connect(ui->listaColores, &QListWidget::itemClicked,
            this, &MainWindow::onColorSeleccionado);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onColorSeleccionado(QListWidgetItem *item) {
    QString colorNombre = item->text();
    ui->lblResultado->setText("Color seleccionado: " + colorNombre);
}
