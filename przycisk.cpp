#include "przycisk.h"
#include<QGraphicsTextItem>
#include<QBrush>


Przycisk::Przycisk(QString nazwa,QGraphicsItem *parent):QObject(),QGraphicsRectItem(parent)
{
	///tworzenie nowego przycisku
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


void Przycisk::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	///co się dzieje po kliknięciu dowolnym przyciskiem myszy w obiekt
    emit clicked(text->toPlainText());
}


void Przycisk::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
	///co się dzieje po najechaniu kursora myszy na obiekt
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::yellow);
    setBrush(brush);
}


void Przycisk::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
	///co się dzieje po wyjściu kursora myszy poza obiekt
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);
}
