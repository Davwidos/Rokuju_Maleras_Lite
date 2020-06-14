#include "smok.h"
#include"gracz.h"
Smok::Smok(QString path,Gra *gra, QGraphicsItem *parent) :Karta(path,gra,parent) //towrzenie karty smok
{
    moc=7;
}

bool Smok::dzialanie(Gracz *g, Gracz *d, UdpSocket *poloczenie)//działanie smoka
{
return true;
}

void Smok::wybrano(QString) //zagranie smoka
{

}
