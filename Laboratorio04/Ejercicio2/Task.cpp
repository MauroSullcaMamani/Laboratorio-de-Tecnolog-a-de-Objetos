#include "Task.h"
#include "ui_Task.h"

Task::Task(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Task)
{
    ui->setupUi(this);

    connect(ui->sendTaskButton,
            &QPushButton::clicked,
            this,
            &Task::sendTask);
}

Task::~Task()
{
    delete ui;
}

void Task::sendTask()
{
    QString texto = ui->Mitext->text().trimmed();

    if (!texto.isEmpty()) {
        emit taskSubmitted(texto);
        ui->Mitext->clear();
        this->hide();
    }
}