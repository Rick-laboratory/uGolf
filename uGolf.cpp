#include "MainWindow.h"
#include <QApplication>
#include <boost/asio/serial_port.hpp>
#include <boost/asio.hpp>
#include "blocking_reader.h"
#include <iostream>
#include <QtSerialPort/QSerialPort>
#include <unistd.h>				//Needed for I2C port
#include <fcntl.h>				//Needed for I2C port
#include <sys/ioctl.h>			//Needed for I2C port
#include <linux/i2c-dev.h>		//Needed for I2C port

int main(int argc, char *argv[])
{
//	int file_i2c;
//	int length;
//	unsigned char buffer[64] = { 0 };
//
//	char *filename = (char*)"/dev/i2c-1";
//	if ((file_i2c = open(filename, O_RDWR)) < 0)
//	{
//		//ERROR HANDLING: you can check errno to see what went wrong
//		printf("Failed to open the i2c bus");
//	}
//	int addr = 0x42;           //<<<<<The I2C address of the slave
//	if(ioctl(file_i2c, I2C_SLAVE, addr) < 0)
//	{
//		printf("Failed to acquire bus access and/or talk to slave.\n");
//		//ERROR HANDLING; you can check errno to see what went wrong
//	}
//	length = 60; 			//<<< Number of bytes to read
//	while(true)
//	{
//		if (read(file_i2c, buffer, length) != length)		//read() returns the number of bytes actually read, if it doesn't match then an error occurred (e.g. no response from the device)
//			{
//				//ERROR HANDLING: i2c transaction failed
//				printf("Failed to read from the i2c bus.\n");
//			}
//		else
//		{
//			printf("%s\n", buffer);
//		}
//	}

    QApplication a(argc, argv);
    MainWindow w; 
	std::cout << sizeof(w) << "\t "<< std::flush;
    w.show();
    
    return a.exec();
}
