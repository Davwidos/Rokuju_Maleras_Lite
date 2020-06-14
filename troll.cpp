#include "troll.h"
#include"gracz.h"
Troll::Troll(QString path,Gra *gra, QGraphicsItem *parent) :Karta(path,gra,parent) // tworzenie karty troll
{
    moc=5;
}

bool Troll::dzialanie(Gracz *g, Gracz *d, UdpSocket *poloczenie) // dzialanie trolla
{
    if(g->k1->getMoc()==7||g->k2->getMoc()==7)
        return false;

return true;
}

void Troll::wybrano(QString) // zagranie trolla
{

}
