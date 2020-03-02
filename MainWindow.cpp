#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <iostream>
#include "UART_Serial.h"
#include "UART_Message_Filter.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	ui->comboBox->addItem("E4");
	ui->comboBox->addItem("E5");
	ui->comboBox->addItem("E6");
	ui->comboBox->addItem("E7");
	ui->comboBox->addItem("E8");
	ui->comboBox->addItem("E9");
	ui->comboBox->addItem("PW");
	ui->comboBox->addItem("A");
	ui->comboBox->addItem("W52");
	ui->comboBox->addItem("W56");
	ui->comboBox->addItem("LW");
	ui->comboBox->addItem("H4");
	ui->comboBox->addItem("W3");
	ui->comboBox->addItem("W5");
	ui->comboBox->addItem("D10,5");
	ui->comboBox->addItem("D12,5");
	ui->AqcuireInitialPosition->setEnabled(false);
	ui->AqcuireCurrentBallPosition->setEnabled(false);
	ui->FinishedHole->setEnabled(false);
	if (fexists("Ref.Source"))
	{
		ReferenceCount = Save_System_Object.IntParseReferenceFile("Ref.Source");
	}
	else
	{
		Save_System_Object.SaveReferenceFirst(ReferenceCount);
	}
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_AqcuireInitialPosition_clicked()
{	
	ui->AqcuireInitialPosition->setEnabled(false);
	TempGPS = UART_Message_Filter_Object.return_GNGLL(UART_Serial_Object);
	TempQstr = QString::fromStdString(TempGPS);
	ui->textBrowser->append(TempQstr + "Club:" + ui->comboBox->currentText());
	setReferenceUp();
	setIndexUp();
	MW_Laenge = TempGPS.substr(7, 10);
	MW_Breite = TempGPS.substr(20, 11);
	MW_Tee.Laenge = GPS_Distance_Calculator_Object.Grad_DM_To_DGrad(MW_Laenge);
	MW_Tee.Breite = GPS_Distance_Calculator_Object.Grad_DM_To_DGrad(MW_Breite);
	GPS_Distance_Calculator_Object.Abstand_Laengengrad(MW_Tee.Breite);
	MW_DistanceStrike.Tee_TargetLine = GPS_Distance_Calculator_Object.Distantace_Tee_Ball(MW_Tee, MW_Target);
	TempQstr2 = QString::number(MW_DistanceStrike.Tee_TargetLine);
	ui->textBrowser->append("Abstand der Initialposition zum Ziel in m: " + TempQstr2 + "\n\n");
	Save_System_Object.SaveData("#Initial", ReferenceCount, IndexCount, TempGPS, ui->comboBox->currentText(),TempQstr2);
	ui->AqcuireCurrentBallPosition->setEnabled(true);
	ui->FinishedHole->setEnabled(true);
}

void MainWindow::on_AqcuireTargetPosition_clicked()
{
	ui->AqcuireTargetPosition->setEnabled(false);
	TempGPS = UART_Message_Filter_Object.return_GNGLL(UART_Serial_Object);
	TempFinish = TempGPS;
	TempQstr = QString::fromStdString(TempGPS);
	ui->textBrowser->append(TempQstr);
	setIndexUp();
	Save_System_Object.SaveData("#Target", ReferenceCount, IndexCount, TempGPS, ui->comboBox->currentText());
	MW_Laenge = TempGPS.substr(7, 10);
	MW_Breite = TempGPS.substr(20, 11);
	MW_Target.Laenge = GPS_Distance_Calculator_Object.Grad_DM_To_DGrad(MW_Laenge);
	MW_Target.Breite = GPS_Distance_Calculator_Object.Grad_DM_To_DGrad(MW_Breite);
	ui->AqcuireInitialPosition->setEnabled(true);
}

