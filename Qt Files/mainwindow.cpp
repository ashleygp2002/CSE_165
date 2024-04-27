// #include "mainwindow.h"
// #include "ui_mainwindow.h"
// #include <Qfile>
// #include <QStandardPaths>
// #include <QMessageBox>


// MainWindow::MainWindow(QWidget *parent)
//     : QMainWindow(parent)
//     , ui(new Ui::MainWindow)
// {
//     ui->setupUi(this);

//     QFile file(path);

//     if(!file.open(QIODevice::ReadWrite)){
//         QMessageBox::information(0, "error", file.errorString());
//     }

//     QTextStream in(&file);

//     while(!in.atEnd()) {
//         QListWidgetItem* item = new QListWidgetItem(in.readLine(), ui->listWidget);
//         ui->listWidget->addItem(item);
//         item->setFlags(item->flags() | Qt::ItemIsEditable);
//     }

//     file.close();
// }

// MainWindow::~MainWindow()
// {
//     delete ui;

//     QFile file(path);

//     if(!file.open(QIODevice::ReadWrite)){
//         QMessageBox::information(0, "error", file.errorString());
//     }

//     QTextStream out(&file);

//     for (int i = 0; i < ui->listWidget->count(); ++i){
//         out<<ui->listWidget->item(i)->text()<<"\n";
//     }

//     file.close();
// }

// void MainWindow::on_btnAdd_clicked()
// {
//     QListWidgetItem* item = new QListWidgetItem(ui->txtTask->text(), ui->listWidget);
//     ui->listWidget->addItem(item);
//     item->setFlags(item->flags() | Qt::ItemIsEditable);
//     ui->txtTask->clear();
//     ui->txtTask->setFocus();
// }


// void MainWindow::on_btnRemove_clicked()
// {
//     QListWidgetItem* item = ui->listWidget->takeItem(ui->listWidget->currentRow());
//     delete item;
// }


// void MainWindow::on_btnRemoveAll_clicked()
// {
//     ui->listWidget->clear();
// }


// #include "mainwindow.h"
// #include "ui_mainwindow.h"
// #include <Qfile>
// #include <QStandardPaths>
// #include <QMessageBox>
// #include <QRegularExpression> // Add this include for QRegularExpression

// MainWindow::MainWindow(QWidget *parent)
//     : QMainWindow(parent)
//     , ui(new Ui::MainWindow)
// {
//     ui->setupUi(this);
//     this->setWindowTitle("Todo List"); //The title for the todo list

//     QFile file(path);

//     if(!file.open(QIODevice::ReadWrite)){
//         QMessageBox::information(0, "error", file.errorString());
//     }

//     QTextStream in(&file);

//     while(!in.atEnd()) {
//         QString task = in.readLine();
//         if (!task.isEmpty()) {
//             QListWidgetItem* item = new QListWidgetItem("• " + task, ui->listWidget); // Prepend bullet point
//             ui->listWidget->addItem(item);
//             item->setFlags(item->flags() | Qt::ItemIsEditable);
//         }
//     }

//     file.close();
// }

// MainWindow::~MainWindow()
// {
//     delete ui;

//     QFile file(path);

//     if(!file.open(QIODevice::ReadWrite)){
//         QMessageBox::information(0, "error", file.errorString());
//     }

//     QTextStream out(&file);

//     for (int i = 0; i < ui->listWidget->count(); ++i){
//         QString task = ui->listWidget->item(i)->text();
//         task.remove(QRegularExpression("^\\s*•\\s*")); // Remove bullet point using QRegularExpression
//         out << task << "\n";
//     }

//     file.close();
// }

// void MainWindow::on_btnAdd_clicked()
// {
//     QListWidgetItem* item = new QListWidgetItem("• " + ui->txtTask->text(), ui->listWidget);
//     ui->listWidget->addItem(item);
//     item->setFlags(item->flags() | Qt::ItemIsEditable);
//     ui->txtTask->clear();
//     ui->txtTask->setFocus();
// }

