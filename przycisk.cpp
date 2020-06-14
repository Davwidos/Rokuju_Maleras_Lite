#include "przycisk.h"
#include<QGraphicsTextItem>
#include<QBrush>

//tworzenie nowego przycisku
Przycisk::Przycisk(QString nazwa,QGraphicsItem *parent):QObject(),QGraphicsRectItem(parent)
{
    setRect(0,0,200,100);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);
    text=new QGraphicsTextItem(nazwa,this);
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);
    setAcceptHoverEvents(true);
}

//co się dzieje po kliknięciu dowolnym przyciskiem myszy w obiekt
void Przycisk::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked(text->toPlainText());
}

//co się dzieje po najechaniu kursora myszy na obiekt
void Przycisk::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::yellow);
    setBrush(brush);
}

//co się dzieje po wyjściu kursora myszy poza obiekt
void Przycisk::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);
}
