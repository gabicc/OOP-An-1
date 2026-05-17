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
#include <vector>
#include <QHeaderView>
#include <QMessageBox>
#include <QFormLayout>

class GUI : public QWidget {
    Q_OBJECT;

private:
    Service &srv;
    vector<Masina> displayedMasini;
    QListWidget *lstMasini = new QListWidget;

    QLineEdit *nrMatricol = new QLineEdit;
    QLabel *lblNrMatricol = new QLabel("Nr Matricol");
    QLabel *lblModel = new QLabel("Model");
    QLabel *lblCuloare = new QLabel("Culoare");
    QLabel *lblKm = new QLabel("Km");
    QLineEdit *model = new QLineEdit;
    QLineEdit *culoare = new QLineEdit;
    QLineEdit *km = new QLineEdit;
    QPushButton *btnAddMasina = new QPushButton("Add masina");
    QPushButton *btnModifyMasina = new QPushButton("Modify masina");
    QPushButton *btnShowAllMasini = new QPushButton("Show all masini");
    QPushButton *btnShowDetaliiMasini = new QPushButton("Show detalii masini");
    QPushButton *btnRentMasina = new QPushButton("Rent masina");
    QPushButton *btnSortareModel = new QPushButton("Sortare dupa model");
    QPushButton *btnSorareNrMatricol = new QPushButton("Sortare dupa nr matricol");
    QPushButton *btnNesortat = new QPushButton("Nesortat");
    QTableWidget *tableMasini = new QTableWidget(10, 4);

public:
    GUI(Service &srv);

    void aranjareInPagina();

    void reloadList(const vector<Masina> &masiniToDisplay) {
        displayedMasini = masiniToDisplay;
        lstMasini->clear();
        for (const auto &masina: masiniToDisplay) {
            lstMasini->addItem(QString::fromStdString(masina.getNrMatricol() + " - " + masina.getModel()
                                                      + " - " + masina.getCuloare()
                                                      + " - " + to_string((int) masina.getKm())));
        }
    }

    void reloadTable(const vector<Masina> &masiniToDisplay) {
        tableMasini->clear();
        for (int i = 0; i < masiniToDisplay.size(); i++) {
            auto &masina = masiniToDisplay[i];
            tableMasini->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(masina.getNrMatricol())));
            tableMasini->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(masina.getModel())));
            tableMasini->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(masina.getCuloare())));
            tableMasini->setItem(i, 3, new QTableWidgetItem(QString::number(masina.getKm())));
        }
    }

    void connect() {
        QObject::connect(btnAddMasina, &QPushButton::clicked, this, [this] {
            try {
                Masina m(nrMatricol->text().toStdString().data(), model->text().toStdString().data(),
                         culoare->text().toStdString().data(), km->text().toDouble());
                srv.addMasina_srv(m);
                vector<Masina> masini = srv.get_all_srv();
                reloadList(masini);
                reloadTable(masini);
            } catch (RepoException &re) {
                QMessageBox::warning(this, "Info", QString::fromStdString(re.what()));
            }
        });
        QObject::connect(btnModifyMasina, &QPushButton::clicked, this, [this] {
            int selectedRow = this->tableMasini->currentRow();
            if (selectedRow < 0) {
                return;
            }
            Masina m(nrMatricol->text().toStdString().data(), model->text().toStdString().data(),
                     culoare->text().toStdString().data(), km->text().toDouble());
            srv.updateMasina_srv(displayedMasini[selectedRow].getNrMatricol().data(), m);
            vector<Masina> masini = srv.get_all_srv();
            reloadTable(masini);
            reloadList(masini);
        });
        QObject::connect(btnShowAllMasini, &QPushButton::clicked, this, [this] {
            reloadList(srv.get_all_srv());
        });
        QObject::connect(btnShowDetaliiMasini, &QPushButton::clicked, this, [this] {
            int selectedRow = this->lstMasini->currentRow();
            if (selectedRow < 0) {
                return;
            }
            Masina masina = displayedMasini[selectedRow];
            nrMatricol->setText(QString::fromStdString(masina.getNrMatricol()));
            model->setText(QString::fromStdString(masina.getModel()));
            culoare->setText(QString::fromStdString(masina.getCuloare()));
            km->setText(QString::number(masina.getKm()));
        });
        QObject::connect(btnRentMasina, &QPushButton::clicked, this, [this] {
            int selectedRow = this->tableMasini->currentRow();
            if (selectedRow < 0) {
                return;
            }
            Masina m = displayedMasini[selectedRow];
            try {
                srv.rentMasina_srv(m.getNrMatricol().data());
                vector<Masina> all = srv.get_all_srv();
                reloadList(all);
                reloadTable(all);
            } catch (RepoException &re) {
                QMessageBox::warning(this, "Info", QString::fromStdString("Masina nu poate fi inchiriata"));
            }
        });
        QObject::connect(btnSorareNrMatricol, &QPushButton::clicked, this, [this] {
            vector<Masina> masini_sorted = srv.sortareNrMatricol_srv();
            reloadList(masini_sorted);
            reloadTable(masini_sorted);
        });
        QObject::connect(btnSortareModel, &QPushButton::clicked, this, [this] {
            vector<Masina> masini_sorted = srv.sortareModel_srv();
            reloadList(masini_sorted);
            reloadTable(masini_sorted);
        });
    }
};


#endif //PRACTICE_MASINI_RULATE_GUI_H
