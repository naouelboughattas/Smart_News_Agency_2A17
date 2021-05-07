#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"equipement.h"
#include"fournisseur.h"


#include <QMainWindow>
#include<QMediaPlayer>
#include<QTimer>






namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString getCurrentId();
protected:
    void changeEvent(QEvent *e);


private slots:
    void on_p_ajouter_2_clicked();

    void on_p_ajouterE_2_clicked();

    void on_afficherE_2_clicked();

    void on_afficherF_2_clicked();

    void on_ModifierE_2_clicked();

    void on_modifierF_2_clicked();

    void on_supprimerF_2_clicked();

    void on_supprimerE_2_clicked();
    void digit_pressed();

    void on_pushButton_dot_released();
    void unary_operation_pressed();
    void on_pushButton_clear_released();
    void on_pushButton_equals_released();
    void binary_operation_pressed();


void  showTime();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_p_rech_id_2_clicked();

    void on_p_rech_libelle_2_clicked();

    void on_p_rech_marque_2_clicked();

    void on_pdf_2_clicked();

    void on_connexion_clicked();

    void on_radioButton_4_clicked();

    void on_deconnexion_clicked();

    void on_pushButton_clicked();

    void on_makeShot_clicked();

private:

    Ui::MainWindow *ui;
    equipement *e;
    Fournisseur *f;
    QMediaPlayer *clic;
QTimer *timer;


};

#endif // MAINWINDOW_H
