#include "kaczor.h"
#include"gracz.h"
#include"gra.h"
Kaczor::Kaczor(QString path,Gra *gra, QGraphicsItem *parent) :Karta(path,gra,parent) // tworzenie karty kaczor
{

    moc=3;
}


bool Kaczor::dzialanie(Gracz *g, Gracz *d, UdpSocket *poloczenie)// dzialanie kaczora
{
    if (d->ochrona==false)
    {



        if(g->k1==this)
        {
            if(g->k2>d->k1)
                gra->wygrana();

             if(g->k2<d->k1)
                 gra->przegrana();
             if(g->k2==d->k1)
                 gra->remis();
        }
        else
        {
            if(g->k1>d->k1)
                gra->wygrana();
             if(g->k1<d->k1)
                 gra->przegrana();
             if(g->k1==d->k1)
                 gra->remis();
        }
    }
return true;

}

void Kaczor::wybrano(QString) // zagranie kaczora
{

}
