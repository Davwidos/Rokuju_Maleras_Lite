#include "kaczor.h"
#include"gracz.h"

Kaczor::Kaczor(QString path,Gra *gra, QGraphicsItem *parent) :Karta(path,gra,parent)
{
    moc=3;
}

bool Kaczor::dzialanie(Gracz *g, Gracz *d, UdpSocket *poloczenie)
{

return true;
}

void Kaczor::wybrano(QString)
{

}
