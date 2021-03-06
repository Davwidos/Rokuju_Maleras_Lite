#include "gra.h"
#include<QApplication>
#include<QDesktopWidget>
#include<QBrush>
#include<windows.h>
#include"gracz.h"
#include"roslinka.h"
#include"mysz.h"
#include"kaczor.h"
#include"pierscien.h"
#include"troll.h"
#include"altanka.h"
#include"smok.h"
#include"skarb.h"
#include<QList>
#include"strona_ins.h"
#include "talia.h"
#include<QDebug>
#include<QMessageBox>
#include<QMediaPlayer>
#include<QMediaPlaylist>
#include<QUrl>
Gra::Gra(QWidget *parent) :QGraphicsView(parent) 
{
	/// tworzenie okna z gra
    QRect rec=QApplication::desktop()->screenGeometry();
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,rec.width(),rec.height());
    QImage image=QImage(":/images/bg.jpg");
    image=image.scaled(rec.width(),rec.height());
    setBackgroundBrush(QBrush(image));
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(rec.width(),rec.height());
    setScene(scene);
    poloczenie=new UdpSocket(this);
    connect(poloczenie,SIGNAL(karta(QString,QString)),this,SLOT(recive(QString,QString)));
    connect(poloczenie,SIGNAL(connected()),this,SLOT(menu()));
    QMediaPlaylist *muzyka= new QMediaPlaylist;
    muzyka->addMedia(QUrl("qrc:/muzyka/muzyka.mp3"));
    muzyka->setPlaybackMode(QMediaPlaylist::Loop);
    QMediaPlayer *muz=new QMediaPlayer;
    muz->setPlaylist(muzyka);
    muz->play();
    menu();
}


Karta *Gra::dobierz() 

{
	///dobieranie karty przez gracza
    if(!talia->empty())
    {
        Karta *k=talia->first();
        talia->removeFirst();
        return k;
    }

    return nullptr;
}

void Gra::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Escape && state!="menu") menu();
}

QList<Przycisk *> Gra::getPrzyciskGracze()
{
    QList<Przycisk*> przyciski;
    //int j=0;
    //for(Karta *t:talia) continue;

    /*for(Gracz *g:*poloczeni)
    {
        Przycisk *przycisk=new Przycisk(g->getNazwa());
        przycisk->setX(width()/2-przycisk->boundingRect().width()/2);
        przycisk->setY(j++*height());
        przyciski.insert(przyciski.end(),przycisk);
    }*/
    return przyciski;
}


void Gra::start() 
{
	/// rozpoczecie gry
    if(state=="polacz") delete dodajPoloczenie;
    gracz=new Gracz(this,"");
    scene->clear();
    state="start";
    talia=new Talia(this);
    talia->tasuj();
    drugigracz=new Gracz(this,"przeciwnik");
    tura();

}

void Gra::stop() 
{
	//// zakonczenie gry
    QApplication::quit();
}

void Gra::menu() 
{
	//// przejscie do menu
    if(state=="instrukcja") delete instru;
    else if(state=="start")
    {
        delete gracz;
        delete talia;
        nastole=nullptr;
    }
    else if(state=="polacz") delete dodajPoloczenie;
    state="menu";
    scene->clear();
    Przycisk *przycisk=new Przycisk("Nowa Gra");
    przycisk->setX(width()/2-przycisk->boundingRect().width()/2);
    connect(przycisk,SIGNAL(clicked(QString)),this,SLOT(nowaGra()));
    scene->addItem(przycisk);
    przycisk=new Przycisk("Połącz");
    przycisk->setX(width()/2-przycisk->boundingRect().width()/2);
    przycisk->setY(przycisk->boundingRect().height());
    connect(przycisk,SIGNAL(clicked(QString)),this,SLOT(polacz()));
    scene->addItem(przycisk);
    przycisk=new Przycisk("Instrukcja");
    przycisk->setX(width()/2-przycisk->boundingRect().width()/2);
    przycisk->setY(2*przycisk->boundingRect().height());
    connect(przycisk,SIGNAL(clicked(QString)),this,SLOT(instrukcja()));
    scene->addItem(przycisk);
    przycisk=new Przycisk("Wyjscie");
    przycisk->setX(width()/2-przycisk->boundingRect().width()/2);
    przycisk->setY(3*przycisk->boundingRect().height());
    connect(przycisk,SIGNAL(clicked(QString)),this,SLOT(stop()));
    scene->addItem(przycisk);
}

void Gra::tura() 
{
	/// zaczecie tury
    Karta *k=gracz->dobierz();
    if(k==nullptr)
    {
         QMessageBox msgBox;
        if(gracz->k1->getMoc()>=drugigracz->k1->getMoc())
        {
            poloczenie->send("20");
            //QMessageBox *box= new QMessageBox (this);
                msgBox.setText("Wygrałeś!");


        }
        else
        {
            poloczenie->send("21");
                msgBox.setText("Przegrałeś!");

        }

        msgBox.exec();
        menu();
       // connect(msgBox,SIGNAL(buttonClicked(QAbstractButton *button)),this,SLOT(menu()));
        return;

    }
    gracz->ochrona=false;
    send(k->getMoc()+10);
    k->setY(height()-k->boundingRect().height());
    scene->addItem(k);
    gracz->k1->setX(width()/2-gracz->k1->boundingRect().width());
    if(gracz->k2==nullptr) return;
    gracz->k2->setX(width()/2);
    gracz->tura=true;
}

void Gra::koniectury(Karta* k) 
{
    //if(!gracz->tura) return;
	///zakonczenie tury
    if(nastole!=nullptr)
    {
        scene->removeItem(nastole);
        delete nastole;
    }
    nastole=k;
    nastole->setX(width()/2-nastole->boundingRect().width()/2);
    nastole->setY(height()/2-nastole->boundingRect().height()/2);
    send(nastole->getMoc());
    drugigracz->ochrona=false;
}

