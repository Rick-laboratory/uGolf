#include "UART_Message_Filter.h"

UART_Message_Filter::UART_Message_Filter()
{
}

UART_Message_Filter::~UART_Message_Filter()
{
}


std::string UART_Message_Filter::return_GNGLL(UART_Serial &USO_Ref)
{
	std::string GNGGA;
	do
	{ 
		GNGGA = uart_collectGLL(USO_Ref);
	} while (GNGGA.find("$GNGLL"));
	return GNGGA;
}

std::string UART_Message_Filter::uart_collectGLL(UART_Serial &USO_Ref) // Collects the buffer until \n appears
{
	bool control = true;
	std::string data = "";
	char Buffer;
	while (control)
	{
		USO_Ref.uart_read(&Buffer, 1);
		
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
		return data;
	}
	else
	{
		data = "not usefull\n";
		return data;
	}
}

std::string UART_Message_Filter::return_GNGGA(UART_Serial &USO_Ref)
{
	std::string GNGGA;
	do
	{ 
		GNGGA = uart_collectGGA(USO_Ref);
	} while (GNGGA.find("$GNGGA"));
	return GNGGA;
}

std::string UART_Message_Filter::uart_collectGGA(UART_Serial &USO_Ref) // Collects the buffer until \n appears
{
	if (!USO_Ref.uart_open("/dev/ttyS0", B9600, 0)) 
		std::cout << "error";
	
	bool control = true;
	std::string data = "";
	char Buffer;
	while (control)
	{
		USO_Ref.uart_read(&Buffer, 1);
		
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
		return data;
	}
	else
	{
		data = "not usefull\n";
		return data;
	}
}
