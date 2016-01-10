#ifndef GATESMODEL_H
#define GATESMODEL_H

#include <QAbstractListModel>
#include <QPoint>
#include <QIcon>
#include "gatetextures.h"

class GatesModel : public QAbstractListModel
{
    Q_OBJECT
public:
    GatesModel (QObject * = 0);

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
   //bool removeRows(int, int, const QModelIndex &)
    bool dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent);
    QMimeData *mimeData(const QModelIndexList &indexes) const;
    QStringList mimeTypes() const;

    int rowCount(const QModelIndex &) const;
    Qt::DropActions supportedDropActions() const;


    void addPiece(const QPixmap&, int);

private:
    QList<QPixmap> pixmaps;
    QList<int> types;
    QPoint pnt;
};



#endif // GATESMODEL_H
