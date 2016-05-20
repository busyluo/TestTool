TEMPLATE = app

QT += qml quick
CONFIG += c++11

PRECOMPILED_HEADER = utils.h

SOURCES += main.cpp \
    ViewModels/treeviewmodel.cpp \
    Models/testmachine.cpp \
    Models/testunit.cpp \
    Models/testitem.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    ViewModels/treeviewmodel.h \
    Models/testmachine.h \
    Models/testunit.h \
    Models/testitem.h \
    utils.h

