#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include "DataManager.h"
#include "SerialManager.h"
#include <QMessageBox>
#include <QDebug>
#include <iostream>
#include <string>
struct CountData
{
	int ReferenceCount = 0;
	int IndexCount = 0;
};

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT
		
public :

    explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
	protected slots :
	void on_AqcuireInitialPosition_clicked();
	void on_AqcuireTargetPosition_clicked();
	void on_AqcuireCurrentBallPosition_clicked();
	void on_FinishedHole_clicked();
	
private:
	Ui::MainWindow *ui;
	int ReferenceCount = 0;
	int IndexCount = 0;
	DataManager DataManagerObject;
	//SerialManager SerialManagerObject;
	//SerialManager SerialManagerObject;
};

#endif // MAINWINDOW_H
