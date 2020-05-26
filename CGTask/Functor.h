/**
* @file Functor.h
* Файл оголошення класу, який виконує функції функтора
* @author Momot Roman
* @version 1.0
* @date 2020.05.26
*/

#pragma once
#include "program.h"	/** Підключення файлу program.h */

class Functor			/** Оголошення класу функтора*/
{
private:
	bool direction;		/** Напрям сортування*/
	int choise;			/** Вибор поля сортування*/

public:
	bool operator()(const unique_ptr<CProgram>& first, const unique_ptr<CProgram>& second) const;	/** Оголошення перевантаженого оператора () */

	Functor(bool, int);		/** Оголошення конструктора по замовчуванням*/
	~Functor();				/** Оголошення деструктора*/
};

