#ifndef PIERSCIEN_H
#define PIERSCIEN_H



#include"karta.h"

class Pierscien :public Karta
{
public:
    Pierscien(QString path,Gra *gra,QGraphicsItem *parent=0);
    bool dzialanie(Gracz *,Gracz *,UdpSocket *);
public slots:
    void wybrano(QString);
};

#endif // Pierscien_H
