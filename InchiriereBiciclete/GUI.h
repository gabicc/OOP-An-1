//
// Created by gabi on 5/17/26.
//

#ifndef INCHIRIEREBICICLETE_GUI_H
#define INCHIRIEREBICICLETE_GUI_H

#include "Service.h"
#include <vector>
#include "Bicicleta.h"
#include <QWidget>
#include "Repo.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListWidget>
#include <QTableWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QStringList>

class GUI: public QWidget{
    Q_OBJECT;
private:
    Service& srv;
    vector<Bicicleta> displayedBiciclete;
    QPushButton* btnInchiriereBicicleta = new QPushButton("Inchiriere bicicleta");
    QPushButton* btnSortareMarime = new QPushButton("Sortare dupa marime");
    QPushButton* btnSortarePret = new QPushButton("Sortare dupa pret");
    QPushButton* btnNesortat = new QPushButton("Nesortat");
    QListWidget* lstBiciclete = new QListWidget;
    QTableWidget* tblBiciclete = new QTableWidget(5, 5);

public:
    GUI(Service& srv);
    ~GUI() {

    }

    void aranjareInPagina();
    void connect();

    void reloadList(vector<Bicicleta> biciclete);
    void reloadTable(vector<Bicicleta> biciclete);
};


#endif //INCHIRIEREBICICLETE_GUI_H
