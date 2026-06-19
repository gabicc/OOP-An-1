//
// Created by gabi on 6/19/26.
//

#include "GUI.h"

GUI::GUI(Service &srv) : srv{srv} {
    aranjareInPagina();
    connect();
    vector<Melodie> melodii = srv.get_all_srv();
    reloadTableMelodii(melodii);
    reloadTableView(melodii);
}

void GUI::aranjareInPagina() {
    QHBoxLayout *mainLayout = new QHBoxLayout(this);

    // LEFT
    QWidget *left = new QWidget;
    QVBoxLayout *lyLeft = new QVBoxLayout(left);
    QWidget *form = new QWidget;
    QFormLayout *lyForm = new QFormLayout(form);
    lyForm->addRow(lblTitlu, titluEdit);
    lyForm->addRow(lblArtist, artistEdit);
    lyForm->addRow(lblGen, genEdit);
    lyForm->addRow(btnAddMelodie, btnRemoveMeldie);

    lyLeft->addWidget(form);

    mainLayout->addWidget(left);

    // CENTER
    mainLayout->addWidget(tblMelodii);

    // RIGHT
    mainLayout->addWidget(tblViewMelodii);
}

void GUI::connect() {
    QObject::connect(btnAddMelodie, &QPushButton::clicked, this, [this] {
        string titlu = this->titluEdit->text().toStdString();
        string artist = this->artistEdit->text().toStdString();
        string gen = this->genEdit->text().toStdString();
        try {
            srv.addMelodie_srv(titlu, artist, gen);
            vector<Melodie> melodii = srv.get_all_srv();
            reloadTableMelodii(melodii);
            reloadTableView(melodii);
        } catch (RepoException &re) {
            QMessageBox::warning(this, "Info", re.what());
        } catch (ValidatorException &ve) {
            QMessageBox::warning(this, "Info", ve.what());
        }
    });
    QObject::connect(btnRemoveMeldie, &QPushButton::clicked, this, [this] {
        int selectedRow = tblViewMelodii->currentIndex().row();
        if (selectedRow >= 0) {
            vector<Melodie> melodii = srv.get_all_srv();
            int id_gasit = melodii[selectedRow].getId();
            srv.removeMelodie_srv(id_gasit);
            melodii = srv.get_all_srv();
            reloadTableMelodii(melodii);
            reloadTableView(melodii);
        }
    });
}

void GUI::reloadTableMelodii(vector<Melodie> melodiiToDilsplay) {
    for (int i = 0; i < melodiiToDilsplay.size(); i++) {
        tblMelodii->setItem(i, 0, new QTableWidgetItem(QString::number(melodiiToDilsplay[i].getId())));
        tblMelodii->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(melodiiToDilsplay[i].getTitlu())));
        tblMelodii->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(melodiiToDilsplay[i].getArtist())));
        tblMelodii->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(melodiiToDilsplay[i].getGen())));
    }
}

void GUI::reloadTableView(vector<Melodie> melodiiToDisplay) {
    // for (int i = 0; i < melodiiToDisplay.size(); i++) {
    //     int cont_artist = 0;
    //     int cont_gen = 0;
    //     for (int j = 0; j < melodiiToDisplay.size(); j++) {
    //         if (i != j) {
    //             if (melodiiToDisplay[i].getArtist() == melodiiToDisplay[j].getArtist())
    //                 cont_artist++;
    //             if (melodiiToDisplay[i].getGen() == melodiiToDisplay[j].getGen())
    //                 cont_gen++;
    //         }
    //     }
    // }
    tblViewMelodii->setModel(new MelodieTableModel(NULL, melodiiToDisplay));
}
