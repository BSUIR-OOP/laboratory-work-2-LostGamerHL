TEMPLATE = app
QT += core gui network sql opengl

SOURCES += \
        factory.h \
        ents/circle.cpp \
        ents/rectangle.cpp \
        glwindow.cpp \
        main.cpp \
        math/vector.cpp

HEADERS += \
    ents/circle.h \
    ents/rectangle.h \
    ents/baseentity.h \
    math/vector.h \
    entity_list.h \
    glwindow.h
