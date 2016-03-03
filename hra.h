#ifndef HRA_H
#define HRA_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QCloseEvent>
#include <QTimer>
#include <QElapsedTimer>

namespace Ui {
class Hra;
}

class Hra : public QMainWindow
{
    Q_OBJECT

public:
    explicit Hra(QWidget *parent = 0);
    void spustHru(int mod);

    ~Hra();

private slots:
    void nahodneVymaluj();

    void novaHra();

    void prohra();

    void rozhodni(bool odpoved);

    void on_spravneBtn_clicked();

    void on_spatneBtn_clicked();

    void stopuj();
protected:
    void closeEvent(QCloseEvent *event);
signals:
    void closed();
private:
    QList<QColor> barvy;
    QString nazvy[5];
    qint64 sekundy;
    qint64 minuty;
    QTimer *casomira;
    QElapsedTimer *stopky;
    int herniMod;
    int aktualniBarva;
    int aktualniNazev;
    int spravne;
    int spatne;
    int celkem;
    Ui::Hra *ui;
    QGraphicsScene *scena;
    QGraphicsRectItem *ctverec;
    QGraphicsTextItem *text;

};

#endif // HRA_H
