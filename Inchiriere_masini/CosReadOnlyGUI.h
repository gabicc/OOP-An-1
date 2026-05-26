//
// Created by gabi on 5/24/26.
//

#ifndef INCHIRIERE_MASINI_COSREADONLYGUI_H
#define INCHIRIERE_MASINI_COSREADONLYGUI_H
#include <QApplication>
#include <QWidget>
#include <QPaintEvent>
#include <QHBoxLayout>
#include <QPainter>
#include <QImage>
#include <QScreen>
#include <vector>
#include <iostream>
#include "Masina.h"
#include "Observer.h"

using namespace std;

class CosReadOnlyGUI: public QWidget, public Observer {
private:
    int count;
protected:

    void paintEvent(QPaintEvent *ev) override ;

public:
    CosReadOnlyGUI() :count(0) {
        this->resize(800,600);
        // QScreen *screen = QGuiApplication::screenAt(window()->mapToGlobal(QPoint(0,0)));
        // if (!screen) screen = QGuiApplication::primaryScreen();
        // move(screen->availableGeometry().topLeft());
    };



    void notify(const vector<Masina>& masini) override;
};


#endif //INCHIRIERE_MASINI_COSREADONLYGUI_H
