//
// Created by gabi on 6/20/26.
//

#include "GUI.h"

GUI::GUI(Service& srv): srv{srv} {
    aranjareInPagina();
    connect();
    reloadTableProduse(srv.get_all_srv());
    reloadTableView(srv.get_all_srv());
}
void GUI::aranjareInPagina() {
    QHBoxLayout* mainLayout = new QHBoxLayout(this);

    // LEFT
    QWidget* left = new QWidget;
    QVBoxLayout* lyLeft = new QVBoxLayout(left);
    QWidget* form = new QWidget;
    QFormLayout* lyForm = new QFormLayout(form);
    lyForm->addRow(lblId, idEdit);
    lyForm->addRow(lblNume, numeEdit);
    lyForm->addRow(lblTip, tipEdit);
    lyForm->addRow(lblPret, pretEdit);
    lyForm->addRow(btnAddProdus);

    lyLeft->addWidget(form);
    mainLayout->addWidget(left);

    // CENTER LEFT
    mainLayout->addWidget(tableProduse);

    // CENTER RIGHT
    mainLayout->addWidget(tableViewProduse);

    // RIGHT
    QWidget* right = new QWidget;
    QVBoxLayout* lyRight = new QVBoxLayout(right);
    pretSlider->setRange(0, 100);
    pretSlider->setValue(0);
    QWidget* rightPret = new QWidget;
    QHBoxLayout* lyRightPret= new QHBoxLayout(rightPret);
    QWidget* formPret = new QWidget;
    QHBoxLayout* formPretLayout = new QHBoxLayout(formPret);

    formPretLayout->addWidget(pret2);
    formPretLayout->addWidget(pretSlider);
    formPretLayout->addWidget(pretValue);

    lyRightPret->addWidget(formPret);
    lyRight->addWidget(rightPret);

    mainLayout->addWidget(right);
}
void GUI::connect() {
    QObject::connect(btnAddProdus, &QPushButton::clicked, this, [this] {
        vector<Produs> produse = srv.get_all_srv();
        int id = idEdit->text().toInt();
        string nume = numeEdit->text().toStdString();
        string tip = tipEdit->text().toStdString();
        double pret = pretEdit->text().toDouble();
        //Produs p(id, nume, tip, pret);
        try {
            srv.addProdus_srv(id, nume, tip, pret);
            reloadTableView(srv.get_all_srv());
            reloadTableProduse(srv.get_all_srv());
            srv.saveToFile_srv();
        } catch (RepoException& re) {
            QMessageBox::warning(this, "Info", re.what());
        }
        catch (ValidatorException& ve) {
            QMessageBox::warning(this, "Info", ve.what());
        }
    });
    QObject::connect(pretSlider, &QSlider::valueChanged, this, [this](int value) {
       pretValue->setText(QString::number(value));
    });
}

void GUI::reloadTableProduse(vector<Produs> produse) {
    tableProduse->clearContents();
    tableProduse->setRowCount(produse.size());
    for (int i = 0; i < produse.size(); i++) {
        auto* item1 = new QTableWidgetItem(QString::number(produse[i].getId()));
        auto* item2 = new QTableWidgetItem(QString::fromStdString(produse[i].getNume()));
        auto* item3 = new QTableWidgetItem(QString::fromStdString(produse[i].getTip()));
        auto* item4 = new QTableWidgetItem(QString::fromStdString(std::to_string(produse[i].getPret())));
        if (produse[i].getPret() <= pretValue->text().toInt()) {
            item1->setBackground(Qt::red);
            item2->setBackground(Qt::red);
            item3->setBackground(Qt::red);
            item4->setBackground(Qt::red);
        }
        tableProduse->setItem(i, 0, item1);
        tableProduse->setItem(i, 1, item2);
        tableProduse->setItem(i, 2, item3);
        tableProduse->setItem(i, 3, item4);
    }

}
void GUI::reloadTableView(vector<Produs> produseToDisplay) {
    tableViewProduse->setModel(new ProdusTableModel(NULL, produseToDisplay));
}

int ProdusTableModel::rowCount(const QModelIndex &parent) const {
    return produse.size();
}
int ProdusTableModel::columnCount(const QModelIndex &parent ) const {
    return 5;
}
QVariant ProdusTableModel::data(const QModelIndex &index, int role ) const {
    int row = index.row();
    int col = index.column();
    switch (role) {
        case Qt::DisplayRole: {
            Produs a = produse[row];
            int cont_voc = 0;
            string name = a.getNume();
            for (int i = 0; i < name.size(); i++) {
                if (name[i] == 'a' || name[i] == 'e' || name[i] == 'o' || name[i] == 'u' || name[i] == 'i' ||
                    name[i] == 'A' || name[i] == 'E' || name[i] == 'O' || name[i] == 'U' || name[i] == 'I')
                    cont_voc++;
            }
            switch (col) {
                case 0: return QString::number(a.getId());
                case 1: return QString::fromStdString(a.getNume());
                case 2: return QString::fromStdString(a.getTip());
                case 3: return QString::fromStdString(std::to_string(a.getPret()));
                case 4: return QString::number(cont_voc);
            }
        }
    }
    return QVariant();
}
QVariant ProdusTableModel::headerData(int section, Qt::Orientation orientation, int role ) const {
    if (orientation == Qt::Horizontal) {
        switch (role) {
            case Qt::DisplayRole: {
                switch (section) {
                    case 0: return QString("Id");
                    case 1: return QString("Nume");
                    case 2: return QString("Tip");
                    case 3: return QString("Pret");
                    case 4: return QString("Contor Vocale");
                }
            }
        }
    }
    return QVariant();
}