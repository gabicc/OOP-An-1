//
// Created by gabi on 6/18/26.
//

#include "GUI.h"

void GUI::aranjareInPagina() {
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QWidget* top = new QWidget;
    QHBoxLayout* topLayout = new QHBoxLayout(top);

    // LEFT
    QWidget* left = new QWidget;
    QVBoxLayout* leftLayout = new QVBoxLayout(left);
    QWidget* form = new QWidget;
    QFormLayout* formLayout = new QFormLayout(form);
    formLayout->addRow(lblId, id);
    formLayout->addRow(lblTitlu, titlu);
    formLayout->addRow(lblArtist, artist);
    rankSlider->setRange(0, 10);
    rankSlider->setValue(0);
    QWidget* formRank = new QWidget;
    QHBoxLayout* formRankLayout = new QHBoxLayout(formRank);
    formRankLayout->addWidget(rankSlider);
    formRankLayout->addWidget(rankValue);
    formLayout->addRow(lblRank, formRank);

    leftLayout->addWidget(form);

    leftLayout->addWidget(btnModifyMelodie);
    leftLayout->addWidget(btnRemoveMelodie);

    //mainLayout->addWidget(left);
    topLayout->addWidget(left);

    //mainLayout->addWidget(tableMelodii);

    //mainLayout->addWidget(tableViewMelodii);
    topLayout->addWidget(tableViewMelodii);

    chart->setMinimumHeight(220);

    mainLayout->addWidget(top);
    mainLayout->addWidget(chart);

    tableViewMelodii->setFixedSize(500, 400);
    tableViewMelodii->setSelectionBehavior(QTableView::SelectRows);
}

void GUI::connect() {
    QObject::connect(rankSlider, &QSlider::valueChanged, this, [this](int value) {
       rankValue->setText(QString::number(value));
    });

    QObject::connect(btnModifyMelodie, &QPushButton::clicked, this, [this] {
        try {
            vector<Melodie> melodii = srv.get_all_srv();
            int selectedRow = tableViewMelodii->currentIndex().row();
            if (selectedRow >= 0) {
                //id->setText(QString::number(melodii[selectedRow].getId()));
                //titlu->setText(QString::fromStdString(melodii[selectedRow].getTitlu()));
                //artist->setText(QString::fromStdString(melodii[selectedRow].getArtist()));
                //rank->setText(QString::number(melodii[selectedRow].getRank()));
                int Id = melodii[selectedRow].getId();
                string Titlu = this->titlu->text().toStdString();
                string Artist = melodii[selectedRow].getArtist();
                int Rank = rankSlider->value();
                srv.modifyMelodie_srv(Id, Titlu, Artist, Rank);
                //reloadTable(srv.get_all_srv());
                reloadTableView(srv.get_all_srv());
                srv.saveToFile_srv();
            }
        } catch (RepoException& re) {
            QMessageBox::warning(this, "Info", re.what());
        }
        catch (ValidatorException& ve) {
            QMessageBox::warning(this, "Info", ve.what());
        }
    });
    QObject::connect(tableViewMelodii, &QTableView::clicked, this, &GUI::onSelectedRow);
    QObject::connect(btnRemoveMelodie, &QPushButton::clicked, this, [this] {
        vector<Melodie> melodii = srv.get_all_srv();
        int selectedRow = tableViewMelodii->currentIndex().row();
        if (selectedRow >= 0) {
            bool gasit = false;
            for (int i = selectedRow + 1; i < melodii.size(); i++) {
                if (melodii[i].getArtist() == melodii[selectedRow].getArtist()) {
                    gasit = true;
                }
            }
            if (gasit == false) {
                QMessageBox::warning(this, "Info", "Nu se poate sterge melodia pentru ca este ultima melodie a artisutlui");
            }
            else {
                srv.removeMelodie_srv(melodii[selectedRow].getId());
                reloadTableView(srv.get_all_srv());
                srv.saveToFile_srv();
            }
        }
    });
}

void GUI::onSelectedRow(const QModelIndex &index) {
    int row = index.row();
    loadRowData(row);
}

