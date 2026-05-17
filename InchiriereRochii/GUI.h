//
// Created by gabi on 5/16/26.
//

#ifndef INCHIRIEREROCHII_GUI_H
#define INCHIRIEREROCHII_GUI_H

#include "Service.h"
#include "Repo.h"
#include "Rochie.h"

#include <QWidget>
#include <QListWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QFormLayout>
#include <QMessageBox>


class GUI: public QWidget {
    Q_OBJECT;
private:
    Service& srv;
    vector<Rochie> displayedRochii;
    QListWidget* lstRochii = new QListWidget;
    QPushButton* btnAddRochie = new QPushButton("Add rochie");
    QPushButton* btnModifyRochie = new QPushButton("Modify rochie");
    QPushButton* btnRemoveRochie = new QPushButton("Remove rochie");
    QLineEdit* cod = new QLineEdit;
    QLineEdit* denumire = new QLineEdit;
    QLineEdit* marime = new QLineEdit;
    QLineEdit* pret = new QLineEdit;
    QLineEdit* disponibil = new QLineEdit;
    QLabel* lblCod = new QLabel("Cod");
    QLabel* lblDenumire = new QLabel("Denumire");
    QLabel* lblMarime = new QLabel("Marime");
    QLabel* lblPret = new QLabel("Pret");
    QLabel* lblDisponibil = new QLabel("Disponibil");
    QTableWidget* tableRochii = new QTableWidget(5, 5);
public:
    GUI(Service& srv);
    void aranjareInPagina();
    void reloadList(vector<Rochie> rochiiToDisplay);
    void reloadTable(vector<Rochie> rochiiToDisplay);
    void connect();
};


#endif //INCHIRIEREROCHII_GUI_H
