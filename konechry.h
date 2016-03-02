#ifndef KONECHRY_H
#define KONECHRY_H

#include <QDialog>

namespace Ui {
class KonecHry;
}

class KonecHry : public QDialog
{
    Q_OBJECT

public:
    explicit KonecHry(QWidget *parent = 0);
    void zobrazKonec(int skore, QString duvod);
    ~KonecHry();

private:
    Ui::KonecHry *ui;
};

#endif // KONECHRY_H
