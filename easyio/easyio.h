#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <list>
#include <vector>

#define STRING_UNINITIALIZED "nosep"


class DataManip{
public:
	static std::vector<std::vector<double> > stringToDouble(std::vector<std::vector<std::string> > stringVector);
	static double stringToDouble(std::string s);
	static std::vector<double> getColumn(std::vector<std::vector<double> > doubleVector, int col);
	static std::vector<std::vector<double> > getColumns(std::vector<std::vector<double> > doubleVector, std::vector<int> cols);
};

class FileManip{
public:
	static std::vector<std::vector<std::string> > read(std::string filename, std::string separator = STRING_UNINITIALIZED);
	static std::vector<std::string> divide(std::string myString, std::string separator);
};

class PrintOut{
public:
	static void screen(std::vector<std::string> myVector, std::string separator="\n");
	static void toFile(std::vector<std::vector<double> > myVector, std::string fileName, std::string seperator=",");
	static void toFile(std::vector<double> myVector, std::string fileName, std::string separator=",");
};

/*std::string ftoa(double tochange);
void stripFilePath(std::string *filename);
void stripFilePaths(std::list<std::string> *filenames);
void stripExtension(std::string *filename);
void stripExtensions(std::list<std::string> *filenames);
void removeExcept(std::string extensionDesired, std::list<std::string> *filenames);
std::list<std::string> importlist(std::string filename);
void exportlist(std::string filename, std::list<std::string> listContents);
std::vector<std::vector<std::string> > importxls(std::string filename);
std::vector<std::vector<std::string> > importcsv(std::string filename, std::string startphrase="", std::string endphrase="");
std::vector<std::vector<std::string> > importconfigfile(std::string filename);
void exportcsv(std::vector<std::vector<std::string> > filematrix, std::string filename="unnamed-from-program.csv",std::string separator=",");
bool getYesNo(std::string);
bool scrapeMatrixForVariable(std::vector<std::vector<std::string> > &varMatrix, std::string varName, double &varVal);
bool scrapeMatrixForVariable(std::vector<std::vector<std::string> > &varMatrix, std::string varName, int &varVal);
bool scrapeMatrixForVariable(std::vector<std::vector<std::string> > &varMatrix, std::string varName, std::string &varVal);*/