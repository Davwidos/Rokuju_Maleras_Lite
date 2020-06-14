#include "roslinka.h"
#include"gracz.h"
Roslinka::Roslinka(QString path, Gra *gra,QGraphicsItem *parent) :Karta(path,gra,parent) // tworzenie karty roślinka
{
    moc=1;
}

bool Roslinka::dzialanie(Gracz *g)  // działanie roślinki
{
return true;
}

void Roslinka::wybrano(QString) // zagranie roślinki
{

}
