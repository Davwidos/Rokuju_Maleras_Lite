#ifndef FORMULARZ_H
#define FORMULARZ_H
#include<QDialog>
#include<QComboBox>

class Formularz:  public QDialog
{
    Q_OBJECT
public:
    Formularz(QWidget *parent=0);
    QComboBox *v;
public slots:
    void wybrane(int);
signals:
    void przek(QString);

};

#endif // FORMULARZ_H
