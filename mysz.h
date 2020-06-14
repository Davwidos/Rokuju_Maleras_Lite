#ifndef MYSZ_H
#define MYSZ_H

#include"karta.h"

class Mysz :public Karta
{
public:
    Mysz(QString path,Gra *gra,QGraphicsItem *parent=0);
   bool dzialanie(Gracz *,Gracz *,UdpSocket *);
public slots:
    void wybrano(QString);
};

#endif // MYSZ_H
