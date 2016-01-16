#ifndef GATELIST_H
#define GATELIST_H

#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QPoint>
#include <QList>
#include <QPolygon>
#include "circuit.h"


class GateList : public QWidget
{
    Q_OBJECT
public:
    GateList(QWidget *parent = 0, const QSize size = QSize(400, 400));

protected:
   void paintEvent(QPaintEvent *);
   void dragEnterEvent(QDragEnterEvent *);
   void dragLeaveEvent(QDragLeaveEvent *);
   void dragMoveEvent(QDragMoveEvent *);
   void dropEvent(QDropEvent *);
   void mousePressEvent(QMouseEvent *);
   void mouseMoveEvent(QMouseEvent *);

private:
    int widthGap;
    int heightGap;
    int findLocation(const QPoint &pos) const;
    int findApproximateLocation(const QPoint &pos) const;
    void addWire(const QPoint &start, const QPoint &end);
    int findConnector(const QPoint &pos) const;
    void addInputConnector(const QRect &rect, int number, int id);
    void addOutputConnector(const QRect &rect, int id);
    int addConnection();
    void addPieces();
    int widgetHeight;
    int widgetWidth;
    Circuit *circuit;
    QRect wireStart;
    int wireStartNum;
    QPixmap highLightedPixmap;
    QRect highLightedRect;
    QRect highLightedConnector;
    QList<QPixmap> piecePixmaps;
    QList<QRect> pieceRects;
    QList<int> pieceType;
    QList<int> pieceId;
    QList<QRect> usedConnectors;
    QList<QRect> connectors;
    QList<int> connectorsId;
    QList<int> connectorsType;
    QList<QRect> probes;
    QList<int> probeIds;
    QList<QPolygon> wires;
};

#endif // GATELIST_H
