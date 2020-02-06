#include "Filter.h"
Filter::Filter()
{
}

Filter::~Filter()
{
}

const std::string Filter::return_GNGLL()
{
	std::string GNGGA;
	do
	{ 
		GNGGA = uart_collectGLL();
	} while (GNGGA.find("$GNGLL"));
	return GNGGA;
}
const std::string Filter::uart_collectGLL() // Collects the buffer until \n appears
{
	if (!Serial::uart_open("/dev/ttyS0", B9600, 0)) 
		std::cout << "error";
	
	bool control = true;
	std::string data = "";
	char Buffer;
	while (control)
	{
		Serial::uart_read(&Buffer, 1);
		
		if (Buffer == '\n')
		{
			data += Buffer;
			control = !control;
		}
		else
		{
			data += Buffer;
		}
	}
	if (!data.find("$GNGLL"))
	{
		close(uartFd);
		return data;
	}
	else
	{
		data = "not usefull\n";
		close(uartFd);
		return data;
	}
}
const std::string Filter::return_GNGGA()
{
	std::string GNGGA;
	do
	{ 
		GNGGA = uart_collectGGA();
	} while (GNGGA.find("$GNGGA"));
	return GNGGA;
}
const std::string Filter::uart_collectGGA() // Collects the buffer until \n appears
{
	if (!Serial::uart_open("/dev/ttyS0", B9600, 0)) 
		std::cout << "error";
	
	bool control = true;
	std::string data = "";
	char Buffer;
	while (control)
	{
		Serial::uart_read(&Buffer, 1);
		
		if (Buffer == '\n')
		{
			data += Buffer;
			control = !control;
		}
		else
		{
			data += Buffer;
		}
	}
	if (!data.find("$GNGGA"))
	{
		close(uartFd);
		return data;
	}
	else
	{
		data = "not usefull\n";
		close(uartFd);
		return data;
	}
}