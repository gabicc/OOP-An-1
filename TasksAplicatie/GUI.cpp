//
// Created by gabi on 6/21/26.
//

#include "GUI.h"

GUI::GUI(Service& srv): srv{srv} {
    aranjareInPagina();
    connect();
    reloadTableTasks(srv.get_all_srv());
    reloadTableViewTasks(srv.get_all_srv());
}
void GUI::aranjareInPagina() {
    QHBoxLayout* mainLayout = new QHBoxLayout(this);

    // LEFT
    QWidget* left = new QWidget;
    QVBoxLayout* lyLeft = new QVBoxLayout(left);
    QWidget* form = new QWidget;
    QFormLayout* lyForm = new QFormLayout(form);
    lyForm->addRow(lblId, idEdit);
    lyForm->addRow(lblDescriere, descriereEdit);
    lyForm->addRow(lblProgramatori, programatoriEdit);
    lyForm->addRow(lblStare, stareEdit);
    lyForm->addWidget(btnAddTask);

    lyLeft->addWidget(form);
    mainLayout->addWidget(left);

    // CENTER LEFT
    mainLayout->addWidget(tableTasks);

    // CENTER CENTER
    mainLayout->addWidget(tableViewTasks);

    // CENTER RIGHT
    QWidget* centerRight = new QWidget;
    QVBoxLayout* lyCenterRight = new QVBoxLayout(centerRight);

    QWidget* slider = new QWidget;
    QHBoxLayout* lySlider = new QHBoxLayout(slider);
    idSlider->setRange(0,100);
    idSlider->setValue(0);
    lySlider->addWidget(idValue);
    lySlider->addWidget(idSlider);
    lySlider->addWidget(idLabelSlider);

    lyCenterRight->addWidget(slider);
    lyCenterRight->addWidget(lblProgramatorFind);
    lyCenterRight->addWidget(progEdit);
    lyCenterRight->addWidget(btnFindTask);

    mainLayout->addWidget(centerRight);

    // RIGHT
    QWidget* right = new QWidget;
    QVBoxLayout* lyRight = new QVBoxLayout(right);
    lyRight->addWidget(btnOpen);
    lyRight->addWidget(btnInPorgress);
    lyRight->addWidget(btnClosed);

    mainLayout->addWidget(right);

}
void GUI::connect() {
    QObject::connect(idSlider, &QSlider::valueChanged, this, [this](int value) {
       idValue->setText(QString::number((value)));
    });
    QObject::connect(btnAddTask, &QPushButton::clicked, this, [this] {
        int id = idEdit->text().toInt();
        string descriere = descriereEdit->text().toStdString();
        string names = programatoriEdit->text().toStdString();
        string stare = stareEdit->text().toStdString();
        vector<string> programatori;
        int i = 0;
        while (i < names.size()) {
            string name;
            int j = i;
            while (names[j] != ',' && names[j] != 0) {
                name.push_back(names[j]);
                j++;
            }
            name[j - i]=0;
            i = j + 1;
            programatori.push_back(name);
        }
        //Task t(id, descriere, programatori, stare);
        try {
            srv.addTask_srv(id, descriere, programatori, stare);
            vector<Task> new_tasks;
            for (Task& t: srv.get_all_srv()) {
                if (t.getId() >= idValue->text().toInt())
                    new_tasks.push_back(t);
            }
            reloadTableTasks(new_tasks);
            reloadTableViewTasks(new_tasks);
            srv.saveToFile_srv();
        } catch (RepoException& re) {
            QMessageBox::warning(this, "Info", re.what());
        }
        catch (ValidatorException& ve) {
            QMessageBox::warning(this, "Info", ve.what());
        }
    });
    QObject::connect(btnFindTask, &QPushButton::clicked, this, [this] {
        string nume_programator = progEdit->text().toStdString();
        vector<Task> taskuri_find = srv.findProgramator_srv(nume_programator);
        // reloadTableTasks(taskuri_find);
        // reloadTableViewTasks(taskuri_find);
        vector<Task> new_tasks;
            for (Task& t: taskuri_find) {
                if (t.getId() >= idValue->text().toInt())
                    new_tasks.push_back(t);
            }
            reloadTableTasks(new_tasks);
            reloadTableViewTasks(new_tasks);
    });
    QObject::connect(btnOpen, &QPushButton::clicked, this, [this] {
        int selectedRow = tableViewTasks->currentIndex().row();
        if (selectedRow >= 0) {
            vector<Task> taskuri = srv.get_all_srv();
            srv.modifyTask_srv(taskuri[selectedRow], "open");
            vector<Task> new_tasks;
            for (Task& t: srv.get_all_srv()) {
                if (t.getId() >= idValue->text().toInt())
                    new_tasks.push_back(t);
            }
            reloadTableTasks(new_tasks);
            reloadTableViewTasks(new_tasks);
        }
    });
    QObject::connect(btnInPorgress, &QPushButton::clicked, this, [this] {
        int selectedRow = tableViewTasks->currentIndex().row();
        if (selectedRow >= 0) {
            vector<Task> taskuri = srv.get_all_srv();
            srv.modifyTask_srv(taskuri[selectedRow], "inprogress");
            vector<Task> new_tasks;
            for (Task& t: srv.get_all_srv()) {
                if (t.getId() >= idValue->text().toInt())
                    new_tasks.push_back(t);
            }
            reloadTableTasks(new_tasks);
            reloadTableViewTasks(new_tasks);
        }
    });
    QObject::connect(btnClosed, &QPushButton::clicked, this, [this] {
        int selectedRow = tableViewTasks->currentIndex().row();
        if (selectedRow >= 0) {
            vector<Task> taskuri = srv.get_all_srv();
            srv.modifyTask_srv(taskuri[selectedRow], "closed");
            vector<Task> new_tasks;
            for (Task& t: srv.get_all_srv()) {
                if (t.getId() >= idValue->text().toInt())
                    new_tasks.push_back(t);
            }
            reloadTableTasks(new_tasks);
            reloadTableViewTasks(new_tasks);
        }
    });
}
void GUI::reloadTableTasks(vector<Task> taskuri) {
    tableTasks->clearContents();
    tableTasks->setRowCount(taskuri.size());
    for (int i = 0; i < taskuri.size(); i++) {
        string progs;
        for (string p: taskuri[i].getProgramatori()) {
            progs += p + " ";
        }
        if (taskuri[i].getId() == 1 || taskuri[i].getId() == 2) {
            auto* item1 = new QTableWidgetItem(QString::number(taskuri[i].getId()));
            auto* item2 = new QTableWidgetItem(QString::fromStdString(taskuri[i].getDescriere()));
            auto* item3 = new QTableWidgetItem(QString::fromStdString(progs));
            auto* item4 = new QTableWidgetItem(QString::fromStdString(taskuri[i].getStare()));
            item1->setBackground(Qt::darkGreen);
            item2->setBackground(Qt::blue);
            item3->setBackground(Qt::blue);
            item4->setBackground(Qt::blue);
            tableTasks->setItem(i, 0, item1);
            tableTasks->setItem(i, 1, item2);
            tableTasks->setItem(i, 2, item3);
            tableTasks->setItem(i, 3, item4);
        }
        //if (taskuri[i].getId() >= idValue->text().toInt()) {
        else {
            tableTasks->setItem(i, 0, new QTableWidgetItem(QString::number(taskuri[i].getId())));
            tableTasks->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(taskuri[i].getDescriere())));
            tableTasks->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(progs)));
            tableTasks->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(taskuri[i].getStare())));
        }
        //}
    }
}
void GUI::reloadTableViewTasks(vector<Task> taskuri) {
    tableViewTasks->setModel(new TaskTableModel(NULL, taskuri));
}

