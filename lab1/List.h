#pragma once

#include "Program.h"
class C_List {
private:
	int ListSize;

public:
	C_Program* List;

	void setListSize(int);
	int getListSize() const;
	C_Program* AddEl(C_Program);
	C_Program* DeleteEl();
	void PrintAll() const;
	void PrintOneEl(int) const;
	C_Program Program1();
	C_Program Program2();

	C_Program TestProgram3();
};