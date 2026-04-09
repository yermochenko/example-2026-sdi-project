#include "CsvWriter.h"

#include "..\util\joiner.h"

CsvWriter::CsvWriter(std::string filename, bool append)
{
	if (append)
	{
		fout.open(filename, std::ios::app);
	}
	else
	{
		fout.open(filename);
	}
	if (!fout.is_open())
	{
		throw "File \"" + filename + "\" can't be written";
	}
}

void CsvWriter::writeLine(std::vector<std::string>* row)
{
	fout << join(*row, ";") << std::endl;
}

void CsvWriter::close()
{
	fout.close();
}

CsvWriter::~CsvWriter()
{
	fout.close();
}
