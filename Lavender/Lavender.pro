QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    courtgame.cpp \
    daynight.cpp \
    main.cpp \
    login.cpp \
    mainmenu.cpp \
    signup.cpp \
    silo.cpp \
    silobuilding.cpp \
    storage.cpp \
    storagebuilding.cpp \
    user.cpp

HEADERS += \
    courtgame.h \
    daynight.h \
    login.h \
    mainmenu.h \
    signup.h \
    silo.h \
    silobuilding.h \
    storage.h \
    storagebuilding.h \
    user.h

FORMS += \
    courtgame.ui \
    daynight.ui \
    login.ui \
    mainmenu.ui \
    signup.ui \
    silo.ui \
    storage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    gifs.qrc \
    pic.qrc

