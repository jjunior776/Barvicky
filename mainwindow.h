#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void nahodneVymaluj();

    void rozhodni(bool odpoved);

    void on_spravneBtn_clicked();

    void on_spatneBtn_clicked();

private:
    QList<QColor> barvy;
    QString nazvy[5];
    int aktualniBarva;
    int aktualniNazev;
    int spravne;
    int spatne;
    int celkem;
    Ui::MainWindow *ui;
    QGraphicsScene *scena;
    QGraphicsRectItem *ctverec;
    QGraphicsTextItem *text;

};

#endif // MAINWINDOW_H
