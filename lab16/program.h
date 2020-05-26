/**
 * @file program.h
 * ϳ��������� ���������� ������� �� ���������� ����� CProgram.
 * @author Momot Roman
 * @version 1.0
 * @date 2020.05.26
 */

#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define CRTDBG_MAP_ALLOC
#include <crtdbg.h>		/** ϳ��������� �������� crtdbg.h*/
#define DEBUG_NEW new(_NORMAL_BLOCK, FILE, __LINE)

#include <string>		/** ϳ��������� �������� string*/
#include <iostream>		/** ϳ��������� �������� iostream*/
#include <iomanip>		/** ϳ��������� �������� iomanip*/
#include <locale>		/** ϳ��������� �������� locale*/
#include <fstream>		/** ϳ��������� �������� fstream*/
#include <sstream>		/** ϳ��������� �������� sstream*/
#include <regex>		/** ϳ��������� �������� regex*/
#include <memory>		/** ϳ��������� �������� memory*/
#include <vector>		/** ϳ��������� �������� vector*/
#include <exception>	/** ϳ��������� �������� exception*/
#include <iterator>		/** ϳ��������� �������� iterator*/

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::boolalpha;
using std::setiosflags;
using std::ios;
using std::ifstream;
using std::istream;
using std::ostream;
using std::ofstream;
using std::stringstream;
using std::istringstream;
using std::regex;
using std::regex_match;
using std::regex_search;
using std::regex_replace;
using std::cmatch;
using std::unique_ptr;
using std::vector;
using std::exception;
using std::iterator;

class CProgram {			/** ���������� �������� �����*/
protected:
	int timeOfWork;			/** ��� ��������� ��������*/
	int size;				/** ����� ��������*/
	int amountOfLines;		/** ʳ������ ����� ���� ��������*/
	int index;				/** ������ ��������*/
	bool useInternet;		/** ����������� �������� �������� �� �*/
	string name;			/** ����� ��������*/

public:
	virtual int getTime() const;		/** ���������� ����������� ������ ��������� ���� ������ ��������*/
	virtual int getSize() const;		/** ���������� ����������� ������ ��������� ������ ��������*/
	virtual int getLines() const;		/** ���������� ����������� ������ ��������� ������� ����� ��������*/
	virtual int getIndex()const;		/** ���������� ����������� ������ ��������� ������� ��������*/
	virtual bool getInternet()const;	/** ���������� ����������� ������ ��������� ���� ������ ��������*/
	virtual string getName() const;		/** ���������� ����������� ������ ��������� ����� ��������*/

	virtual string getInfo() const;		/** ���������� ��������� ������� ��������� ���������� ��������*/
	virtual void enter(istream&);

	CProgram();										/** ���������� ������������ �� �������������*/
	CProgram(bool, int, int, int, int, string);		/** ���������� ������������ � �����������*/
	CProgram(const CProgram& other);				/** ���������� ������������ ���������*/
	virtual ~CProgram();							/** ���������� ����������� �����������*/

	friend ofstream& operator<< (ofstream&,const CProgram&);	/** ���������� ��������������� ��������� ������ � ����*/
	friend ostream& operator<< (ostream&, const CProgram&);		/** ���������� ��������������� ��������� ������ � �������*/

	void* operator new(size_t);
	void* operator new[](size_t);
	void operator delete(void*);
	void operator delete[](void*);
};


