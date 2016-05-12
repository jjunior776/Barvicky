#include "ctverec.h"

Ctverec::Ctverec(int x, int y, int sirka, int vyska, QColor zakladniObrys, QColor zakladniBarva)
{
    this->setRect(x,y,sirka,vyska);
    this->setPen(zakladniObrys);
    this->setBrush(zakladniBarva);
}

void Ctverec::pridejBarvu(QColor barva)
{
    barvy.append(barva);
}

void Ctverec::nastavBarvu(int index)
{
    this->setBrush(barvy.at(index));
}

void Ctverec::nastavBarvu(QColor barva)
{
    this->setBrush(barva);
}

