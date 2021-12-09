#include "mainwindow.h"
#include "login.h"
#include <QApplication>
#include "user.h"
#include <QVector>
#include <QFile>
#include <QTextStream>
#include <QIODevice>
#include <QDebug>
#include <iostream>
#include <register.h>
#include "favouriteswidget.h"
#include "foodwidget.h"
class FavouritesWidget;
class FoodWidget;
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    QVector<User>users;
    QFile fl(QDir::currentPath()+"\\users.txt");
    fl.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream inp(&fl);
    //Пользователи обшый для всех поэтому нам нужно сначало их прочитать

    while(!inp.atEnd())
    {
        QStringList user=inp.readLine().split(";");
        User us(user);
        users.push_back(us);
    }
    fl.close();
    LogIn *in=new LogIn();
    Register *reg=new Register();
    in->setUsers(users);
    in->show();
    MainWindow w;
    QObject::connect(in,&LogIn::isCorrect,&w,&MainWindow::OnShow);
    QObject::connect(reg,&Register::toLogin,in,&LogIn::inRegister);
    QObject::connect(in,&LogIn::toRegister,reg,&Register::show);
    return a.exec();
}
