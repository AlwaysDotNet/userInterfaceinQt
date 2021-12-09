#include "foodwidget.h"
#include "ui_foodwidget.h"
#include <QLine>

FoodWidget::FoodWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FoodWidget)
{
    ui->setupUi(this);

}

FoodWidget::FoodWidget(const QString& name,const int dur,const QString& typ, QWidget *parent):
    QWidget(parent),
    ui(new Ui::FoodWidget)
{
    this->fod=new Food(name,dur,typ);
    this->imgFod=new ImageView();
    this->imgFod->setImage(fod->getImgPath());
    this->imgFod->SetIsMousePress(false);
    this->fav=new FavouritesWidget(this->imgFod);
    this->ings=new QLabel();
    this->ings->setMaximumWidth(this->width());
    this->ings->setWordWrap(true);

    QString sings="";
    int i=0;
    for(QString it:fod->getIngridents())
    {
        sings+=it+" ";
        i+=(int)sings.length();
        if(i>40)
        {
            sings+="\n";
            i=0;
        }
    }
    this->ings=new QLabel(sings+" \nВремя приготовление "+fod->getDurMin()+"минут");

    this->recepts=new QLabel(fod->getRecept());
    this->ings->setFont(QFont("Times New Roman",12,2,false));
    this->ings->setStyleSheet("border:2px solid black;");
    this->recepts->setStyleSheet("border:4px solid yellow;");
    this->recepts->setFont(QFont("Times New Roman",12,2,true));
    this->recepts->setWordWrap(true);
    this->ings->setAlignment(Qt::AlignJustify);
    this->ings->setMargin(4);
    this->recepts->setAlignment(Qt::AlignJustify);
    this->recepts->setMargin(4);
    QVBoxLayout *vbox=new QVBoxLayout(this);
    vbox->addWidget(this->imgFod);
    vbox->addWidget(ings);
    vbox->addStretch(4);
    vbox->addWidget(recepts);
    this->imgFod->setFixedSize(400,300);

}

FoodWidget::~FoodWidget()
{
    delete ui;
    delete this->fod;
    delete this->imgFod;
    delete this->ings;
    delete this->recepts;
}

Food::foodType FoodWidget::getTypeFood() const
{
    return this->fod->getType();
}
