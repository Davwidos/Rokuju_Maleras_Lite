#ifndef TROLL_H
#define TROLL_H


#include"karta.h"

class Troll :public Karta
{
public:
    Troll(QString path,Gra *gra,QGraphicsItem *parent=0);
    bool dzialanie(Gracz *,Gracz *,UdpSocket *);
public slots:
    void wybrano(QString);
};

#endif // Troll_H
