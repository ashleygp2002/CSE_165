#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QStandardPaths>
#include "task.h" // Include the Task classes

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAdd_clicked();
    void on_btnRemove_clicked();
    void on_btnRemoveAll_clicked();
    void saveToDoList(); // Declaration of the saveToDoList() function

private:
    Ui::MainWindow *ui;
    QString path; // Move path variable here
    QList<Task*> tasks; // Store Task objects instead of QString in the list
};

#endif // MAINWINDOW_H
