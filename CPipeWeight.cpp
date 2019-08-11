#include "CPipeWeight.h"
#include "ui_CPipeWeight.h"

CPipeWeight::CPipeWeight(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CPipeWeight)
{
    ui->setupUi(this);
    //���ó�ʼ���Ի���
    initForm();
    this->setWindowTitle(QStringLiteral("�ֹܸ˸����������������   code by  �ɶ����� QQ:550551769"));
}

CPipeWeight::~CPipeWeight()
{
    delete ui;
}
void CPipeWeight::initForm()
{

    //��ʼ������Ի���,��Ҫ���������������������б���
    ui->tableWidget_mainpipe->setColumnCount(6);
    strMainPipe<<QStringLiteral("�κ�")<<QStringLiteral("�Ծ�")<<QStringLiteral("����")<<QStringLiteral("�ں�")<<QStringLiteral("�γ�")<<QStringLiteral("����");
    ui->tableWidget_mainpipe->setHorizontalHeaderLabels(strMainPipe);
    ui->tableWidget_mainpipe->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_mainpipe->horizontalHeader()->setStyleSheet("QHeaderView::section{background:#e1e1e1;}");
    ui->tableWidget_mainpipe->verticalHeader()->setStyleSheet("QHeaderView::section{background:#e1e1e1;}");
    ui->tableWidget_mainpipe->setStyleSheet("QTableCornerButton::section{background:#e1e1e1;}");
    ui->tableWidget_mainpipe->setAlternatingRowColors(true);
    ui->tableWidget_mainpipe->setContextMenuPolicy(Qt::CustomContextMenu);
    QObject::connect(ui->pushButton_mainpipeadd,SIGNAL(clicked()),this,SLOT(mainpipeadd_clicked()));
    QObject::connect(ui->pushButton_mainpipesub,SIGNAL(clicked()),this,SLOT(mainpipesub_clicked()));

    ui->tableWidget_arm->setColumnCount(7);
    strArm<<QStringLiteral("�κ�")<<QStringLiteral("�Ծ�")<<QStringLiteral("����")<<QStringLiteral("�ں�")<<QStringLiteral("�γ�")<<QStringLiteral("����")<<QStringLiteral("����");
    ui->tableWidget_arm->setHorizontalHeaderLabels(strArm);
    ui->tableWidget_arm->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_arm->horizontalHeader()->setStyleSheet("QHeaderView::section{background:#e1e1e1;}");
    ui->tableWidget_arm->verticalHeader()->setStyleSheet("QHeaderView::section{background:#e1e1e1;}");
    ui->tableWidget_arm->setStyleSheet("QTableCornerButton::section{background:#e1e1e1;}");
    ui->tableWidget_arm->setAlternatingRowColors(true);
    ui->tableWidget_arm->setContextMenuPolicy(Qt::CustomContextMenu);
    QObject::connect(ui->pushButton_armadd,SIGNAL(clicked()),this,SLOT(armadd_clicked()));
    QObject::connect(ui->pushButton_armsub,SIGNAL(clicked()),this,SLOT(armsub_clicked()));

    ui->tableWidget_flange->setColumnCount(6);
    strFlange<<QStringLiteral("����")<<QStringLiteral("�⾶")<<QStringLiteral("�ھ�")<<QStringLiteral("���")<<QStringLiteral("����")<<QStringLiteral("����");
    ui->tableWidget_flange->setHorizontalHeaderLabels(strFlange);
    ui->tableWidget_flange->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_flange->horizontalHeader()->setStyleSheet("QHeaderView::section{background:#e1e1e1;}");
    ui->tableWidget_flange->verticalHeader()->setStyleSheet("QHeaderView::section{background:#e1e1e1;}");
    ui->tableWidget_flange->setStyleSheet("QTableCornerButton::section{background:#e1e1e1;}");
    ui->tableWidget_flange->setAlternatingRowColors(true);
    ui->tableWidget_flange->setContextMenuPolicy(Qt::CustomContextMenu);
    QObject::connect(ui->pushButton_flangeadd,SIGNAL(clicked()),this,SLOT(flangeadd_clicked()));
    QObject::connect(ui->pushButton_flangesub,SIGNAL(clicked()),this,SLOT(flangesub_clicked()));

    ui->tableWidget_flat->setColumnCount(9);
    strPlate<<QStringLiteral("���")<<"L1(R)"<<"L2"<<"L3"<<"L4"<<"L5"<<QStringLiteral("���")<<QStringLiteral("����")<<QStringLiteral("����");
    ui->tableWidget_flat->setHorizontalHeaderLabels(strPlate);
    ui->tableWidget_flat->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_flat->horizontalHeader()->setStyleSheet("QHeaderView::section{background:#e1e1e1;}");
    ui->tableWidget_flat->verticalHeader()->setStyleSheet("QHeaderView::section{background:#e1e1e1;}");
    ui->tableWidget_flat->setStyleSheet("QTableCornerButton::section{background:#e1e1e1;}");
    ui->tableWidget_flat->setAlternatingRowColors(true);
    ui->tableWidget_flat->setContextMenuPolicy(Qt::CustomContextMenu);
    QObject::connect(ui->pushButton_flatadd,SIGNAL(clicked()),this,SLOT(flatadd_clicked()));
    QObject::connect(ui->pushButton_flatsub,SIGNAL(clicked()),this,SLOT(flatsub_clicked()));

   /* for(int i =0;i<5;i++)
    {
        ui->tableWidget_mainpipe->setColumnWidth(i,80);
        ui->tableWidget_flange->setColumnWidth(i,80);
        ui->tableWidget_arm->setColumnWidth(i,80);
    }
    for(int i =0;i<9;i++)
    {
       ui->tableWidget_flat->setColumnWidth(i,55);
    }*/
    //�����ض�Ĭ��Ϊ�ֲ��ض�7850kg/m3
    ui->lineEdit_Gama->setText(QStringLiteral("7850"));
    ui->comboBox_size->setCurrentIndex(0);
    ui->comboBox_method->setCurrentIndex(0);
    ui->comboBox_shape->setCurrentIndex(5);
    ui->comboBox_platemethod->setCurrentIndex(0);
    ui->comboBox_plateshape->setCurrentIndex(0);
    ui->comboBox_flangeshape->setCurrentIndex(4);
    ui->comboBox_flangemethod->setCurrentIndex(2);
    ui->comboBox_armsize->setCurrentIndex(0);
    ui->comboBox_armmethod->setCurrentIndex(0);
    ui->comboBox_armshape->setCurrentIndex(3);

    //��ʼ��Ϊ1��
    ui->tableWidget_mainpipe->setRowCount(1);
    ui->tableWidget_arm->setRowCount(1);
    ui->tableWidget_flat->setRowCount(1);
    ui->tableWidget_flange->setRowCount(1);
    //��ʼ����Ϊ0
    for(int i=0;i<ui->tableWidget_mainpipe->columnCount();i++)
    {
        itemMainPipe = new QTableWidgetItem;
        itemMainPipe->setText("0");
        ui->tableWidget_mainpipe->setItem(0,i,itemMainPipe);
    }
    for(int i=0;i<ui->tableWidget_arm->columnCount();i++)
    {
        itemArm = new QTableWidgetItem;
        itemArm->setText("0");
        ui->tableWidget_arm->setItem(0,i,itemArm);
    }
    for(int i=0;i<ui->tableWidget_flange->columnCount();i++)
    {
        itemFlange = new QTableWidgetItem;
        itemFlange->setText("0");
        ui->tableWidget_flange->setItem(0,i,itemFlange);
    }
    for(int i=0;i<ui->tableWidget_flat->columnCount();i++)
    {
        itemPlate = new QTableWidgetItem;
        itemPlate->setText("0");
        ui->tableWidget_flat->setItem(0,i,itemPlate);
    }

    gama = ui->lineEdit_Gama->text().toDouble();

}
/*
void CPipeWeight::createMenu()
{
   // if(popMenu!=nullptr) popMenu->clear();
    popMenu = new QMenu();
    insert_action = new QAction(this);
    delete_action = new QAction(this);
    insert_action->setText(tr("����"));
    delete_action->setText(tr("ɾ��"));

}
//����pop�˵�
void CPipeWeight::pop_menu(QPoint pos)
{
    popMenu->clear();
    popMenu->addAction(insert_action);
    popMenu->addAction(delete_action);
    popMenu->exec(QCursor::pos());
}
void CPipeWeight::contextMenuEvent(QContextMenuEvent *event)
{
    popMenu->clear();
    QPoint pos = event->pos();
    //rightclickitem = this->itemAt(pos);
}
//������
void CPipeWeight::insertmainpipeRow()
{
    ui->tableWidget_mainpipe->insertRow(1);
}
void CPipeWeight::insertarmRow()
{
    ui->tableWidget_arm->insertRow(1);
}
void CPipeWeight::insertflateRow()
{
    ui->tableWidget_flat->insertRow(1);
}
void CPipeWeight::insertflangeRow()
{
    ui->tableWidget_flange->insertRow(1);
}
//ɾ����
void CPipeWeight::deletemainpipeRow()
{
    ui->tableWidget_mainpipe->removeRow(1);
}
void CPipeWeight::deletearmRow()
{
    ui->tableWidget_arm->removeRow(1);
}
void CPipeWeight::deleteflateRow()
{
    ui->tableWidget_flat->removeRow(1);
}
void CPipeWeight::deleteflangeRow()
{
    ui->tableWidget_flange->removeRow(1);
}*/
//��������һ��
void CPipeWeight::mainpipeadd_clicked()
{
    int i = ui->tableWidget_mainpipe->rowCount();
    ui->tableWidget_mainpipe->insertRow(i);
    for(int j=0;j<ui->tableWidget_mainpipe->columnCount();j++)
    {
        itemMainPipe = new QTableWidgetItem;
        itemMainPipe->setText("0");
        ui->tableWidget_mainpipe->setItem(i,j,itemMainPipe);
    }

}
//���˼���һ��
void CPipeWeight::mainpipesub_clicked()
{
    int index = ui->tableWidget_mainpipe->rowCount();
    if(index>1) ui->tableWidget_mainpipe->removeRow(1);
}
//�ᵣ����һ��
void CPipeWeight::armadd_clicked()
{
    int i = ui->tableWidget_arm->rowCount();
    ui->tableWidget_arm->insertRow(i);
    for(int j=0;j<ui->tableWidget_arm->columnCount();j++)
    {
        itemArm = new QTableWidgetItem;
        itemArm->setText("0");
        ui->tableWidget_arm->setItem(i,j,itemArm);
    }
}
//�ᵣ����һ��
void CPipeWeight::armsub_clicked()
{
    int index = ui->tableWidget_arm->rowCount();
    if(index>1) ui->tableWidget_arm->removeRow(1);
}
//����һ�з���
void CPipeWeight::flangeadd_clicked()
{
    int i = ui->tableWidget_flange->rowCount();
     ui->tableWidget_flange->insertRow(i);
     for(int j=0;j<ui->tableWidget_flange->columnCount();j++)
     {
         itemFlange = new QTableWidgetItem;
         itemFlange->setText("0");
         ui->tableWidget_flange->setItem(i,j,itemFlange);
     }
}
//����һ�з���
void CPipeWeight::flangesub_clicked()
{
    int index = ui->tableWidget_flange->rowCount();
    if(index>1) ui->tableWidget_flange->removeRow(1);
}
//����һ�мӾ���
void CPipeWeight::flatadd_clicked()
{
    int i = ui->tableWidget_flat->rowCount();
    ui->tableWidget_flat->insertRow(i);
    for(int j=0;j<ui->tableWidget_flat->columnCount();j++)
    {
        itemPlate = new QTableWidgetItem;
        itemPlate->setText("0");
        ui->tableWidget_flat->setItem(i,j,itemPlate);
    }
}
//����һ�мӾ���
void CPipeWeight::flatsub_clicked()
{
    int index = ui->tableWidget_flat->rowCount();
    if(index>1) ui->tableWidget_flat->removeRow(1);
}
//��ʾ�Ӿ���ʾ��ͼ
void CPipeWeight::on_pushButton_pic_clicked()
{
    picdiag = new PicDialog(this);
    picdiag->exec();
}
//��ȡ�ض�
void CPipeWeight::on_lineEdit_Gama_editingFinished()
{
    gama =ui->lineEdit_Gama->text().toDouble();
    qDebug()<<tr("�ض�")<<gama;
}
//���˼���
void CPipeWeight::caculationMainpipe()
{
    //��ȡtablewidget����������
    int indexRow = ui->tableWidget_mainpipe->rowCount();
    //int indexColumn = ui->tableWidget_mainpipe->columnCount();
    //���������м����
    //�Ծ����������γ���б�ࡢ���ܳ������ܳ�����ȡ�������Ƥ��Ӱ������ĺ��,����
     double ru=0.0,rd=0.0,h=0.0,t=0.0,dt=0.0,G=0.0;
     //������̱��� ���ܳ� ���ܳ� б�� ���
     double Lu=0.0,Ld=0.0,Lx=0.0,V=0.0;
     //Բ�Ľ�
     double beta;

    //���˳ߴ���� 0��ʾ �߶Ա� 1��ʾ �����
    pipeSize = ui->comboBox_size->currentIndex();
    //���˶��������
    switch (ui->comboBox_shape->currentIndex())
    {
        //Բ��
        case 0:
            pipeShape = 1.0;
        break;
        //���ı���
        case 1:
            pipeShape = 4.0;
        break;
        //��������
        case 2:
            pipeShape = 6.0;
         break;
        //���˱���
        case 3:
            pipeShape = 8.0;
         break;
        //��ʮ������
        case 4:
            pipeShape = 12.0;
        break;
        //��ʮ������
        case 5:
            pipeShape = 16.0;
        break;
        //Ĭ��ʮ������
        default:
            ui->comboBox_shape->setCurrentIndex(5);
            pipeShape = 16.0;
        break;
    }
    //Բ�Ľ�
    beta = 2*PI/pipeShape;
    //��������������� 0��ʾ ����Ƥ 1��ʾ ��о�� 2��ʾ ����Ƥ
    pipeMethod = ui->comboBox_method->currentIndex();

    /*qDebug()<<tr("��������")<<indexRow;
    qDebug()<<tr("�ߴ����")<<pipeSize;
    qDebug()<<tr("����α�")<<pipeShape;
    qDebug()<<tr("�������")<<pipeMethod;
    qDebug()<<tr(" �ض� ")<<gama;
    qDebug()<<tr("1:1 ����=")<<ui->tableWidget_mainpipe->item(0,0)->text().toDouble();*/
   for(int i=0;i<indexRow;i++)
   {
       //�Ծ�һ��
       ru = ui->tableWidget_mainpipe->item(i,1)->text().toDouble()*0.5;
       //����һ��
       rd = ui->tableWidget_mainpipe->item(i,2)->text().toDouble()*0.5;
       //�ں�
       t = ui->tableWidget_mainpipe->item(i,3)->text().toDouble();
       //�γ�
       h = ui->tableWidget_mainpipe->item(i,4)->text().toDouble();
       //б��
       Lx = sqrt(h*h+(rd-ru)*(rd-ru));
       /*qDebug()<<"ru="<<ru;
       qDebug()<<"rd="<<rd;
       qDebug()<<"t="<<t;
       qDebug()<<"h="<<h;*/
       // ����Ƥо��
       switch (pipeMethod)
       {
           case 0:
               dt = 0.0;
               break;
           case 1:
               dt = 0.5*t;
               break;
           case 2:
           dt = t;
               break;
           default:
           dt = 0.0;
               break;
       }
       //�����ϵ��µ��ܳ�
       if(pipeShape ==1.0)
       {
           Lu = 2*PI*(ru-dt);
           Ld = 2*PI*(rd-dt);
       }
       else
       {
            //�߶Ա�
            if(pipeSize ==0)
            {
                Lu = pipeShape*2.0*(ru-dt)*tan(0.5*beta);
                Ld = pipeShape*2.0*(rd-dt)*tan(0.5*beta);
            }
            //�����
            else if (pipeSize==1)
            {
                Lu = pipeShape*2.0*(ru-dt)*sin(0.5*beta);
                Ld = pipeShape*2.0*(rd-dt)*sin(0.5*beta);
            }
       }//end if
       V = 0.5*(Lu+Ld)*Lx*t;
       G = 0.000000001*gama*V;
       itemMainPipe = new QTableWidgetItem;
       itemMainPipe->setText(QString::number(G,10,2));
       ui->tableWidget_mainpipe->setItem(i,5,itemMainPipe);
   }//end for
}
//����ᵣ����
void CPipeWeight::caculatinArm()
{
    //��ȡtablewidget����������
    int indexRow = ui->tableWidget_arm->rowCount();
    //���������м����
    //�Ծ����������γ���б�ࡢ���ܳ������ܳ�����ȡ�������Ƥ��Ӱ������ĺ��,����
     double ru=0.0,rd=0.0,h=0.0,t=0.0,dt=0.0,G=0.0;
     //������̱��� ���ܳ� ���ܳ� б�� ��� ����
     double Lu=0.0,Ld=0.0,Lx=0.0,V=0.0,n=0.0;
     //Բ�Ľ�
     double beta;
    //���˳ߴ���� 0��ʾ �߶Ա� 1��ʾ �����
    armSize = ui->comboBox_armsize->currentIndex();
    //���˶��������
    switch (ui->comboBox_armshape->currentIndex())
    {
        //Բ��
        case 0:
            armShape = 1.0;
        break;
        //���ı���
        case 1:
            armShape = 4.0;
        break;
        //��������
        case 2:
           armShape = 6.0;
         break;
        //���˱���
        case 3:
            armShape = 8.0;
         break;
        default:
            ui->comboBox_armshape->setCurrentIndex(3);
            armShape = 8.0;
        break;
    }
    //Բ�Ľ�
    beta = 2*PI/armShape;
    //��������������� 0��ʾ ����Ƥ 1��ʾ ��о�� 2��ʾ ����Ƥ
    armMethod = ui->comboBox_armmethod->currentIndex();
   for(int i=0;i<indexRow;i++)
   {
       //�Ծ�һ��
       ru = ui->tableWidget_arm->item(i,1)->text().toDouble()*0.5;
       //����һ��
       rd = ui->tableWidget_arm->item(i,2)->text().toDouble()*0.5;
       //�ں�
       t = ui->tableWidget_arm->item(i,3)->text().toDouble();
       //�γ�
       h = ui->tableWidget_arm->item(i,4)->text().toDouble();
       //����
       n = ui->tableWidget_arm->item(i,5)->text().toDouble();
       //б��
       Lx = sqrt(h*h+(rd-ru)*(rd-ru));
       /*qDebug()<<"ru="<<ru;
       qDebug()<<"rd="<<rd;
       qDebug()<<"t="<<t;
       qDebug()<<"h="<<h;*/
       // ����Ƥо��
       switch (armMethod)
       {
           case 0:
               dt = 0.0;
               break;
           case 1:
               dt = 0.5*t;
               break;
           case 2:
           dt = t;
               break;
           default:
           dt = 0.0;
               break;
       }
       //�����ϵ��µ��ܳ�
       if(armShape ==1.0)
       {
           Lu = 2*PI*(ru-dt);
           Ld = 2*PI*(rd-dt);
       }
       else
       {
            //�߶Ա�
            if(pipeSize ==0)
            {
                Lu = armShape*2.0*(ru-dt)*tan(0.5*beta);
                Ld = armShape*2.0*(rd-dt)*tan(0.5*beta);
            }
            //�����
            else if (armSize==1)
            {
                Lu = armShape*2.0*(ru-dt)*sin(0.5*beta);
                Ld = armShape*2.0*(rd-dt)*sin(0.5*beta);
            }
       }//end if
       V = 0.5*(Lu+Ld)*Lx*t;
       G = 0.000000001*gama*V*n;
       itemArm = new QTableWidgetItem;
       itemArm->setText(QString::number(G,10,2));
       ui->tableWidget_arm->setItem(i,6,itemArm);
   }//end for
}
//���㷨������
void CPipeWeight::caculationFlange()
{
    //�����������е��м����
    double d0=0.0,di=0.0,t=0.0,n=0.0,V=0.0,G=0.0;

    switch (ui->comboBox_flangeshape->currentIndex())
    {
        //���ı���
        case 0:
            flangeShape = 4.0;
        break;
        //��������
        case 1:
            flangeShape = 6.0;
        break;
        //���˱���
        case 2:
            flangeShape = 8.0;
         break;
        //��ʮ������
        case 3:
            flangeShape = 12.0;
         break;
        //��ʮ������
        case 4:
            flangeShape = 16.0;
        break;

        //Ĭ��ʮ������
        default:
            ui->comboBox_shape->setCurrentIndex(4);
            flangeShape = 16.0;
        break;
    }
    for (int i=0;i<ui->tableWidget_flange->rowCount();i++)
    {
        d0 = ui->tableWidget_flange->item(i,1)->text().toDouble();
        di = ui->tableWidget_flange->item(i,2)->text().toDouble();
        t = ui->tableWidget_flange->item(i,3)->text().toDouble();
        n = ui->tableWidget_flange->item(i,4)->text().toDouble();
        switch (ui->comboBox_flangemethod->currentIndex())
        {
            //����
            case 0:
                V=d0*d0*t;
                break;
            //����Բ
            case 1:
                V=(d0*d0-0.25*PI*di*di)*t;
                break;
            //Բ��Բ
            case 2:
                V=0.25*PI*(d0*d0-di*di)*t;
                break;
            //Բ�������
            case 3:
                V=(0.25*PI*d0*d0-0.25*flangeShape*di*di*tan(PI/flangeShape))*t;
                break;
            //Բ��
            case 4:
                V=0.25*PI*d0*d0*t;
                break;
            default:
                break;
        }
        G = 0.000000001*gama*V*n;
        itemFlange = new QTableWidgetItem;
        itemFlange->setText(QString::number(G,10,2));
        ui->tableWidget_flange->setItem(i,5,itemFlange);
    }//end for
}
//�Ӿ������
void CPipeWeight::caculationFlate()
{
    //���γߴ�
    double L1=0.0,L2=0.0,L3=0.0,L4=0.0,L5=0.0;
    //�м����
    double  V=0.0,G=0.0,t=0.0,n=0.0;
    //0��ʾ�н� 1��ʾ���� 2��ʾ˫�н� 3��ʾ˫����
    flateShape = ui->comboBox_plateshape->currentIndex();
    //0��ʾ�ü��� 1��ʾ����
    flatemethod = ui->comboBox_platemethod->currentIndex();
    for (int i=0;i<ui->tableWidget_flat->rowCount();i++)
    {
        L1 = ui->tableWidget_flat->item(i,1)->text().toDouble();
        L2 = ui->tableWidget_flat->item(i,2)->text().toDouble();
        L3 = ui->tableWidget_flat->item(i,3)->text().toDouble();
        L4 = ui->tableWidget_flat->item(i,4)->text().toDouble();
        L5 = ui->tableWidget_flat->item(i,5)->text().toDouble();
        t = ui->tableWidget_flat->item(i,6)->text().toDouble();
        n = ui->tableWidget_flat->item(i,7)->text().toDouble();
        if(flatemethod ==1)
        {
            V = L2*L5*t;
        }
        else if(flatemethod ==0)
        {
            switch (flateShape)
            {
                //�н�
                case 0:
                    V = (L2*L5-0.5*L1*L1-0.5*(L5-L3)*(L2-L4))*t;
                    break;
                //����
                case 1:
                    V = (L2*L5-0.25*PI*L1*L1-0.5*(L5-L3)*(L2-L4))*t;
                    break;
                //˫�н�
                case 2:
                    V = (L2*L5-L1*L1-0.5*(L5-L3)*(L2-L4))*t;
                    break;
                case 3:
                    V = (L2*L5-0.5*PI*L1*L1-0.5*(L5-L3)*(L2-L4))*t;
                    break;
                //�н�
                default:
                    V = (L2*L5-0.5*L1*L1-0.5*(L5-L3)*(L2-L4))*t;
                    break;
            }
        }//edn if
        G= 0.000000001*gama*V*n;
        itemPlate = new QTableWidgetItem;
        itemPlate->setText(QString::number(G,10,2));
        ui->tableWidget_flat->setItem(i,8,itemPlate);
    }//end for

}
//����
void CPipeWeight::on_pushButton_caculation_clicked()
{
    caculationMainpipe();
    caculatinArm();
    caculationFlange();
    caculationFlate();
}
//���������
void CPipeWeight::on_pushButton_output_clicked()
{
    QFile outFile("output.txt");
    //�����QIODevice::Text �򲻻���
    if(outFile.open(QFile::WriteOnly|QFile::Truncate|QIODevice::Text))
    {
        QTextStream outPut(&outFile);
        int indexMainpipeRow=0,indexMainpipeColumn=0,indexArmRow=0,indexArmColumn=0,indexFlangeRow=0,indexFlangeColumn=0,indexFlateRow=0,indexFlateColumn=0;
        indexMainpipeRow = ui->tableWidget_mainpipe->rowCount();
        indexMainpipeColumn = ui->tableWidget_mainpipe->columnCount();
        indexArmRow = ui->tableWidget_arm->rowCount();
        indexArmColumn = ui->tableWidget_arm->columnCount();
        indexFlangeRow = ui->tableWidget_flange->rowCount();
        indexFlangeColumn = ui->tableWidget_flange->columnCount();
        indexFlateRow = ui->tableWidget_flat->rowCount();
        indexFlateColumn = ui->tableWidget_flat->columnCount();
        outPut<<QStringLiteral("                   �ֹܸ˸���������������") <<endl;
        outPut<<QStringLiteral("                   �ֹܸ������������� ") <<endl;
        outPut<<QStringLiteral("�κ�    ")<<QStringLiteral("�Ծ�    ")<<QStringLiteral("����    ")<<QStringLiteral("�ں�    ")<<QStringLiteral("�γ�    ")<<
                QStringLiteral("����")<<endl;
        for (int i=0;i<indexMainpipeRow;i++)
        {
            for(int j=0;j<indexMainpipeColumn;j++)
            {
                outPut<<ui->tableWidget_mainpipe->item(i,j)->text()<<"         ";
            }
            outPut<<endl;
        }
        outPut<<QStringLiteral("                   �ֹܸ˺ᵣ�������� ") <<endl;
        outPut<<QStringLiteral("�κ�    ")<<QStringLiteral("�Ծ�    ")<<QStringLiteral("����    ")<<QStringLiteral("�ں�    ")<<QStringLiteral("�γ�    ")<<
                QStringLiteral("����    ")<<QStringLiteral("����")<<endl;
        for (int i=0;i<indexArmRow;i++)
        {
           for (int j=0;j<indexArmColumn;j++)
           {
               outPut<<ui->tableWidget_arm->item(i,j)->text()<<"         ";
           }
           outPut<<endl;
        }
        outPut<<QStringLiteral("                   �ֹܸ˷����������� ") <<endl;
        outPut<<QStringLiteral("����    ")<<QStringLiteral("�⾶   ")<<QStringLiteral("�ھ�    ")<<QStringLiteral("���    ")<<QStringLiteral("����    ")<<
                QStringLiteral("����    ")<<endl;
        for (int i=0;i<indexFlangeRow;i++)
        {
            for (int j=0;j<indexFlangeColumn;j++)
            {
                outPut<<ui->tableWidget_flange->item(i,j)->text()<<"         ";
            }
            outPut<<endl;
        }
        outPut<<QStringLiteral("                   �ֹܸ˼Ӿ����������� ") <<endl;
        outPut<<QStringLiteral("���    ")<<"L1(R)    "<<"L2    "<<"L3    "<<"L4    "<<"L5    "<<QStringLiteral("���    ")<<QStringLiteral("����    ")<<
                QStringLiteral("����")<<endl;
        for (int i=0;i<indexFlateRow;i++)
        {
            for (int j=0;j<indexFlateColumn;j++)
            {
                outPut<<ui->tableWidget_flat->item(i,j)->text()<<"         ";
            }
            outPut<<endl;
        }
        QString curtime;
        curtime = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss:zzz");
        outPut<<curtime<<endl;
        outPut<<QStringLiteral("�������ɳɶ����ڱ�д��������������ϵQQ:550551769��")<<endl;
    }//end if
    else
    {}

}
