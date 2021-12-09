#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QScrollBar>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->userImage=new ImageView();
    this->userImage->setImage(QDir::currentPath()+"icons\\female.jpg");
    userImage->setFixedSize(50,50);
    this->ui->horizontalLayout_2->addWidget(this->userImage,1,Qt::AlignRight);

    QFile base(QDir::currentPath()+"\\bases.txt");
    base.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream in(&base);
    while(!in.atEnd())
    {
        QStringList line=in.readLine().split(' ');
        QString name=line.first();
        line.pop_front();
        int durat=0;
        durat=line.first().toInt();
        line.pop_front();
        QString typ=line.first();
        FoodWidget *fdW=new FoodWidget(name,durat,typ);
        this->foos.push_back(fdW);
        qDebug()<<name<<" "<<typ;
        line.clear();
    }
    base.close();

    QWidget *main=new QWidget(this);
    layW=new QVBoxLayout(main);
    qDebug()<<foos.size();
    for(int i=0;i<foos.size();i++)
        layW->addWidget(foos[i]);
    QScrollArea *ar=new QScrollArea();
    ar->setWidgetResizable(true);
    ar->setWidget(main);
    ar->verticalScrollBar()->setEnabled(true);
    this->ui->verticalLayout->addWidget(ar);
    this->ui->nameRadio->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete this->userImage;
    delete this->layW;
    for(int i=0;i<foos.size();i++)
        delete foos[i];
    foos.clear();
}

void MainWindow::OnShow(const User& us)
{

    this->userImage->setImage(us.getFile());
    this->ui->label->setText("Hi! "+us.getName());
    this->show();
}

//Кнопка поиск
void MainWindow::on_pushButton_clicked()
{
   Food::foodType ftype=Food::foodType::One;
   if(ui->oneRad->isChecked())
       ftype=Food::foodType::One;
   else if(ui->twoRad->isChecked())
       ftype=Food::foodType::Two;
   else if(ui->desertRad->isChecked())
       ftype=Food::foodType::Two;
   for(int i=0;i<foos.size();i++)
       this->layW->removeWidget(foos[i]);
   for(int i=0;i<this->foos.size();i++)
   {
       if(foos[i]->getTypeFood()==ftype)
           this->layW->addWidget(foos[i]);
   }
}

