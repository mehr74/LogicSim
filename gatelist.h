#ifndef GATELIST_H
#define GATELIST_H

#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QPoint>
#include <QList>

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

private:
    int findLocation(const QPoint &pos) const;
    void addPieces();
    int widgetHeight;
    int widgetWidth;
    QRect highLightedRect2;
    QRect highLightedRect;
    QList<QPixmap> piecePixmaps;
    QList<QRect> pieceRects;
    QList<QPoint> pieceLocations;
};

#endif // GATELIST_H
