#include "kaczor.h"
#include"gracz.h"
#include"gra.h"
Kaczor::Kaczor(QString path,Gra *gra, QGraphicsItem *parent) :Karta(path,gra,parent) // tworzenie karty kaczor
{

    moc=3;
    nazwa="Kaczor";
}


bool Kaczor::dzialanie(Gracz *g, Gracz *d, UdpSocket *poloczenie)// dzialanie kaczora
{
    if (d->ochrona==false)
    {



        if(g->k1==this)
        {
            if(g->k2->getMoc()>d->k1->getMoc())
            {
                gra->wygrana();
                return false;
            }

             if(g->k2->getMoc()<d->k1->getMoc())
             {
                 gra->przegrana();
                 return false;
             }
             if(g->k2->getMoc()==d->k1->getMoc())
               {  gra->wiadomosc("remis!");
                poloczenie->send("23");

             }

        }
        else
        {
            if(g->k1->getMoc()>d->k1->getMoc())   
            {
                gra->wygrana();
                return false;
            }
             if(g->k1->getMoc()<d->k1->getMoc())
             {
                 gra->przegrana();
                 return false;
             }
             if(g->k1->getMoc()==d->k1->getMoc())
                 gra->wiadomosc("remis!");
                                 poloczenie->send("23");
        }
    }
return true;

}

void Kaczor::wybrano(QString) // zagranie kaczora
{

}
