//
// Created by gabi on 6/22/26.
//

#include "GUI.h"

GUI::GUI(Service& srv): srv{srv} {
    // pre: srv - Service&
    // post: efectuez operatiile de aranjareinpagina, connect si reload la ambele tabele
    aranjareInPagina();
    connect();
    reloadTableStudents(srv.get_all_srv());
    reloadTableViewStudents(srv.get_all_srv());
}
void GUI::aranjareInPagina() {
    // post: creem GUI care va avea un tablewidget(stanga), un tableview(centru) si butoane(dreapta)
    QHBoxLayout* mainLayout = new QHBoxLayout(this);

    // LEFT
    mainLayout->addWidget(tableStudents);

    // CENTER LEFT
    mainLayout->addWidget(tableViewStudents);

    // CENTER RIGHT
    QWidget* centerRight = new QWidget;
    QVBoxLayout* lyCenterRight = new QVBoxLayout(centerRight);
    lyCenterRight->addWidget(btnIntinerire);
    lyCenterRight->addWidget(btnImbatranire);
    lyCenterRight->addWidget(btnSterge);

    mainLayout->addWidget(centerRight);

    // RIGHT
    QWidget* right = new QWidget;
    QVBoxLayout* lyRight = new QVBoxLayout(right);
    lyRight->addWidget(btnUndo);
    lyRight->addWidget(btnRedo);

    mainLayout->addWidget(right);
}
void GUI::connect() {
    // post: conectam butoanele la functionalizatea pe care trebuie sa o aiba
    QObject::connect(btnIntinerire, &QPushButton::clicked, this, [this] {
        // post: intinereste fiecare student cu un an
        srv.intinerire_srv();
        reloadTableStudents(srv.get_all_srv());
        reloadTableViewStudents(srv.get_all_srv());
        srv.saveToFile_srv(srv.get_all_srv());
    });
    QObject::connect(btnImbatranire, &QPushButton::clicked, this, [this] {
        // post: imbatraneste fiecare student cu un an
        srv.imbatranire_srv();
        reloadTableStudents(srv.get_all_srv());
        reloadTableViewStudents(srv.get_all_srv());
        srv.saveToFile_srv(srv.get_all_srv());
    });
    QObject::connect(btnSterge, &QPushButton::clicked, this, [this] {
        // post: sterge studentul care este pe linia selectata
        vector<Student> students = srv.get_all_srv();
        int selectedRow = tableViewStudents->currentIndex().row();
        if (selectedRow >= 0) {
            srv.removeStudent_srv(students[selectedRow].getNrMatricol());
            reloadTableStudents(srv.get_all_srv());
            reloadTableViewStudents(srv.get_all_srv());
            srv.saveToFile_srv(srv.get_all_srv());
        }
    });
    QObject::connect(btnUndo, &QPushButton::clicked, this, [this] {
        // post: refac ultima operatie
        srv.undo_srv();
        reloadTableStudents(srv.get_all_srv());
        reloadTableViewStudents(srv.get_all_srv());
        srv.saveToFile_srv(srv.get_all_srv());
    });
    QObject::connect(btnRedo, &QPushButton::clicked, this, [this] {
        // post: refac ultima operatie de undo
        srv.redo_srv();
        reloadTableStudents(srv.get_all_srv());
        reloadTableViewStudents(srv.get_all_srv());
        srv.saveToFile_srv(srv.get_all_srv());
    });

}
void GUI::reloadTableStudents(vector<Student> studenti) {
    // post: refacem tabelwidget si coloram dupa facultate
    for (int i = 0; i < studenti.size(); i++) {
        auto* item1 = new QTableWidgetItem(QString::number(studenti[i].getNrMatricol()));
        auto* item2 = new QTableWidgetItem(QString::fromStdString(studenti[i].getNume()));
        auto* item3 = new QTableWidgetItem(QString::number(studenti[i].getVarsta()));
        auto* item4 = new QTableWidgetItem(QString::fromStdString(studenti[i].getFacultate()));
        if (studenti[i].getFacultate() == "mate") {
            item1->setBackground(Qt::red);
            item2->setBackground(Qt::red);
            item3->setBackground(Qt::red);
            item4->setBackground(Qt::red);
        }
        else if (studenti[i].getFacultate() == "info") {
            item1->setBackground(Qt::blue);
            item2->setBackground(Qt::blue);
            item3->setBackground(Qt::blue);
            item4->setBackground(Qt::blue);
        }
        else if (studenti[i].getFacultate() == "mate-info") {
            item1->setBackground(Qt::green);
            item2->setBackground(Qt::green);
            item3->setBackground(Qt::green);
            item4->setBackground(Qt::green);
        }
        else if (studenti[i].getFacultate() == "ai") {
            item1->setBackground(Qt::darkBlue);
            item2->setBackground(Qt::darkBlue);
            item3->setBackground(Qt::darkBlue);
            item4->setBackground(Qt::darkBlue);
        }
        tableStudents->setItem(i, 0, item1);
        tableStudents->setItem(i, 1, item2);
        tableStudents->setItem(i, 2, item3);
        tableStudents->setItem(i, 3, item4);
    }

}
void GUI::reloadTableViewStudents(vector<Student> studenti) {
    // post: refacem tabelview
    tableViewStudents->setModel(new StudentsTableModel(NULL, studenti));
}

int StudentsTableModel::rowCount(const QModelIndex &parent ) const{
    // post:returnam nr de studenti din taleview
    return studenti.size();
}
int StudentsTableModel::columnCount(const QModelIndex &parent) const{
    // post: returnam nr de coloane din tableview
    return 4;
}
QVariant StudentsTableModel::data(const QModelIndex &index, int role ) const {
    // post: incarcam tableview cu datele de la studenti
    int row = index.row();
    int col = index.column();
    switch (role) {
        case Qt::DisplayRole: {
            Student a = studenti[row];
            // auto item1 = QString::number(a.getNrMatricol());
            // auto item2 = QString::fromStdString(a.getNume());
            // auto item3 = QString::number(a.getVarsta());
            // auto item4 = QString::fromStdString(a.getFacultate());
            // if (a.getFacultate() == "mate") {
            //
            // }
            switch (col) {
                case 0: return QString::number(a.getNrMatricol());
                case 1: return QString::fromStdString(a.getNume());
                case 2: return QString::number(a.getVarsta());
                case 3: return QString::fromStdString(a.getFacultate());
            }
        }
    }
    return QVariant();

}
QVariant StudentsTableModel::headerData(int section, Qt::Orientation orientation, int role ) const {
    // post: incarcam header-urile de la tabel
    if (orientation == Qt::Horizontal) {
        switch (role) {
            case Qt::DisplayRole: {
                switch (section) {
                    case 0: return QString("NrMatricol");
                    case 1: return QString("Nume");
                    case 2: return QString("Varsta");
                    case 3: return QString("Facultate");
                }
            }
        }
    }
    return QVariant();
}