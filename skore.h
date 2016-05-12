#ifndef SKORE_H
#define SKORE_H

#include <QDialog>
#include <QCloseEvent>
#include <QShowEvent>
#include <QSqlQueryModel>

namespace Ui {
class Skore;
}

class Skore : public QDialog
{
    Q_OBJECT

public:
    explicit Skore(QWidget *parent = 0);
    ~Skore();
private slots:
    void inicializujSe();
    //void on_debugClean_clicked();
    void on_filtrCb_activated(int index);
    void refresh(int filtr, bool razeni);
    void on_serazeniCb_activated(int index);

protected:
    void closeEvent(QCloseEvent *event);
    void showEvent(QShowEvent *event);
signals:
    void closed();
    void showed();
private:
    Ui::Skore *ui;
    QSqlQueryModel *model;
};

#endif // SKORE_H
