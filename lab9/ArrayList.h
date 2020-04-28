#pragma once
#include "Array.h"

class ArrayList
{
private:
	int listSize;		//������ ������������� �������
	Array* arrayList;	//������������ ������ ��������
	float* task;		//������ ������� �������� ���������

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

