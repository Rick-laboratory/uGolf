#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "UART_Serial.h"
#include "UART_Message_Filter.h"
#include "GPS_Distance_Calculator.h"
#include "Save_System.h"
#include <QMessageBox>
#include <QDebug>
#include <fstream>
#include <string>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected slots:
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
	int UIFinishedCount = 0;
	int ReferenceCount = 0;
	int IndexCount = 0;
	UART_Serial UART_Serial_Object;
	UART_Message_Filter UART_Message_Filter_Object;
	GPS_Distance_Calculator GPS_Distance_Calculator_Object;
	Save_System Save_System_Object;
	std::string MW_Laenge, MW_Breite;
	double MW_Current_Laenge, MW_Current_Breite;
	std::string TempGPS;
	std::string TempFinish;
	QString TempQstr, TempQstr2, TempQstr3, TempQstr4;
	
	Distance_Shot MW_DistanceStrike;
	GPS_Data MW_Tee, MW_Target, MW_Ball, MW_Lotpunkt;
	
	
};

#endif // MAINWINDOW_H
