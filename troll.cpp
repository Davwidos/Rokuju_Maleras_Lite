#include "troll.h"
#include"gracz.h"
Troll::Troll(QString path,Gra *gra, QGraphicsItem *parent) :Karta(path,gra,parent)
{
    moc=5;
}

bool Troll::dzialanie(Gracz *g)
{
return true;
}

void Troll::wybrano(QString)
{

}
