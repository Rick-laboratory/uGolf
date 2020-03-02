#include "UART_Serial.h"
#include <iostream>

UART_Serial::UART_Serial()
{
	std::cout <<  "ich wurde erstellt\n";
	if (!uart_open("/dev/ttyS0", B9600, 0)) 
		std::cout << "error\n";
}


UART_Serial::~UART_Serial()
{
	close(uartFd);
	std::cout << "ich wurde geloescht\n";

}

int UART_Serial::set_interface_attribs(int fd, int speed, int parity)
{
	struct termios tty;
	memset(&tty, 0, sizeof tty);
	if (tcgetattr(fd, &tty) != 0)
	{
		fprintf(stderr, "error %d from tcgetattr", errno);
		return -1;
	}

	cfsetospeed(&tty, speed);
	cfsetispeed(&tty, speed);

	tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;    // 8-bit chars
	// disable IGNBRK for mismatched speed tests, otherwise receive break
	// as \000 chars
	tty.c_iflag &= ~IGNBRK;    					// disable break processing
	tty.c_lflag = 0;    						// no signaling chars, no echo, no canonical processing
	tty.c_oflag = 0;    						// no remapping, no delays
	tty.c_cc[VMIN]  = 0;    					// read doesn't block
	tty.c_cc[VTIME] = 5;    					// 0.5 seconds read timeout
	tty.c_iflag &= ~(IXON | IXOFF | IXANY);     // shut off xon/xoff ctr
	tty.c_cflag |= (CLOCAL | CREAD);    		// ignore modem controls, enable reading
	tty.c_cflag &= ~(PARENB | PARODD);    		// shut off parity
	tty.c_cflag |= parity;
	tty.c_cflag &= ~CSTOPB;
	tty.c_cflag &= ~CRTSCTS;

	if (tcsetattr(fd, TCSANOW, &tty) != 0)
	{
		fprintf(stderr, "error %d from tcsetattr", errno);
		return -1;
	}
	return 0;
}

void UART_Serial::set_blocking(int fd, int should_block)
{
	struct termios tty;
	memset(&tty, 0, sizeof tty);
	if (tcgetattr(fd, &tty) != 0)
	{
		fprintf(stderr, "error %d from tggetattr", errno);
		return;
	}

	tty.c_cc[VMIN]  = should_block ? 1 : 0;
	tty.c_cc[VTIME] = 5;    					// 0.5 seconds read timeout

	if(tcsetattr(fd, TCSANOW, &tty) != 0)
	        fprintf(stderr, "error %d setting term attributes", errno);
}

void UART_Serial::uart_writestr(const char* string) {
	write(uartFd, string, strlen(string));
}	

void UART_Serial::uart_write(void* data, size_t len) {
	write(uartFd, data, len); 
}

ssize_t UART_Serial::uart_read(void* buffer, size_t charsToRead) {
	return read(uartFd, buffer, charsToRead); 
}

int UART_Serial::uart_open(const char* port, int baud, int blocking) {
	uartFd = open(port, O_RDWR | O_NOCTTY | O_SYNC);
	
	if (uartFd < 0)
	{
		fprintf(stderr, "error %d opening %s: %s", errno, port, strerror(errno));
		return -1;
	}
	
	set_interface_attribs(uartFd, baud, 0);    	// set speed, 8n1 (no parity)
	set_blocking(uartFd, blocking);    			//set blocking mode
	//printf("Port %s opened.\n", port); 
	return 1;
}
