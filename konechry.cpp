#include "konechry.h"
#include "ui_konechry.h"

KonecHry::KonecHry(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KonecHry)
{
    ui->setupUi(this);
}

KonecHry::~KonecHry()
{
    delete ui;
}
