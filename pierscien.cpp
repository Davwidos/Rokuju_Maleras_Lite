#include "pierscien.h"
#include"gracz.h"
Pierscien::Pierscien(QString path,Gra *gra, QGraphicsItem *parent) :Karta(path,gra,parent) // tworzenie karty pierscien
{
    moc=4;
}

bool Pierscien::dzialanie(Gracz *g) // dzialanie pierscienia
{
    g->ochrona=true;
    return true;
}

void Pierscien::wybrano(QString) // zagranie pierscienia
{

}
