#include "pierscien.h"
#include"gracz.h"
Pierscien::Pierscien(QString path,Gra *gra, QGraphicsItem *parent) :Karta(path,gra,parent) 
{
	/// tworzenie karty pierscien
    moc=4;
    nazwa="Pierscien";
}

bool Pierscien::dzialanie(Gracz *g, Gracz *d, UdpSocket *poloczenie) 
{
	/// dzialanie pierscienia
    g->ochrona=true;
    return true;
}

void Pierscien::wybrano(QString) // zagranie pierscienia
{

}
