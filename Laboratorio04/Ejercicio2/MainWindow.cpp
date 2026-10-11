#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Task.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , taskWidget(nullptr)
{
    ui->setupUi(this);

    taskWidget = new Task();
    taskWidget->setWindowTitle("Ingresar Nueva Tarea");

    connect(ui->addTaskButton,
            &QPushButton::clicked,
            this,
            &MainWindow::openTaskForm);

    connect(taskWidget,
            &Task::taskSubmitted,
            this,
            &MainWindow::receiveTask);
}

MainWindow::~MainWindow()
{
    delete taskWidget;
    delete ui;
}

void MainWindow::openTaskForm()
{
    taskWidget->show();
    taskWidget->raise();
    taskWidget->activateWindow();
}

void MainWindow::receiveTask(const QString &text)
{
    ui->statusLabel->setText("Tarea recibida: " + text);
}