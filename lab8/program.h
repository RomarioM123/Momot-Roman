#pragma once

#include "author.h"
#include "date.h"

#define _CRT_SECURE_NO_WARNINGS
#define CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, FILE, __LINE)

#include <string>
#include <iostream>
#include <iomanip>
#include <locale>
#include <fstream>
#include <sstream>
#include <regex>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::boolalpha;
using std::setiosflags;
using std::ios;
using std::ifstream;
using std::ofstream;
using std::stringstream;
using std::regex;
using std::regex_match;
using std::regex_search;
using std::cmatch;

typedef bool (comp)(const int&, const int&);

class CProgram {
protected:
	int timeOfWork;			//average time of program execution
	int size;				//size of program
	int amountOfLines;		//number of lines in code
	int index;				//index
	bool useInternet;		//use internet
	string name;			//name of program
	CAuthor author;			//creator of program
	CDate date;				//date of creating program

public:
	int getTime() const;
	int getSize() const;
	int getLines() const;
	int getIndex()const;
	bool getInternet()const;
	string getName() const;

	virtual string getInfo() const = 0;
	virtual void input(istream&) = 0;
	virtual stringstream getStr() const = 0;

	CProgram();
	CProgram(bool, int, int, int, int, string, CAuthor, sint, sint, sint);
	CProgram(const CProgram& other);
	virtual ~CProgram();

	friend ofstream& operator<< (ofstream&,const CProgram&);
	friend ostream& operator<< (ostream&, const CProgram&);
	friend istream& operator>> (istream&, CProgram&);
	virtual bool operator==(const string) const;
	CProgram& operator= (CProgram&);
};


