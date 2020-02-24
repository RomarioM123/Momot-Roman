#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#define CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, FILE, __LINE)

#include <stdio.h> 
#include <locale.h>     

class C_Program {
private:
    int TimeOfWork;     //average time of program execution
    int size;           //size of program
    int AmountOfLines;  //number of lines in code
    int index;          //index
    const char* trojan; //trojan(yes or no)
public:
    int getTime() const;
    int getSize() const;
    int getLines() const;
    int getIndex()const;
    const char* getTrojan()const;

    void setTime(const int);
    void setSize(const int);
    void setLines(const int);
    void setIndex(const int);
    void setTrojan(const char*);

    C_Program();
    C_Program(char*, int, int, int, int);
    C_Program(const C_Program& other);
    ~C_Program();
};



