#ifndef SPONSORS_H
#define SPONSORS_H


#include <QDialog>

namespace Ui {
class sponsors;
}

class sponsors : public QDialog
{
    Q_OBJECT

public:
    explicit sponsors(QWidget *parent = nullptr);
    ~sponsors();

private:
    Ui::sponsors *ui;
};

#endif // SPONSORS_H
