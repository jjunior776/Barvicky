#include "menu.h"
#include "ui_menu.h"
#include <QFile>
#include <QSqlDatabase>
#include <QSqlQuery>

Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    if(QFile::exists("db.sqlite")){
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("db.sqlite");
        db.open();
    }
    else{
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("db.sqlite");
        db.open();
        QSqlQuery vytvorTabulku;
        vytvorTabulku.exec("CREATE TABLE Skore ("
                           "id INTEGER PRIMARY KEY NOT NULL, prezdivka TEXT, skore INTEGER, "
                           "cas TEXT, rychlost TEXT);");
    }
    this->setWindowTitle("Barvičky - Menu");

    oknoHry = new Hra;
    connect(oknoHry,SIGNAL(closed()),this,SLOT(show()));
    connect(ui->klasikBtn,SIGNAL(clicked(bool)),this,SLOT(hide()));
    connect(ui->nekonecBtn,SIGNAL(clicked(bool)),this,SLOT(hide()));

    oknoSkore = new Skore;
    connect(oknoSkore,SIGNAL(closed()),this,SLOT(show()));
    connect(ui->statistikyBtn,SIGNAL(clicked(bool)),oknoSkore,SLOT(show()));
    connect(ui->statistikyBtn,SIGNAL(clicked(bool)),this,SLOT(hide()));

}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_konecBtn_clicked()
{
    this->close();
}

void Menu::on_klasikBtn_clicked()
{
    oknoHry->spustHru(0);
}

void Menu::on_nekonecBtn_clicked()
{
    oknoHry->spustHru(1);
}
