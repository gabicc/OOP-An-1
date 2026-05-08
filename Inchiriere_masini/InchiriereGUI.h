//
// Created by gabi on 5/5/26.
//

#ifndef INCHIRIERE_MASINI_INCHIRIEREGUI_H
#define INCHIRIERE_MASINI_INCHIRIEREGUI_H

#include <iostream>
#include <vector>
#include <string>
#include <QtWidgets/QApplication>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QGroupBox>
#include "Service.h"
#include <QRadioButton>
#include <QTableWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QHeaderView>

using namespace std;

class InchiriereGUI: public QWidget {
private:
    Service& srv;

    QLabel* lblNrInmatric = new QLabel{"Nr Inmatriculare: "};
    QLabel* lblProducator = new QLabel{"Producator: "};
    QLabel* lblModel = new QLabel{"Model: "};
    QLabel* lblTip = new QLabel{"Tip: "};

    QLineEdit* editNrInmatric;
    QLineEdit* editProducator;
    QLineEdit* editModel;
    QLineEdit* editTip;

    QPushButton* btnAddMasina;
    QPushButton* btnRemoveMasina;
    QPushButton* btnModifyMasina;
    QPushButton* btnFilterMasiniProducator;
    QPushButton* btnFilterMasiniTip;

    QGroupBox* groupBox = new QGroupBox(tr("Tip sortare"));

    QRadioButton* radioSrtNrInmatric = new QRadioButton(QString::fromStdString("Nr Inmatriculare"));
    QRadioButton* radioSrtTip = new QRadioButton(QString::fromStdString("Tip"));
    QRadioButton* radioSrtProducatorModel = new QRadioButton(QString::fromStdString("Producator+Model"));

    QPushButton* btnReloadData;

    QTableWidget* tableMasini;

    void initializeGUIComponents();

    void connectSignalsSlots();
    void reloadMasiniList(vector<Masina> masini);
public:
    InchiriereGUI(Service& srv): srv{srv} {
        initializeGUIComponents();
        connectSignalsSlots();
        reloadMasiniList(srv.get_all_srv());
    }
    void guiAddMasina();

};


#endif //INCHIRIERE_MASINI_INCHIRIEREGUI_H
