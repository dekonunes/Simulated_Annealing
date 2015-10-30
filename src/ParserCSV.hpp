/*
 * Read a generic CSV file
 */

#ifndef _PARSER_CSV_HPP_
#define _PARSER_CSV_HPP_

#include <string>
#include <vector>

class CsvFile {
public:
	std::vector< std::vector<std::string> > info;
	int lines;
	int columns;

	CsvFile(const char *file, char delim=';', int startLine=1);
	~CsvFile();
	
	// read CSV file
	std::vector< std::vector<std::string> > readCSV( const char *file, char delim=';', int startLine=1 );
	
	 // shows a string matrix
	void show();
	
	// auxiliary methods
	std::vector<std::string> splitString( const char *str, char c );
	std::vector<int> splitStringToInt( const char *str, char c );
	//std::vector<int> splitStringToFloat( const char *str, char c );
};

#endif
