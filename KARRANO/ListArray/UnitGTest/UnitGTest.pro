include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        ../listarray.h \
        tst_test.h

SOURCES += \
        ../listarray.cpp \
        main.cpp
