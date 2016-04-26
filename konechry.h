#ifndef KONECHRY_H
#define KONECHRY_H

#include <QDialog>
#include <QShowEvent>
#include <QSqlQueryModel>

namespace Ui {
class KonecHry;
}

class KonecHry : public QDialog
{
    Q_OBJECT

public:
    explicit KonecHry(QWidget *parent = 0);
    //int zobrazKonec(int skore, int sekundy);
    int skore;
    int sekundy;
    ~KonecHry();
protected:
    void showEvent(QShowEvent *event);
signals:
    void showed();
    void zavriHru();
private slots:
    void inicializujSe();
    void on_zapsatBtn_clicked();

    void on_menuBtn_clicked();

private:
    Ui::KonecHry *ui;
    double rychlost;
    QSqlQueryModel *model;
};

#endif // KONECHRY_H
