#-------------------------------------------------
#
# Project created by QtCreator 2017-04-26T18:01:29
#
#-------------------------------------------------

QT       += widgets

TARGET = ClickLib
TEMPLATE = lib

DEFINES += CLICKLIB_LIBRARY

VERSION = 1.21
DEFINES += VERSION=\\\"$$VERSION\\\"
# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += clicklib.cpp \
    systemtrey.cpp \
    win.cpp

HEADERS += clicklib.h\
        clicklib_global.h \
    systemtrey.h \
    win.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

RESOURCES += \
    resource.qrc

#Подключение OpenCv
PUTH_TO_OPENCV = "G:\qt\opencv\opencv\build\bin"
DEFINES += PUTH_TO_OPENCV=\\\"$$PUTH_TO_OPENCV\\\"
INCLUDEPATH += G:\qt\opencv\opencv\build\include

LIBS += $$PUTH_TO_OPENCV\libopencv_core320.dll
LIBS += $$PUTH_TO_OPENCV\libopencv_highgui320.dll
LIBS += $$PUTH_TO_OPENCV\libopencv_imgcodecs320.dll
LIBS += $$PUTH_TO_OPENCV\libopencv_imgproc320.dll
LIBS += $$PUTH_TO_OPENCV\libopencv_features2d320.dll
LIBS += $$PUTH_TO_OPENCV\libopencv_calib3d320.dll
LIBS += $$PUTH_TO_OPENCV\libopencv_videoio320.dll
LIBS += $$PUTH_TO_OPENCV\libopencv_video320.dll
LIBS += $$PUTH_TO_OPENCV\opencv_ffmpeg320.dll
LIBS += -lgdi32
LIBS += -lkernel32

LIBS += -lgdi32
LIBS += -lkernel32
