#ifndef GRA_H
#define GRA_H
#include<QGraphicsView>
#include<QGraphicsScene>
#include"gracz.h"
#include"karta.h"
#include"przycisk.h"
#include<QKeyEvent>
#include<QList>
#include"instrukcja.h"
#include"talia.h"
#include"udpsocket.h"
#include<QInputDialog>
#include"dodajpoloczenie.h"
#include"gracze.h"
#include<QGraphicsTextItem>
class Gra:public QGraphicsView
{
    Q_OBJECT
public:
    Gra(QWidget *parent=0);
    Karta *dobierz();
    void keyPressEvent(QKeyEvent *event);
    QList<Przycisk *> getPrzyciskGracze();
    void kolejnatura(int k);
    QGraphicsScene *scene;
    Karta *nastole=nullptr;
    void nastepnyGracz();
public slots:
    void nowaGra();
    void start(QString);
    void stop();
    void menu();
    void tura();
    void koniectury(Karta*);
    void instrukcja();
    void recive(QString,QString);
    void polacz();

private:
    Gracz *gracz;
    Gracz *turagracza;
    QList<Gracz*> gracze;
    Talia *talia;
    QString state;
    bool host=false;
    Instrukcja *instru;
    UdpSocket *poloczenie;
    DodajPoloczenie *dodajPoloczenie;
    QGraphicsTextItem *czyja;


};

#endif // GRA_H
