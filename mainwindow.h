#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "login.h"
#include "register.h"
#include  <QVector>
#include <QHBoxLayout>
#include <QtWidgets>
#include "imageview.h"
#include "user.h"
#include "foodwidget.h"
#include <QFile>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class LogIn;
class Register;
class ImageView;
class User;
class FooWidget;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
 public slots:
    void OnShow(const User&);
private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    ImageView *userImage;
    QVBoxLayout *layW;
    QVector<FoodWidget*>foos;
};
#endif // MAINWINDOW_H
