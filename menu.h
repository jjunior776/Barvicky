#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include "hra.h"
#include "skore.h"

namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = 0);
    ~Menu();

private slots:
    void on_konecBtn_clicked();

    void on_klasikBtn_clicked();

    void on_nekonecBtn_clicked();

private:
    Ui::Menu *ui;
    Hra *oknoHry;
    Skore *oknoSkore;
};

#endif // MENU_H
