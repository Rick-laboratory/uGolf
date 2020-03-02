#pragma once
#include "UART_Serial.h"
#include <string>
#include <iostream>
class UART_Message_Filter
{
public:
	UART_Message_Filter();
	~UART_Message_Filter();
	std::string return_GNGGA(UART_Serial &USO_Ref);
	std::string return_GNGLL(UART_Serial &USO_Ref);
	

private:
	std::string uart_collectGGA(UART_Serial &USO_Ref);
	std::string uart_collectGLL(UART_Serial &USO_Ref);
};

