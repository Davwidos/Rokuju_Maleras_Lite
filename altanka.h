#ifndef ALTANKA_H
#define ALTANKA_H


#include"karta.h"

class Altanka :public Karta
{
public:
    Altanka(QString path,Gra *gra,QGraphicsItem *parent=0);
    bool dzialanie(Gracz *,Gracz *,UdpSocket *);

public slots:
    void wybrano(QString);
};

#endif // Altanka_H
