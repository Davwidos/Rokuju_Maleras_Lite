#ifndef STRONA_INS_H
#define STRONA_INS_H
#include<QObject>
#include<QGraphicsPixmapItem>
#include<QString>
#include<QGraphicsSceneMouseEvent>
class Strona_ins:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Strona_ins(QString path, QGraphicsItem *parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
signals:
    void clicked(bool m);
};

#endif // INSTRUKCJA_H
