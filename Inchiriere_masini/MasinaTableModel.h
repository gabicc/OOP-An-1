#ifndef INCHIRIERE_MASINI_MASINATABLE_MODEL_H
#define INCHIRIERE_MASINI_MASINATABLE_MODEL_H

#include <QAbstractTableModel>
#include <vector>
#include "Masina.h"

using namespace std;

class MasinaTableModel : public QAbstractTableModel {
    Q_OBJECT
private:
    vector<Masina> masini;

public:
    explicit MasinaTableModel(QObject* parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    void updateMasini(const vector<Masina>& newMasini);
    Masina getMasina(int row) const;
    void clear();
};

#endif //INCHIRIERE_MASINI_MASINATABLE_MODEL_H