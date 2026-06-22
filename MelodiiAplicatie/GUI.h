//
// Created by gabi on 6/18/26.
//

#ifndef MELODIIAPLICATIE_GUI_H
#define MELODIIAPLICATIE_GUI_H

#include <QApplication>
#include <QWidget>
#include <QTableWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include "Service.h"
#include <QTableView>
#include <QAbstractTableModel>
#include <QSlider>
#include <QFormLayout>
#include <QPainter>
#include <QPaintEvent>
#include <algorithm>

class BarChart: public QWidget {
    Q_OBJECT;
private:
    vector<Melodie> melodii;
public:
    explicit BarChart(QWidget* parent = nullptr): QWidget(parent) {};
    void setMelodii(const vector<Melodie>& m) {
        melodii = m;
        update();
    }
protected:
    void paintEvent(QPaintEvent *event) override;
};

class MelodieTableModel: public QAbstractTableModel {
    Q_OBJECT;
private:
    vector<Melodie> melodii;
public:
    MelodieTableModel(QObject* parent, vector<Melodie> melodii): QAbstractTableModel{parent}, melodii{melodii} {};
    // int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

};

class GUI: public QWidget {
    Q_OBJECT;
private:
    Service& srv;
    //vector<Melodie> displayedMelodii;
    //QTableWidget* tableMelodii = new QTableWidget(10, 4);
    QTableView* tableViewMelodii = new QTableView;
    QLabel* lblId = new QLabel("Id");
    QLabel* lblTitlu = new QLabel("Titlu");
    QLabel* lblArtist = new QLabel("Artist");
    QLabel* lblRank = new QLabel("Rank");
    QLineEdit* id = new QLineEdit;
    QLineEdit* titlu = new QLineEdit;
    QLineEdit* artist = new QLineEdit;
    //QLineEdit* rank = new QLineEdit;
    QSlider* rankSlider = new QSlider(Qt::Horizontal);
    QLabel* rankValue = new QLabel("0");
    QPushButton* btnModifyMelodie = new QPushButton("Update");
    QPushButton* btnRemoveMelodie = new QPushButton("Delete");
    BarChart* chart = new BarChart;
public:
    GUI(Service& srv): srv{srv} {
        aranjareInPagina();
        connect();
        //reloadTable(srv.get_all_srv());
        reloadTableView(srv.get_all_srv());
    }
    void aranjareInPagina();
    void connect();
    //void reloadTable(vector<Melodie> melodiiToDisplay);
    void reloadTableView(vector<Melodie> melodiiToDisplay);
    void loadRowData(int row);
    void onSelectedRow(const QModelIndex &index);
};


#endif //MELODIIAPLICATIE_GUI_H
