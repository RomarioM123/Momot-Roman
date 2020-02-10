#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#define CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, FILE, __LINE)

#include <stdio.h> 
#include <locale.h>	    

class Program {
private:
	int TimeOfWork;		//average time of program execution
	int size;			//size of program
	int AmountOfLines;	//number of lines in code

public:
	int getTime() const;
	int getSize() const;
	int getLines() const;
	void setTime(int);
	void setSize(int);
	void setLines(int);
};

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

	Program Program1()
	{
		Program Program1;
		Program1.setTime(25326);
		Program1.setSize(2000);
		Program1.setLines(500);
		return Program1;
	}

	Program Program2()
	{
		Program Program2;
		Program2.setTime(55555);
		Program2.setSize(11111);
		Program2.setLines(22222);
		return Program2;
	}
};

