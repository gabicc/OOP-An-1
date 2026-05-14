//
// Created by gabi on 5/14/26.
//

#ifndef PRACTICE_MASINI_RULATE_GUI_H
#define PRACTICE_MASINI_RULATE_GUI_H

#include "Service.h"
#include "Repo.h"
#include "Masina.h"
#include <QWidget>
#include <QListWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <bits/syscall.h>

class GUI: public QWidget {
    Q_OBJECT;
private:
    Service& srv;
    QlistWidget* lstMasini = new QListWidget;
    QLineEdit* nrMatricol = new QLineEdit;
    QLineEdit* model = new QLineEdit;
    QLineEdit* culoare = new QLineEdit;
    QLineEdit* km = new QLineEdit;
    QPushButton* showAllMasini = new QPushButton("Show all masini");
    QPushButton* showDetaliiMasini = new QPushButton("Show detalii masini");
    QPushButton* sortareModel = new QPushButton("Sortare dupa model");
    QPushButton* sorareNrMatricol = new QPushButton("Sortare dupa nr matricol");
    QPushButton* nesortat = new QPushButton("Nesortat");
public:
    GUI(Service& srv): srv{srv} {
        auto* mainLayout = new QHBoxLayout;
        auto* buttonLayout = new QVBoxLayout;
        mainLayout->addWidget(lstMasini);
        mainLayout->addWidget(buttonLayout);

        buttonLayout->addWidget(showAllMasini);
        buttonLayout->addWidget(showDetaliiMasini);
        buttonLayout->addWidget(sorareNrMatricol);
        buttonLayout->addWidget(sortareModel);
        buttonLayout->addWidget(nesortat);
        connect();

        populateList(srv.get_all_srv());

    };
};


#endif //PRACTICE_MASINI_RULATE_GUI_H
