#Generated by VisualGDB project wizard. 
#Feel free to modify any flags you want.
#Visit http://visualgdb.com/makefiles for more details.

QT       += core gui serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = uGolf
TEMPLATE = app

#By default the following file lists are updated automatically by VisualGDB.

SOURCES   += DataManager.cpp SerialManager.cpp uGolf.cpp MainWindow.cpp
HEADERS   += blocking_reader.h SerialManager.h DataManager.h MainWindow.h
FORMS     += MainWindow.ui
RESOURCES += 

include($$lower($$join(CONFIGNAME,,,.pro)))

QMAKE_CFLAGS 	+= $$COMMONFLAGS
QMAKE_CXXFLAGS 	+= $$COMMONFLAGS
QMAKE_LFLAGS 	+= $$COMMONFLAGS

OBJECTS_DIR = $$DESTDIR
MOC_DIR     = $$DESTDIR
RCC_DIR     = $$DESTDIR
UI_DIR      = $$DESTDIR
