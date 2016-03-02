#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    oknoHry = new Hra;
    connect(oknoHry,SIGNAL(closed()),this,SLOT(show()));
    connect(ui->klasikBtn,SIGNAL(clicked(bool)),this,SLOT(hide()));
    connect(ui->nekonecBtn,SIGNAL(clicked(bool)),this,SLOT(hide()));
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
