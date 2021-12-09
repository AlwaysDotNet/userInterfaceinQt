#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QVector>
#include "user.h"
#include <QMessageBox>
namespace Ui {
class LogIn;
}
class User;
class LogIn : public QWidget
{
    Q_OBJECT
private:
    QString Login;
    QString Password;
    QVector<User>users;
signals:
    void isCorrect(const User&);//Перейти к главному окну
    void toRegister();//Перейти к окну регистрация
public:
    explicit LogIn(QWidget *parent = nullptr);
    void setUsers(QVector<User>&);
    QString getLog()const;
    QString getPass()const;
    ~LogIn();
public slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void inRegister(const User&);

private:
    Ui::LogIn *ui;
};

#endif // LOGIN_H
