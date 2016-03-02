#include "hra.h"
#include "ui_hra.h"
#include "QPainter"
#include "time.h"
#include <QMessageBox>

Hra::Hra(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Hra)
{
    ui->setupUi(this);
    srand(time(NULL));

    scena = new QGraphicsScene(this);
    ui->platnoGV->setScene(scena);

    ctverec = new QGraphicsRectItem(0,50,100,100);
    text = new QGraphicsTextItem("Barvička");

    text->setPos(0,150);

    barvy.append(QColor("red"));
    barvy.append(QColor("blue"));
    barvy.append(QColor("green"));
    barvy.append(QColor("yellow"));
    barvy.append(QColor("magenta"));

    nazvy[0] = "Červná";
    nazvy[1] = "Modrá";
    nazvy[2] = "Zelená";
    nazvy[3] = "Žlutá";
    nazvy[4] = "Fialová";

    scena->addItem(ctverec);
    scena->addItem(text);

    novaHra();
}

Hra::~Hra()
{
    delete ui;
}

void Hra::nahodneVymaluj(){
    aktualniBarva = rand()%5;
    aktualniNazev = rand()%5;
    text->setPlainText(nazvy[aktualniNazev]);
    ctverec->setBrush(barvy.at(aktualniBarva));
}

void Hra::on_spravneBtn_clicked()
{
    rozhodni(true);
}

void Hra::on_spatneBtn_clicked()
{
    rozhodni(false);
}

void Hra::rozhodni(bool odpoved){
    if((odpoved==true)&&(aktualniBarva==aktualniNazev))
        spravne++;
    else if ((odpoved==false)&&(aktualniBarva!=aktualniNazev))
        spravne++;
    else
        spatne++;
    celkem++;
    if((herniMod==0)&&(spatne>0)){
        prohra();
    }
    else {
        ui->spravneText->setText("Správně: "+QString::number(spravne));
        ui->spatneText->setText("Špatně: "+QString::number(spatne));
        ui->celkemText->setText("Celkem: "+QString::number(celkem));
        nahodneVymaluj();
    }
}

void Hra::spustHru(int mod){
    herniMod = mod;
    novaHra();
    this->show();
}

void Hra::novaHra(){
    nahodneVymaluj();
    spravne = spatne = celkem = 0;
    ui->spravneText->setText("Správně: "+QString::number(spravne));
    ui->spatneText->setText("Špatně: "+QString::number(spatne));
    ui->celkemText->setText("Celkem: "+QString::number(celkem));
    if(herniMod==0){                                                //<-- klasik
        this->setWindowTitle("Barvičky - Klasik");
        ui->celkemText->hide();
        ui->spatneText->hide();
    }
    else if(herniMod==1){                                           //<-- nekonečny
        this->setWindowTitle("Barvičky - Nekonečný");
        ui->celkemText->show();
        ui->spatneText->show();
    }
}

void Hra::prohra(){
    QMessageBox konecHry;
    konecHry.setText("Prohrál jsi, zkus to znovu");
    konecHry.exec();
    novaHra();
}

void Hra::closeEvent(QCloseEvent *event){
    emit closed();
    event->accept();
}
