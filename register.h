#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>
#include <QGraphicsScene>
#include "user.h"
#include "imageview.h"
#include <QFile>
#include <QDir>
namespace Ui {
class Register;
}
class User;
class ImageView;
class Register : public QWidget
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

signals:
    void toLogin(const User&);

private slots:

    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

private:
    Ui::Register *ui;//Главное окно
    ImageView *img;//Фото ползоователя
};

#endif // REGISTER_H
