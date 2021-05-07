#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "journaliste.h"
#include "connection.h"
#include"missions.h"
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

    void on_tab_journaliste_activated(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_modifierp_clicked();

    void on_supprimer_clicked();

    void on_recherchep_clicked();

    void on_tri_p_clicked();

    void on_pdf_p_clicked();

    void on_afficherp_clicked();

    void on_apply_clicked();

    void on_envoyer_clicked();


private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H

