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
    konecDialog = new KonecHry;
    scena = new QGraphicsScene(this);
    ui->platnoGV->setScene(scena);
    casomira = new QTimer(this);
    stopky = new QElapsedTimer;
    ctverec = new QGraphicsRectItem(0,50,100,100);
    ctverec->setPen(QColor("white"));
    text = new QGraphicsTextItem;
    sekundy = 0;
    minuty = 0;
    connect(casomira,SIGNAL(timeout()),this,SLOT(stopuj()));
    connect(konecDialog,SIGNAL(zavriHru()),this,SLOT(uzavriSe()));
    text->setPos(0,150);

    barvy.append(QColor("red"));
    barvy.append(QColor("blue"));
    barvy.append(QColor("green"));
    barvy.append(QColor("yellow"));
    barvy.append(QColor("magenta"));

    nazvy[0] = "Červená";
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

void Hra::stopuj(){
    sekundy = ((stopky->elapsed()/1000) - (minuty*60));
    if(sekundy>60){
        minuty++;
        if(minuty<10){
            ui->minutyText->setText("0"+QString::number(minuty));
        }
        else{
            ui->minutyText->setText(QString::number(minuty));
        }
    }
    if(sekundy<10){
        ui->sekundyText->setText("0"+QString::number(sekundy));
    }
    else{
        ui->sekundyText->setText(QString::number(sekundy));
    }
}

void Hra::nahodneVymaluj(){
    aktualniBarva = rand()%5;
    aktualniNazev = rand()%5;
    text->setPlainText(nazvy[aktualniNazev]);
    ctverec->setBrush(barvy.at(aktualniBarva));
}

void Hra::on_spravneBtn_clicked()
{
    if(!casomira->isActive()){
        ui->spatneBtn->show();
        ui->spravneBtn->setText("Správně");
        ctverec->setPen(QColor("black"));
        nahodneVymaluj();
        casomira->start();
        stopky->start();
    }
    else{
        rozhodni(true);
    }
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
    //nahodneVymaluj();
    ui->spatneBtn->hide();
    ui->spravneBtn->setText("Spustit hru");
    ctverec->setBrush(QColor("white"));
    ctverec->setPen(QColor("white"));
    text->setPlainText(" ");
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
    casomira->stop();
    konecDialog->sekundy = minuty*60 + sekundy;
    konecDialog->skore = spravne;
    konecDialog->exec();

    ui->sekundyText->setText("00");
    ui->minutyText->setText("00");
    novaHra();
}

void Hra::closeEvent(QCloseEvent *event){
    emit closed();
    casomira->stop();
    ui->sekundyText->setText("00");
    ui->minutyText->setText("00");
    event->accept();
}

void Hra::uzavriSe(){
    this->close();
}
