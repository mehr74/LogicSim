#include "gatelist.h"
#include <QRect>
#include <QPaintEvent>
#include <iostream>
#include <iomanip>
#include <QDrag>
#include <QMimeData>
#include "gatetextures.h"
using namespace std;

GateList::GateList(QWidget *parent, const QSize size)
    :QWidget(parent)
{
    cout << "Create new gatelist (" << widgetWidth << ", " << widgetHeight << ")" << endl;
    widgetHeight = size.height();
    widgetWidth = size.width();
    addPieces();
    setAcceptDrops(true);

    setMaximumSize(size);
    setMinimumSize(size);
}

void GateList::addPieces()
{

    QRect mRect;
    QSize *size = new QSize(80, 50);

    cout << "Height : " << size->height() << endl;
    cout << "Width  : " << size->width() << endl;

    pieceLocations.clear();
    piecePixmaps.clear();
    pieceRects.clear();
/*
    for(int i = 0; i < 10; i++)
    {
        mRect = QRect(10, i * (size->height() + 10) + 10, size->width() , size->height());
        cout << "#-Add-Rectange-------------------------------------" << endl
                << left << setw(15) << "#-Size: " << "("<< size->width() << ", " << size->height() << ")" << endl
                << left << setw(15) << "#-Location: " << "(10, " << i*(size->height() + 10) + 10 << ")" << endl
                << left << setw(15) << "#-Image: " << "\"" << objectPics[i] << "\"" << endl
                << "#--------------------------------------------------\n" << endl;
        QPixmap temp(objectPics[i]);
        QPixmap *pieceImage = new QPixmap(temp.scaled(*size));

        piecePixmaps.append(*pieceImage);
        pieceRects.append(mRect);
    }
    */

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            mRect = QRect(j * (size->width() +30) + 10,
                          i * (size->height() + 10) + 10,
                          size->width(),
                          size->height());
            cout << "#-Add-Rectange-------------------------------------" << endl
                    << left << setw(15) << "#-Size: " << "("<< size->width() << ", " << size->height() << ")" << endl
                    << left << setw(15) << "#-Location: " << "(" << j * (size->width() +30) + 10 << ", " << i*(size->height() + 10) + 10 << ")" << endl
                    << left << setw(15) << "#-Image: " << "\"" << objectPics[EMPTY] << "\"" << endl
                    << "#--------------------------------------------------\n" << endl;
            QPixmap temp(objectPics[EMPTY]);
            QPixmap *pieceImage = new QPixmap(temp.scaled(*size));

            piecePixmaps.append(*pieceImage);
            pieceRects.append(mRect);
        }
    }

    for(int i = 0; i < pieceRects.size(); i++)
    {
        cout << "#-QRectangle" << endl
                << "location" << "(" << pieceRects[i].x() << ", " << pieceRects[i].y() << ")" << endl
                << "size" << "(" << pieceRects[i].width() << ", " << pieceRects[i].height() << ")" << endl;
    }


    update();
}



void GateList::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);

    painter.fillRect(event->rect(), QColor(71,71,71));


    for (int i = 0; i < pieceRects.size(); ++i)
    {
        painter.drawPixmap(pieceRects[i], piecePixmaps[i]);
    }

    if(highLightedRect.isValid())
    {
        painter.setBrush(QColor("#ffcccc"));
        painter.setPen(Qt::NoPen);
        painter.drawRect(highLightedRect.adjusted(0, 0, 0, 0));
    }

    if(highLightedRect2.isValid())
    {
        painter.setBrush(QColor("#113388"));
        painter.setPen(Qt::NoPen);
        painter.drawRect(highLightedRect2.adjusted(0, 0, -1, -1));
    }

    painter.end();
}

void GateList::dragEnterEvent(QDragEnterEvent *event)
{
    cout << "DragEnterEvent called!" << endl;
    event->accept();
    /*
    if(event->mimeData())
        event->accept();
    else
        event->ignore();
        */
}

void GateList::dragLeaveEvent(QDragLeaveEvent *event)
{
    event->accept();
}

void GateList::dragMoveEvent(QDragMoveEvent *event)
{
    event->accept();
    QRect updateRect;
    updateRect = highLightedRect;
    if(findLocation(event->pos())!=-1)
    {
        cout << "Location find : " << findLocation(event->pos()) << endl;
        highLightedRect = pieceRects[findLocation(event->pos())];

        event->accept();
    }
    else
    {
        highLightedRect = QRect();
        event->ignore();
    }
    update(updateRect);
}

void GateList::dropEvent(QDropEvent *event)
{
    cout << "DropEvent called!" << endl;
    int target = findLocation(event->pos());
    if(target != -1)
    {
        cout << "I have to replace it!" << endl;

        QByteArray pieceData = event->mimeData()->data("image/x-puzzle-piece");
        QDataStream stream(&pieceData, QIODevice::ReadOnly);
        QRect square = pieceRects[target];
        QPixmap pixmap;
        stream >> pixmap;
        piecePixmaps[target] = pixmap;

        highLightedRect = QRect();

    }
    update();
}

void GateList::mousePressEvent(QMouseEvent *event)
{
    cout << "MousePressEvent called at (" << event->pos().x() << ", " << event->pos().y() << ")" << endl;
    int target = findLocation(event->pos());
    if(target != -1)
    {
     //   highLightedRect2 = pieceRects[target];
    }
    update(highLightedRect2);
}

int GateList::findLocation(const QPoint &point) const
{
    for(int i = 0; i < pieceRects.size(); i++)
    {
        if(point.x() >= pieceRects[i].x() && point.x() <= (pieceRects[i].x() + pieceRects[i].width()) &&
           point.y() >= pieceRects[i].y() && point.y() <= (pieceRects[i].y() + pieceRects[i].height()))
        {
            return i;
        }
    }

    return -1;
}
