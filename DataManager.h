#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <QString>
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
	int IntParseReferenceFile(char const * const SourceFile);
	int CountLines(char const* const SourceFile);
	void RemoveLine(char const* const SourceFile, const int Line);
	void SaveData(std::string type, int ref, int index, std::string gps, QString combobox);
	void SaveReference(int ReferenceCount);
	void SaveReferenceFirst(int ReferenceCount);
private:
	
};
