#ifndef STATISTIQUES_H
#define STATISTIQUES_H
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QPainter>
#include <QSqlQuery>
#include <QDialog>
using namespace std;

namespace Ui {
class statistiques;
}

class statistiques : public QDialog
{
    Q_OBJECT

public:
    explicit statistiques(QWidget *parent = nullptr);
    int Statistique_partie2() ;
        int Statistique_partie3() ;
         int Statistique_partie4() ;
         int Statistique_partie5() ;
         int Statistique_partie6() ;
        void paintEvent(QPaintEvent *) ;

    ~statistiques();

private:
    Ui::statistiques *ui;
private slots :
};

#endif // STATISTIQUES_H
