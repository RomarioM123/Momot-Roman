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