// void GUI::reloadTable(vector<Melodie> melodiiToDisplay) {
//     tableMelodii->clearContents();
//     tableMelodii->setFixedSize(500, 400);
//     tableMelodii->setRowCount(melodiiToDisplay.size());
//     tableMelodii->setColumnCount(4);
//     QStringList tblHeaderList;
//     tblHeaderList << "Id" << "Titlu" << "Artist" << "Rank";
//     tableMelodii->setHorizontalHeaderLabels(tblHeaderList);
//     for (int i = 0; i < melodiiToDisplay.size(); i++) {
//         tableMelodii->setItem(i, 0, new QTableWidgetItem(QString::number(melodiiToDisplay[i].getId())));
//         tableMelodii->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(melodiiToDisplay[i].getTitlu())));
//         tableMelodii->setItem(i, 2, new QTableWidgetItem(QString::fromStdString((melodiiToDisplay[i].getArtist()))));
//         tableMelodii->setItem(i, 3, new QTableWidgetItem(QString::number(melodiiToDisplay[i].getRank())));
//     }
// }

void GUI::reloadTableView(vector<Melodie> melodiiToDisplay) {
    tableViewMelodii->setModel(new MelodieTableModel(NULL, melodiiToDisplay));
    chart->setMelodii(melodiiToDisplay);
}

int MelodieTableModel::rowCount(const QModelIndex &parent) const {
    return melodii.size();
}

int MelodieTableModel::columnCount(const QModelIndex &parent) const {
    return 5;
}

QVariant MelodieTableModel::data(const QModelIndex &index, int role) const {
    int row = index.row();
    int col = index.column();
    switch (role) {
        case Qt::DisplayRole: {
            Melodie a = melodii[row];
            int x = 0;
            for (Melodie m: melodii) {
                if (m.getRank() == a.getRank())
                    x++;
            }
            switch (col) {
                case 0: return QString::number(a.getId());
                case 1: return QString::fromStdString(a.getTitlu());
                case 2: return QString::fromStdString(a.getArtist());
                case 3: return QString::number(a.getRank());
                case 4: return QString::number(x);
            }
        }
    }

    return QVariant();
}

QVariant MelodieTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (orientation == Qt::Horizontal) {
        switch (role) {
            case Qt::DisplayRole: {
                switch (section) {
                    case 0: return QString("Id");
                    case 1: return QString("Titlu");
                    case 2: return QString("Artist");
                    case 3: return QString("Rank");
                    case 4: return QString("Contor rank");
                }
            }
        }
    }
    return QVariant();
}

void GUI::loadRowData(int row) {
    vector<Melodie> melodii = srv.get_all_srv();
    if (row >= 0 && row < melodii.size()) {
        Melodie m = melodii[row];
        id->setText(QString::number(m.getId()));
        titlu->setText(QString::fromStdString(m.getTitlu()));
        artist->setText(QString::fromStdString(m.getArtist()));
        rankSlider->setValue(m.getRank());
    }
}

void BarChart::paintEvent(QPaintEvent*) {
    QPainter p(this);
    p.fillRect(rect(), Qt::white);

    int freq[11] = {0};
    for (auto& m: melodii) {
        freq[m.getRank()]++;
    }

    int maxFreq = 1;
    for (int x: freq) {
        if (x > maxFreq)
            maxFreq = x;
    }
    int left = 20, right = 20, top = 20, bottom = 30;
    int w = width() - left - right;
    int h = height() - top - bottom;
    int barW = w/11;

    for (int i = 0; i < 11; i++) {
        int barH = (freq[i] * h) / maxFreq;
        int x = left + i * barW;
        int y = top + (h - barH);

        p.setBrush(QColor(70, 130, 180));
        p.drawRect(x, y, barW - 4, barH);
        p.fillRect(x, y, barW - 4, barH, QColor(70, 130, 180));

        p.drawText(x, height() - 10, QString::number(i));
        p.drawText(x, y - 5, QString::number(freq[i]));
    }
}