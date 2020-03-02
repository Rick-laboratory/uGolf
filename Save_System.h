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
class Save_System
{
public:
	Save_System();
	~Save_System();
	StringData ParseReferenceFile(char const* const SourceFile);
	int IntParseReferenceFile(char const * const SourceFile);
	int CountLines(char const* const SourceFile);
	void RemoveLine(char const* const SourceFile, const int Line);
	void SaveData(std::string type, int ref, int index, std::string gps, QString combobox);
	void SaveData(std::string type, int ref, int index, std::string gps, QString combobox, QString TempQstr1);
	void SaveData(std::string type, int ref, int index, std::string gps, QString combobox, QString TempQstr1, QString TempQstr2, QString TempQstr3);
	void SaveReference(int ReferenceCount);
	void SaveReferenceFirst(int ReferenceCount);
private:				
};

