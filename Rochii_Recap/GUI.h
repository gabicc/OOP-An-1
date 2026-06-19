//
// Created by gabi on 6/13/26.
//

#ifndef ROCHII_RECAP_GUI_H
#define ROCHII_RECAP_GUI_H
#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QTableWidget>
#include "Service.h"
#include "Rochie.h"
#include <QFormLayout>
#include <QMessageBox>

class GUI: public QWidget {
    Q_OBJECT
private:
    Service& srv;
    QTableWidget* tableRochii = new QTableWidget(10, 5);
    QLineEdit* editCod = new QLineEdit;
    QLineEdit* editDenum = new QLineEdit;
    QLineEdit* editMarime = new QLineEdit;
    QLineEdit* editPret = new QLineEdit;
    QLineEdit* editDisponib = new QLineEdit;
    QLabel* lblCod = new QLabel("Cod");
    QLabel* lblDenum = new QLabel("Denumire");
    QLabel* lblMarime = new QLabel("Marime");
    QLabel* lblPret = new QLabel("Pret");
    QLabel* lblDisponib = new QLabel("Disponibilitate");
    QPushButton* btnAdd = new QPushButton("Add");
    QPushButton* btnModify = new QPushButton("Modify");
    QPushButton* btnRemove = new QPushButton("Remove");
public:
    GUI(Service& srv);
    virtual ~GUI() {

    }
    void aranjareInPagina();
    void connect();
    void reloadTable(vector<Rochie> rochii);
};


#endif //ROCHII_RECAP_GUI_H
