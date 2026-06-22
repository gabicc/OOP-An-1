//
// Created by gabi on 6/22/26.
//

#ifndef STUDENTIAPLICATIE_GUI_H
#define STUDENTIAPLICATIE_GUI_H

#include <iostream>
#include <string>
#include "Student.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <exception>
#include "Repo.h"
#include "Validator.h"
#include "Service.h"
#include <assert.h>

using namespace std;

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableWidget>
#include <QTableView>
#include <QPushButton>
#include <QAbstractTableModel>

class StudentsTableModel: public QAbstractTableModel {
private:
    vector<Student> studenti;
public:
    StudentsTableModel(QObject* parent, vector<Student> studs): QAbstractTableModel{parent}, studenti{studs} {};
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
};

class GUI: public QWidget {
    Q_OBJECT;
private:
    Service& srv;
    QTableView* tableViewStudents = new QTableView;
    QTableWidget* tableStudents = new QTableWidget(10, 4);
    QPushButton* btnIntinerire = new QPushButton("Intinerire");
    QPushButton* btnImbatranire = new QPushButton("Imbatranire");
    QPushButton* btnSterge = new QPushButton("Sterge");
    QPushButton* btnUndo = new QPushButton("Undo");
    QPushButton* btnRedo = new QPushButton("Redo");
public:
    GUI(Service& srv);
    void aranjareInPagina();
    void connect();
    void reloadTableStudents(vector<Student> studenti);
    void reloadTableViewStudents(vector<Student> studenti);

};


#endif //STUDENTIAPLICATIE_GUI_H
