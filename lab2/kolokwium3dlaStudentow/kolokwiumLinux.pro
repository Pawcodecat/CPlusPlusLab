TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cc \
        matrix.cc \
        matrixTests.cc \
        utils/argumentParsing.cc \
        utils/programmersDetails.cc

DISTFILES +=

HEADERS += \
    matrix.h \
    matrixElement.h \
    utils/argumentParsing.h \
    utils/programmerDetails.h

INCLUDEPATH += \
    libs/gtest/include/

LIBS += \
    -L$$_PRO_FILE_PWD_/libs/gtest/libsLinux/ -lgtest -pthread
