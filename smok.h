#ifndef SMOK_H
#define SMOK_H


#include"karta.h"

class Smok :public Karta
{
public:
    Smok(QString path,Gra *gra,QGraphicsItem *parent=0);
    bool dzialanie(Gracz *,Gracz *,UdpSocket *);
public slots:
    void wybrano(QString);
};

#endif // Smok_H
