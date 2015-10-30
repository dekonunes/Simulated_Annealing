#include "ParserCSV.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

CsvFile::CsvFile(const char *file, char delim, int startLine) {
	info = readCSV(file, delim, startLine);
}

CsvFile::~CsvFile() {}

vector< vector<std::string> > CsvFile::readCSV( const char *file, char delim, int startLine )
{
	vector< vector<std::string> > matrixStrings;
	vector<std::string> lineStrings;
	std::string tempLine;
    int lineCounter = 1;
    int infoCounter = 0;

	ifstream csvFile(file);
	if(csvFile.is_open())
	{
		while( getline(csvFile,tempLine) )
		{
			if(lineCounter >= startLine)
			{
                const char* str = tempLine.c_str();
                lineStrings = splitString( str, delim );
                if(infoCounter==1)
					this->columns = (int) lineStrings.size();
				matrixStrings.push_back(lineStrings);
				infoCounter++;
			} else
                lineCounter++;
		}
			csvFile.close();
	} else
		cerr << "Unable to open CSV file." << endl;

	this->lines = infoCounter;
	return matrixStrings;
}

void CsvFile::show()
{
	for(unsigned int i=0; i < info.size(); i++)
	{
		for(unsigned int j=0; j < info[i].size(); j++)
			cout << info[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

vector<string> CsvFile::splitString( const char *str, char c )
{
    vector<string> result;
    do
    {
        const char *begin = str;

        while(*str != c && *str)
            str++;

        result.push_back(string(begin, str));
    } while (0 != *str++);
    return result;
}

std::vector<int> CsvFile::splitStringToInt( const char *str, char c )
{
    vector<int> result;
    do
    {
        const char *begin = str;

        while(*str != c && *str)
            str++;

        result.push_back(atoi(string(begin, str).c_str()) );
    } while (0 != *str++);
    return result;
}
