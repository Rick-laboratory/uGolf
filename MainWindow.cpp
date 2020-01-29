#include "MainWindow.h"
#include "ui_MainWindow.h"


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
	
	
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_AqcuireInitialPosition_clicked()
{
	char Buffer = { 0 };
	std::string tmp;
	if (!Serial::uart_open("/dev/ttyS0", B9600, 0)) 
		std::cout << "error";
	
	while (true)
	{
		Serial::uart_read(&Buffer, 60);
		std::cout << Buffer << std::flush;
	}
}

void MainWindow::on_AqcuireTargetPosition_clicked()
{
	//defines a constant path for the data Index Reference Storage
	char const * const path = "data.IRS";
	DataManagerObject.RemoveLine(path, 1);
}

void MainWindow::on_AqcuireCurrentBallPosition_clicked()
{
	// initialises a Struct with index and reference data
	StringData data = DataManagerObject.ParseReferenceFile("data.IRS");
	qDebug() << QString::fromStdString(data.IndexSource) + " " + QString::fromStdString(data.ReferenceSource);
}

void MainWindow::on_FinishedHole_clicked()
{
	DataManagerObject.SaveData();
}