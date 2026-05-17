//
// Created by gabi on 5/17/26.
//

#include "GUI.h"

GUI::GUI(Service& srv): srv{srv} {
    aranjareInPagina();
    connect();

    reloadList(srv.get_all_srv());
    reloadTable(srv.get_all_srv());
}

void GUI::aranjareInPagina() {
    QHBoxLayout* mainLayout = new QHBoxLayout(this);

    // LEFT
    mainLayout->addWidget(lstBiciclete);

    // CENTER
    QWidget* center = new QWidget;
    QVBoxLayout* lyCenter = new QVBoxLayout(center);

    lyCenter->addWidget(btnInchiriereBicicleta);
    lyCenter->addWidget(btnSortareMarime);
    lyCenter->addWidget(btnSortarePret);
    lyCenter->addWidget(btnNesortat);

    mainLayout->addWidget(center);

    // RIGHT
    QStringList tblHeaderList;
    tblHeaderList << "Cod" << "Denumire" << "Marime" << "Pret" << "Disponibila";
    tblBiciclete->setHorizontalHeaderLabels(tblHeaderList);
    mainLayout->addWidget(tblBiciclete);
}

void GUI::connect() {
    QObject::connect(btnInchiriereBicicleta, &QPushButton::clicked, this, [this] {
        int clickedRow = this->tblBiciclete->currentRow();
        if (clickedRow < 0) {
            return;
        }
        int cod = this->tblBiciclete->item(clickedRow, 0)->text().toInt();
        try {
            srv.inchiriereBicicleta_srv(cod);
            reloadList(srv.get_all_srv());
            reloadTable(srv.get_all_srv());
        }
        catch (RepoException& re) {
            QMessageBox::warning(this, "Info", QString::fromStdString(re.what()));
        }
    });
    QObject::connect(btnSortareMarime, &QPushButton::clicked, this, [this] {
        vector<Bicicleta> sorted = srv.sortareMarime_srv();
        reloadList(sorted);
        reloadTable(sorted);
    });
    QObject::connect(btnSortarePret, &QPushButton::clicked, this, [this] {
       vector<Bicicleta> sorted = srv.sortarePret_srv();
        reloadList(sorted);
        reloadTable(sorted);
    });
    QObject::connect(btnNesortat, &QPushButton::clicked, this, [this] {
       vector<Bicicleta> nesortat = srv.nesortat_srv();
        reloadList(nesortat);
        reloadTable(nesortat);
    });
}

void GUI::reloadList(vector<Bicicleta> biciclete) {
    displayedBiciclete = biciclete;
    lstBiciclete->clear();
    for (Bicicleta& b: biciclete) {
        if (b.getDisponibila() == 1)
            lstBiciclete->addItem(QString::fromStdString((to_string(b.getCod()) + " - " + b.getDenumire() + " - "
            + b.getMarime() + " - " + to_string(b.getPret()) + " - " + "True")));
        else
            lstBiciclete->addItem(QString::fromStdString((to_string(b.getCod()) + " - " + b.getDenumire() + " - "
            + b.getMarime() + " - " + to_string(b.getPret()) + " - " + "False")));
    }
}

void GUI::reloadTable(vector<Bicicleta> biciclete) {
    tblBiciclete->clearContents();
    tblBiciclete->setRowCount(biciclete.size());
    for (int i = 0; i < biciclete.size(); i++) {
        tblBiciclete->setItem(i, 0, new QTableWidgetItem(QString::number(biciclete[i].getCod())));
        tblBiciclete->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(biciclete[i].getDenumire())));
        tblBiciclete->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(biciclete[i].getMarime())));
        tblBiciclete->setItem(i, 3, new QTableWidgetItem(QString::number(biciclete[i].getPret())));
        if (biciclete[i].getDisponibila() == 1)
            tblBiciclete->setItem(i, 4, new QTableWidgetItem(QString::fromStdString("True")));
        else
            tblBiciclete->setItem(i, 4, new QTableWidgetItem(QString::fromStdString("False")));
    }
}
