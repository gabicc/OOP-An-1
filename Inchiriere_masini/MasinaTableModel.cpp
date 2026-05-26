#include "MasinaTableModel.h"

MasinaTableModel::MasinaTableModel(QObject* parent)
    : QAbstractTableModel(parent) {
}

int MasinaTableModel::rowCount(const QModelIndex& parent) const {
    if (parent.isValid())
        return 0;
    return (int)masini.size();
}

int MasinaTableModel::columnCount(const QModelIndex& parent) const {
    if (parent.isValid())
        return 0;
    return 4;
}

QVariant MasinaTableModel::data(const QModelIndex& index, int role) const {
    if (!index.isValid() || index.row() >= (int)masini.size() || index.row() < 0)
        return QVariant();

    if (role == Qt::DisplayRole) {
        const Masina& masina = masini[index.row()];

        switch (index.column()) {
            case 0:
                return QString::fromStdString(masina.get_nr_inmatriculare());
            case 1:
                return QString::fromStdString(masina.get_producator());
            case 2:
                return QString::fromStdString(masina.get_model());
            case 3:
                return QString::fromStdString(masina.get_tip());
            default:
                return QVariant();
        }
    }

    return QVariant();
}

QVariant MasinaTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
            case 0:
                return QString("Nr Inmatriculare");
            case 1:
                return QString("Producator");
            case 2:
                return QString("Model");
            case 3:
                return QString("Tip");
            default:
                return QVariant();
        }
    }

    return QVariant();
}

void MasinaTableModel::updateMasini(const vector<Masina>& newMasini) {
    beginResetModel();
    masini = newMasini;
    endResetModel();
}

Masina MasinaTableModel::getMasina(int row) const {
    if (row >= 0 && row < (int)masini.size()) {
        return masini[row];
    }
    throw runtime_error("Index out of bounds");
}

void MasinaTableModel::clear() {
    beginResetModel();
    masini.clear();
    endResetModel();
}