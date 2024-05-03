#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Todo List");

    path = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/toDoFile.txt";

    QFile file(path);

    if(!file.open(QIODevice::ReadWrite)){
        QMessageBox::information(0, "Error", file.errorString());
    }

    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();
        if (!line.isEmpty()) {
            // Split the line to check if it contains a marker for the task type
            QStringList parts = line.split(':');
            if (parts.size() == 2 && parts[0] == "Priority Task") {
                // Create a PriorityTask object
                Task* task = new PriorityTask(parts[1], 1); // Assuming priority level 1
                tasks.append(task);
            } else {
                // Create a SimpleTask object
                Task* task = new SimpleTask(line);
                tasks.append(task);
            }
            // Add the task description to the list widget
            QListWidgetItem* item = new QListWidgetItem(line, ui->listWidget);
            ui->listWidget->addItem(item);
            item->setFlags(item->flags() | Qt::ItemIsEditable);
        }
    }

    file.close();
}


MainWindow::~MainWindow()
{
    saveToDoList(); // Save ToDo List when the application is closed
    qDeleteAll(tasks); // Delete all Task objects
    delete ui;
}

void MainWindow::saveToDoList()
{
    QFile file(path);

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)){
        QMessageBox::information(0, "Error", file.errorString());
    }

    QTextStream out(&file);

    for (Task* task : tasks) { // Loop through the list of Task objects
        out << dynamic_cast<Task*>(task)->getDescription() << "\n"; // Output task description
    }

    file.close();
}


void MainWindow::on_btnAdd_clicked()
{
    QString taskDescription = ui->txtTask->text();
    if (!taskDescription.isEmpty()) {
        Task* task = nullptr;

        // Check if the task description contains "today"
        if (taskDescription.contains("today", Qt::CaseInsensitive)) {
            task = new PriorityTask(taskDescription, 1);
        } else {
            task = new SimpleTask(taskDescription);
        }

        if (task) {
            tasks.append(task); // Add task to the list
            QListWidgetItem* item = new QListWidgetItem(task->getDescription(), ui->listWidget);
            ui->listWidget->addItem(item);
            item->setFlags(item->flags() | Qt::ItemIsEditable);
            ui->txtTask->clear();
            ui->txtTask->setFocus();
            saveToDoList(); // Save ToDo List when an item is added
        }
    }
}




void MainWindow::on_btnRemove_clicked()
{
    int row = ui->listWidget->currentRow();
    if (row >= 0 && row < tasks.size()) { // Check if valid row index
        delete tasks.takeAt(row); // Delete Task object
        ui->listWidget->takeItem(row); // Remove item from the list widget
        saveToDoList(); // Save ToDo List when an item is removed
    }
}

void MainWindow::on_btnRemoveAll_clicked()
{
    qDeleteAll(tasks); // Delete all Task objects
    tasks.clear(); // Clear the list
    ui->listWidget->clear(); // Clear the list widget
    saveToDoList(); // Save ToDo List when all items are removed
}


