#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPainter"
#include "time.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(NULL));

    spravne = 0;
    spatne = 0;
    celkem = 0;
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

    nahodneVymaluj();

    scena->addItem(ctverec);
    scena->addItem(text);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::nahodneVymaluj(){
    aktualniBarva = rand()%5;
    aktualniNazev = rand()%5;
    text->setPlainText(nazvy[aktualniNazev]);
    ctverec->setBrush(barvy.at(aktualniBarva));
}

void MainWindow::on_spravneBtn_clicked()
{
    rozhodni(true);
}

void MainWindow::on_spatneBtn_clicked()
{
    rozhodni(false);
}

void MainWindow::rozhodni(bool odpoved){
    if((odpoved==true)&&(aktualniBarva==aktualniNazev))
        spravne++;
    else if ((odpoved==false)&&(aktualniBarva!=aktualniNazev))
        spravne++;
    else
        spatne++;
    celkem++;
    ui->spravneText->setText("Správně: "+QString::number(spravne));
    ui->spatneText->setText("Špatně: "+QString::number(spatne));
    ui->celkemText->setText("Celkem: "+QString::number(celkem));
    nahodneVymaluj();
}
