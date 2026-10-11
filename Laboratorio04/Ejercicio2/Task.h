#ifndef TASK_H
#define TASK_H

#include <QWidget>
#include <QString>

namespace Ui {
class Task;
}

class Task : public QWidget
{
    Q_OBJECT

public:
    explicit Task(QWidget *parent = nullptr);
    ~Task();

signals:
    void taskSubmitted(const QString &text);

private slots:
    void sendTask();

private:
    Ui::Task *ui;
};

#endif // TASK_H