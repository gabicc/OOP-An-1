//
// Created by gabi on 5/24/26.
//

#include "CosReadOnlyGUI.h"
#include <random>

void CosReadOnlyGUI::notify(const vector<Masina>& masini){
    count = masini.size();
    repaint();
}

void CosReadOnlyGUI::paintEvent(QPaintEvent *ev) {
    QPainter p{ this };
    p.drawImage(0, 0, QImage("sky.jpg" ).scaled(size()));

    for (int i = 0; i < count; i++) {
        int ox=rand() % 400;
        int oy=rand() % 300;
        int ce = rand() %3;
        switch (ce) {
            case 0:
                p.drawLine(ox, oy, ox+20, oy+20);
                break;
            case 1:
                p.drawEllipse(ox, oy, 120, 80);
                break;
            case 2:
                p.drawRect(ox + 50, oy, 180, 120);
                break;
            default:
                break;
        }

    }

    // p.drawLine(0, 0, width(), height());
    // p.drawEllipse(100, 100, 200, 200);
    //p.drawImage(0, 0, QImage("sky.jpg" ).scaled(size()));
}
