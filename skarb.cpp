#include "skarb.h"
#include"gracz.h"
Skarb::Skarb(QString path,Gra *gra, QGraphicsItem *parent) :Karta(path,gra,parent)
{
    moc=8;
}

bool Skarb::dzialanie(Gracz *g, Gracz *d, UdpSocket *poloczenie)
{
return true;
}

void Skarb::wybrano(QString)
{

}
