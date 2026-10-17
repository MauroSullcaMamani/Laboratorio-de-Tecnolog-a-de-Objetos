#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QListWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listaPaises->addItems({
        "Peru",
        "Argentina",
        "Brasil",
        "Francia",
        "Japon",
        "Mexico"
    });
    connect(ui->listaPaises,
            &QListWidget::itemClicked,
            this,
            [this](QListWidgetItem *item) {
                mostrarInformacion(item->text());
            });
}

void MainWindow::mostrarInformacion(const QString &pais)
{
    if (pais == "Peru") {
        ui->labelInfo->setText("Capital: Lima\nIdioma: Espanol");
    }
    else if (pais == "Argentina") {
        ui->labelInfo->setText("Capital: Buenos Aires\nIdioma: Espanol");
    }
    else if (pais == "Brasil") {
        ui->labelInfo->setText("Capital: Brasilia\nIdioma: Portugues");
    }
    else if (pais == "Francia") {
        ui->labelInfo->setText("Capital: Paris\nIdioma: Frances");
    }
    else if (pais == "Japon") {
        ui->labelInfo->setText("Capital: Tokio\nIdioma: Japones");
    }
    else if (pais == "Mexico") {
        ui->labelInfo->setText("Capital: Ciudad de Mexico\nIdioma: Espanol");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
