#ifndef SKORE_H
#define SKORE_H

#include <QDialog>

namespace Ui {
class Skore;
}

class Skore : public QDialog
{
    Q_OBJECT

public:
    explicit Skore(QWidget *parent = 0);
    ~Skore();

protected:
    void closeEvent(QCloseEvent *event);
signals:
    void closed();

private:
    Ui::Skore *ui;
};

#endif // SKORE_H
