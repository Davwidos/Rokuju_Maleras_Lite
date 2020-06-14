#ifndef KARTA_H
#define KARTA_H

#include<QObject>
#include<QGraphicsPixmapItem>
#include<QGraphicsSceneMouseEvent>
#include"przycisk.h"
#include"udpsocket.h"
class Gracz;
class Gra;

class Karta :public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Karta(QString path,Gra*,QGraphicsItem *parent=0);
    void gracze();
    void clearPrzyciski();
    virtual bool dzialanie(Gracz *, Gracz *,UdpSocket *poloczenie)=0;

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    int getMoc();
    QString getNazwa();
public slots:
    virtual void wybrano(QString)=0;
signals:
    void clicked(Karta *k);
protected:
    short moc;
    Gra *gra;
    QList<Przycisk*> przyciski;
    QString nazwa;
};
#endif // KARTA_H