void MainWindow::on_AqcuireCurrentBallPosition_clicked()
{
	ui->AqcuireCurrentBallPosition->setEnabled(false);
	TempGPS = UART_Message_Filter_Object.return_GNGLL(UART_Serial_Object);
	TempQstr = QString::fromStdString(TempGPS);
	ui->textBrowser->append(TempQstr + "Club:" + ui->comboBox->currentText());
	setIndexUp();
	MW_Laenge = TempGPS.substr(7, 10);
	MW_Breite = TempGPS.substr(20, 11);
    MW_Ball.Laenge = GPS_Distance_Calculator_Object.Grad_DM_To_DGrad(MW_Laenge);
    MW_Ball.Breite = GPS_Distance_Calculator_Object.Grad_DM_To_DGrad(MW_Breite);
    MW_DistanceStrike.Tee_Ball = GPS_Distance_Calculator_Object.Distantace_Tee_Ball(MW_Tee, MW_Ball);
    MW_DistanceStrike.TargetLine_Ball = GPS_Distance_Calculator_Object.Distantace_Tee_Ball(MW_Ball,MW_Target);
	TempQstr2 = QString::number(MW_DistanceStrike.TargetLine_Ball);
	ui->textBrowser->append("Abstand der Ballposition zum Ziel in m: " + TempQstr2);
	MW_Lotpunkt = GPS_Distance_Calculator_Object.Lot_Punkt_bestimmen(MW_Tee, MW_Target, MW_Ball);
	MW_DistanceStrike.TargetLine_Ball = GPS_Distance_Calculator_Object.Distantace_Tee_Ball(MW_Lotpunkt, MW_Ball);
	TempQstr3 = QString::number(MW_DistanceStrike.TargetLine_Ball);
	ui->textBrowser->append("Abstand TargetLine_Ball[Lotpunkt] in m: " + TempQstr3);
	MW_DistanceStrike.TargetLine_Ball = GPS_Distance_Calculator_Object.Distantace_Tee_Ball(MW_Lotpunkt, MW_Target);
	TempQstr4 = QString::number(MW_DistanceStrike.TargetLine_Ball);
	ui->textBrowser->append("Abstand Tee_TargetLine[Lotpunkt] in m: " + TempQstr4 + "\n\n");
	MW_Tee = MW_Ball;
	Save_System_Object.SaveData("#Followup", ReferenceCount, IndexCount, TempGPS, ui->comboBox->currentText(),TempQstr2,TempQstr3,TempQstr4);
	ui->AqcuireCurrentBallPosition->setEnabled(true);
}

void MainWindow::on_FinishedHole_clicked()
{
	ui->FinishedHole->setEnabled(false);
	ui->AqcuireCurrentBallPosition->setEnabled(false);
	MW_DistanceStrike.Tee_TargetLine = GPS_Distance_Calculator_Object.Distantace_Tee_Ball(MW_Tee, MW_Target);
	TempQstr2 = QString::number(MW_DistanceStrike.Tee_TargetLine);
	ui->textBrowser->append("Finished, mit einer Distanz von "+TempQstr2+"m zum letzten Abschlagspunkt\n\n" );

	setIndexUp();
	Save_System_Object.SaveData("#Finished", ReferenceCount, IndexCount, TempFinish, ui->comboBox->currentText());
	char const * const path = "Ref.Source";
	Save_System_Object.RemoveLine(path, 2);
	Save_System_Object.SaveReference(ReferenceCount);
	ui->AqcuireTargetPosition->setEnabled(true);
	IndexCount = 0;
	UIFinishedCount++;
	if (UIFinishedCount > 2)
	{
		ui->textBrowser->clear();
		ui->textBrowser->clearHistory();
		UIFinishedCount = 0;
	}
}

void MainWindow::setIndexUp()
{
	IndexCount++;
}


int MainWindow::getIndexCount()
{
	return IndexCount;
}


void MainWindow::setReferenceUp()
{
	ReferenceCount++;
}


int MainWindow::getReferenceCount()
{
	return ReferenceCount;
}
