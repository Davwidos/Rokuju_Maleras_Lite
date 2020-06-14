#include "udpsocket.h"
#include<QNetworkInterface>
#include<QHostAddress>
#include<QDebug>
UdpSocket::UdpSocket(QGraphicsView *viev,QObject *parent):QObject(parent)
{
	/// stworzenie soceta
    myudpsocket=new QUdpSocket(this);
    //myudpsocket->bind(QHostAddress("25.150.240.229"),1234);
    myudpsocket->bind(QHostAddress::Any,1234);
    connect(myudpsocket,SIGNAL(readyRead()),this,SLOT(readyRead()));
}

QList<QString> UdpSocket::getConnections() 
{
	/// zwraca polaczone adresy
    QList<QString> list;
    for(QHostAddress address:allConnections) list.push_front(address.toString());
    return list;
}

void UdpSocket::addConnection(QString address) 
{
	/// dodanie polaczenia
    QByteArray data;
    data.append("connect");
    myudpsocket->writeDatagram(data,QHostAddress(address),1234);
}

void UdpSocket::readyRead() 
{
	///odczytanie danych wyslanych przez innego gracza
    QByteArray buffer;
    QHostAddress sender;
    buffer.resize(myudpsocket->pendingDatagramSize());
    unsigned short int port;
    myudpsocket->readDatagram(buffer.data(),buffer.size(),&sender,&port);
    qDebug()<<buffer.data();
    if(czekajNaAdresy)
    {
        if(buffer=="koniec")
        {
            czekajNaAdresy=false;
            //qDebug()<<allConnections.size();
            emit connected();
            send(sender.toString(),sender);
            return;
        }
        QHostAddress newAddress(buffer.data());
        bool t = true;
        for(QHostAddress address:allConnections)
            if(address==newAddress)
            {
                t=false;
                break;
            }
        if(t) allConnections.push_front(newAddress);

    }
    if(czekajNaTwojAdres)
    {
        twojAdres=buffer.data();
        czekajNaTwojAdres=false;
         //qDebug()<<twojAdres;
    }
    bool t=false;
    if(buffer=="connect")
    {
        t=true;
        send("connected");
        for(QHostAddress address:allConnections)
            if(sender!=address) send(address.toString());
        send("koniec");
        czekajNaTwojAdres=true;
    }
    if(buffer=="connected")
    {
        t=true;
        czekajNaAdresy=true;
    }
    if(t) for(QHostAddress address:allConnections)
            if(address==sender)
            {
                t=false;
                break;
            }
    if(t) allConnections.push_front(sender);
    if(buffer=="disconnect") allConnections.removeOne(sender);
    emit karta(buffer.data(),sender.toString());
}

void UdpSocket::send(QString messege, QHostAddress address) 
{
	/// wyslanie danych
    QByteArray data;
    data.append(messege);
    if(address!=QHostAddress::Null) while(myudpsocket->writeDatagram(data,address,1234)!=data.size());
    for(QHostAddress address:allConnections) while(myudpsocket->writeDatagram(data,address,1234)!=data.size());

}

