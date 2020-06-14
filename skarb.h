#ifndef SKARB_H
#define SKARB_H


#include"karta.h"

class Skarb :public Karta
{
public:
    Skarb(QString path,Gra *gra,QGraphicsItem *parent=0);
    bool dzialanie(Gracz *,Gracz *,UdpSocket *);
public slots:
    void wybrano(QString);
};

#endif // Skarb_H
