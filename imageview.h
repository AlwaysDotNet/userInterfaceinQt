#ifndef IMAGEVIEW_H
#define IMAGEVIEW_H

#include <QWidget>

namespace Ui {
class ImageView;
}

class ImageView : public QWidget
{
    Q_OBJECT

public:
    explicit ImageView(QWidget *parent = nullptr);
    void setImage(const QString&);
    void mousePressEvent(QMouseEvent *event) override;
    QString getPath()const;
    bool SetIsMousePress(bool bl);
    void setFixedSize(const int w,const int h);
    ~ImageView();

private:
    Ui::ImageView *ui;
    QString imgPath;//Имя файла
    bool isMouse;//Можно нажать на кнопку или нет
};

#endif // IMAGEVIEW_H
