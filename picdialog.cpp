#include "picdialog.h"
#include "ui_picdialog.h"

PicDialog::PicDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PicDialog)
{
    ui->setupUi(this);
    ui->label->setScaledContents(true);
    ui->label->setPixmap(QPixmap(":/pics/shiyit.png"));
    ui->label->show();

}

PicDialog::~PicDialog()
{
    delete ui;
}
