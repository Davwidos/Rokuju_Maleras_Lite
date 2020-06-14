#include "altanka.h"
#include"gracz.h"
Altanka::Altanka(QString path,Gra *gra, QGraphicsItem *parent) :Karta(path,gra,parent) // tworzenie karty altanka 
{
    moc=6;
}

bool Altanka::dzialanie(Gracz *g) // dzialanie altanki
{
return true;
}

void Altanka::wybrano(QString) // zagranie altanki
{

}
