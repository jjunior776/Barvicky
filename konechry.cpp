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
    ui->szsText->setText(QString::number(rychlost));
}

void KonecHry::showEvent(QShowEvent *event){
    emit showed();
    event->accept();
}

void KonecHry::on_zapsatBtn_clicked()
{
    QString jmeno = ui->jmenoText->text();
    model->setQuery("INSERT INTO Skore(prezdivka, skore, cas, rychlost) "
                    "VALUES('"+jmeno+"',"
                    " '"+QString::number(skore)+"',"
                    " '"+QString::number(sekundy)+"',"
                    " '"+QString::number(rychlost)+"');");
    ui->jmenoText->clear();
// INSERT INTO Skore(prezdivka, skore, cas, rychlost) VALUES('Karel','5','30','5/30')

}

void KonecHry::on_menuBtn_clicked()
{
    this->close();
    emit zavriHru();
}




