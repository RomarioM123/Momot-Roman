/**
* @file programList.cpp
* Файл реалізації методів класу CList
* @author Momot Roman
* @version 1.0
* @date 2020.05.26
*/

#include "programList.h"	/** Підключення файлу programList.h */

CList::~CList()				/** Реалізація деструктора */
{
	programList.clear();	/** Очищення пам'яті масива програм */
}
CList::CList()				/** Реалізація конструктора за замовчуванням */
{
	for (size_t i = 0; i < 5; i++)		/** Масив, який заповнює вектор елементами */
	{
		if (i == 0)
			programList.emplace_back(new CProgram());
		else if (i == 1)
			programList.emplace_back(new CMalware(1, 8800, 555, 35, 35634, "BestMalware", "Exploit"));
		else if (i == 2)
			programList.emplace_back(new CProgram(0, 423, 20, 654, 53453, "Calculator"));
		else if (i == 3)
			programList.emplace_back(new CProgramForSale(0, 345, 789, 423, 67456, "MoneyStealer", 99999));
		else
			programList.emplace_back(new CMalware());
	}
}
void CList::PrintList() const noexcept		/** Реалізація методу виведення списку на екран */
{	
	try
	{
		if (programList.size() == 0)		/** Перевірка розміру списка */
			throw exception("Список пуст.");

		int value = 1;

		cout << endl << setiosflags(ios::left);
		cout << setw(12) << "  Время" << setw(12) << "Размер";
		cout << setw(10) << "Строки" << setw(11) << "Интернет";
		cout << setw(14) << "Индекс" << setw(17) << "Название";
		cout << setw(14) << "Тип/Цена" << endl;			/** Виведення назв полів класів */

		for_each(programList.begin(), programList.end(), [&value](const unique_ptr<CProgram>& program)	/** Цикл, який виводить список елементів */
			{
				cout << value << ". " << *program << endl;	/** Виведення номеру та полів елемента */
				value++;		/** Збільшення зміної нумерування */
			});

		cout << endl;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}
int CList::Task(int minimalSize) const		/** Реалізація метода виконання індивідуального завдання */
{
	int value = 1;				/** Оголошення змінної кількості відповідних елементів */
	
	for (const auto& program : programList)		/** Цикл який обходить усі елементи масиву */
	{
		if (program->getLines() > minimalSize && *program != "Trojan")	/** Перевірка полів елементів */
		{
			cout << value << ". " << *program << endl;	/** Виведення елемента на екран */
			value++;	/** Збільшення змінної нумерування масиву */
		}
	}

	if (value == 0)		/** Якщо елементів немає */
		throw exception("Программы с такими параметрами отсутствуют.");

	return value;		/** Повернення кількості відповідних елементів */
}
int CList::AddProgram(int value)	/** Реалізація метода додавання нової програми */
{
	if (value == 1)
	{
		CProgram* temp = new CProgram;	/** Створення елемента класу CProgram */
		programList.emplace_back(temp);	/** Вставка елемента у масив */
	}
	else if (value == 2)
	{
		CProgram* temp = new CMalware;	/** Створення елемента класу CMalware */
		programList.emplace_back(temp);	/** Вставка елемента у масив */
	}
	else if (value == 3)
	{
		CProgram* temp = new CProgramForSale;	/** Створення елемента класу CProgramForSale */
		programList.emplace_back(temp);			/** Вставка елемента у масив */
	}
	else
		throw exception("Неверная команда.");

	return programList.size();			/** Повернення розміру списку */
}
int CList::DeleteProgram(int value)		/** Реалізація метода видалення програми */
{
	if (programList.size() == 0)		/** Перевірка розміру списку */
		throw exception("Cписок программ пуст.");

	int number = -1;
	bool findEl = false;	
	std::vector<unique_ptr<CProgram>>::iterator it;	/** Створення ітератора */

	for (const auto& program : programList)		/** Цикл, який обробляє усі елементи колекції */
	{
		if (program->getIndex() == value)		/** Якщо програма має потрібний індекс */
		{
			number++;				/** Збільшення змінної номеру елементу */
			findEl = true;			/** Змінення зміної знаходження елемента */
			break;					/** Зупинка роботи циклу */
		}
		else
			number++;				/** Збільшення змінної номеру елементу */
	}

	if (findEl)		/** Якщо елемент з потрібним індексом був найден */
	{
		it = programList.begin();	/** Встановлення покажчика на початок списку */
		advance(it, number);		/** Переміщення покажчика на потрібний елемент */
		programList.erase(it);		/** Видалення потрібного елементу */

		cout << "Удаление выполнено." << endl;
	}
	else
		throw exception("Элемент не найден.");

	return programList.size();		/** Повернення змінної розміру списку */
}
void CList::Sort(Functor& choise) noexcept	/** Реалізація метода сортування списку */
{
	std::sort(programList.begin(), programList.end(), choise);	/** Сортування списку */
}
int CList::SaveFile(string filename) const	/** Реалізація метода запису даних у файл */
{
	if (programList.size() == 0)	/** Перевірка розміру масиву */
		throw exception("Список пуст.");
	
	ofstream fout(filename);		/** Відкриття файлу */
	if (!fout.is_open())			/** Перевірка чи відкритий файл */
		throw exception("Невозможно открыть файл.");
	
	fout << setiosflags(ios::left);
	fout << setw(12) << "  Время" << setw(12) << "Размер";
	fout << setw(10) << "Строки" << setw(11) << "Интернет";
	fout << setw(14) << "Индекс" << setw(17) << "Название";
	fout << setw(14) << "Тип/Цена" << endl;	/** Виведення назв полів */

	int value = 1;
	for (const auto& program : programList)	/** Цикл, який обробляє усі елементи масиву */
	{
		fout << setiosflags(ios::left) << setw(2) << value << ". ";	/** Виведення нумерування елементів */
		fout << *program << endl;	/** Виведення полів елементів */
		value++;
	}

	fout.close();		/** Закриття файлу */
	return value - 1;	/** Повернення кількості елементів, які були збережені у файл */
}
int CList::ReadFile(string filename)	/** Реалізація метода читання даних з файлу */
{
	regex expressionProgram("([\\d]* [\\d]* [\\d]* [\\d]* [1|0]* [A-ZА-Я]+[\\wА-Яа-я,.;:-]* [\\wА-Яа-я,.;:-]*)");	/** Регулярний вираз для класу CProgram */
	regex expressionMalware("([\\d]* [\\d]* [a-zA-ZА-Яа-я]* [\\d]* [\\d]* [1|0]* [A-ZА-Я]+[\\wА-Яа-я,.;:-]* [\\wА-Яа-я,.;:-]*)");	/** Регулярний вираз для класу CMalware */
	regex expressionProgramForSelling("([\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [1|0]* [A-ZА-Я]+[\\wА-Яа-я,.;:-]* [\\wА-Яа-я,.;:-]*)");	/** Регулярний вираз для класу CProgramForSale */
	regex replaceSymbols("[;:-]");	/** Регулярний вираз для символів, які треба замінити */

	string temp, data, replacement = "";
	int value = 0;
	ifstream fin(filename);		/** Відкриття файлу */
	istringstream ss;
	
	if (!fin.is_open())			/** Перевірка чи відкритий файл */
	{
		throw exception("Невозможно открыть файл для чтения.");
		return programList.size();
	}

	while (!fin.eof())			/** Цикл, який працює до кінця файлу */
	{	
		getline(fin, data);		/** Отримання строки з файлу */
		temp = regex_replace(data, replaceSymbols, replacement);	/** Видалення символів які не підходять */
		temp += " ";

		if (regex_match(temp, expressionProgram))	/** Перевірка на відповідність до класу CProgram */
		{
			istringstream ss(temp);
			CProgram* program = new CProgram();		/** Створення змінної класу CProgram */
			
			ss >> *program;
			programList.emplace_back(program);		/** Вставка елемента у масив */
			value++;								/** Збільшення змінної кількості нових елементів */
		}
		else if (regex_match(temp, expressionMalware))	/** Перевірка на відповідність до класу CProgram */
		{
			istringstream ss(temp);
			CMalware* program = new CMalware();			/** Створення змінної класу CMalware */

			ss >> *program;
			programList.emplace_back(program);			/** Вставка елемента у масив */
			value++;									/** Збільшення змінної кількості нових елементів */
		}
		else if (regex_match(temp, expressionProgramForSelling))	/** Перевірка на відповідність до класу CProgram */
		{
			istringstream ss(temp);
			CProgramForSale* program = new CProgramForSale();		/** Створення змінної класу CProgramForSale */

			ss >> *program;
			programList.emplace_back(program);						/** Вставка елемента у масив */
			value++;												/** Збільшення змінної кількості нових елементів */
		}
	}

	fin.close();		/** Закриття файлу */
	return value;		/** Повернення змінної кількості нових елементів */
}
int CList::GetIndex(int value) const	/** Реалізація метода отримання індексу елементів */
{
	return programList[value]->getIndex();	/** Повернення індексу */
}





