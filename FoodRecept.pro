QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    favouriteswidget.cpp \
    food.cpp \
    foodwidget.cpp \
    imageview.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    register.cpp \
    user.cpp

HEADERS += \
    favouriteswidget.h \
    food.h \
    foodwidget.h \
    imageview.h \
    login.h \
    mainwindow.h \
    register.h \
    user.h

FORMS += \
    favouriteswidget.ui \
    foodwidget.ui \
    imageview.ui \
    login.ui \
    mainwindow.ui \
    register.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resours.qrc
