QT += quick widgets multimedia multimediawidgets

CONFIG += c++11
INCLUDEPATH +=/usr/local/include
LIBS += -L/usr/local/lib -lopencv_imgproc -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_videoio -lopencv_features2d  -lopencv_objdetect -lopencv_xfeatures2d

#ALL LIBS
#LIBS +=-L/usr/local/lib -lopencv_dnn -lopencv_ml -lopencv_objdetect -lopencv_shape \
#-lopencv_stitching -lopencv_superres -lopencv_videostab \
#-lopencv_calib3d -lopencv_features2d -lopencv_highgui \
#-lopencv_videoio -lopencv_imgcodecs -lopencv_video \
#-lopencv_photo -lopencv_imgproc -lopencv_flann -lopencv_core -lopencv_xfeatures2d

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
    matchmainwindows.cpp \
    imageprovider.cpp \
    videoprovider.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    matchmainwindows.h \
    imageprovider.h \
    videoprovider.h
