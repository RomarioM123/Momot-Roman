#pragma once
#include "Header.h"

class CProgram {
protected:
	int timeOfWork;			//average time of program execution
	int size;				//size of program
	int amountOfLines;		//number of lines in code
	int index;				//index
	bool useInternet;		//use internet
	string name;			//name of program

public:
	virtual string getInfo() const;
	virtual stringstream getStr() const;
	int getID() const;

	CProgram();
	CProgram(bool, int, int, int, int, string);
	CProgram(const CProgram&);
	virtual ~CProgram();

	friend ostream& operator<< (ostream&, const CProgram&);
	virtual bool operator==(const int) const;
};


