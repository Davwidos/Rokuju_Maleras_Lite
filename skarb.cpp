#include "skarb.h"
#include"gracz.h"
Skarb::Skarb(QString path,Gra *gra, QGraphicsItem *parent) :Karta(path,gra,parent) // towrzenie karty skarb
{
    moc=8;
}

bool Skarb::dzialanie(Gracz *g // działanie skarbu
{
return true;
}

void Skarb::wybrano(QString) //zagranie skarbu
{

}
