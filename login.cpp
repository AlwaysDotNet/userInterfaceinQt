#include "login.h"
#include "ui_login.h"

LogIn::LogIn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogIn)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

}

void LogIn::setUsers(QVector<User> &us)
{
 this->users=us;
}

QString LogIn::getLog() const
{
    return this->Login;
}
//Возврашение пассворд
QString LogIn::getPass() const
{
   return this->Password;
}

LogIn::~LogIn()
{
    delete ui;
}
//Найдем ползователя по парол и логину
void LogIn::on_pushButton_clicked()
{
    bool isOk=false;
    for(auto it:users)
    {
        if(this->ui->lineEdit->text().compare(it.getLog())==0&&this->ui->lineEdit_2->text().compare(it.getPass())==0)
        {
            this->Login=this->ui->lineEdit->text();
            this->Password=this->ui->lineEdit_2->text();
            emit this->isCorrect(it);
            this->hide();
            isOk=true;
            deleteLater();
            break;
        }
    }
    if(!isOk)
        QMessageBox::information(this,"Информация","Неправильный парол или логин");

}

//Переход к окну регистрация
void LogIn::on_pushButton_2_clicked()
{
  emit this->toRegister();
    this->hide();
}
//Слот принятие от окно регистрация
void LogIn::inRegister(const User &u)
{
    this->users.push_back(u);//Добавим ползоваетля
    this->show();
}

