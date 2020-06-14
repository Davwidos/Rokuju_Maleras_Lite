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
    Gracz *gracz;
    Gracz *drugigracz;
    UdpSocket *poloczenie;
public slots:
    void nowaGra();
    void start();
    void stop();
    void menu();
    void tura();
    void koniectury(Karta*);
    void instrukcja();
    void recive(QString,QString);
    void send(int);
    void polacz();
    void wygrana();
    void przegrana();
    void wiadomosc(QString);


private:



    Talia *talia;
    QString state;
    Instrukcja *instru;

    DodajPoloczenie *dodajPoloczenie;


};

#endif // GRA_H
