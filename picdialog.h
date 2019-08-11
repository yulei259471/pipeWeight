#ifndef PICDIALOG_H
#define PICDIALOG_H
//#include<QGraphicsView>
#include <QDialog>
#include<QLabel>

namespace Ui {
class PicDialog;
}

class PicDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PicDialog(QWidget *parent = nullptr);
    ~PicDialog();
    QLabel *piclable;
    Ui::PicDialog *ui;

private slots:


private:

    //QGraphicsView *gv;

};

#endif // PICDIALOG_H
