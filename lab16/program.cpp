/**
* @file program.cpp
* Файл реалізації методів базового класу
* @author Momot Roman
* @version 1.0
* @date 2020.05.26
*/

#include "program.h"

int CProgram::getTime() const		/** Реалізація геттера часу роботи програми */
{ 
	return timeOfWork;				/** Повернення часу роботи програми */
}
int CProgram::getSize() const		/** Реалізація геттера розміру програми */
{ 
	return size;					/** Повернення розміру програми */
}
int CProgram::getLines() const		/** Реалізація геттера кількості рядків коду програми */
{ 
	return amountOfLines;			/** Повернення кількості рядків коду програми */
}
int CProgram::getIndex() const		/** Реалізація геттера індексу програми */
{ 
	return index;					/** Повернення індексу програми */
}
bool CProgram::getInternet()const	/** Реалізація геттера інтернету */
{ 
	return useInternet;				/** Повернення інтернету */
}
string CProgram::getName()const		/** Реалізація геттера назви програми */
{ 
	return name;					/** Повернення назви програми */
}

void CProgram::enter(istream& data)	/** Реалізація перевантаженого оператора вводу */
{
	data >> index >> timeOfWork >> size >> amountOfLines >> useInternet >> name;	/** Введення даних у об'єкт типу istream */
}
string CProgram::getInfo() const	/** Реалізація методу отримання даних програми */
{
	stringstream temp;				/** Створення змінної типу stringstream */
	temp.setf(ios::left);

	temp << setw(10) << timeOfWork << setw(12) << size
		<< setw(9) << amountOfLines << setw(12) << boolalpha << useInternet
		<< setw(11) << index << setw(16) << name;	/** Запис даних у об'єкт типу stringstream */

	return temp.str();				/** Повернення даних у форматі string */
}


CProgram::CProgram(bool internet, int time, int size, int lines, int index, string name) : useInternet(internet), timeOfWork(time), size(size), amountOfLines(lines), index(index), name(name) {}	/** Реалізація конструктора з параметрами */
CProgram::CProgram() : useInternet(false), timeOfWork(200), size(200), amountOfLines(200), index(0101), name("Basic") {}	/** Реалізація конструктора за замовчуванням */
CProgram::CProgram(const CProgram& other) : useInternet(other.useInternet), timeOfWork(other.timeOfWork), size(other.size), amountOfLines(other.amountOfLines), index(other.index), name(other.name) {}	/** Реалізація конструктора копіювання */
CProgram::~CProgram() {}			/** Реалізація деструктора */

ofstream& operator<< (ofstream& output, const CProgram& program)	/** Реалізація перевантаженого оператора запису даних у файл */
{
	output << program.getInfo();	/** Виклик фкнції отримання інформації */
	return output;					/** Повернення інформації */
}
ostream& operator<< (ostream& output, const CProgram& program)		/** Реалізація перевантаженого оператора виводу даних у консоль */
{
	output << program.getInfo();	/** Виклик фкнції отримання інформації */
	return output;					/** Повернення інформації */
}
void* CProgram::operator new(size_t value)
{
	cout << "Вызов оператора new для класса CProgram" << endl;
	return ::operator new(value);
}
void* CProgram::operator new[](size_t value)
{
	cout << "Вызов оператора new[] для класса CProgram" << endl;
	return ::operator new[](value);
}
void CProgram::operator delete(void* pointer)
{
	cout << "Вызов оператора delete для класса CProgram" << endl;
	::operator delete(pointer);
}
void CProgram::operator delete[](void* pointer)
{
	cout << "Вызов оператора delete[] для класса CProgram" << endl;
	::operator delete(pointer);
}
