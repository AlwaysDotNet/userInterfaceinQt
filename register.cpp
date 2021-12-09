#include "register.h"
#include "ui_register.h"

Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    this->img=new ImageView();
    this->img->setImage(QDir::currentPath()+"\\icons\\openIcon.jpg");
    ui->verticalLayout_3->addWidget(this->img);
    setAttribute(Qt::WA_DeleteOnClose);
}

Register::~Register()
{
    delete ui;
    delete img;
}

void Register::on_pushButton_2_clicked()
{
    QApplication::quit();
}

//Кнопка создать при этом не забудем сохранит все данные на файл
void Register::on_pushButton_clicked()
{
    QString l=ui->mailEdit->text();
    QString p=ui->pasEdit->text();
    QString n=ui->nameEdit->text();
    QString sn=ui->snameEdit->text();
    QString fl=img->getPath();
    User u(l,p,n,sn,fl);
    //Добавим все в файл
    QFile wrfl(QDir::currentPath()+"\\users.txt");
    wrfl.open(QIODevice::Append|QFile::Text);
    QTextStream out(&wrfl);
    out<<"\n"<<n<<";"<<sn<<";"<<fl<<";"<<l<<";"<<p;
    wrfl.close();
    emit toLogin(u);
    this->hide();
}

