#ifndef SPRAVABAREV_H
#define SPRAVABAREV_H

#include <QWidget>

namespace Ui {
class SpravaBarev;
}

class SpravaBarev : public QWidget
{
    Q_OBJECT

public:
    explicit SpravaBarev(QWidget *parent = 0);
    ~SpravaBarev();

private:
    Ui::SpravaBarev *ui;
};

#endif // SPRAVABAREV_H
