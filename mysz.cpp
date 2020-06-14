#include "mysz.h"
#include"gracz.h"
#include"gra.h"

Mysz::Mysz(QString path,Gra *gra, QGraphicsItem *parent) :Karta(path,gra,parent) // tworzenie karty mysz
{
    moc=2;
}

bool Mysz::dzialanie(Gracz *g) //dzialanie myszy
{
    gracze();
    return true;
}

void Mysz::wybrano(QString nazwa) // zagranie myszy
{
}
