/**
* @file programForSale.h
* Файл оголошення класу-спадкоемця.
* @author Momot Roman
* @version 1.0
* @date 2020.05.26
*/

#pragma once
#include "program.h"					/** Підключення файлу program.h */
class CProgramForSale final : public CProgram	/** Оголошення класу спадкоємця */
{
private:
	int price;		/** Ціна програми */				

public:
	int getTime() const override;		/** Оголошення перевантаженого гетера отримання часу виконання програми */
	int getSize() const override;		/** Оголошення перевантаженого гетера отримання розміру програми */
	int getLines() const override;		/** Оголошення перевантаженого гетера отримання кількості рядків коду програми */
	int getIndex()const override;		/** Оголошення перевантаженого гетера отримання індексу програми */
	bool getInternet()const override;	/** Оголошення перевантаженого гетера отримання часу виконання програми */
	string getName() const override;	/** Оголошення перевантаженого гетера отримання назви програми */
	
	string getInfo() const override;	/** Оголошення перевантаженого метода отримання інформації програми */
	void enter(istream&) override;		/** Оголошення перевантаженого метода вводу інформації програми */

	CProgramForSale();											/** Оголошення конструктора за замовчуванням */
	CProgramForSale(bool, int, int, int, int, string, int);		/** Оголошення конструктора з параметрами */
	CProgramForSale(const CProgramForSale&);					/** Оголошення конструктора копіювання */
	~CProgramForSale() override;								/** Оголошення перевантаженого деструктора */

	CProgramForSale& operator= (CProgramForSale&);	/** Оголошення оператора присвоювання */
	bool operator!=(const string) const override;	/** Оголошення перевантаженого оператора нерівності */
	bool operator==(const int) const override;		/** Оголошення перевантаженого оператора порівняння */
};

