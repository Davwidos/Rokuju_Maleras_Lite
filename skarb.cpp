#include "skarb.h"
#include"gracz.h"
#include"gra.h"
#include<QMessageBox>

Skarb::Skarb(QString path,Gra *gra, QGraphicsItem *parent) :Karta(path,gra,parent)// towrzenie karty skarb
{
    moc=8;
}

bool Skarb::dzialanie(Gracz *g, Gracz *d, UdpSocket *poloczenie)// działanie skarbu
{
    QMessageBox *msgBox=new QMessageBox (gra);
    poloczenie->send("21");
    msgBox->setText("Przegrałeś!");
    msgBox->exec();
    gra->menu();
return true;
}

void Skarb::wybrano(QString) //zagranie skarbu
{

}
