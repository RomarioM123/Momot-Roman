#pragma once
#include "Program.h"

class C_List {
private:
	int listSize;

public:
	C_Program* list;
	void setListSize(int);
	int getListSize() const;
	
	void CreateList(int);
	void PrintAll() const;
	void PrintOneEl(int) const;
	void AddEl(C_Program&);
	void DeleteEl(int);
	void Task(int);
	int LinesInFile(string);
	void ReadFile(string);
	void SaveToFile(string);
	stringstream GetOneEl(int) const;

	C_Program GetProgramID(int)const;
	C_Program Programs(int);
	~C_List();
};