//
// Created by gabi on 5/5/26.
//

#include "InchiriereGUI.h"

#include "CosCRUDGUI.h"
#include "CosReadOnlyGUI.h"

void InchiriereGUI::initializeGUIComponents() {
    QHBoxLayout *lyMain = new QHBoxLayout;
    this->setLayout(lyMain);

    QWidget *left = new QWidget;
    QVBoxLayout *lyLeft = new QVBoxLayout;
    left->setLayout(lyLeft);

    QWidget *form = new QWidget;
    QFormLayout *lyForm = new QFormLayout;
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

    QWidget *right = new QWidget;
    QVBoxLayout *lyRight = new QVBoxLayout;
    right->setLayout(lyRight);

    QWidget *rightright = new QWidget;
    lyRightRight = new QVBoxLayout;
    rightright->setLayout(lyRightRight);

    QWidget *right3 = new QWidget;
    QVBoxLayout* lyRight3 = new QVBoxLayout;
    right3->setLayout(lyRight3);
    listWidgetMasini = new QListWidget;
    lyRight3->addWidget(listWidgetMasini);

    //int noLines = 10;
    //int noColumns = 4;
    //this->tableMasini = new QTableWidget{noLines, noColumns};

    QVBoxLayout *lyRadioBox = new QVBoxLayout;
    this->groupBox->setLayout(lyRadioBox);
    lyRadioBox->addWidget(radioSrtNrInmatric);
    lyRadioBox->addWidget(radioSrtProducatorModel);
    //lyRadioBox->addWidget(radioSrtModel);
    lyRadioBox->addWidget(radioSrtTip);

    btnSortMasini = new QPushButton("Sorteaza masini");
    lyRadioBox->addWidget(btnSortMasini);

    lyLeft->addWidget(groupBox);

    btnUndo = new QPushButton("Undo");
    lyLeft->addWidget(btnUndo);
    lyLeft->addWidget(btnDeschidereCosReadOnly);

    QWidget *formRandom = new QWidget;
    QFormLayout *lyFormRandom = new QFormLayout;
    formRandom->setLayout(lyFormRandom);
    btnGenerareRandomMasini = new QPushButton("Genereaza masini random");
    lyFormRandom->addWidget(btnGenerareRandomMasini);

    spinBoxRandomMasini = new QSpinBox;
    spinBoxRandomMasini->setMinimum(1);
    lyFormRandom->addRow(spinBoxRandomMasini, btnGenerareRandomMasini);
    lyLeft->addWidget(formRandom);

    // Crezi modelul și view-ul
    modelMasini = new MasinaTableModel(this);
    tableMasini = new QTableView;
    tableMasini->setModel(modelMasini);

    // Setează dimensiunile coloanelor
    tableMasini->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    tableMasini->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    lyRight->addWidget(tableMasini);

    QWidget *formSearch = new QWidget;
    QFormLayout *lyFormSearch = new QFormLayout;
    formSearch->setLayout(lyFormSearch);

    btnFilterMasiniProducator = new QPushButton("Filtreaza masini dupa producator");
    btnFilterMasiniTip = new QPushButton("Filtreaza masini dupa tip");

    btnRemoveMasina = new QPushButton("Sterge masina");
    lyFormSearch->addRow(btnRemoveMasina);
    lyFormSearch->addRow(btnFilterMasiniProducator, btnFilterMasiniTip);

    lyRight->addWidget(formSearch);

    lyMain->addWidget(left);
    lyMain->addWidget(right);
    lyMain->addWidget(rightright);
    lyMain->addWidget(right3);
}

void InchiriereGUI::reloadMasiniList(vector<Masina> masini) {
    modelMasini->updateMasini(masini);
}

