QT += core gui opengl


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

include(front/qtgifimage/src/gifimage/qtgifimage.pri)

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ./front/main.cpp \
    ./front/mainwindow.cpp \
    ./front/glwidget.cpp \
    ./controller/controller.cpp \
    ./model/affin.cpp \
    ./model/validation.cpp \
    ./model/backend.cpp \
    ./front/settings.cpp \

HEADERS += \
    ./front/mainwindow.h \
    ./front/glwidget.h \
    ./model/backend.h \
    ./model/validation.h \
    ./controller/controller.h \
FORMS += \
    ./front/mainwindow.ui

ICON = ./assets/Viewer.icns


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ./front/resources.qrc
