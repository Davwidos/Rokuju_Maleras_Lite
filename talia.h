#ifndef TALIA_H
#define TALIA_H
#include <QList>
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
class Talia:public QList<Karta*>
{
public:
    Talia(Gra *t);
    QList<Karta*>::iterator it;
    ~Talia();
    void tasuj();
    Karta *dobierzMoc(int);



};

#endif // TALIA_H
