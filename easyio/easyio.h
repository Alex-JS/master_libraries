#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <list>
#include <vector>
#include <map>

#define STRING_UNINITIALIZED "nosep"



class FileManip{
public:
	static std::vector<std::vector<std::string> > read(std::string filename, std::string separator = STRING_UNINITIALIZED);
	static std::vector<std::string> divide(std::string myString, std::string separator);
};

class DataManip{
public:
	static std::vector<std::vector<double> > stringToDouble(std::vector<std::vector<std::string> > stringVector);
	static double stringToDouble(std::string s);
	static std::vector<double> getColumn(std::vector<std::vector<double> > doubleVector, int col);
	static std::vector<std::vector<double> > getColumns(std::vector<std::vector<double> > doubleVector, std::vector<int> cols);
	
	static std::map<std::string,double> readVariableFile(std::string fileName){
		std::vector<std::vector<std::string> > rawData = FileManip::read(fileName);
		std::map<std::string,double>  processedData;
		for (int i=0; i<rawData.size(); i++){
			processedData.insert(std::pair<std::string,double>(rawData[i][0],atof(rawData[i][1].c_str())));
		}
		return processedData;
	}

	static void fillVariable(double &var, std::string varname, std::map<std::string,double> varfilecontents){
		var = varfilecontents[varname];
	}

	static void fillVariable(int &var, std::string varname, std::map<std::string,double> varfilecontents){
		var = (int)varfilecontents[varname];
	}
};


class PrintOut{
public:
	static void screen(std::vector<std::string> myVector, std::string separator="\n");
	static void toFile(std::vector<std::vector<double> > myVector, std::string fileName, std::string seperator=",");
	static void toFile(std::vector<double> myVector, std::string fileName, std::string separator=",");
	static void toFile(std::vector<std::vector<std::vector<double> > > myVector, std::string fileName, std::string separator=",");
};
