#ifndef MISSION_JOURNALISTE_H
#define MISSION_JOURNALISTE_H

#include <QDialog>

namespace Ui {
class mission_journaliste;
}

class mission_journaliste : public QDialog
{
    Q_OBJECT

public:
    explicit mission_journaliste(QWidget *parent = nullptr);
    ~mission_journaliste();

private slots:
    void on_pushButton_clicked();

private:
    Ui::mission_journaliste *ui;
};

#endif // MISSION_JOURNALISTE_H
