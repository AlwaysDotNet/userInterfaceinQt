#include "imageview.h"
#include "ui_imageview.h"
#include  <QFileDialog>
ImageView::ImageView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImageView)
{
    ui->setupUi(this);
    ui->label->setFixedSize(150,150);
    this->isMouse=true;
}

void ImageView::setImage(const QString &filename)
{
    QPixmap p(filename);
    this->ui->label->setPixmap(p.scaled(this->width(),this->height(),Qt::KeepAspectRatio));
    this->imgPath=filename;
}

void ImageView::mousePressEvent(QMouseEvent *event)
{

    if(isMouse)
    {
        QString filename=QFileDialog::getOpenFileName(this,tr("открыт файл"),QDir::currentPath(),tr("Image Files (*.png *.jpg *.bmp)"));
        QPixmap p(filename);

        this->imgPath=filename;
        this->ui->label->setPixmap(p.scaled(this->width(),this->height(),Qt::KeepAspectRatio));
    }
}

QString ImageView::getPath() const
{
    return this->imgPath;
}

bool ImageView::SetIsMousePress(bool bl)
{
    this->isMouse=bl;
}

void ImageView::setFixedSize(const int w, const int h)
{
    this->setImage(this->imgPath);
    this->ui->label->setFixedSize(w,h);
}

ImageView::~ImageView()
{
    delete ui;
}