// void MainWindow::on_btnRemove_clicked()
// {
//     QListWidgetItem* item = ui->listWidget->takeItem(ui->listWidget->currentRow());
//     delete item;
// }

// void MainWindow::on_btnRemoveAll_clicked()
// {
//     ui->listWidget->clear();
// }




/*
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <Qfile>
#include <QStandardPaths>
#include <QMessageBox>
#include <QRegularExpression> // Add this include for QRegularExpression

    MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
, ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Todo List"); //The title for the todo list

    QFile file(path);

    if(!file.open(QIODevice::ReadWrite)){
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);

    while(!in.atEnd()) {
        QString task = in.readLine();
        if (!task.isEmpty()) {
            QListWidgetItem* item = new QListWidgetItem("• " + task, ui->listWidget); // Prepend bullet point
            ui->listWidget->addItem(item);
            item->setFlags(item->flags() | Qt::ItemIsEditable);
        }
    }

    file.close();
}

MainWindow::~MainWindow()
{
    delete ui;

    QFile file(path);

    if(!file.open(QIODevice::ReadWrite)){
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream out(&file);

    for (int i = 0; i < ui->listWidget->count(); ++i){
        QString task = ui->listWidget->item(i)->text();
        task.remove(QRegularExpression("^\\s*•\\s*")); // Remove bullet point using QRegularExpression
        out << task << "\n";
    }

    file.close();
}

void MainWindow::on_btnAdd_clicked()
{
    QListWidgetItem* item = new QListWidgetItem("• " + ui->txtTask->text(), ui->listWidget);
    ui->listWidget->addItem(item);
    item->setFlags(item->flags() | Qt::ItemIsEditable);
    ui->txtTask->clear();
    ui->txtTask->setFocus();
}

void MainWindow::on_btnRemove_clicked()
{
    QListWidgetItem* item = ui->listWidget->takeItem(ui->listWidget->currentRow());
    delete item;
}

void MainWindow::on_btnRemoveAll_clicked()
{
    ui->listWidget->clear();
}
*/




#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QStandardPaths>
#include <QMessageBox>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Todo List");

    QFile file(path);

    if(!file.open(QIODevice::ReadWrite)){
        QMessageBox::information(0, "Error", file.errorString());
    }

    QTextStream in(&file);

    while(!in.atEnd()) {
        QString task = in.readLine();
        if (!task.isEmpty()) {
            QListWidgetItem* item = new QListWidgetItem("• " + task, ui->listWidget);
            ui->listWidget->addItem(item);
            item->setFlags(item->flags() | Qt::ItemIsEditable);
        }
    }

    file.close();
}

MainWindow::~MainWindow()
{
    saveToDoList(); // Save ToDo List when the application is closed
    delete ui;
}

void MainWindow::saveToDoList()
{
    QFile file(path);

    if(!file.open(QIODevice::ReadWrite)){
        QMessageBox::information(0, "Error", file.errorString());
    }

    QTextStream out(&file);

    for (int i = 0; i < ui->listWidget->count(); ++i){
        QString task = ui->listWidget->item(i)->text();
        task.remove(QRegularExpression("^\\s*•\\s*"));
        out << task << "\n";
    }

    file.close();
}

void MainWindow::on_btnAdd_clicked()
{
    QListWidgetItem* item = new QListWidgetItem("• " + ui->txtTask->text(), ui->listWidget);
    ui->listWidget->addItem(item);
    item->setFlags(item->flags() | Qt::ItemIsEditable);
    ui->txtTask->clear();
    ui->txtTask->setFocus();
    saveToDoList(); // Save ToDo List when an item is added
}

void MainWindow::on_btnRemove_clicked()
{
    QListWidgetItem* item = ui->listWidget->takeItem(ui->listWidget->currentRow());
    delete item;
    saveToDoList(); // Save ToDo List when an item is removed
}

void MainWindow::on_btnRemoveAll_clicked()
{
    ui->listWidget->clear();
    saveToDoList(); // Save ToDo List when all items are removed
}

