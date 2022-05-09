QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

HEADERS +=\
../OOPlab2/algorithms.h

SOURCES += \
    tst_tests.cpp\
     ../OOPlab2/algorithms.cpp
INCLUDEPATH += ../OOPlab2

