#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "article.h"
#include "connection.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:


    void on_pb_ajouter_clicked();

    void on_modifier_clicked();

    void on_supprimer_clicked();

    void on_pushButton_clicked();

    void on_gestion_article_clicked();

    void on_return_2_clicked();

    void on_trier_clicked();

    void on_recherche_clicked();

    void on_pdf_clicked();

private:
    Ui::MainWindow *ui;
    Article *g ;
    Article *r ;
    Article *t ;
    Article *j ;

};
#endif // MAINWINDOW_H
