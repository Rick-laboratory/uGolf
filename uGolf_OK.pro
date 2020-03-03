#Generated by VisualGDB project wizard. 
#Feel free to modify any flags you want.
#Visit http://visualgdb.com/makefiles for more details.

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = uGolf_OK
TEMPLATE = app

#By default the following file lists are updated automatically by VisualGDB.

SOURCES   += GPS_Distance_Calculator.cpp Save_System.cpp UART_Message_Filter.cpp UART_Serial.cpp uGolf_OK.cpp MainWindow.cpp
HEADERS   += GPS_Distance_Calculator.h Save_System.h UART_Message_Filter.h UART_Serial.h MainWindow.h
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