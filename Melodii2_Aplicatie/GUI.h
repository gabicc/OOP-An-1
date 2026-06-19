//
// Created by gabi on 6/19/26.
//

#ifndef MELODII2_APLICATIE_GUI_H
#define MELODII2_APLICATIE_GUI_H

#include <QApplication>
#include <QWidget>
#include "Service.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QTableView>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QAbstractTableModel>

class MelodieTableModel: public QAbstractTableModel {
    Q_OBJECT;
private:
    vector<Melodie> melodii;
public:
    MelodieTableModel(QObject* parent, vector<Melodie> melodiii): QAbstractTableModel{parent}, melodii{melodiii} {};
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role=Qt::DisplayRole) const override;
};

class GUI: public QWidget {
    Q_OBJECT;
private:
    Service& srv;
    QTableWidget* tblMelodii = new QTableWidget;
    QTableView* tblViewMelodii = new QTableView;
    QLabel* lblTitlu = new QLabel("Titlu");
    QLabel* lblArtist = new QLabel("Artist");
    QLabel* lblGen = new QLabel("Gen");
    QLineEdit* titluEdit = new QLineEdit;
    QLineEdit* artistEdit = new QLineEdit;
    QLineEdit* genEdit = new QLineEdit;
    QPushButton* btnAddMelodie = new QPushButton("Add");
    QPushButton* btnRemoveMeldie = new QPushButton("Delete");
public:
    GUI(Service& srv);
    void aranjareInPagina();
    void connect();
    void reloadTableMelodii(vector<Melodie> melodiiToDilsplay);
    void reloadTableView(vector<Melodie> melodiiToDisplay);
};


#endif //MELODII2_APLICATIE_GUI_H
