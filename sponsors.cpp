#include "sponsors.h"
#include "ui_sponsors.h"

sponsors::sponsors(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sponsors)
{
    ui->setupUi(this);
}

sponsors::~sponsors()
{
    delete ui;
}
