//
// Created by gabi on 6/20/26.
//

#ifndef PRODUSEAPLICATIE_GUI_H
#define PRODUSEAPLICATIE_GUI_H

#include <QApplication>
#include <QWidget>
#include "Service.h"
#include "Repo.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTableView>
#include <QFormLayout>
#include <QSlider>
#include <QMessageBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QAbstractTableModel>
#include <QListWidgetItem>
#include <QTableWidget>

class ProdusTableModel: public QAbstractTableModel {
    Q_OBJECT;
private:
    vector<Produs> produse;
public:
    ProdusTableModel(QObject* parent, vector<Produs> produse): QAbstractTableModel{parent}, produse{produse} {};
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
};

class GUI: public QWidget {
    Q_OBJECT;
private:
    Service& srv;
    QTableView* tableViewProduse = new QTableView;
    QTableWidget* tableProduse = new QTableWidget(10, 4);
    QLabel* lblId = new QLabel("Id");
    QLabel* lblNume = new QLabel("Nume");
    QLabel* lblTip = new QLabel("Tip");
    QLabel* lblPret = new QLabel("Pret");
    QLineEdit* idEdit = new QLineEdit;
    QLineEdit* numeEdit = new QLineEdit;
    QLineEdit* tipEdit = new QLineEdit;
    QLineEdit* pretEdit = new QLineEdit;
    QPushButton* btnAddProdus = new QPushButton("Add");
    QLabel* pret2 = new QLabel("Pret");
    QSlider* pretSlider = new QSlider(Qt::Horizontal);
    QLabel* pretValue = new QLabel("0");

public:
    GUI(Service& srv);
    void aranjareInPagina();
    void connect();
    void reloadTableView(vector<Produs> produseToDisplay);
    void reloadTableProduse(vector<Produs> produseToDisplay);
};


#endif //PRODUSEAPLICATIE_GUI_H
