#pragma once
#include <errno.h>
#include <fcntl.h> 
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
static int uartFd = -1; 
struct Serial
{
	static int set_interface_attribs(int fd, int speed, int parity);
	static void set_blocking(int fd, int should_block);
	static void uart_writestr(const char* string);
	static void uart_write(void* data, size_t len);
	static ssize_t uart_read(void* buffer, size_t charsToRead);
	static int uart_open(const char* port, int baud, int blocking);
	static const std::string uart_collect();
	static const std::string return_GNGGA();
	//static DataTuple test(std::string text);
};