void InchiriereGUI::connectSignalsSlots() {
    QObject::connect(btnAddMasina, &QPushButton::clicked, this, &InchiriereGUI::guiAddMasina);

    QObject::connect(btnRemoveMasina, &QPushButton::clicked, this, &InchiriereGUI::guiRemoveMasina);

    QObject::connect(btnModifyMasina, &QPushButton::clicked, this, &InchiriereGUI::guiModificaMasina);

    QObject::connect(btnFilterMasiniProducator, &QPushButton::clicked, this, &InchiriereGUI::guiFilterMasiniProducator);

    QObject::connect(btnFilterMasiniTip, &QPushButton::clicked, this, &InchiriereGUI::guiFilterMasiniTip);

    QObject::connect(btnSortMasini, &QPushButton::clicked, this, &InchiriereGUI::guiSortMasini);

    QObject::connect(btnUndo, &QPushButton::clicked, this, &InchiriereGUI::guiUndo);

    QObject::connect(btnGenerareRandomMasini, &QPushButton::clicked, this, &InchiriereGUI::guiGenerareRandomMasini);

    QObject::connect(btnDeschidereCosReadOnly, &QPushButton::clicked, this, &InchiriereGUI::guiDeschidereCosReadOnly);
}

void InchiriereGUI::guiDeschidereCosReadOnly() {
    CosCRUDGUI* cosCRUDgui = new CosCRUDGUI(srv, this);
    CosReadOnlyGUI* cosReadOnly = new CosReadOnlyGUI;
    this->registerObserver(cosCRUDgui);
    this->registerObserver(cosReadOnly);
    cosCRUDgui->show();
    cosReadOnly->show();
}

void InchiriereGUI::guiGenerareRandomMasini() {
    int nrMasini = spinBoxRandomMasini->value();
    int n = nrMasini;
    for (int i = 0; i < n; i++) {
        Masina m = Masina::genereaza_masina(i);
        bool exista_producator = are_producator(m.get_producator());
        srv.adaugaMasina_srv(m);
        if (exista_producator == false) {
            QPushButton* btnMasina = new QPushButton(QString::fromStdString(m.get_producator()));
            //QObject::connect(btnMasina, &QPushButton::clicked, [&]() {
                //this->editProducator->setText(btnMasina->text());
            //});
            lyRightRight->addWidget(btnMasina);
            butoaneDinamice.push_back(btnMasina);
        }
    }
    this->reloadMasiniList(srv.get_all_srv());

}

bool InchiriereGUI::are_producator(string producator) {
    vector<Masina> all = this->srv.get_all_srv();
    for (auto& m: all) {
        if (m.get_producator() == producator)
            return true;
    }
    return false;
}

void InchiriereGUI::guiAddMasina() {
    try {
        string nrInamtric = editNrInmatric->text().toStdString();
        string producator = editProducator->text().toStdString();
        string model = editModel->text().toStdString();
        string tip = editTip->text().toStdString();

        editNrInmatric->clear();
        editProducator->clear();
        editModel->clear();
        editTip->clear();

        bool exista_producator = are_producator(producator);
        this->srv.adaugaMasina_srv(Masina{nrInamtric, producator, model, tip});
        this->reloadMasiniList(srv.get_all_srv());
        if (exista_producator == false) {
            QPushButton* btnMasina = new QPushButton(QString::fromStdString(producator));
            lyRightRight->addWidget(btnMasina);
            butoaneDinamice.push_back(btnMasina);
        }


        // afisam mesaj ca masina s-a adaugat cu succes
        //QMessageBox::information(this, "Info", QString::fromStdString("Masina adaugata cu succes. "));
    } catch (RepoException &re) {
        QMessageBox::warning(this, "Info", QString::fromStdString(re.getErrorMessage()));
    } catch (ValidationException &ve) {
        QMessageBox::warning(this, "Info", QString::fromStdString(ve.getErrorMessage()));
    }
}

void InchiriereGUI::guiModificaMasina() {
    QModelIndexList selected = this->tableMasini->selectionModel()->selectedRows();

    if (!selected.isEmpty()) {
        int selectedRow = selected.first().row();

        try {
            Masina masina = modelMasini->getMasina(selectedRow);
            QString nrInmatricVechi = QString::fromStdString(masina.get_nr_inmatriculare());
            QString nrInmatricNou = editNrInmatric->text();

            editNrInmatric->clear();
            editProducator->clear();
            editModel->clear();
            editTip->clear();

            this->srv.modificaMasina_srv(nrInmatricVechi.toStdString(), nrInmatricNou.toStdString());
            this->reloadMasiniList(srv.get_all_srv());
        } catch (RepoException &re) {
            QMessageBox::warning(this, "Info", QString::fromStdString(re.getErrorMessage()));
        }
    } else {
        QMessageBox::warning(this, "Info", QString::fromStdString("Selectati o masina pentru a o modifica"));
    }
}

