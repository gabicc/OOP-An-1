//
// Created by gabi on 5/16/26.
//

#include "GUI.h"

GUI::GUI(Service& srv): srv{srv} {
    aranjareInPagina();
    connect();
    vector<Rochie> all = srv.get_all_srv();

    reloadList(all);
    reloadTable(all);
}

void GUI::aranjareInPagina() {
    QHBoxLayout* mainLayout = new QHBoxLayout(this);

    // LEFT
    QWidget* left = new QWidget;
    QVBoxLayout* lyLeft = new QVBoxLayout(left);
    QWidget* formLabels = new QWidget;
    QFormLayout* lyFormLabels = new QFormLayout(formLabels);
    lyFormLabels->addRow(lblCod, cod);
    lyFormLabels->addRow(lblDenumire, denumire);
    lyFormLabels->addRow(lblMarime, marime);
    lyFormLabels->addRow(lblPret, pret);
    lyFormLabels->addRow(lblDisponibil, disponibil);
    lyFormLabels->addRow(btnAddRochie, btnModifyRochie);

    lyLeft->addWidget(formLabels);
    mainLayout->addWidget(left);

    // CENTER LEFT
    mainLayout->addWidget(lstRochii);

    // CENTER RIGHT
    QVBoxLayout* lyCenterRight = new QVBoxLayout;
    lyCenterRight->addWidget(btnRemoveRochie);

    mainLayout->addLayout(lyCenterRight);

    // RIGHT
    QStringList tblHeaderList;
    tblHeaderList << "Cod" << "Denumire" << "Marime" << "Pret" << "Disponibil";
    tableRochii->setHorizontalHeaderLabels(tblHeaderList);
    mainLayout->addWidget(tableRochii);
}

void GUI::reloadList(vector<Rochie> rochiiToDisplay) {
    displayedRochii = rochiiToDisplay;
    lstRochii->clear();
    for (auto& rochie: rochiiToDisplay) {
        lstRochii->addItem(QString::fromStdString(to_string(rochie.get_cod()) + " - " + rochie.get_denumire() + " - " +
        to_string(rochie.get_marime()) + " - " + to_string(rochie.get_pret()) + " - " + to_string(rochie.get_disponibil())));
    }
}

void GUI::reloadTable(vector<Rochie> rochiiToDisplay) {
    tableRochii->clear();
    tableRochii->setRowCount(rochiiToDisplay.size());
    for (int i = 0; i < rochiiToDisplay.size(); i++) {
        auto& rochie = rochiiToDisplay[i];
        tableRochii->setItem(i, 0, new QTableWidgetItem(QString::number(rochie.get_cod())));
        tableRochii->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(rochie.get_denumire())));
        tableRochii->setItem(i, 2, new QTableWidgetItem(QString::number(rochie.get_marime())));
        tableRochii->setItem(i, 3, new QTableWidgetItem(QString::number(rochie.get_pret())));
        tableRochii->setItem(i, 4, new QTableWidgetItem(QString::number(rochie.get_disponibil())));
    }
}

void GUI::connect() {
    QObject::connect(btnAddRochie, &QPushButton::clicked, this, [this] {
        vector<Rochie> rochii = srv.get_all_srv();
        try {
            if (disponibil->text().toStdString() == "1") {
                Rochie r(stoi(cod->text().toStdString()), denumire->text().toStdString(),
                    stod(marime->text().toStdString()), stod(pret->text().toStdString()), 1);
                srv.addRochie_srv(r);
                reloadList(srv.get_all_srv());
                reloadTable(srv.get_all_srv());
            }
            else if (disponibil->text().toStdString() == "0") {
                Rochie r(stoi(cod->text().toStdString()), denumire->text().toStdString(),
                    stod(marime->text().toStdString()), stod(pret->text().toStdString()), 0);
                srv.addRochie_srv(r);
                reloadList(srv.get_all_srv());
                reloadTable(srv.get_all_srv());
            }
        }
        catch (RepoException& re) {
            QMessageBox::warning(this, "Info", QString::fromStdString(re.what()));
        }
        catch (ValidatorException& ve) {
            QMessageBox::warning(this, "Info", QString::fromStdString(ve.what()));
        }
    });
}