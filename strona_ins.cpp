#include "strona_ins.h"
Strona_ins::Strona_ins(QString s,QGraphicsItem *p):QObject(),QGraphicsPixmapItem(p)
{ 
   setPixmap(QPixmap(s));
     setScale(1.1);

}

void Strona_ins::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
        emit clicked(0);
    else
        emit clicked(1);
}


