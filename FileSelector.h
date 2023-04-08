#pragma once
#include <string>

class FileSelector
{
public:
	bool OpenFile();

	std::string GetSelectedFile() { return m_SelectedFile; };
	std::string GetFilePath() { return m_FilePath; };

	FileSelector() = default;
	~FileSelector() = default;
	FileSelector(const FileSelector& other) = default;
	FileSelector(FileSelector&& other) = default;
	FileSelector& operator=(const FileSelector& other) = default;
	FileSelector& operator=(FileSelector&& other) = default;

private:
	std::string m_SelectedFile;
	std::string m_FilePath;
};

