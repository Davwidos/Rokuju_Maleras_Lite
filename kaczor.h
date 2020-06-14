#ifndef KACZOR_H
#define KACZOR_H

#include"karta.h"

class Kaczor :public Karta
{
public:
    Kaczor(QString path,Gra *gra,QGraphicsItem *parent=0);
   bool dzialanie(Gracz *,Gracz *,UdpSocket *);

public slots:
    void wybrano(QString);
};

#endif // KACZOR_H
