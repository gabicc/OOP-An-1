//
// Created by gabi on 5/18/26.
//

#ifndef PROCESORSIPLACADEBAZA_GUI_H
#define PROCESORSIPLACADEBAZA_GUI_H

#include "Service.h"
#include "Procesor.h"
#include "PlacaDeBaza.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QWidget>
#include <QListWidget>
#include <QTableWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>

class GUI: public QWidget{
    Q_OBJECT
private:
    Service& srv;
    vector<Procesor> displayedProcesoare;
    vector<PlacaDeBaza> displayedPlaci;
    QListWidget* lstProcesoare = new QListWidget;
    QListWidget* lstPlaci = new QListWidget;
    QLabel* lblNumePlaca = new QLabel("Nume placa");
    QLabel* lblSocluPlaca = new QLabel("Soclu placa");
    QLabel* lblPretPlaca = new QLabel("Pret placa");
    QLineEdit* numePlaca = new QLineEdit;
    QLineEdit* socluPlaca = new QLineEdit;
    QLineEdit* pretPlaca = new QLineEdit;
    QPushButton* btnAddPlaca = new QPushButton("Add placa");
    QPushButton* btnFiltrarePlaci = new QPushButton("Filtrare placi");
    QPushButton* btnPretTotal = new QPushButton("Pret total");
public:
    GUI(Service& srv);
    ~GUI() {

    }
    void aranjareInPagina();
    void connect();
    void reloadListPlaci(vector<PlacaDeBaza> placi);
    void reloadListProcesoare(vector<Procesor> procesoare);
};


#endif //PROCESORSIPLACADEBAZA_GUI_H
