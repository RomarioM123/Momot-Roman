#pragma once
#include "Array.h"

class ArrayList
{
private:
	int listSize;		//размер динамического массива
	Array* arrayList;	//динамический массив массивов
	int* task;			//массив средних значений элементов

public:
	int getListSize() const;

	void createArr();
	bool ReadFile(string, int);
	int LinesInFile(string) const;
	void OutputArr(int) const;
	void Task(int);
	void SaveToFile(string, int) const;

	/*Array& operator[](const int);
    ArrayList& operator=(ArrayList&);*/


	~ArrayList();
};

