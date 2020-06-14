#include "instrukcja.h"
#include "gra.h"

Instrukcja::Instrukcja(QGraphicsScene *g):QObject(),QList<Strona_ins *>() 
{
	/// instrukcja
   sc=g;
    Strona_ins *instrukcja=new Strona_ins(":/images/MUNCHKIN_Lista_Skarbow/MUNCHKIN_Lista_Skarbow-01.jpg");
    insert(end(),instrukcja);
    instrukcja->setPos(g->width()/2-instrukcja->boundingRect().width()/2,g->height()/2-instrukcja->boundingRect().height()/2);

            for( int i=2;i<25;i++)
    {
         QString n=":/images/MUNCHKIN_Lista_Skarbow/MUNCHKIN_Lista_Skarbow-";
        if(i<10)
            n=n+"0"+QString::number(i)+".jpg";
        else
            n=n+QString::number(i)+".jpg";
       instrukcja=new Strona_ins(n);
        insert(end(),instrukcja);
        instrukcja->setPos(g->width()/2-instrukcja->boundingRect().width()/2,g->height()/2-instrukcja->boundingRect().height()/2);
    }
            it=begin();
            connect(*it,SIGNAL(clicked(bool)),this,SLOT(ins(bool)));
            sc->addItem(*it);
}

void Instrukcja::ins(bool k) 
{
	/// wyswietlenie instrukcji
    if(k)
    {
        if(it+1==end())
        return;

        it++;
        sc->removeItem(*(it-1));
        disconnect(*(it-1),SIGNAL(clicked(bool)),this,SLOT(ins(bool)));
        connect(*it,SIGNAL(clicked(bool)),this,SLOT(ins(bool)));
        sc->addItem(*it);
        return;
    }
    if(it==begin())
    return;

    sc->removeItem(*it);
    disconnect(*it,SIGNAL(clicked(bool)),this,SLOT(ins(bool)));
    connect(*(it-1),SIGNAL(clicked(bool)),this,SLOT(ins(bool)));
    sc->addItem(*(it-1));
    it--;
}

