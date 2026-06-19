//
// Created by gabi on 6/13/26.
//

#include "GUI.h"
#include "GUI.h"

GUI::GUI(Service& srv): srv{srv} {
    aranjareInPagina();
    connect();
    reloadTable(srv.get_all_srv());
}

void GUI::aranjareInPagina() {
    QHBoxLayout* mainLayout = new QHBoxLayout(this);

    // LEFT
    QWidget* left = new QWidget;
    QVBoxLayout* lyLeft = new QVBoxLayout(left);
    QWidget* formLabels = new QWidget;
    QFormLayout* lyFormLabel = new QFormLayout(formLabels);
    lyFormLabel->addRow(lblCod, editCod);
    lyFormLabel->addRow(lblDenum, editDenum);
    lyFormLabel->addRow(lblMarime, editMarime);
    lyFormLabel->addRow(lblPret, editPret);
    lyFormLabel->addRow(lblDisponib, editDisponib);

    lyLeft->addWidget(formLabels);
    mainLayout->addWidget(left);

    // CENTER
    mainLayout->addWidget(tableRochii);

    // RIGHT
    QWidget* right = new QWidget;
    QVBoxLayout* lyRight = new QVBoxLayout(right);
    lyRight->addWidget(btnAdd);
    lyRight->addWidget(btnModify);
    lyRight->addWidget(btnRemove);

    mainLayout->addWidget(right);

}

void GUI::reloadTable(vector<Rochie> rochii) {
    tableRochii->clearContents();
    tableRochii->setRowCount(rochii.size());
    for (int i = 0; i < rochii.size(); i++) {
        tableRochii->setItem(i, 0, new QTableWidgetItem(QString::number(rochii[i].getCod())));
        tableRochii->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(rochii[i].getDenumire())));
        tableRochii->setItem(i, 2, new QTableWidgetItem(QString::number(rochii[i].getMarime())));
        tableRochii->setItem(i, 3, new QTableWidgetItem(QString::number(rochii[i].getPret())));
        if (rochii[i].getDisponibilitate()) {
            tableRochii->setItem(i, 4, new QTableWidgetItem("true"));
        }
        else {
            tableRochii->setItem(i, 4, new QTableWidgetItem("false"));
        }
    }
}

void GUI::connect() {
    QObject::connect(btnAdd, &QPushButton::clicked, this, [this] {
        vector<Rochie> rochii = srv.get_all_srv();
        try {
            if (editDisponib->text().toStdString() == "true") {
                Rochie r(stoi(editCod->text().toStdString()), editDenum->text().toStdString(),
                    stoi(editMarime->text().toStdString()), stoi(editPret->text().toStdString()), true);
                srv.addRochie_srv(r);
                reloadTable(srv.get_all_srv());
            }
            else {
                Rochie r(stoi(editCod->text().toStdString()), editDenum->text().toStdString(),
                    stoi(editMarime->text().toStdString()), stoi(editPret->text().toStdString()), false);
                srv.addRochie_srv(r);
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
    QObject::connect(btnModify, &QPushButton::clicked, this, [this] {
       vector<Rochie> rochii = srv.get_all_srv();
        try {
            if (editDisponib->text().toStdString() == "true") {
                Rochie r(stoi(editCod->text().toStdString()), editDenum->text().toStdString(),
                    stoi(editMarime->text().toStdString()), stoi(editPret->text().toStdString()), true);
                srv.updateRochie_srv(r);
                reloadTable(srv.get_all_srv());
            }
            else {
                Rochie r(stoi(editCod->text().toStdString()), editDenum->text().toStdString(),
                    stoi(editMarime->text().toStdString()), stoi(editPret->text().toStdString()), false);
                srv.updateRochie_srv(r);
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
    QObject::connect(btnRemove, &QPushButton::clicked, this, [this] {
        vector<Rochie> rochii = srv.get_all_srv();
        int selectedRow = tableRochii->currentRow();
        if (selectedRow >= 0) {
            int cod = rochii[selectedRow].getCod();
            srv.removeRochie_srv(cod);
            reloadTable(srv.get_all_srv());
        }
    });
}
