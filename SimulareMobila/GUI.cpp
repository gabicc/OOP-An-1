//
// Created by gabi on 5/19/26.
//

#include "GUI.h"

GUI::GUI(Service& srv): srv{srv} {
    aranjareInPagina();
    connect();

    reloadTable(srv.getAll_srv());
}

void GUI::aranjareInPagina() {
    QHBoxLayout* mainLayout = new QHBoxLayout(this);

    // LEFT
    QWidget* left = new QWidget;
    QVBoxLayout* lyLeft = new QVBoxLayout(left);
    QFormLayout* lyForm = new QFormLayout;
    lyForm->addRow(lblID, ID);
    lyForm->addRow(lblType, type);
    lyForm->addRow(lblNrPieces, nrPieces);
    lyForm->addRow(lblAssemblyTime, assemblyTime);
    lyForm->addRow(btnAddMobila);
    lyLeft->addLayout(lyForm);

    mainLayout->addWidget(left);

    // CENTER LEFT
    QStringList tableHeaderList;
    tableHeaderList << "ID" << "Type" << "Nr pieces" << "Assembly time";
    tableMobile->setHorizontalHeaderLabels(tableHeaderList);
    mainLayout->addWidget(tableMobile);

    // CENTER RIGHT
    QWidget* right = new QWidget;
    QVBoxLayout* lyRight = new QVBoxLayout(right);
    lyRight->addWidget(btnFilterType);

    mainLayout->addWidget(right);

    // RIGHT
    QWidget* radioButtons = new QWidget;
    QVBoxLayout* lyRadioButtons = new QVBoxLayout(radioButtons);
    lyRadioButtons->addWidget(radioBtnNrPieces);
    lyRadioButtons->addWidget(radioBtnAssemblyTime);
    lyRadioButtons->addWidget(btnSortare);

    mainLayout->addWidget(radioButtons);

}
void GUI::connect() {
    QObject::connect(btnAddMobila, &QPushButton::clicked, this, [this] {
        vector<Mobila> mobile;
        Mobila m(ID->text().toInt(), type->text().toStdString(), nrPieces->text().toInt(), assemblyTime->text().toInt());
        try {
            srv.addMobila_srv(m);
            reloadTable(srv.getAll_srv());
        }
        catch (ValidatorException& ve) {
            QMessageBox::warning(this, "Info", QString::fromStdString(ve.what()));
        }
    });
    QObject::connect(btnFilterType, &QPushButton::clicked, this, [this] {
        int selectedRow = tableMobile->currentRow();
        if (selectedRow < 0) {
            reloadTable(srv.getAll_srv());
        }
        else {
            string type = displayedMobile[selectedRow].getType();
            vector<Mobila> filtered = srv.filtrareType_srv(type);
            reloadTable(filtered);
        }
    });
    QObject::connect(btnSortareAssemblyTime, &QPushButton::clicked, this, [this] {
       vector<Mobila> sorted = srv.sortareAssemblyTime_srv();
        reloadTable(sorted);
    });
    QObject::connect(btnSortareNrPieces, &QPushButton::clicked, this, [this] {
        vector<Mobila> sorted = srv.sortareNrPieces_srv();
        reloadTable(sorted);
    });
    QObject::connect(btnSortare, &QPushButton::clicked, this, [this] {
       if (radioBtnNrPieces->isChecked()) {
           vector<Mobila> sorted = srv.sortareNrPieces_srv();
           reloadTable(sorted);
       }
       else if (radioBtnAssemblyTime->isChecked()) {
           vector<Mobila> sorted = srv.sortareAssemblyTime_srv();
           reloadTable(sorted);
       }
    });
}

void GUI::reloadTable(vector<Mobila> mobileToDisplay) {
    displayedMobile = mobileToDisplay;
    tableMobile->clearContents();
    tableMobile->setRowCount(displayedMobile.size());
    for (int i = 0; i < displayedMobile.size(); i++) {
        tableMobile->setItem(i, 0, new QTableWidgetItem(QString::number(displayedMobile[i].getId())));
        tableMobile->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(displayedMobile[i].getType())));
        tableMobile->setItem(i, 2, new QTableWidgetItem(QString::number(displayedMobile[i].getNrPieces())));
        tableMobile->setItem(i, 3, new QTableWidgetItem(QString::number(displayedMobile[i].getAssemblyTime())));
    }
}