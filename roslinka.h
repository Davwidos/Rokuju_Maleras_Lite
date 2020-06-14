#ifndef ROSLINKA_H
#define ROSLINKA_H
#include"karta.h"

class Roslinka: public Karta
{
public:
    Roslinka(QString path,Gra *gra,QGraphicsItem *parent=0);
    bool dzialanie(Gracz *,Gracz *,UdpSocket *);
public slots:
    void wybrano(QString);
};

#endif // ROSLINKA_H
