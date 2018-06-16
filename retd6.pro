QT += widgets
QMAKE_CXXFLAGS = -std=c++11
QMAKE_LFLAGS = -std=c++11

CONFIG += console

SOURCES += \
    automate.cpp \
    main.cpp \
    auto_1d.cpp \
    auto_2d.cpp \
    bas_droite.cpp


HEADERS += \
    automate.h \
    auto_1d.h \
    auto_2d.h \
    jeuvie.h \
    bas_droite.h \
    autoelem.h


