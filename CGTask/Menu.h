/**
* @file Menu.h
* Файл оголошення класу меню
* @author Momot Roman
* @version 1.0
* @date 2020.05.26
*/

#pragma once
#include "programList.h"	/** Підключення файлу programList.h */
class Menu
{
public:
	void menu() const;		/** Оголошення методу роботи зі списком*/
	
	Menu();					/** Оголошення конструктора за замовчуванням */
	~Menu();				/** Оголошення деструктором */
};

