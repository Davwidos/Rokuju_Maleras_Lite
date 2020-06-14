#include "skarb.h"
#include"gracz.h"
#include"gra.h"
#include<QMessageBox>

Skarb::Skarb(QString path,Gra *gra, QGraphicsItem *parent) :Karta(path,gra,parent)
{
	/// towrzenie karty skarb
    moc=8;
    nazwa="Skarb";
}

bool Skarb::dzialanie(Gracz *g, Gracz *d, UdpSocket *poloczenie)
{
	/// działanie skarbu
   gra->przegrana();
return false;
}

void Skarb::wybrano(QString) //zagranie skarbu
{

}
