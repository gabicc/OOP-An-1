//
// Created by gabi on 5/19/26.
//

#ifndef SIMULAREMOBILA_GUI_H
#define SIMULAREMOBILA_GUI_H

#include "Service.h"
#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTableWidget>
#include <QPushButton>
#include <vector>
#include "Mobila.h"
#include <QMessageBox>
#include <QRadioButton>

class GUI: public QWidget {
    Q_OBJECT
private:
    Service& srv;
    vector<Mobila> displayedMobile;
    QTableWidget* tableMobile = new QTableWidget(10, 4);
    QLabel* lblID = new QLabel("ID");
    QLabel* lblType = new QLabel("Type");
    QLabel* lblNrPieces = new QLabel("Nr pieces");
    QLabel* lblAssemblyTime = new QLabel("Assembly time");
    QLineEdit* ID = new QLineEdit;
    QLineEdit* type = new QLineEdit;
    QLineEdit* nrPieces = new QLineEdit;
    QLineEdit* assemblyTime = new QLineEdit;
    QPushButton* btnAddMobila = new QPushButton("Add mobila");
    QPushButton* btnFilterType = new QPushButton("Filter by type");
    QPushButton* btnSortareNrPieces = new QPushButton("Sortare dupa nr pieces");
    QPushButton* btnSortareAssemblyTime = new QPushButton("Sortare dupa assembly time");
    QRadioButton* radioBtnNrPieces = new QRadioButton("Nr pieces");
    QRadioButton* radioBtnAssemblyTime = new QRadioButton("Assembly time");
    QPushButton* btnSortare = new QPushButton("Sortare");
public:
    GUI(Service& srv);
    ~GUI() {

    }
    void aranjareInPagina();
    void connect();

    void reloadTable(vector<Mobila> mobile);
};


#endif //SIMULAREMOBILA_GUI_H
