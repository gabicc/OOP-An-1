//
// Created by gabi on 6/21/26.
//

#ifndef TASKSAPLICATIE_GUI_H
#define TASKSAPLICATIE_GUI_H

#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTableWidget>
#include <QTableView>
#include <QSlider>
#include <QFormLayout>
#include <QPushButton>
#include <QMessageBox>

#include <exception>

#include <iostream>
#include <string.h>
#include <vector>
#include "Task.h"
#include <fstream>
#include <sstream>
#include "Repo.h"
#include "Validator.h"
#include <assert.h>
#include "Service.h"
#include <QAbstractTableModel>

using namespace std;

class TaskTableModel: public QAbstractTableModel {
    Q_OBJECT;
private:
    vector<Task> taskuri;
public:
    TaskTableModel(QObject* parent, vector<Task> tasks): QAbstractTableModel{parent}, taskuri{tasks} {};
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
};

class GUI: public QWidget {
    Q_OBJECT;
private:
    Service& srv;
    QTableWidget* tableTasks = new QTableWidget(10, 4);
    QTableView* tableViewTasks = new QTableView;
    QLabel* lblId = new QLabel("Id");
    QLabel* lblDescriere = new QLabel("Denumire");
    QLabel* lblProgramatori = new QLabel("Programatori: ");
    QLabel* lblStare = new QLabel("Stare");
    QLineEdit* idEdit = new QLineEdit;
    QLineEdit* descriereEdit = new QLineEdit;
    QLineEdit* programatoriEdit = new QLineEdit;
    QLineEdit* stareEdit = new QLineEdit;
    QSlider* idSlider = new QSlider(Qt::Horizontal);
    QLabel* idValue = new QLabel("0");
    QLabel* idLabelSlider = new QLabel("Id");
    QPushButton* btnAddTask = new QPushButton("Add");
    QPushButton* btnFindTask = new QPushButton("Find");
    QPushButton* btnOpen = new QPushButton("Open");
    QPushButton* btnInPorgress = new QPushButton("Inprogress");
    QPushButton* btnClosed = new QPushButton("Closed");
    QLabel* lblProgramatorFind = new QLabel("Programator");
    QLineEdit* progEdit = new QLineEdit;
public:
    GUI(Service& srv);
    void aranjareInPagina();
    void connect();
    void reloadTableTasks(vector<Task> taskuri);
    void reloadTableViewTasks(vector<Task> taskuri);
};


#endif //TASKSAPLICATIE_GUI_H
