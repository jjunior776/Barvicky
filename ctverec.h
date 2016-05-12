#ifndef CTVEREC_H
#define CTVEREC_H

#include <QObject>
#include <QPainter>
#include <QGraphicsRectItem>

class Ctverec : public QGraphicsRectItem
{
public:
    Ctverec(int x, int y, int sirka, int vyska, QColor zakladniObrys, QColor zakladniBarva);
    QList<QColor> barvy;
    int aktualniBarva;
    int predchoziBarva;
public slots:
    void pridejBarvu(QColor barva);
    void nastavBarvu(int index);
    void nastavBarvu(QColor barva);
};

#endif // CTVEREC_H
