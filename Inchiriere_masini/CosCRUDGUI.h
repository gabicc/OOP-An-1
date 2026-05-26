//
// Created by gabi on 5/24/26.
//

#ifndef INCHIRIERE_MASINI_COSCRUDGUI_H
#define INCHIRIERE_MASINI_COSCRUDGUI_H
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QPushButton>
#include <vector>
#include "Masina.h"
#include "Observer.h"
#include "Service.h"
class InchiriereGUI;

class CosCRUDGUI: public QWidget, public Observer {
private:
    Service& srv;
    InchiriereGUI* parent;
    QTableWidget* tblMasiniCos = new QTableWidget(10, 4);
    QPushButton* btnGenerareNMasini = new QPushButton("Generare masina in cos");
    QPushButton* btnGolireCos = new QPushButton("Golire cos");
public:
    CosCRUDGUI(Service& srv, InchiriereGUI* parent);

    void aranjareInPagina();

    void connect();

    void notify(const vector<Masina>& masini) override;

    void generareMasinaCRUD();

    void golireCosCRUD();
};


#endif //INCHIRIERE_MASINI_COSCRUDGUI_H
