#ifndef UDPSOCKET_H
#define UDPSOCKET_H
#include<QUdpSocket>
#include<QObject>
#include<QGraphicsView>
class UdpSocket:public QObject
{
    Q_OBJECT
public:
    UdpSocket(QGraphicsView*,QObject *parent=0);
    QList<QString> getConnections();

public slots:
    void readyRead();
    void send(QString,QHostAddress address=QHostAddress::Null);
    void addConnection(QString);
    void dajMojAddres();
signals:
    void karta(QString,QString);
    void connected();
    void tura();
    void start(QString);
private:
    QUdpSocket *myudpsocket;
    QList<QHostAddress> allConnections;
    bool czekajNaAdresy=false;
    bool czekajNaTwojAdres=false;
    QString twojAdres=nullptr;
};

#endif // UDPSOCKET_H
