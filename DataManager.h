#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
struct StringData
{
	std::string IndexSource;
	std::string ReferenceSource;
};
class DataManager
{
public:
	DataManager();
	~DataManager();
	StringData ParseReferenceFile(char const* const SourceFile);
	int CountLines(char const* const SourceFile);
	void RemoveLine(char const* const SourceFile, const int Line);
	void SaveData();
private:
	
};
