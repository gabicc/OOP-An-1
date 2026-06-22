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
            srv.saveToFile_srv();
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
            srv.saveToFile_srv();
        }
    });
}

void GUI::reloadTableMelodii(vector<Melodie> melodiiToDilsplay) {
    tblMelodii->clearContents();
    tblMelodii->setRowCount(melodiiToDilsplay.size());
    for (int i = 0; i < melodiiToDilsplay.size(); i++) {
        tblMelodii->setItem(i, 0, new QTableWidgetItem(QString::number(melodiiToDilsplay[i].getId())));
        tblMelodii->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(melodiiToDilsplay[i].getTitlu())));
        tblMelodii->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(melodiiToDilsplay[i].getArtist())));
        tblMelodii->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(melodiiToDilsplay[i].getGen())));
    }
}

void GUI::reloadTableView(vector<Melodie> melodiiToDisplay) {
    tblViewMelodii->setModel(new MelodieTableModel(NULL, melodiiToDisplay));
}

int MelodieTableModel::rowCount(const QModelIndex &parent) const {
    return melodii.size();
}
int MelodieTableModel::columnCount(const QModelIndex &parent) const {
    return 6;
}
QVariant MelodieTableModel::data(const QModelIndex &index, int role ) const {
    int row = index.row();
    int col = index.column();
    switch (role) {
        case Qt::DisplayRole: {
            Melodie a = melodii[row];
            int cont_artisti = 1;
            int cont_gen = 1;
            for (int i = 0; i < melodii.size(); i++) {
                if (i != row) {
                    if (melodii[i].getArtist() == a.getArtist())
                        cont_artisti++;
                    if (melodii[i].getGen() == a.getGen())
                        cont_gen++;
                }
            }
            switch (col) {
                case 0: return QString::number(a.getId());
                case 1: return QString::fromStdString(a.getTitlu());
                case 2: return QString::fromStdString(a.getArtist());
                case 3: return QString::fromStdString(a.getGen());
                case 4: return QString::number(cont_artisti);
                case 5: return QString::number(cont_gen);
            }
        }
    }
    return QVariant();
}
QVariant MelodieTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (orientation == Qt::Horizontal) {
        switch (role) {
            case Qt::DisplayRole: {
                switch (section) {
                    case 0: return QString("Id");
                    case 1: return QString("Titlu");
                    case 2: return QString("Artist");
                    case 3: return QString("Gen");
                    case 4: return QString("Contor artisti");
                    case 5: return QString("Contor gen");
                }
            }
        }
    }
    return QVariant();
}
