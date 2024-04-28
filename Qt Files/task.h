#ifndef TASK_H
#define TASK_H

#include <QString>

// Base class representing a generic task
class Task {
public:
    virtual ~Task() {} // Virtual destructor for polymorphism
    virtual QString getDescription() const = 0; // Pure virtual function
};

// Derived class representing a simple task
class SimpleTask : public Task {
public:
    explicit SimpleTask(const QString& description) : description(description) {}
    QString getDescription() const override {
        return "Simple Task: " + description;
    }
private:
    QString description;
};

// Derived class representing a priority task
class PriorityTask : public Task {
public:
    explicit PriorityTask(const QString& description, int priority) : description(description), priority(priority) {}
    QString getDescription() const override {
        return "Priority Task: " + description + " (Priority: " + QString::number(priority) + ")";
    }
private:
    QString description;
    int priority;
};

#endif // TASK_H
