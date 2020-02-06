#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
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
	ui->FinishedHole->setEnabled(false);
	if (fexists("Ref.Source"))
	{
		ReferenceCount = DataManagerObject.IntParseReferenceFile("Ref.Source");
	}else
	{
		DataManagerObject.SaveReferenceFirst(ReferenceCount);
	}
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_AqcuireInitialPosition_clicked()
{	
	ui->AqcuireInitialPosition->setEnabled(false);
	TempGPS = FilterObject.return_GNGLL();
	TempQstr = QString::fromStdString(TempGPS);
	ui->textBrowser->append(TempQstr);
	setReferenceUp();
	setIndexUp();
	DataManagerObject.SaveData("#Initial", ReferenceCount, IndexCount, TempGPS, ui->comboBox->currentText());
}

void MainWindow::on_AqcuireTargetPosition_clicked()
{
	ui->AqcuireTargetPosition->setEnabled(false);
	ui->FinishedHole->setEnabled(true);
	TempGPS = FilterObject.return_GNGLL();
	TempFinish = TempGPS;
	TempQstr = QString::fromStdString(TempGPS);
	ui->textBrowser->append(TempQstr);
	setIndexUp();
	DataManagerObject.SaveData("#Target", ReferenceCount, IndexCount, TempGPS, ui->comboBox->currentText());
}

void MainWindow::on_AqcuireCurrentBallPosition_clicked()
{
	ui->AqcuireCurrentBallPosition->setEnabled(false);
	TempGPS = FilterObject.return_GNGLL();
	TempQstr = QString::fromStdString(TempGPS);
	ui->textBrowser->append(TempQstr);
	setIndexUp();
	DataManagerObject.SaveData("#Followup", ReferenceCount, IndexCount, TempGPS, ui->comboBox->currentText());
	ui->AqcuireCurrentBallPosition->setEnabled(true);
}

void MainWindow::on_FinishedHole_clicked()
{
	ui->FinishedHole->setEnabled(false);
	ui->textBrowser->append("Finished");
	setIndexUp();
	DataManagerObject.SaveData("#Finished", ReferenceCount, IndexCount, TempFinish, ui->comboBox->currentText());
	char const * const path = "Ref.Source";
	DataManagerObject.RemoveLine(path, 2);
	DataManagerObject.SaveReference(ReferenceCount);
	ui->AqcuireInitialPosition->setEnabled(true);
	ui->AqcuireTargetPosition->setEnabled(true);
	ui->FinishedHole->setEnabled(true);
	IndexCount = 0;
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
