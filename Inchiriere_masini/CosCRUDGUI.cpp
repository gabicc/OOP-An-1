//
// Created by gabi on 5/24/26.
//

#include "CosCRUDGUI.h"
#include "InchiriereGUI.h"

CosCRUDGUI::CosCRUDGUI(Service& srv, InchiriereGUI* parent): srv{srv}, parent{parent} {
    aranjareInPagina();
    connect();
}

void CosCRUDGUI::aranjareInPagina() {
    QHBoxLayout* mainLayout = new QHBoxLayout(this);

    // LEFT
    QWidget* left = new QWidget;
    QVBoxLayout* lyLeft = new QVBoxLayout(left);

    lyLeft->addWidget(btnGenerareNMasini);
    lyLeft->addWidget(btnGolireCos);

    mainLayout->addWidget(left);

    // RIGHT
    mainLayout->addWidget(tblMasiniCos);
}

void CosCRUDGUI::connect() {
    QObject::connect(btnGenerareNMasini, &QPushButton::clicked, this, &CosCRUDGUI::generareMasinaCRUD);

    QObject::connect(btnGolireCos, &QPushButton::clicked, this, &CosCRUDGUI::golireCosCRUD);
}

void CosCRUDGUI::generareMasinaCRUD() {
    Masina m = Masina::genereaza_masina(rand());
    srv.adaugaMasina_srv(m);
    parent->reloadMasiniList(srv.get_all_srv());
}

void CosCRUDGUI::golireCosCRUD() {
    srv.golire_srv();
    parent->reloadMasiniList(srv.get_all_srv());
}

void CosCRUDGUI::notify(const vector<Masina>& masini) {
    tblMasiniCos->clearContents();
    tblMasiniCos->setRowCount(masini.size());
    for (int i = 0; i < masini.size(); i++) {
        const Masina& m = masini[i];
        tblMasiniCos->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(m.get_nr_inmatriculare())));
        tblMasiniCos->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(m.get_producator())));
        tblMasiniCos->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(m.get_model())));
        tblMasiniCos->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(m.get_tip())));
    }
}
