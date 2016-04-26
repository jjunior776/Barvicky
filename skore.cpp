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
    model->setQuery("SELECT * FROM Skore");
}