int TaskTableModel::rowCount(const QModelIndex &parent) const {
    return taskuri.size();
}
int TaskTableModel::columnCount(const QModelIndex &parent) const {
    return 5;
}
QVariant TaskTableModel::data(const QModelIndex &index, int role ) const {
    int row = index.row();
    int col = index.column();
    switch (role) {
        case Qt::DisplayRole: {
            Task a = taskuri[row];
            vector<string> names = a.getProgramatori();
            string programatori;
            for (string& n: names) {
                programatori += n + ",";
            }
            int x = 10;// calculez contor la ceva
            switch (col) {
                case 0: return QString::number(a.getId());
                case 1: return QString::fromStdString(a.getDescriere());
                case 2: return QString::fromStdString(programatori);
                case 3: return QString::fromStdString(a.getStare());
                case 4: return QString::number(x);
            }
        }
    }
    return QVariant();
}
QVariant TaskTableModel::headerData(int section, Qt::Orientation orientation, int role ) const {
    if (orientation == Qt::Horizontal) {
        switch (role) {
            case Qt::DisplayRole: {
                switch (section) {
                    case 0: return QString("Id");
                    case 1: return QString("Descriere");
                    case 2: return QString("Programatori");
                    case 3: return QString("Stare");
                    case 4: return QString("Contor ceva");
                }
            }
        }
    }
    return QVariant();
}