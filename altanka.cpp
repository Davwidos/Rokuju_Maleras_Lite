#include "altanka.h"
#include"gracz.h"
#include"gra.h"
Altanka::Altanka(QString path,Gra *gra, QGraphicsItem *parent) :Karta(path,gra,parent)
{
    moc=6;
}

bool Altanka::dzialanie(Gracz *g, Gracz *d, UdpSocket *poloczenie)
{
    if(g->k1->getMoc()==7||g->k2->getMoc()==7)
        return false;
  if (d->ochrona==false)
  {
      Karta *b=d->k1;
      b->setY(gra->height()-b->boundingRect().height());
      connect(b,SIGNAL(clicked(Karta*)),g,SLOT(zagraj(Karta*)));
      if(g->k1==this)
      {
          gra->scene->removeItem(g->k2);
          disconnect(g->k2,SIGNAL(clicked(Karta*)),g,SLOT(zagraj(Karta*)));
          d->k1=g->k2;
      g->k2=b;

      b->setX(gra->width()/2);

      }
      else
      {
          gra->scene->removeItem(g->k1);
          disconnect(g->k1,SIGNAL(clicked(Karta*)),g,SLOT(zagraj(Karta*)));
          d->k1=g->k1;
      g->k1=b;
      b->setX(gra->width()/2-b->boundingRect().width());
      }
      gra->scene->addItem(b);
      poloczenie->send("22");
  }
return true;
}

void Altanka::wybrano(QString)
{

}
