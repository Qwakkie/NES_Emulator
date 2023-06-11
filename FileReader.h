#pragma once
#include <fstream>

class FileReader
{
public:
	FileReader(std::string filePath);
	
	char* ReadFile(int& dataSize);

	~FileReader();
	FileReader(const FileReader& other) = delete;
	FileReader(FileReader&& other) = delete;
	FileReader& operator=(const FileReader& other) = delete;
	FileReader& operator=(FileReader&& other) = delete;
private:
	std::ifstream m_InputStream;
};

