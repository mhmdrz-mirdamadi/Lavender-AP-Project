QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    baseestablish.cpp \
    basefarm.cpp \
    basesilo.cpp \
    basestorage.cpp \
    baseuser.cpp \
    courtgame.cpp \
    dairyfarm.cpp \
    daynight.cpp \
    hayfarm.cpp \
    hayfarmbuilding.cpp \
    levelup.cpp \
    locklands.cpp \
    main.cpp \
    login.cpp \
    mainmenu.cpp \
    poultryfarm.cpp \
    sheepfold.cpp \
    signup.cpp \
    silo.cpp \
    silobuilding.cpp \
    storage.cpp \
    storagebuilding.cpp \
    user.cpp \
    wheatfarm.cpp \
    wheatfarmbuilding.cpp

HEADERS += \
    baseestablish.h \
    basefarm.h \
    basesilo.h \
    basestorage.h \
    baseupgrade.h \
    baseuser.h \
    courtgame.h \
    dairyfarm.h \
    daynight.h \
    hayfarm.h \
    levelup.h \
    hayfarmbuilding.h \
    locklands.h \
    login.h \
    mainmenu.h \
    poultryfarm.h \
    sheepfold.h \
    signup.h \
    silo.h \
    silobuilding.h \
    storage.h \
    storagebuilding.h \
    user.h \
    wheatfarm.h \
    wheatfarmbuilding.h

FORMS += \
    courtgame.ui \
    dairyfarm.ui \
    daynight.ui \
    hayfarm.ui \
    levelup.ui \
    locklands.ui \
    login.ui \
    mainmenu.ui \
    poultryfarm.ui \
    sheepfold.ui \
    signup.ui \
    silo.ui \
    storage.ui \
    wheatfarm.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    gifs.qrc \
    pic.qrc

