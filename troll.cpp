#include "troll.h"
#include"gracz.h"
Troll::Troll(QString path,Gra *gra, QGraphicsItem *parent) :Karta(path,gra,parent) // tworzenie karty troll
{
    moc=5;
}

bool Troll::dzialanie(Gracz *g) // dzialanie trolla
{
return true;
}

void Troll::wybrano(QString) // zagranie trolla
{

}
