QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

#HEADERS +=\
#../OOPlab2/algorithms.h

SOURCES += \
    asdasd.cpp \
    tst_tests.cpp
 #    ../OOPlab2/algorithms.cpp
#INCLUDEPATH += ../OOPlab2




win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../lib/ -lalgoslib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../lib/ -lalgoslib

INCLUDEPATH += $$PWD/../lib
DEPENDPATH += $$PWD/../lib

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../QT/labs/build-checklib-Desktop_Qt_6_2_0_MinGW_64_bit-Debug/release/ -lchecklib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../QT/labs/build-checklib-Desktop_Qt_6_2_0_MinGW_64_bit-Debug/debug/ -lchecklib


HEADERS += \
    asdasd.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../QT/labs/build-checklib-Desktop_Qt_6_2_0_MinGW_64_bit-Debug/release/ -lchecklib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../QT/labs/build-checklib-Desktop_Qt_6_2_0_MinGW_64_bit-Debug/debug/ -lchecklib

INCLUDEPATH += $$PWD/../../../QT/labs/checklib
DEPENDPATH += $$PWD/../../../QT/labs/checklib
