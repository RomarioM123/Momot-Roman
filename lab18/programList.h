/**
* @file programList.h
* ���� ���������� �����-����������.
* @author Momot Roman
* @version 1.0
* @date 2020.05.26
*/

#pragma once
#include "programForSale.h"		/** ϳ��������� ����� programForSale.h */
#include "malware.h"			/** ϳ��������� ����� malware.h */
#include "Functor.h"			/** ϳ��������� ����� Functor.h */

class CList {					/** ���������� �����-���������� */
private:
	vector <unique_ptr<CProgram>> programList;	/** ��������� ��� ��������� �������� */

public:
	void PrintList() const noexcept;	/** ���������� ������ ������ ������ � ������� */
	int Task(int) const;				/** ���������� ������ ��������� �������������� ��������� */
	int AddProgram(int);				/** ���������� ������ ��������� ������ �������� � ������ */
	int DeleteProgram(int);				/** ���������� ������ ��������� �������� � ������ */
	void Sort(Functor&) noexcept;		/** ���������� ������ ���������� ����� */
	int SaveFile(string) const;			/** ���������� ������ ��������� ����� � ���� */
	int ReadFile(string);				/** ���������� ������ ������ ������ � ������� */
	int GetIndex(int) const;			/** ���������� ������ ��������� ������� �� ������� */

	CList();							/** ���������� ������������ �� ������������� */
	~CList();							/** ���������� ����������� */
};