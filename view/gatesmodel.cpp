#include "gatesmodel.h"
#include <QPixmap>
#include <QMimeData>

GatesModel::GatesModel(QObject *parent)
    :QAbstractListModel(parent)
{
}

void GatesModel::addPiece(const QPixmap &pixmap, int type)
{
    int row = 0;
    beginInsertRows(QModelIndex(), row, row);
    pixmaps.insert(row, pixmap);
    types.insert(row, type);
    endInsertRows();
}

QVariant GatesModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DecorationRole)
        return QIcon(pixmaps.value(index.row()).scaled(80, 50,
                         Qt::KeepAspectRatio, Qt::SmoothTransformation));
    else if (role == Qt::UserRole)
        return pixmaps.value(index.row());

    else if (role == Qt::UserRole+1)
        return types.value(index.row());

    return QVariant();
}

Qt::ItemFlags GatesModel::flags(const QModelIndex &index) const
{
    if (index.isValid())
        return (Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsDragEnabled);

    return Qt::ItemIsDropEnabled;
}

bool GatesModel::dropMimeData(const QMimeData *data, Qt::DropAction action,
                               int row, int column, const QModelIndex &parent)
{
    return true;
}

QStringList GatesModel::mimeTypes() const
{
    QStringList types;
    types << "image/gates";
    return types;
}

QMimeData *GatesModel::mimeData(const QModelIndexList &indexes) const
{
    QMimeData *mimeData = new QMimeData();
    QByteArray encodedData;

    QDataStream stream(&encodedData, QIODevice::WriteOnly);

    foreach (QModelIndex index, indexes)
    {
        if (index.isValid()) {
            QPixmap pixmap = data(index, Qt::UserRole).value<QPixmap>();
            int logicObj = data(index, Qt::UserRole+1).value<int>();
            stream << pixmap;
            stream << logicObj;
        }
    }

    mimeData->setData("image/gates", encodedData);
    return mimeData;
}

int GatesModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    else
        return pixmaps.size();
}

Qt::DropActions GatesModel::supportedDropActions() const
{
    return Qt::CopyAction | Qt::MoveAction;
}
