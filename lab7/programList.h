#pragma once
#include "programForSale.h"
#include "malware.h"

class CList {
private:
	int listSize;
	C_Program** programList;

public:
	int getListSize() const;
	
	C_Program** createList(int, CAuthor*);
	C_Program** addProgram(C_Program*, C_Program**);
	C_Program** delProgram(int, C_Program**);
	C_Program* newProgram(CAuthor*, int);
	void printAll(C_Program** program) const;
	stringstream getOneEl(int) const;
	sint task(int);
	void saveToFile(string);
	int linesInFile(string);
	C_Program** readFile(string);
	C_Program** enterNewProgram();
	int regexTask(CList&);
	int getProgramID(int, C_Program**)const;
	void sort(comp);
	static bool sortAsc(const int&, const int&);
	static bool sortDesc(const int&, const int&);

	~CList();
};