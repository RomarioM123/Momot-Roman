#pragma once
#include "program.h"

class CList {
private:
	int listSize;

public:
	C_Program* list;

	void setListSize(int);
	int getListSize() const;
	
	void createList(int);
	void printAll() const;
	void printOneEl(int) const;
	void addEl(C_Program&);
	void deleteEl(int);
	int task(int);
	int linesInFile(string);
	void readFile(string);
	void saveToFile(string);
	stringstream getOneEl(int) const;
	void showOneEl(stringstream&) const;
	void enterNewEl();
	void regexTask();
	void sort(comp);

	static bool sortAsc(const int&, const int&);
	static bool sortDesc(const int&, const int&);

	C_Program getProgramID(int)const;
	C_Program programs(int);
	~CList();
};