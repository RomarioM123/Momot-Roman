#pragma once
#include "Array.h"

class ArrayList
{
private:
	int listSize;		//размер динамического массива
	Array* arrayList;	//динамический массив массивов
	float* task;		//массив средних значений элементов

public:
	void ReadFile(string);
	int LinesInFile(string) const;
	void OutputArr() const;
	void Task();
	void SaveToFile(string) const;
	void DeleteArr();
	void CheckArr(int, int);

	~ArrayList();
};