void InchiriereGUI::guiRemoveMasina() {
    QModelIndexList selected = this->tableMasini->selectionModel()->selectedRows();

    if (!selected.isEmpty()) {
        int selectedRow = selected.first().row();

        try {
            Masina masina = modelMasini->getMasina(selectedRow);
            QString nrInmatric = QString::fromStdString(masina.get_nr_inmatriculare());
            QString producator = QString::fromStdString(masina.get_producator());

            this->srv.stergeMasina_srv(nrInmatric.toStdString());
            this->reloadMasiniList(srv.get_all_srv());

            for (auto it = butoaneDinamice.begin(); it != butoaneDinamice.end(); it++) {
                if ((*it)->text() == producator) {
                    if (are_producator(producator.toStdString()) == false) {
                        lyRightRight->removeWidget((*it));
                        (*it)->deleteLater();
                        butoaneDinamice.erase(it);
                        break;
                    }
                }
            }
        } catch (RepoException &re) {
            QMessageBox::warning(this, "Info", QString::fromStdString(re.getErrorMessage()));
        }
    } else {
        QMessageBox::warning(this, "Info", QString::fromStdString("Selectati o masina pentru a o sterge"));
    }
}

void InchiriereGUI::guiFilterMasiniProducator() {
    QModelIndexList selected = this->tableMasini->selectionModel()->selectedRows();

    if (!selected.isEmpty()) {
        int selectedRow = selected.first().row();

        try {
            Masina masina = modelMasini->getMasina(selectedRow);
            QString producator = QString::fromStdString(masina.get_producator());

            vector<Masina> newMasini = this->srv.filtreaza_dupa_producator_srv(producator.toStdString());
            this->reloadMasiniList(newMasini);
        } catch (RepoException &re) {
            QMessageBox::warning(this, "Info", QString::fromStdString(re.getErrorMessage()));
        }
    } else {
        QMessageBox::warning(this, "Info",
                             QString::fromStdString("Selectati o masina pentru a filtra dupa producator"));
    }
}

void InchiriereGUI::guiFilterMasiniTip() {
    QModelIndexList selected = this->tableMasini->selectionModel()->selectedRows();

    if (!selected.isEmpty()) {
        int selectedRow = selected.first().row();

        try {
            Masina masina = modelMasini->getMasina(selectedRow);
            QString tip = QString::fromStdString(masina.get_tip());

            vector<Masina> newMasini = this->srv.filtreaza_dupa_tip_srv(tip.toStdString());
            this->reloadMasiniList(newMasini);
        } catch (RepoException &re) {
            QMessageBox::warning(this, "Info", QString::fromStdString(re.getErrorMessage()));
        }
    } else {
        QMessageBox::warning(this, "Info", QString::fromStdString("Selectati o masina pentru a filtra dupa tip"));
    }
}

void InchiriereGUI::guiSortMasini() {
    if (this->radioSrtProducatorModel->isChecked())
        this->reloadMasiniList(srv.sorteaza_dupa_producator_model_srv());
        //else if (this->radioSrtModel->isChecked())
        //this->reloadMasiniList(srv.sorteaza_dupa_producator_model_srv());
    else if (this->radioSrtTip->isChecked())
        this->reloadMasiniList(srv.sorteaza_dupa_tip_srv());
    else if (this->radioSrtNrInmatric->isChecked())
        this->reloadMasiniList(srv.sorteaza_dupa_nr_inmatriculare_srv());
    else
        QMessageBox::warning(this, "Info", QString::fromStdString("Selectati un criteriu de sortare"));
}

void InchiriereGUI::guiUndo() {
    try {
        this->srv.Undo();
        this->reloadMasiniList(srv.get_all_srv());
    } catch (RepoException &re) {
        QMessageBox::warning(this, "Info", QString::fromStdString(re.getErrorMessage()));
    }
}