#include "roslinka.h"
#include"gracz.h"
#include"gra.h"
#include<QMessageBox>
#include<QComboBox>
#include "formularz.h"
Roslinka::Roslinka(QString path, Gra *gra,QGraphicsItem *parent) :Karta(path,gra,parent) // tworzenie karty roślinka
{
    moc=1;
    nazwa="Roslinka";
}


bool Roslinka::dzialanie(Gracz *g, Gracz *d, UdpSocket *poloczenie)  // działanie roślinki
{
  Formularz formularz;
  connect(&formularz,SIGNAL(wyb(QString)),this,SLOT(wybrano(QString)));
  formularz.exec();
  if(wyb==d->k1->getNazwa())
  {
      gra->wygrana();
      return false;
  }
return true;
}

void Roslinka::wybrano(QString a) // zagranie roślinki
{
    wyb=a;
}
