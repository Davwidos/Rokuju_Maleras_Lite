#include "mysz.h"
#include"gracz.h"
#include"gra.h"

Mysz::Mysz(QString path,Gra *gra, QGraphicsItem *parent) :Karta(path,gra,parent)
{
    moc=2;
}

bool Mysz::dzialanie(Gracz *g, Gracz *d, UdpSocket *poloczenie)
{
    gracze();
    return true;
}

void Mysz::wybrano(QString nazwa)
{
}
