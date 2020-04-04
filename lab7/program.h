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
#include <locale.h>
#include <fstream>
#include <sstream>
#include <regex>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::stringstream;
using std::boolalpha;
using std::regex;
using std::ifstream;
using std::ofstream;
using std::regex_match;
using std::regex_search;
using std::cmatch;
using std::setiosflags;
using std::ios;

typedef bool (comp)(const int&, const int&);

class C_Program {
	
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
	
	virtual int getTime() const;
	virtual int getSize() const;
	virtual int getLines() const;
	virtual int getIndex()const;
	virtual bool getInternet()const;
	virtual string getName() const;
	virtual sint getDay()const;
	virtual sint getMonth()const;
	virtual sint getYear()const;
	virtual string getAuthor()const;

	virtual void print() const = 0;
	virtual stringstream getStr() const = 0;
	virtual void writeInFile(ofstream&) = 0;

	/*void setTime(const int);
	void setSize(const int);
	void setLines(const int);
	void setIndex(const int);
	void setInternet(const bool);
	void setName(const string);
	void setDay(const sint);
	void setMonth(const sint);
	void setYear(const sint);
	void setAuthor(const string);*/

	C_Program();
	C_Program(bool, int, int, int, int, string, CAuthor, sint, sint, sint);
	C_Program(const C_Program& other);
	virtual ~C_Program();
};


