//
// Created by gabi on 5/18/26.
//

#include "GUI.h"

GUI::GUI(Service &srv): srv{srv} {
    aranjareInPagina();
    connect();

    reloadListProcesoare(srv.get_all_procesor_srv());
    reloadListPlaci(srv.get_all_placi_srv());
}

void GUI::aranjareInPagina() {
    QHBoxLayout* mainLayout = new QHBoxLayout(this);

    // LEFT
    QWidget* left = new QWidget;
    QVBoxLayout* lyLeft = new QVBoxLayout(left);
    QFormLayout* lyFormLabels = new QFormLayout;
    lyFormLabels->addRow(lblNumePlaca, numePlaca);
    lyFormLabels->addRow(lblSocluPlaca, socluPlaca);
    lyFormLabels->addRow(lblPretPlaca, pretPlaca);
    lyFormLabels->addRow(btnAddPlaca);

    mainLayout->addLayout(lyFormLabels);

    // CENTER LEFT
    mainLayout->addWidget(lstProcesoare);

    // CENTER RIGHT
    mainLayout->addWidget(lstPlaci);

    // RIGHT
    QVBoxLayout* lyRight = new QVBoxLayout;
    lyRight->addWidget(btnFiltrarePlaci);
    lyRight->addWidget(btnPretTotal);

    mainLayout->addLayout(lyRight);
}

void GUI::connect() {
    QObject::connect(btnAddPlaca, &QPushButton::clicked, this, [this] {
        vector<PlacaDeBaza> placi = srv.get_all_placi_srv();
        PlacaDeBaza p(numePlaca->text().toStdString(), stoi(socluPlaca->text().toStdString()),
            stod(pretPlaca->text().toStdString()));
        try {
            srv.addPlaca_srv(p);
            reloadListPlaci(srv.get_all_placi_srv());
        }
        catch (RepoException& re) {
            QMessageBox::warning(this, "Info", QString::fromStdString(re.what()));
        }
        numePlaca->clear();
        socluPlaca->clear();
        pretPlaca->clear();
    });
    QObject::connect(btnFiltrarePlaci, &QPushButton::clicked, this, [this] {
        int selectedRow = this->lstPlaci->currentRow();
        if (selectedRow < 0) {
            QMessageBox::warning(this, "Info", "Selected row is unavailable");
            return;
        }
        vector<PlacaDeBaza> placi = srv.get_all_placi_srv();
        int soclu = placi[selectedRow].getSocluPlaca();
        vector<PlacaDeBaza> filtered = srv.filtrarePlaciSoclu_srv(soclu);
        reloadListPlaci(filtered);
    });
}

void GUI::reloadListPlaci(vector<PlacaDeBaza> placi) {
    displayedPlaci = placi;
    lstPlaci->clear();
    for (auto& p: placi) {
        auto* item = new QListWidgetItem(QString::fromStdString(p.getNumePlaca()) + " - " +
            QString::number(p.getSocluPlaca()) + " - " + QString::number(p.getPretPlaca()));
        if (p.getPretPlaca() > 1000)
            item->setBackground(Qt::red);
        else
            item->setBackground(Qt::green);
        lstPlaci->addItem(item);
    }
}

void GUI::reloadListProcesoare(vector<Procesor> procesoare) {
    displayedProcesoare = procesoare;
    lstProcesoare->clear();
    for (auto& p: procesoare) {
        auto* item = new QListWidgetItem(QString::fromStdString(p.getNume()) + " - " + QString::number(p.getNrThrd()) + " - " +
            QString::number(p.getSoclu()) + " - " + QString::number(p.getPret()));
        if (p.getPret() > 1000)
            item->setBackground(Qt::red);
        else
            item->setBackground(Qt::green);
        lstProcesoare->addItem(item);
    }
}