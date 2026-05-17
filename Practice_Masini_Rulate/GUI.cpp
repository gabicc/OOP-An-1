//
// Created by gabi on 5/14/26.
//

#include "GUI.h"

GUI::GUI(Service& srv): srv{srv} {
    aranjareInPagina();
    connect();
    vector<Masina> all = srv.get_all_srv();

    reloadList(all);
    reloadTable(all);
};

void GUI::aranjareInPagina() {
    QHBoxLayout* mainLayout = new QHBoxLayout(this);


    // LEFT
    QWidget* left = new QWidget;
    QVBoxLayout* lyLeft = new QVBoxLayout(left);
    //left->setLayout(lyLeft);
    QWidget* formLabels = new QWidget;
    QFormLayout* lyFormLeftLabels = new QFormLayout(formLabels);
    lyFormLeftLabels->addRow(lblNrMatricol, nrMatricol);
    lyFormLeftLabels->addRow(lblModel, model);
    lyFormLeftLabels->addRow(lblCuloare, culoare);
    lyFormLeftLabels->addRow(lblKm, km);
    lyFormLeftLabels->addRow(btnAddMasina, btnModifyMasina);

    lyLeft->addWidget(formLabels);
    mainLayout->addWidget(left);

    // CENTER LEFT
    mainLayout->addWidget(lstMasini);
    // QWidget* center = new QWidget;
    // QVBoxLayout* lyCenter = new QVBoxLayout(center);
    // lyCenter->addWidget(lstMasini);

    // CENTER RIGHT
    QWidget* formCenterRight = new QWidget;
    QVBoxLayout* lyCenterRight = new QVBoxLayout(formCenterRight);
    lyCenterRight->addWidget(btnShowAllMasini);
    lyCenterRight->addWidget(btnShowDetaliiMasini);
    lyCenterRight->addWidget(btnRentMasina);
    lyCenterRight->addWidget(btnSorareNrMatricol);
    lyCenterRight->addWidget(btnSortareModel);
    lyCenterRight->addWidget(btnNesortat);

    mainLayout->addWidget(formCenterRight);

    // RIGHT
    QStringList tblHeaderList;
    tblHeaderList << "Nr Inmatriculare" << "Model" << "Culoare" << "Km";
    tableMasini->setHorizontalHeaderLabels(tblHeaderList);

    mainLayout->addWidget(tableMasini);

}