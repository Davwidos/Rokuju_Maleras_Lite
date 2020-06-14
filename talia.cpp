#include "talia.h"
#include "karta.h"
#include"gracz.h"
#include"roslinka.h"
#include"mysz.h"
#include"kaczor.h"
#include"pierscien.h"
#include"troll.h"
#include"altanka.h"
#include"smok.h"
#include"skarb.h"
#include <time.h>
#include<QDebug>
Talia::Talia(Gra *t): QList<Karta *>()
{
    for(int i=0;i<5;i++)
    {
        Roslinka *r=new Roslinka(":/images/1.png",t);
       insert(end(),r);
    }
    for(int i=0;i<2;i++)
    {
        Mysz *m=new Mysz(":/images/2.png",t);
       insert(end(),m);
        Kaczor *k=new Kaczor(":/images/3.png",t);
        insert(end(),k);
        Pierscien *p=new Pierscien(":/images/4.png",t);
        insert(end(),p);
        Troll * tr=new Troll(":/images/5.png",t);
        insert(end(),tr);
    }
    Altanka *a=new Altanka(":/images/6.png",t);
    insert(end(),a);
    Smok *s=new Smok(":/images/7.png",t);
    insert(end(),s);
    Skarb *sk=new Skarb(":/images/8.png",t);
    insert(end(),sk);
}
Talia::~Talia()
{
    for(Karta *k:*this) delete k;
    clear();
}
void Talia::tasuj()
{
    QList<Karta*> t0;
    QList<Karta*> t1;
    QList<Karta*> t2;
    QList<Karta*> t3;
      srand(time(NULL));
            for(Karta *k:*this)
    {
    int g=rand()%4;
    switch(g)
    {
    case 0:
    {
        t0.insert(t0.end(),k);
        removeFirst();
    }
        break;
    case 1:
    {
        t1.insert(t1.end(),k);
        removeFirst();
    }
        break;
    case 2:
    {
        t2.insert(t2.end(),k);
        removeFirst();
    }
        break;
    case 3:
    {
        t3.insert(t3.end(),k);
        removeFirst();
    }
    }
    }
        for(Karta *k:t0)
        {
            insert(end(),k);
        }
        for(Karta *k:t1)
        {
            insert(end(),k);
        }
        for(Karta *k:t2)
        {
            insert(end(),k);
        }
        for(Karta *k:t3)
        {
            insert(end(),k);
        }

}

Karta *Talia::dobierzMoc(int m)
{
    for(Karta* k:*this)
        if(k->getMoc()==m)
        {
            removeOne(k);
            return k;
        }
    return nullptr;
}

