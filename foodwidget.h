#ifndef FOODWIDGET_H
#define FOODWIDGET_H

#include <QWidget>
#include "imageview.h"
#include "favouriteswidget.h"
#include <QLabel>
#include "food.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
namespace Ui {
class FoodWidget;
}
class ImageView;
class FavouritesWidget;
class Food;
class FoodWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FoodWidget(QWidget *parent = nullptr);
    FoodWidget(const QString& name,const int dur,const QString& type,QWidget*parent=nullptr);
    ~FoodWidget();
    Food::foodType getTypeFood()const;
private:
    Ui::FoodWidget *ui;
    FavouritesWidget *fav;
    ImageView *imgFod;
    QLabel *ings;
    QLabel *recepts;
    Food *fod;
public:

};

#endif // FOODWIDGET_H
