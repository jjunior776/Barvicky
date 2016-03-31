#include "skore.h"
#include "ui_skore.h"

Skore::Skore(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Skore)
{
    ui->setupUi(this);
}

Skore::~Skore()
{
    delete ui;
}
