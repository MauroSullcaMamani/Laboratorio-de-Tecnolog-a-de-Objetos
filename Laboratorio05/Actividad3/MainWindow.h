#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

class QLabel;
class QListWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void mostrarDatos(const QString &pais);

private:
    QListWidget *listaPaises;
    QLabel *detallePais;
};

#endif
