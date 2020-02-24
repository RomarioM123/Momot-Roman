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

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::stringstream;

class C_Program {
private:
	int timeOfWork;     //average time of program execution
	int size;           //size of program
	int amountOfLines;  //number of lines in code
	int index;          //index
	bool trojan;		//trojan(yes or no)
	string name;		//name of program
public:
	int getTime() const;
	int getSize() const;
	int getLines() const;
	int getIndex()const;
	bool getTrojan()const;
	string getName() const;

	void setTime(const int);
	void setSize(const int);
	void setLines(const int);
	void setIndex(const int);
	void setTrojan(const bool);
	void setName(const string);

	C_Program();
	C_Program(bool, int, int, int, int, string);
	C_Program(const C_Program& other);
	~C_Program();
};


