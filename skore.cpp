#include "skore.h"
#include "ui_skore.h"

Skore::Skore(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Skore)
{
    ui->setupUi(this);
    model = new QSqlQueryModel;
    ui->skoreView->horizontalHeader()->setStretchLastSection(true);
    connect(this,SIGNAL(showed()),this,SLOT(inicializujSe()));
    ui->skoreView->setModel(model);
    inicializujSe();
}

Skore::~Skore()
{
    delete ui;
}

void Skore::closeEvent(QCloseEvent *event){
    emit closed();
    event->accept();
}

void Skore::showEvent(QShowEvent *event){
    emit showed();
}

void Skore::inicializujSe(){
    refresh(ui->filtrCb->currentIndex(),false);
    model->setHeaderData(0,Qt::Horizontal, "Přezdívka");
    model->setHeaderData(1,Qt::Horizontal, "Skóre");
    model->setHeaderData(2,Qt::Horizontal, "Čas");
    model->setHeaderData(3,Qt::Horizontal, "Rychlost");
}

/*void Skore::on_debugClean_clicked()
{
    model->setQuery("DELETE FROM Skore");
}
*/

void Skore::on_filtrCb_activated(int index)
{
    refresh(index,ui->serazeniCb->currentIndex());
}

void Skore::on_serazeniCb_activated(int index)
{
    refresh(ui->filtrCb->currentIndex(),index);
}

void Skore::refresh(int filtr, bool razeni){
    QString filtrText;
    switch (filtr) {
    case 0:{
        filtrText = "skore";
        break;
    }
    case 1:{
        filtrText = "rychlost";
        break;
    }
    case 2:{
        filtrText = "cas";
        break;
    }
    case 3:{
        filtrText = "prezdivka";
        break;
    }
    default:
        break;
    }
    if(razeni==true){
        filtrText += " ASC";
    }
    else{
        filtrText += " DESC";
    }
    model->setQuery("SELECT prezdivka,skore,cas,rychlost FROM Skore ORDER BY "+filtrText);
}

