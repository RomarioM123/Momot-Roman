#pragma once
#include "Program.h"

class C_List {
private:
    int listSize;

public:
<<<<<<< HEAD
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
    ~C_List();
=======
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
	~C_List();
>>>>>>> 042bc953d2b5e7240b67c16e27875c0f044d9563
};