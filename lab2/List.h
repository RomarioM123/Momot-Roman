#pragma once
#include "Program.h"

class CList {
private:
    int listSize;

public:
    C_Program* List;
    void setListSize(int);
    int getListSize() const;
    void CreateList(int);
    void PrintAll() const;
    void PrintOneEl(int) const;
    void AddEl(C_Program&);
    void DeleteEl(int);
    void Task(int);
    void GetProgramID(int)const;
    
    C_Program Programs(int);
    ~CList();

};