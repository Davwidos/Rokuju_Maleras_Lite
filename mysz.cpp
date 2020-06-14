#include "mysz.h"
#include"gracz.h"
#include"gra.h"

Mysz::Mysz(QString path,Gra *gra, QGraphicsItem *parent) :Karta(path,gra,parent) 
{
	/// tworzenie karty mysz
    moc=2;
    nazwa="Mysz";
}


bool Mysz::dzialanie(Gracz *g, Gracz *d, UdpSocket *poloczenie)
{
	 ///dzialanie myszy
    gra->wiadomosc(d->k1->getNazwa());
    return true;
}

void Mysz::wybrano(QString nazwa) // zagranie myszy
{
}
