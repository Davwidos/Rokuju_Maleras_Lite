#include "roslinka.h"
#include"gracz.h"
Roslinka::Roslinka(QString path, Gra *gra,QGraphicsItem *parent) :Karta(path,gra,parent) 
{
	/// tworzenie karty roślinka
    moc=1;
    nazwa="Roslinka";
}


bool Roslinka::dzialanie(Gracz *g, Gracz *d, UdpSocket *poloczenie)  
{
	/// działanie roślinki
return true;
}

void Roslinka::wybrano(QString) // zagranie roślinki
{

}
