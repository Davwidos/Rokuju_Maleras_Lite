#include "udpsocket.h"
#include<QNetworkInterface>
#include<QHostAddress>
#include<QDebug>
UdpSocket::UdpSocket(QGraphicsView *viev,QObject *parent):QObject(parent)
{
    myudpsocket=new QUdpSocket(this);
    //myudpsocket->bind(QHostAddress("25.150.240.229"),1234);
    myudpsocket->bind(QHostAddress::Any,1234);
    connect(myudpsocket,SIGNAL(readyRead()),this,SLOT(readyRead()));



}

QList<QString> UdpSocket::getConnections()
{
    QList<QString> list;
    for(QHostAddress address:allConnections) list.push_front(address.toString());
    return list;
}

void UdpSocket::addConnection(QString address)
{
    send("connect",QHostAddress(address));
}

void UdpSocket::dajMojAddres()
{
    if(twojAdres==nullptr)
    {
        if(allConnections.empty()) return;
        send("giveme",allConnections.first());
        czekajNaTwojAdres=true;
        return;
    }
    emit start(twojAdres);
}

void UdpSocket::readyRead()
{
    QByteArray buffer;
    QHostAddress sender;
    buffer.resize(myudpsocket->pendingDatagramSize());
    unsigned short int port;
    myudpsocket->readDatagram(buffer.data(),buffer.size(),&sender,&port);
    if(buffer=="giveme") send(sender.toString(),sender);
    if(czekajNaAdresy)
    {
        if(buffer=="koniec")
        {
            czekajNaAdresy=false;
            //qDebug()<<allConnections.size();
            emit connected();
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
    if(czekajNaTwojAdres && buffer[0]==':')
    {
        twojAdres=buffer.data();
        czekajNaTwojAdres=false;
        emit start(twojAdres);
    }
    bool t=false;
    bool w=false;
    if(buffer=="connect") w=true;
    if(buffer=="connected")
    {
        t=true;
        czekajNaAdresy=true;
    }
    if(t || w) for(QHostAddress address:allConnections)
            if(address==sender)
            {
                t=false;
                break;
            }
    if(t || w)
    {
        allConnections.push_front(sender);
    }
    if(w)
    {
        send("connected");
        for(QHostAddress address:allConnections)
            if(sender!=address) send(address.toString());
        send("koniec");
    }
    if(t || w) return;
    if(buffer=="disconnect") allConnections.removeOne(sender);
    emit karta(buffer.data(),sender.toString());
}

void UdpSocket::send(QString messege, QHostAddress address)
{
    QByteArray data;
    data.append(messege);
    if(address!=QHostAddress::Null) myudpsocket->writeDatagram(data,address,1234);
    for(QHostAddress address:allConnections) myudpsocket->writeDatagram(data,address,1234);

}

