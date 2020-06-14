#include "dodajpoloczenie.h"
#include<QLabel>
#include<QFormLayout>


DodajPoloczenie::DodajPoloczenie(QWidget *parent) : QGroupBox(parent) //Dodaje poloczenie za pomoca hamachi "te okienko co wpisuje sie adres"
{
	///Dodaje poloczenie za pomoca hamachi "te okienko co wpisuje sie adres"
    setTitle("Dodaj nowe poloczenie");
    QLabel *label=new QLabel("Addres");
    lineEdit=new QLineEdit(this);
    QFormLayout *layout=new QFormLayout(this);
    layout->addRow(label,lineEdit);
    button=new QPushButton("Połącz",this);
    layout->addRow(button);
    connect(button,SIGNAL(pressed()),this,SLOT(zatwierdzono()));
}

void DodajPoloczenie::zatwierdzono() 
{
	///wyslanie adresu IP
    emit wyslij(lineEdit->text());
}
