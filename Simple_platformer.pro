TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -LD:/SFML1/lib

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-network-d -lsfml-window-d -lsfml-system-d



SOURCES += main.cpp \
    mywindow.cpp \
    game.cpp \
    player.cpp \
    world.cpp \
    enemy.cpp \
    entity.cpp \
TinyXML/tinyxml.cpp \
TinyXML/tinystr.cpp\
TinyXML/tinyxmlparser.cpp \
TinyXML/tinyxmlerror.cpp \
    level.cpp \
    animation.cpp


INCLUDEPATH += D:/SFML1/include
DEPENDPATH += D:/SFML1/include

HEADERS += \
    mywindow.h \
    game.h \
    player.h \
    world.h \
    enemy.h \
    entity.h \
    level.h \
TinyXML/tinyxml.h \
TinyXML/tinystr.h \
    animation.h
