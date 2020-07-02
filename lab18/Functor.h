/**
* @file Functor.h
* ���� ���������� �����, ���� ������ ������� ��������
* @author Momot Roman
* @version 1.0
* @date 2020.05.26
*/

#pragma once
#include "program.h"	/** ϳ��������� ����� program.h */

class Functor			/** ���������� ����� ��������*/
{
private:
	bool direction;		/** ������ ����������*/
	int choise;			/** ����� ���� ����������*/

public:
	bool operator()(const unique_ptr<CProgram>& first, const unique_ptr<CProgram>& second) const;	/** ���������� ��������������� ��������� () */

	Functor(bool, int);		/** ���������� ������������ �� �������������*/
	~Functor();				/** ���������� �����������*/
};

