//
// Created by gabi on 5/5/26.
//

#include "InchiriereGUI.h"

void InchiriereGUI::initializeGUIComponents() {
    QHBoxLayout* lyMain = new QHBoxLayout;
    this->setLayout(lyMain);

    QWidget* left = new QWidget;
    QVBoxLayout* lyLeft = new QVBoxLayout;
    left -> setLayout(lyLeft);

    QWidget* form = new QWidget;
    QFormLayout* lyForm = new QFormLayout;
    form->setLayout(lyForm);
    editNrInmatric = new QLineEdit;
    editProducator = new QLineEdit;
    editModel = new QLineEdit;
    editTip = new QLineEdit;

    lyForm->addRow(lblNrInmatric, editNrInmatric);
    lyForm->addRow(lblProducator, editProducator);
    lyForm->addRow(lblModel, editModel);
    lyForm->addRow(lblTip, editTip);
    btnAddMasina = new QPushButton("Adauga masina");
    btnModifyMasina = new QPushButton("Modifica masina");

    //lyForm->addWidget(btnAddMasina);
    lyForm->addRow(btnAddMasina, btnModifyMasina);

    lyLeft->addWidget(form);

    QWidget* right = new QWidget;
    QVBoxLayout* lyRight = new QVBoxLayout;
    right ->setLayout(lyRight);

    int noLines = 10;
    int noColumns = 4;
    this->tableMasini = new QTableWidget{noLines, noColumns};

    QStringList tblHeaderList;
    tblHeaderList << "Nr Inmatriculare" << "Producator" << "Model" << "Tip";
    this->tableMasini->setHorizontalHeaderLabels(tblHeaderList);

    this->tableMasini->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    lyRight->addWidget(tableMasini);

    QWidget* formSearch = new QWidget;
    QFormLayout* lyFormSearch = new QFormLayout;
    formSearch->setLayout(lyFormSearch);

    btnFilterMasiniProducator = new QPushButton("Filtreaza masini dupa producator");
    btnFilterMasiniTip = new QPushButton("Filtreaza masini dupa tip");

    btnRemoveMasina = new QPushButton("Sterge masina");
    lyFormSearch->addRow(btnRemoveMasina);
    lyFormSearch->addRow( btnFilterMasiniProducator, btnFilterMasiniTip);

    lyRight->addWidget(formSearch);

    lyMain->addWidget(left);
    lyMain->addWidget(right);
}

void InchiriereGUI::connectSignalsSlots() {

}
void InchiriereGUI::reloadMasiniList(vector<Masina> masini) {
    masini = srv.get_all_srv();
}

void InchiriereGUI::guiAddMasina() {

}
