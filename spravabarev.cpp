#include "spravabarev.h"
#include "ui_spravabarev.h"

SpravaBarev::SpravaBarev(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SpravaBarev)
{
    ui->setupUi(this);
}

SpravaBarev::~SpravaBarev()
{
    delete ui;
}
