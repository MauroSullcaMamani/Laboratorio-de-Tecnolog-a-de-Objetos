/********************************************************************************
** Form generated from reading UI file 'Task.ui'
**
** Created by: Qt User Interface Compiler version 6.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASK_H
#define UI_TASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Task
{
public:
    QLineEdit *Mitext;
    QPushButton *sendTaskButton;

    void setupUi(QWidget *Task)
    {
        if (Task->objectName().isEmpty())
            Task->setObjectName("Task");
        Task->resize(400, 300);
        Mitext = new QLineEdit(Task);
        Mitext->setObjectName("Mitext");
        Mitext->setGeometry(QRect(60, 30, 161, 41));
        sendTaskButton = new QPushButton(Task);
        sendTaskButton->setObjectName("sendTaskButton");
        sendTaskButton->setGeometry(QRect(100, 90, 80, 24));

        retranslateUi(Task);

        QMetaObject::connectSlotsByName(Task);
    } // setupUi

    void retranslateUi(QWidget *Task)
    {
        Task->setWindowTitle(QCoreApplication::translate("Task", "Form", nullptr));
        Mitext->setPlaceholderText(QCoreApplication::translate("Task", "Escribe una tarea aqu\303\255...", nullptr));
        sendTaskButton->setText(QCoreApplication::translate("Task", "Enviar tarea", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Task: public Ui_Task {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASK_H
