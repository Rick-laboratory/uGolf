#include "MainWindow.h"
#include <QApplication>
#include <iostream>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
	std::cout << sizeof(w) << "\t " << std::flush;
    w.show();
    
    return a.exec();
}
