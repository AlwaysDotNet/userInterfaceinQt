#include "favouriteswidget.h"
#include "ui_favouriteswidget.h"

FavouritesWidget::FavouritesWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FavouritesWidget)
{
    ui->setupUi(this);
    this->setFixedSize(50,50);
    setAttribute(Qt::WA_TranslucentBackground);
    this->setToolTip("Добавить в избранное");
    //Сосотояние который появится этот виджет
    ui->label->setFixedSize(width(),height());
    QPixmap px(QDir::currentPath()+"\\icons\\izbran1.jpg");
    px=px.scaled(ui->label->width(),ui->label->height(),Qt::KeepAspectRatio);
    this->ui->label->setPixmap(px);
    this->is=false;
}

void FavouritesWidget::mousePressEvent(QMouseEvent *event)
{
    if(!this->is)
    {
        QPixmap px(QDir::currentPath()+"\\icons\\izbran2.jpg");
        px=px.scaled(ui->label->width(),ui->label->height(),Qt::KeepAspectRatio);
        this->ui->label->setPixmap(px);
        this->is=true;
    }
    else
    {
        QPixmap px(QDir::currentPath()+"\\icons\\izbran1.jpg");
        px=px.scaled(ui->label->width(),ui->label->height(),Qt::KeepAspectRatio);
        this->ui->label->setPixmap(px);
        this->is=false;
    }
}

bool FavouritesWidget::getIs() const
{
    return this->is;
}

FavouritesWidget::~FavouritesWidget()
{
    delete ui;
}
