#include "DataManager.h"

DataManager::DataManager()
{
}

DataManager::~DataManager()
{
}

int DataManager::IntParseReferenceFile(char const * const SourceFile)
{
	std::ifstream stream(SourceFile);
	std::string line;
	std::stringstream ss;
	int iRefCount;
	while (getline(stream,line))
	{
		if (line.find("#Reference") != std::string::npos)
		{
		}
		else
		{
			iRefCount = std::stoi(line);
		}
	}
	return iRefCount;
}

StringData DataManager::ParseReferenceFile(char const* const SourceFile)
{
	std::ifstream stream(SourceFile);
	
	std::string line;
	std::stringstream ss[2];
	
	enum class DataType
	{
		NONE      = -1,
		INDEX     = 0,
		REFERENCE = 1
	};
	DataType type = DataType::NONE;
	while (getline(stream, line))
	{
		if (line.find("#InitData") != std::string::npos)
		{
			if (line.find("Index") != std::string::npos)
				type = DataType::INDEX;
			else if (line.find("Reference") != std::string::npos)
				type = DataType::REFERENCE;
		}
		else
		{
			ss[(int)type] << line;
		}
	}
	
	return { ss[0].str(), ss[1].str() };
}

int DataManager::CountLines(char const* const SourceFile)
{
	std::ifstream InFile;
	InFile.open(SourceFile, std::ios::in);
	char data[100];
	int Line = 0;
	while (InFile.getline(data, 100)) Line++;
	
	return Line;
}

void DataManager::RemoveLine(char const* const SourceFile, const int Line)
{
	std::ifstream InFile;
	char tempPath[100] = "tempfile.txt";
	InFile.open(SourceFile, std::ios::in);
	if (InFile)
	{
		int numLine = CountLines(SourceFile);
		if (numLine < Line)
		{
			std::cerr << "\n no line to delete\n";
			
			return;
		}
		std::ofstream outfile;
		outfile.open(tempPath, std::ios::out);
		char data[100];
		int i = 0;
		while (InFile.getline(data, 100))
		{
			i++;
			if (i == Line) continue;
			outfile << data << "\n";
		}
		outfile.close();
	}
	InFile.close();
	remove(SourceFile);
	rename(tempPath, SourceFile);
}



void DataManager::SaveData(std::string type, int ref, int index,std::string gps,QString combobox)
{
	std::string temp = combobox.toUtf8().constData();
	std::ostringstream StringStream;
	StringStream << "#Reference\n" << ref << "\n" << "#Index\n" << index << "\n" << type << "\n" << gps << "#Club\n" << temp << "\n";
	std::fstream H_target("Dat.Source", std::ios::app);   //appends data into the data.IRS file
	H_target << StringStream.str();
	H_target.close();
}


void DataManager::SaveReference(int ReferenceCount)
{
	std::ostringstream oss;
	oss << ReferenceCount;
	std::fstream SourceFile("Ref.Source", std::ios::app);
	SourceFile << oss.str();
	SourceFile.close();
}

void DataManager::SaveReferenceFirst(int ReferenceCount)
{
	std::ostringstream oss;
	oss << "#Reference\n"<< ReferenceCount;
	std::fstream SourceFile("Ref.Source", std::ios::app);
	SourceFile << oss.str();
	SourceFile.close();
}