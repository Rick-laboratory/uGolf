#pragma once
#include "SerialManager.h"
class Filter
{
public:
	Filter();
	~Filter();

	const std::string return_GNGGA();
	const std::string uart_collectGGA();
	const std::string return_GNGLL();
	const std::string uart_collectGLL();
private:
	
};