void Gra::kolejnatura(int m)
{
	/// przejscie do kolejnej tury
    Karta *k;
    if(m==1) k=new Roslinka(":/images/1.png",this);
    else if(m==2) k=new Mysz(":/images/2.png",this);
    else if(m==3) k=new Kaczor(":/images/3.png",this);
    else if(m==4)
    {
        k=new Pierscien(":/images/4.png",this);
        drugigracz->ochrona=true;

    }
    else if(m==5) k=new Troll(":/images/5.png",this);
    else if(m==6) k=new Altanka(":/images/6.png",this);
    else if(m==7) k=new Smok(":/images/7.png",this);
    else if(m==8) k=new Skarb(":/images/8.png",this);
    else return;
    if(nastole!=nullptr)
    {
        scene->removeItem(nastole);
        delete nastole;
    }
    nastole=k;
    nastole->setX(width()/2-nastole->boundingRect().width()/2);
    nastole->setY(height()/2-nastole->boundingRect().height()/2);
    scene->addItem(nastole);
    tura();
}

void Gra::nowaGra() 
{
  /// rozpoczecie nowej gry
    start();
     qDebug()<<talia->size()<<"tyle kart";
    poloczenie->send(QString::number(dobierz()->getMoc()+30));
    poloczenie->send(QString::number(dobierz()->getMoc()+30));
    poloczenie->send(QString::number(dobierz()->getMoc()+30));
    qDebug()<<talia->size()<<"tyle kart";
    tura();
}

void Gra::instrukcja() 
{
	/// otworzenie instrukcji
    state="instrukcja";
    scene->clear();
     instru=new Instrukcja(scene);



}

void Gra::recive(QString s,QString nadawca) 
{
	/// otrzymywanie danych od drugiego gracza
    if(!isdigit(s.toStdString()[0]))
    {
        return;
    }
    int k=s.toInt();
    if(k==0) return;
    if(state!="start") start();
    if(k<10)
    {
        if(drugigracz->k1->getMoc()==k)
        {
            delete drugigracz->k1;
        drugigracz->k1=drugigracz->k2;
        }
        else
            delete drugigracz->k2;
        kolejnatura(k);
        return;
    }
    if(k<20)
    {

        if(drugigracz->k1==nullptr)
           drugigracz->k1= talia->dobierzMoc(k%10);
        else
            drugigracz->k2= talia->dobierzMoc(k%10);
        return;
    }
    if(k==20)
    {
         QMessageBox msgBox;
        msgBox.setText("Przegrałeś!");
        msgBox.exec();
        menu();
        return;
       // connect(msgBox,SIGNAL(buttonClicked(QAbstractButton *button)),this,SLOT(menu()));
    }
    if(k==21)
    {
        QMessageBox msgBox;
        msgBox.setText("Wygrałeś!");
        msgBox.exec();
       // connect(msgBox,SIGNAL(buttonClicked(QAbstractButton *button)),this,SLOT(menu()));
        menu();
        return;
    }
    if(k==22)
    {
        Karta *b=gracz->k1;
        scene->removeItem(gracz->k1);
        disconnect(gracz->k1,SIGNAL(clicked(Karta*)),gracz,SLOT(zagraj(Karta*)));
        if(drugigracz->k1->getMoc()!=6)
        {

            gracz->k1=drugigracz->k1;

        drugigracz->k1=b;
        }
        else
        {
            gracz->k1=drugigracz->k2;
        drugigracz->k2=b;
        }
        connect(gracz->k1,SIGNAL(clicked(Karta*)),gracz,SLOT(zagraj(Karta*)));
        gracz->k1->setY(height()-gracz->k1->boundingRect().height());
        gracz->k1->setX(width()/2-gracz->k1->boundingRect().width());
        scene->addItem(gracz->k1);
        return;
    }
    if(k==23)
    {
        wiadomosc("remis!");
        return;

    }
    if(k==24)
    {
        scene->removeItem(gracz->k1);
                delete gracz->k1;
        gracz->k1=nullptr;
        tura();
        gracz->tura=false;
        return;
    }
    if(k<40)
    {
       talia->dobierzMoc(k%10);
    }
}

void Gra::send(int w) 
{
/// wyslanie fanych do drugiego gracza
    poloczenie->send(QString::number(w));
}

void Gra::polacz() 
{
	/// laczenie z innym graczem
    state="polacz";
    scene->clear();
    dodajPoloczenie=new DodajPoloczenie(this);
    dodajPoloczenie->resize(width()/2,height()/2);
    dodajPoloczenie->move(width()/2-dodajPoloczenie->width()/2,height()/2-dodajPoloczenie->height()/2);
    dodajPoloczenie->setVisible(true);
    connect(dodajPoloczenie,SIGNAL(wyslij(QString)),poloczenie,SLOT(addConnection(QString)));

}

void Gra::wygrana()
{
	//// wyswietlenie okna z wygrana
    QMessageBox msgBox;
    poloczenie->send("20");
    msgBox.setText("Wygrałeś!");
    msgBox.exec();
    this->menu();
}
void Gra::przegrana()
{
	///wyswietlenie okna z przegrana
    QMessageBox msgBox;
    poloczenie->send("21");
    msgBox.setText("Przegrałeś!");
    msgBox.exec();
    this->menu();
}
void Gra::wiadomosc(QString t)
{
	/// wyswietlenie wiadomosc w trakcie gry
    QMessageBox *msgBox= new QMessageBox(this);
    msgBox->setText(t);
    msgBox->show();


}

