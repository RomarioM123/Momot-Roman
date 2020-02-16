#pragma once

#include "Program.h"
class C_List {
private:
	int listSize;

public:
	C_Program* List;
	void setListSize(int);
	int getListSize() const;
	void CreateList();
	void PrintAll() const;
	void PrintOneEl(int) const;
	void AddEl(C_Program&);
	void DeleteEl(int);
	void FreeMemory();
	
	C_Program Program1();
	C_Program Program2();
	C_Program TestProgram3();
};