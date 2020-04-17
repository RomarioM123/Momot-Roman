#pragma once
#include "programForSale.h"
#include "malware.h"

class CList {
private:
	int listSize;
	CProgram** programList;

public:
	int getListSize() const;
	
	void createList(int, CAuthor*);
	void addProgram(CProgram*);
	void delProgram(int);
	CProgram* newProgram(CAuthor*, int) const;
	void printAll() const;
	sint task(int) const;
	int linesInFile(string) const;
	void readFile(string);
	void saveFile(string) const;
	void enterNewProgram();
	int regexTask() const;
	void getOneEl(int) const;
	int getProgramID(int)const;
	void sort(comp) const;
	static bool sortAsc(const int&, const int&);
	static bool sortDesc(const int&, const int&);

	int testID() const;
	stringstream testStringstream(int);
	CProgram* copyTest();

	CProgram* operator[] (int);

	~CList();
};