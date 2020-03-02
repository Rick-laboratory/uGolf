#pragma once
#include <errno.h>
#include <fcntl.h> 
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
class UART_Serial
{
public:
	UART_Serial();
	~UART_Serial();
	int set_interface_attribs(int fd, int speed, int parity);
	void set_blocking(int fd, int should_block);
	void uart_writestr(const char* string);
	void uart_write(void* data, size_t len);
	ssize_t uart_read(void* buffer, size_t charsToRead);
	int uart_open(const char* port, int baud, int blocking);
private:
	int uartFd = -1; 

};
