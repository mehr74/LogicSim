#include "gatelist.h"
#include <QRect>
#include <QPaintEvent>
#include <iostream>
#include <iomanip>
#include <QDrag>
#include <QMimeData>
#include <QHoverEvent>
#include "model/gatetextures.h"
using namespace std;

GateList::GateList(QWidget *parent, const QSize size)
    :QWidget(parent)
{
    cout << "Create new gatelist (" << widgetWidth << ", " << widgetHeight << ")" << endl;
    widgetHeight = size.height();
    widgetWidth = size.width();
    circuit = new Circuit();
    addPieces();
    setAcceptDrops(true);
    setMouseTracking(true);

    setMaximumSize(size);
    setMinimumSize(size);
}

void GateList::addPieces()
{

    QRect mRect;
    QSize *size = new QSize(80, 50);

    piecePixmaps.clear();
    pieceRects.clear();

    widthGap = 80;
    heightGap = 25;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            mRect = QRect(j * (size->width() + widthGap) ,
                          i * (size->height() + heightGap),
                          size->width(),
                          size->height());
            cout << "#-Add-Rectange-------------------------------------" << endl
                    << left << setw(15) << "#-Size: " << "("<< size->width() << ", " << size->height() << ")" << endl
                    << left << setw(15) << "#-Location: " << "(" << j * (size->width() +30) + 10
                    << ", " << i*(size->height() + 10) + 10 << ")" << endl
                    << left << setw(15) << "#-Image: " << "\"" << objectPics[EMPTY] << "\"" << endl
                    << "#--------------------------------------------------\n" << endl;
            QPixmap temp(objectPics[EMPTY]);
            QPixmap *pieceImage = new QPixmap(temp.scaled(*size));

            piecePixmaps.append(*pieceImage);
            pieceRects.append(mRect);
            pieceType.append(EMPTY);
            pieceId.append(0);
        }
    }

    update();
}



void GateList::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);

    painter.fillRect(event->rect(), QColor(255,255,255));


    for (int i = 0; i < pieceRects.size(); ++i)
    {
        painter.drawPixmap(pieceRects[i], piecePixmaps[i]);
    }

    for (int i = 0; i < connectors.size(); ++i)
    {
        QPixmap *connectorPixmap = new QPixmap(objectPics[CONNECTOR]);
        painter.drawPixmap(connectors[i], *connectorPixmap);
    }

    for (int i = 0; i < probes.size(); ++i)
    {
        QPixmap *probePixmap;
        if(circuit->getSignal(probeIds[i]) == true)
        {
            probePixmap = new QPixmap(objectPics[PROBE_ON]);
        }
        else
        {
            probePixmap = new QPixmap(objectPics[PROBE_OFF]);
        }
        painter.drawPixmap(probes[i], *probePixmap);
    }

    for (int i =0; i < usedConnectors.size(); ++i)
    {
        QPixmap *connectorPixmap = new QPixmap(objectPics[CONNECTOR_USED]);
        painter.drawPixmap(usedConnectors[i], *connectorPixmap);
    }

    for (int i = 0; i < wires.size(); i++)
    {
        painter.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap));
        painter.drawPolygon(wires[i]);
    }

    if(highLightedRect.isValid())
    {
        painter.drawPixmap(highLightedRect, highLightedPixmap);
    }

    if(highLightedConnector.isValid())
    {
        QPixmap *connectorPixmap = new QPixmap(objectPics[CONNECTOR_HOVERED]);
        painter.drawPixmap(highLightedConnector, *connectorPixmap);
    }

    if(wireStart.isValid())
    {
        QPixmap *connectorPixmap = new QPixmap(objectPics[CONNECTOR_HOVERED]);
        painter.drawPixmap(wireStart, *connectorPixmap);
    }

    painter.end();
}

