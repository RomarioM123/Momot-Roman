/**
* @file programForSale.cpp
* Файл реалізації методів класу-спадкоємця
* @author Momot Roman
* @version 1.0
* @date 2020.05.26
*/

#include "programForSale.h"				/** Підключення файлу programForSale.h */

int CProgramForSale::getTime() const	/** Реалізація геттера часу роботи програми */
{
	return timeOfWork;					/** Повернення часу роботи програми */
}
int CProgramForSale::getSize() const	/** Реалізація геттера розміру програми */
{
	return size;						/** Повернення розміру програми */
}
int CProgramForSale::getLines() const	/** Реалізація геттера кількості рядків коду програми */
{
	return amountOfLines;				/** Повернення кількості рядків коду програми */
}
int CProgramForSale::getIndex() const	/** Реалізація геттера індексу програми */
{
	return index;						/** Повернення індексу програми */
}
bool CProgramForSale::getInternet()const/** Реалізація геттера інтернету */
{
	return useInternet;					/** Повернення інтернету */
}
string CProgramForSale::getName()const	/** Реалізація геттера назви програми */
{
	return name;						/** Повернення назви програми */
}

string CProgramForSale::getInfo() const	/** Реалізація методу отримання даних програми */
{
	stringstream temp;					/** Створення змінної типу stringstream */
	temp.setf(ios::left);

	temp << setw(10) << timeOfWork << setw(12) << size
		<< setw(9) << amountOfLines << setw(12) << boolalpha << useInternet
		<< setw(11) << index << setw(20) << name
		<< setw(14) << price;			/** Запис даних у об'єкт типу stringstream */

	return temp.str();					/** Повернення даних у форматі string */
}
void CProgramForSale::enter(istream& data)	/** Реалізація перевантаженого оператора вводу */
{
	data >> index >> timeOfWork >> price >> size >> amountOfLines >> useInternet >> name;	/** Введення даних у об'єкт типу istream */
}

CProgramForSale::CProgramForSale(bool internet, int time, int size, int lines, int index, string name, int price) : CProgram(internet, time, size, lines, index, name), price(price) {}	/** Реалізація конструктора з параметрами */
CProgramForSale::CProgramForSale() : CProgram(), price(2000) {}		/** Реалізація конструктора за замовчуванням */
CProgramForSale::CProgramForSale(const CProgramForSale& other) : CProgram(other), price(other.price) {}		/** Реалізація конструктора копіювання */
CProgramForSale::~CProgramForSale() {}		/** Реалізація деструктора */

CProgramForSale& CProgramForSale::operator=(CProgramForSale& temp)	/** Реалізація перевантаженого оператора присвоювання */
{
	if (this == &temp)					/** Перевірка якщо змінні однакові */
		return *this;

	CProgramForSale::operator=(temp);	/** Присвоювання полів базового класу */
	int price = temp.price;				/** Присвоювання полів ціни */

	return *this;
}
bool CProgramForSale::operator!=(const string type) const	/** Реалізація перевантаженого оператора нерівності */
{
	return true;	/** Перевірка відбувається за типом зловмисного ПО (звичайна програма не може бути зловмисним ПО) */
}
bool CProgramForSale::operator==(const int index) const		/** Реалізація перевантаженого оператора порівняння */
{
	return this->index == index;							/** Перевірка відбувається за індексом */
}