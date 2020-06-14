#include "kaczor.h"
#include"gracz.h"

Kaczor::Kaczor(QString path,Gra *gra, QGraphicsItem *parent) :Karta(path,gra,parent) // tworzenie karty kaczor
{
    moc=3;
}

bool Kaczor::dzialanie(Gracz *g) // dzialanie kaczora
{

return true;
}

void Kaczor::wybrano(QString) // zagranie kaczora
{

}