void GateList::dragEnterEvent(QDragEnterEvent *event)
{
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
    int target = findApproximateLocation(event->pos());
    if(target !=-1)
    {
        if(pieceType[target] != EMPTY)
        {
            highLightedRect = QRect();
            event->ignore();
            update();
            return;
        }

        highLightedRect = pieceRects[target];
        QByteArray pieceData = event->mimeData()->data("image/gates");
        QDataStream stream(&pieceData, QIODevice::ReadOnly);
        stream >> highLightedPixmap;

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
    int target = findApproximateLocation(event->pos());
    if(target != -1)
    {
        if(pieceType[target] != EMPTY)
        {
            highLightedRect = QRect();
            event->ignore();
            return;
        }

        QByteArray pieceData = event->mimeData()->data("image/gates");
        QDataStream stream(&pieceData, QIODevice::ReadOnly);
        int gateType;
        QPixmap pixmap;
        stream >> pixmap;
        stream >> gateType;

        int id = circuit->addGate(gateType);
        piecePixmaps[target] = pixmap;
        pieceType[target] = gateType;
        pieceId[target] = id;

        addInputConnector(pieceRects[target], circuit->InCount(gateType), id);
        addOutputConnector(pieceRects[target], id);

        highLightedRect = QRect();
    }
    update();
}

void GateList::mousePressEvent(QMouseEvent *event)
{
    int target = findConnector(event->pos());
    if(target != -1)
    {
        if(wireStart.isValid())
        {
            usedConnectors.append(wireStart);
            usedConnectors.append(connectors[target]);
            QPoint start = QPoint(wireStart.x() + 5, wireStart.y() + 5);
            QPoint end = QPoint(connectors[target].x() + 5, connectors[target].y() + 5);
            circuit->addConnection(connectorsId[wireStartNum], connectorsId[target],
                                   connectorsType[wireStartNum], connectorsType[target]);
            addWire(start, end);
            wireStart = QRect();
        }
        else
        {
            wireStart = connectors[target];
            wireStartNum = target;
        }
    }
    else
    {
        wireStart = QRect();
    }
    update();
}

void GateList::mouseMoveEvent(QMouseEvent *event)
{
    int target = findConnector(event->pos());
    if(target != -1)
    {
        highLightedConnector = connectors[target];
    }
    else
    {
        highLightedConnector = QRect();
    }
    update();
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

int GateList::findConnector(const QPoint &point) const
{
    for(int i = 0; i < connectors.size(); i++)
    {
        if(point.x() >= connectors[i].x() && point.x() <= (connectors[i].x() + connectors[i].width()) &&
           point.y() >= connectors[i].y() && point.y() <= (connectors[i].y() + connectors[i].height()))
        {
            return i;
        }
    }

    return -1;
}

int GateList::findApproximateLocation(const QPoint &point)const
{
    for(int i = 0; i < pieceRects.size(); i++)
    {
        if(point.x() >= (pieceRects[i].x() - widthGap/2) &&
           point.x() <= (pieceRects[i].x() + pieceRects[i].width() + widthGap/2) &&
           point.y() >= (pieceRects[i].y() - heightGap/2) &&
           point.y() <= (pieceRects[i].y() + pieceRects[i].height() + heightGap/2))
        {
            return i;
        }
    }
    return -1;
}

void GateList::addInputConnector(const QRect &rect, int number, int id)
{
    QRect mRect;
    if(number == 1)
    {
        mRect = QRect(rect.x()- 10, rect.y() + (rect.height()/2) - 5, 10, 10);
        connectors.append(mRect);
        connectorsId.append(id);
        connectorsType.append(INPUT_CONNECTOR1);
    }
    else if(number == 2)
    {
        mRect = QRect(rect.x()-10, rect.y() + 8, 10, 10);
        connectors.append(mRect);
        connectorsId.append(id);
        connectorsType.append(INPUT_CONNECTOR1);
        mRect = QRect(rect.x()-10, rect.y() + 32, 10, 10);
        connectors.append(mRect);
        connectorsId.append(id);
        connectorsType.append(INPUT_CONNECTOR2);
    }
}

void GateList::addOutputConnector(const QRect &rect, int id)
{
    QRect mRect;
    mRect = QRect(rect.x()+ rect.width(), rect.y() + (rect.height()/2) - 5, 10, 10);
    connectors.append(mRect);
    connectorsId.append(id);
    connectorsType.append(OUTPUT_CONNECTOR);

    mRect = QRect(rect.x()+rect.width() - 10, rect.y() + rect.height() - 10, 8, 8);
    probes.append(mRect);
    probeIds.append(id);
}

void GateList::addWire(const QPoint &start, const QPoint &end)
{
    if(start.x() > end.x())
        addWire(end, start);

    QPolygon wire;
    wire.append(start);
 //   wire.append(QPoint(start.x(), end.y()));
    wire.append(end);
    wires.append(wire);
}

int GateList::addConnection()
{
    return -1;
}
