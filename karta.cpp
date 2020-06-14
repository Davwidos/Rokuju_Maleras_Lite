#include "karta.h"
#include"gra.h"
#include"przycisk.h"
#include<QDebug>
//klasa obsługujaca  dzialanie kart
Karta::Karta(QString path,Gra *gra,QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent) 
{
    setPixmap(QPixmap(path).scaled(200,282));
    this->gra=gra;
}

void Karta::gracze()
{
    /*for(Przycisk *przycisk:gra->getPrzyciskGracze())
        connect(przycisk,SIGNAL(clicked(STring)),this,SLOT(wybrano(QString)));*/

}

void Karta::clearPrzyciski()
{
    for(Przycisk * p:przyciski)
    {
        gra->scene->removeItem(p);
        delete p;
    }
    przyciski.clear();
}

void Karta::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked(this);
}

int Karta::getMoc()
{
    return moc;
}

QString Karta::getNazwa()
{
    return nazwa;
}
