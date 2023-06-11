#include "pch.h"
#include "FileReader.h"

FileReader::FileReader(std::string filePath)
	:m_InputStream{filePath.data(), std::ios::in | std::ios::binary|std::ios::ate}
{
}

char* FileReader::ReadFile(int& dataSize)
{
    std::streampos size = m_InputStream.tellg();
    dataSize = size;
    char* data = new char[size];
    m_InputStream.seekg(0, std::ios::beg);
    m_InputStream.read(data, size);
    return data;
}

FileReader::~FileReader()
{
	m_InputStream.close();
}

