#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include "DataManager.h"
#include "Filter.h"
#include <QMessageBox>
#include <QDebug>
#include <iostream>
#include <string>
#include <fstream>

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
	void setIndexUp();
	int getIndexCount();
	void setReferenceUp();
	int getReferenceCount();
	bool fexists(const std::string& filename) {
		std::ifstream ifile(filename.c_str());
		return (bool)ifile;
	}
	
	
private:
	Ui::MainWindow *ui;
	int ReferenceCount = 0;
	int IndexCount = 0;
	DataManager DataManagerObject;
	Filter FilterObject;
	//SerialManager SerialManagerObject;
	std::string TempGPS;
	std::string TempFinish;
	QString TempQstr;
};

#endif // MAINWINDOW_H