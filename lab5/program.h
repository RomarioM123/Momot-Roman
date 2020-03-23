#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
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
using std::regex_match;
using std::regex_search;
using std::cmatch;
using std::setiosflags;
using std::ios;

#include "author.h"
#include "date.h"

typedef bool (comp)(const int&, const int&);

class C_Program {
private:
	int timeOfWork;			//average time of program execution
	int size;				//size of program
	int amountOfLines;		//number of lines in code
	int index;				//index
	bool trojan;			//trojan(yes or no)
	string name;			//name of program
	CAuthor author;			//creator of program
	CDate date;				//date of creating program
public:
	int getTime() const;
	int getSize() const;
	int getLines() const;
	int getIndex()const;
	bool getTrojan()const;
	string getName() const;
	sint getDay()const;
	sint getMonth()const;
	sint getYear()const;
	string getAuthor()const;

	void setTime(const int);
	void setSize(const int);
	void setLines(const int);
	void setIndex(const int);
	void setTrojan(const bool);
	void setName(const string);
	void setDay(const sint);
	void setMonth(const sint);
	void setYear(const sint);
	void setAuthor(const string);

	C_Program();
	C_Program(bool, int, int, int, int, string, CAuthor, sint, sint, sint);
	C_Program(const C_Program& other);
	~C_Program();
};


