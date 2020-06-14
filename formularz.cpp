#include "formularz.h"
#include<QLabel>
#include<QFormLayout>
#include <QComboBox>
Formularz::Formularz(QWidget *parent):QDialog(parent)
{
    QLabel *label=new QLabel("Zgadnij, jaka karte ma przciwnik");
    QFormLayout *layout=new QFormLayout(this);
    v=new QComboBox(this);
    v->addItem("Altanka");
    v->addItem("Mysz");
    v->addItem("Kaczor");
    v->addItem("Skarb");
    v->addItem("Smok");
    v->addItem("Troll");
    v->addItem("Pierscien");
     layout->addRow(label);
     connect(v,SIGNAL(textActivated(QString*)),this,SLOT(wybrane(QString*)));
     layout->addRow(v);

}

void Formularz::wybrane(QString *wyb)
{
    emit przek(*wyb);
    done(1);

}
