/**
* @file Functor.cpp
* Файл реалізації методів класу Functor
* @author Momot Roman
* @version 1.0
* @date 2020.05.26
*/

#include "Functor.h"			/** Підключення файлу Functor.h */

bool Functor::operator()(const unique_ptr<CProgram>& first, const unique_ptr<CProgram>& second) const	/** Реалізація перегруження оператору () */
{
	if (choise == 1)			/** Якщо треба сортувати по назві */
	{
		if (direction == true)	/** Вибір напряму сортування */
			return first->getName() > second->getName();
		else
			return first->getName() < second->getName();
	}
	else if (choise == 2)		/** Якщо треба сортувати по індексу */
	{
		if (direction == true)	/** Вибір напряму сортування */
			return first->getIndex() > second->getIndex();
		else
			return first->getIndex() < second->getIndex();
	}
	else if (choise == 3)		/** Якщо треба сортувати по кількості рядків коду */
	{
		if (direction == true)	/** Вибір напряму сортування */
			return first->getLines() > second->getLines();
		else
			return first->getLines() < second->getLines();
	}
	else if (choise == 4)		/** Якщо треба сортувати по розміру програми */
	{
		if (direction == true)	/** Вибір напряму сортування */
			return first->getSize() > second->getSize();
		else
			return first->getSize() < second->getSize();
	}
	else if (choise == 5)		/** Якщо треба сортувати по часу виконання роботи програми */
	{
		if (direction == true)	/** Вибір напряму сортування */
			return first->getTime() > second->getTime();
		else
			return first->getTime() < second->getTime();
	}
	else if (choise == 6)		/** Якщо треба сортувати по Інтернету */
	{
		if (direction == true)	/** Вибір напряму сортування */
			return first->getInternet() > second->getInternet();
		else
			return first->getInternet() < second->getInternet();
	}
}

Functor::Functor(bool direction, int choise) :direction(direction), choise(choise) {}	/** Реалізація конструктора з параметрами */
Functor::~Functor() {}			/** Реалізація деструктора */