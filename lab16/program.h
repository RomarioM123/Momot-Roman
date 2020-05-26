/**
 * @file program.h
 * Підключення необхідних бібліотек та оголошення класу CProgram.
 * @author Momot Roman
 * @version 1.0
 * @date 2020.05.26
 */

#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define CRTDBG_MAP_ALLOC
#include <crtdbg.h>		/** Підключення бібліотеки crtdbg.h*/
#define DEBUG_NEW new(_NORMAL_BLOCK, FILE, __LINE)

#include <string>		/** Підключення бібліотеки string*/
#include <iostream>		/** Підключення бібліотеки iostream*/
#include <iomanip>		/** Підключення бібліотеки iomanip*/
#include <locale>		/** Підключення бібліотеки locale*/
#include <fstream>		/** Підключення бібліотеки fstream*/
#include <sstream>		/** Підключення бібліотеки sstream*/
#include <regex>		/** Підключення бібліотеки regex*/
#include <memory>		/** Підключення бібліотеки memory*/
#include <vector>		/** Підключення бібліотеки vector*/
#include <exception>	/** Підключення бібліотеки exception*/
#include <iterator>		/** Підключення бібліотеки iterator*/

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

class CProgram {			/** Оголошення базового класу*/
protected:
	int timeOfWork;			/** Час виконання програми*/
	int size;				/** Розмір програми*/
	int amountOfLines;		/** Кількість рядків коду програми*/
	int index;				/** Індекс програми*/
	bool useInternet;		/** Використовує програма Інтернет чи ні*/
	string name;			/** Назва програми*/

public:
	virtual int getTime() const;		/** Оголошення віртуального гетера отримання часу роботи програми*/
	virtual int getSize() const;		/** Оголошення віртуального гетера отримання розміру програми*/
	virtual int getLines() const;		/** Оголошення віртуального гетера отримання кількості рядків програми*/
	virtual int getIndex()const;		/** Оголошення віртуального гетера отримання індексу програми*/
	virtual bool getInternet()const;	/** Оголошення віртуального гетера отримання часу роботи програми*/
	virtual string getName() const;		/** Оголошення віртуального гетера отримання назви програми*/

	virtual string getInfo() const;		/** Оголошення віртуальної функції отримання інформації програми*/
	virtual void enter(istream&);

	CProgram();										/** Оголошення конструктора по замовчуванням*/
	CProgram(bool, int, int, int, int, string);		/** Оголошення конструктора з параметрами*/
	CProgram(const CProgram& other);				/** Оголошення конструктора копіювання*/
	virtual ~CProgram();							/** Оголошення віртуального деструктора*/

	friend ofstream& operator<< (ofstream&,const CProgram&);	/** Оголошення перевантаженого оператора виводу у файл*/
	friend ostream& operator<< (ostream&, const CProgram&);		/** Оголошення перевантаженого оператора виводу у консоль*/

	void* operator new(size_t);
	void* operator new[](size_t);
	void operator delete(void*);
	void operator delete[](void*);
};


