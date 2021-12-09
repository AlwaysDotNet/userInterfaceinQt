#ifndef FAVOURITESWIDGET_H
#define FAVOURITESWIDGET_H

#include <QWidget>
#include <QDir>
namespace Ui {
class FavouritesWidget;
}

class FavouritesWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FavouritesWidget(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event) override;
    bool getIs()const;//Состояние
    ~FavouritesWidget();
signals:
    void clicked();
private:
    Ui::FavouritesWidget *ui;
    bool is;//Отключено или нет
};

#endif // FAVOURITESWIDGET_H
