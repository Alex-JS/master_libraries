#pragma once

#include "easyio.h"

using namespace std;

vector<string> FileManip::divide(string myString, string separator){
	//----- Divides a string at the points of 'separator' -----//
	vector<string> divided;
	while (myString.find(separator)!=string::npos){
		// Find the separator
		size_t found = myString.find(separator);
		// Cut the string at the point of the separator
		divided.push_back(myString.substr(0,found));
		// Remove the portion of the string read to the separator
		myString.erase(myString.begin(),myString.begin()+found+1);
	}
	divided.push_back(myString);
	return divided;
}

void PrintOut::screen(vector<string> myVector, string separator){
	for (int i=0; i<myVector.size(); i++){
		printf("%s%s",myVector[i].c_str(),separator.c_str());
	}
}

vector<vector<string> > FileManip::read(string filename, string separator){
	//----- Reads in a file and converts to a vector matrix of strings -----//
 	
	if (separator==STRING_UNINITIALIZED){
		// Determine the type of file and infer the separator
		vector<string> divided = divide(filename,".");
		if (divided.back()=="csv"){
			separator = ",";
		} else if (divided.back()=="xls"){
			separator = "\t";
		} else {
			printf("Unknown extension %s: please specify separator type. Aborting.\n",divided.back().c_str());
			system("pause");
			exit(1);
		}

	}


	ifstream file(filename.c_str());
    if (!file.is_open()) printf("Failed to open file %s.\n", filename.c_str());
    string value;
    vector<vector<string> > filematrix;

    while (file.good()){
        getline(file,value);
        istringstream iss(value);
        string word;
        vector<string> line;
		while (getline(iss,word,*separator.c_str())){
            line.push_back(word);
        }
        if (line.size()) filematrix.push_back(line);
    }
    file.close();
    return filematrix;
}

double DataManip::stringToDouble(string s){
	return atof(s.c_str());
}

vector<vector<double> > DataManip::stringToDouble(vector<vector<string> > stringVector){
	vector<vector<double> > doubleVector;
	for (int i=0; i<stringVector.size(); i++){
		doubleVector.push_back(vector<double>(stringVector[i].size(),0.0));
		for (int j=0; j<stringVector[i].size(); j++){
			doubleVector[i][j] = stringToDouble(stringVector[i][j]);
		}
	}
	return doubleVector;
}

vector<double> DataManip::getColumn(vector<vector<double> > doubleVector, int col){
	vector<double> colVector = vector<double>(doubleVector.size(),0.0);
	for (int i=0; i<doubleVector.size(); i++){
		if (doubleVector[i].size()<=col){
			printf("Cannot access column %i. Aborting",col);
			system("pause");
			exit(1);
		} else {
			colVector[i]=doubleVector[i][col];
		}
	}
	return colVector;
}

vector<vector<double> > DataManip::getColumns(vector<vector<double> > doubleVector, vector<int> cols){
	vector<vector<double> > colVector;
	for (int i=0; i<doubleVector.size(); i++){
		colVector.push_back(vector<double>(cols.size(),0.0));
		for (int j=0; j<cols.size(); j++){
			int col = cols[j];
			if (doubleVector[i].size()<=col){
				printf("Cannot access column %i. Aborting",col);
				system("pause");
				exit(1);
			} else{
				colVector[i][j]=doubleVector[i][col];
			}
		}
	}
	return colVector;
}

void PrintOut::toFile(vector<vector<double> > myVector, string fileName, string separator){
    ofstream file;
    file.open(fileName.c_str());
    if (file.is_open()){
		for (int i=0; i<myVector.size(); i++){
			for (int j=0; j<myVector[i].size(); j++){
				//printf("%f%s",myVector[i][j],separator.c_str());
				file << myVector[i][j] << separator;
            }
            //printf("\n");
            file << "\n";
        }
        file.close();
    }
    else {
		printf("Failed to open %s.",fileName.c_str());
    }
}

void PrintOut::toFile(vector<double> myVector, string fileName, string separator){
    ofstream file;
    file.open(fileName.c_str());
    if (file.is_open()){
		for (int i=0; i<myVector.size(); i++){
			file << myVector[i] << separator;
        }
        file.close();
    }
    else {
		printf("Failed to open %s.",fileName.c_str());
    }
}


////// begin old file
/*
string ftos(double f){
	string s;
	stringstream ss;
	ss << f;
	ss >> s;
	return s;
}

string itos(int i){
	string s;
	stringstream ss;
	ss << i;
	ss >> s;
	return s;
}


void prints(double * array_first, int dim1, int dim2, std::string label){
    /*------------------------------------------------------------------------------------------*
    |   "Print Array": Takes in address of first element of 2D array and prints out, labeled    |
    *------------------------------------------------------------------------------------------*/
/*
    printf("Showing %s:\n\n", label.c_str());
    for (int i=0; i<dim1; i++){
        for (int j=0; j<dim2; j++){
            printf("%f, ", array_first[i*dim1+j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void prints(double * array_first, int dim1, std::string label){
    /*------------------------------------------------------------------------------------------*
    |   "Print Array": Takes in address of first element of 1D array and prints out, labeled    |
    *------------------------------------------------------------------------------------------*/
/*
    printf("Showing %s:\n\n", label.c_str());
    for (int i=0; i<dim1; i++){
        printf("%f, ", array_first[i]);
    }
    printf("\n\n");
}


void wait_for_key(){
    printf("\nPress ENTER to continue...\n");
    cin.clear();
    cin.ignore(cin.rdbuf()->in_avail());
    cin.get();
    return;
}

void wait_for_key_silently(){
    printf("\n");
    cin.clear();
    cin.ignore(cin.rdbuf()->in_avail());
    cin.get();
    return;
}*/
