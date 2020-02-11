#pragma once

#include "Program.h"
class List {
private:
	int ListSize;

public:
	Program* List;

	void setListSize(int);
	int getListSize() const;
	Program* AddEl(Program);
	Program* DeleteEl();
	void PrintAll() const;
	void PrintOneEl(int) const;
	Program Program1();
	Program Program2();
};