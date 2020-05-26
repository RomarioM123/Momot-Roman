/**
* @file programList.h
* Файл оголошення класу-контролера.
* @author Momot Roman
* @version 1.0
* @date 2020.05.26
*/

#pragma once
#include "programForSale.h"		/** Підключення файлу programForSale.h */
#include "malware.h"			/** Підключення файлу malware.h */
#include "Functor.h"			/** Підключення файлу Functor.h */

class CList {					/** Оголошення класу-контролера */
private:
	vector <unique_ptr<CProgram>> programList;	/** Контейнер для зберігання елементів */

public:
	void PrintList() const noexcept;	/** Оголошення методу виводу списку у консоль */
	int Task(int) const;				/** Оголошення методу виконання індивідуального завднання */
	int AddProgram(int);				/** Оголошення методу додавання нового елемента у список */
	int DeleteProgram(int);				/** Оголошення методу видалення програми зі списку */
	void Sort(Functor&) noexcept;		/** Оголошення методу сортування даних */
	int SaveFile(string) const;			/** Оголошення методу виведення даних у файл */
	int ReadFile(string);				/** Оголошення методу виводу списку у консоль */
	int GetIndex(int) const;			/** Оголошення методу отримання індекса за номером */

	CList();							/** Оголошення конструктора за замовчуванням */
	~CList();							/** Оголошення деструктора */
};