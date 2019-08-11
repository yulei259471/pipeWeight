#ifndef CPIPEWEIGHT_H
#define CPIPEWEIGHT_H

#include <QWidget>
#include<QTableWidget>
#include<QStringList>
#include<QMenu>
#include<QAction>
#include<QPoint>
#include<QtGui>
#include<QDebug>
#include<QTableWidgetItem>
#include<QPixmap>
#include<QLabel>
#include<QFile>
#include<QTextStream>
#include <QTextCodec>
#include<QDateTime>
#include"picdialog.h"

const double PI=3.1415926;
namespace Ui {
class CPipeWeight;
}

class CPipeWeight : public QWidget
{
    Q_OBJECT

public:
    explicit CPipeWeight(QWidget *parent = nullptr);
    ~CPipeWeight();
    void initForm();
    //void createMenu();
    //计算主杆重量
    void  caculationMainpipe();
    //计算横担重量
    void caculatinArm();
    //计算法兰重量
    void  caculationFlange();
    //计算加劲板重量
    void caculationFlate();

private slots:
    //弹出右键菜单
   /* void pop_menu(QPoint pos);
    void contextMenuEvent(QContextMenuEvent *event);
    //插入行
    void insertmainpipeRow();
    void insertarmRow();
    void insertflangeRow();
    void insertflateRow();
    //删除行
    void deletemainpipeRow();
    void deletearmRow();
    void deleteflangeRow();
    void deleteflateRow();*/
    //主杆增加一行
    void mainpipeadd_clicked();
    //主杆减少一行
    void mainpipesub_clicked();

    void armadd_clicked();

    void armsub_clicked();

    void flangeadd_clicked();

    void flangesub_clicked();

    void flatadd_clicked();

    void flatsub_clicked();
    //显示加劲板示意图
    void on_pushButton_pic_clicked();
    //计算
    void on_pushButton_caculation_clicked();
    //获取重度
    void on_lineEdit_Gama_editingFinished();
    //输出计算书
    void on_pushButton_output_clicked();

private:
    Ui::CPipeWeight *ui;
    //主杆多边形数量
    double pipeShape;
    //主杆重量计算规则 0表示 按外皮 1表示 按芯线 2表示 按内皮
    int pipeMethod;
    //主杆尺寸规则 0表示 边对边 1表示 楞对楞
    int pipeSize;

    //横担多边形数量
    double armShape;
    //横担重量计算规则 0表示 按外皮 1表示 按芯线 2表示 按内皮
    int armMethod;
    //横担尺寸规则 0表示 边对边 1表示 楞对楞
    int armSize;

    //法兰计算规则 0表示 方板 1表示 方减圆 2表示 圆减圆 3表示 圆减多边形 4表示圆盘
     int flangemethod;
     //法兰主杆截面 0表示圆形 1表示 正四边形 2 表示 正六边形 3表示 正八边形 4表示 正十二边形 5表示 正十六边形
     double flangeShape;

     //加劲板计算规则
     int flatemethod;
     //加劲板形状 切角 倒角 双切角 双倒角
     int flateShape;


     //表头   主杆 横担 法兰 劲板
     QStringList strMainPipe,strArm,strFlange,strPlate;

     //材料重度
     double gama;
     //通过item 操作数据
     QTableWidgetItem *itemMainPipe,*itemArm,*itemFlange,*itemPlate;
     //QTableWidgetItem *rightclickitem;
     //右键菜单
      //QMenu *popMenu;
      //菜单action
      //QAction *insert_action,*delete_action;
     //显示加劲板示意图
      PicDialog *picdiag;
      //计算书输出
      //QFile *outFile;
};

#endif // CPIPEWEIGHT_H
