#include "troll.h"
#include"gracz.h"
#include "gra.h"
Troll::Troll(QString path,Gra *gra, QGraphicsItem *parent) :Karta(path,gra,parent) // tworzenie karty troll
{
    moc=5;
    nazwa="Troll";
}

bool Troll::dzialanie(Gracz *g, Gracz *d, UdpSocket *poloczenie) // dzialanie trolla
{
    if(g->k1->getMoc()==7||g->k2->getMoc()==7)
        return false;
if (d->ochrona==false)
{
    if(d->k1->getMoc()==8)
    {
        gra->wygrana();
        return false;
    }
    else
    {
        delete d->k1;
        d->k1=nullptr;

        poloczenie->send("24");
    }
}
return true;
}

void Troll::wybrano(QString) // zagranie trolla
{

}
