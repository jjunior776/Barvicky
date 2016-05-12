#include "konechry.h"
#include "ui_konechry.h"

KonecHry::KonecHry(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KonecHry)
{
    ui->setupUi(this);
    sekundy = 0;
    skore = 0;
    rychlost = 0;
    connect(this,SIGNAL(showed()),this,SLOT(inicializujSe()));
    model = new QSqlQueryModel;

}

KonecHry::~KonecHry()
{
    delete ui;
}

void KonecHry::inicializujSe(){
    ui->casText->setText(QString::number(sekundy) + "sekund");
    ui->skoreText->setText(QString::number(skore));
    rychlost = (double)skore/sekundy;  
    if((QString::number(rychlost)=="nan")||(QString::number(rychlost)=="inf")||(rychlost<0))
        rychlost = 0;
    ui->szsText->setText(QString::number(rychlost));
    zapsan = false;
    ui->jmenoText->setEnabled(true);
    ui->zapsatBtn->setEnabled(true);
    ui->jmenoText->setText("");
}

void KonecHry::showEvent(QShowEvent *event){
    emit showed();
    event->accept();
}

void KonecHry::on_zapsatBtn_clicked()
{
    if(zapsan==false){
        QString jmeno = ui->jmenoText->text();
        model->setQuery("INSERT INTO Skore(prezdivka, skore, cas, rychlost) "
                    "VALUES('"+jmeno+"','"+QString::number(skore)+"','"+QString::number(sekundy)+"','"+QString::number(rychlost)+"');");
        ui->jmenoText->setEnabled(false);
        ui->jmenoText->setText("Hráč "+ui->jmenoText->text()+"byl zapsán");
        ui->zapsatBtn->setEnabled(false);
        zapsan = true;
    }
}

void KonecHry::on_menuBtn_clicked()
{
    this->close();
    emit zavriHru();
}





void KonecHry::on_restartBtn_clicked()
{
    this->close();
}
