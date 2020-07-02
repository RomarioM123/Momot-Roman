/**
* @file Menu.cpp
* Файл реалізації методів класу Menu
* @author Momot Roman
* @version 1.0
* @date 2020.05.26
*/

#include "Menu.h"		/** Підключення файлу Menu.h*/

void Menu::menu() const	/** Виклик метода діалогового меню*/
{
	/** Оголошення змінних для роботи програми*/
	int choise, choise2;
	int size = -1, value;
	bool stop = true;	
	string filename;	/** Назва файлу */
	CList list;			/** Список елементів */
	
	while (stop != 0)	/** Цикл, який працює поки користувач не захоче вийти*/
	{
		cout << endl;
		cout << "1) Вывести список на экран" << endl;
		cout << "2) Удаление элемента" << endl;
		cout << "3) Добавление элемента" << endl;
		cout << "4) Индивидуальное задание" << endl;
		cout << "5) Работа с файлами" << endl;
		cout << "6) Сортировка" << endl;
		cout << "7) Завершение работы" << endl;
		cout << "==========================" << endl;
		cout << "Ваш выбор: ";
		cin >> choise;	/** Введення зміної вибору дії*/
		cout << endl;

		switch (choise)
		{
		case 1:

			list.PrintList();	/** Виклик методу виведення списку у консоль */
			
			break;

		case 2:
			cout << "Введите ID элемента, который хотите удалить: ";
			cin >> choise;	/** Введення зміної вибору дії*/
			cout << endl;

			try
			{
				list.DeleteProgram(choise);	/** Виклик методу видалення елемента */
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl;
			}

			break;

		case 3:
			cout << "Выберите программу, которую хотите добавить:" << endl;
			cout << "1. Элемент класса CProgram" << endl;
			cout << "2. Элемент класса CMalware" << endl;
			cout << "3. Элемент класса CProgramForSale" << endl;
			cout << "=================================" << endl;
			cout << "Ваш выбор: ";
			cin >> value;	/** Введення зміної вибору дії*/
			
			try
			{
				list.AddProgram(value);		/** Виклик методу додавання програми */
			}
			catch (const std::exception & ex)
			{
				cout << ex.what() << endl;
			}
			cout << "Программа добавлена." << endl;

			break;
		case 4:
			cout << "Индивидуальное задание:\nПолучить список программ, размер которых больше заданного размера(например 100 Кбайт). Из списка убрать \"трояны\"" << endl;
			cout << "Введите минимальный розмер программы: ";
			cin >> value;		/** Введення зміної вибору дії*/
			cout << endl;

			try
			{
				list.Task(value);		/** Виклик методу виконання індивідуального завдання */
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl;
			}

			break;

		case 5:
			cout << "Что делать?" << endl;
			cout << "1) Запись в файл" << endl;
			cout << "2) Чтение файла" << endl;
			cout << "3) Вернуться назад" << endl;
			cout << "==================" << endl;
			cout << "Ваш выбор: ";
			cin >> choise2;		/** Введення зміної вибору дії*/
			cout << endl;

			if (choise2 == 1)
			{
				string::size_type n;
				cout << "Введите название файла для записи: ";
				cin >> filename;	/** Введення назви файлу */
				cout << endl;

				n = filename.find(".txt");
				if (n > 187) filename += string(".txt");

				try
				{
					list.SaveFile(filename);	/** Виклик методу запису списка у файл */
				}
				catch (const std::exception & ex)
				{
					cout << ex.what() << endl;
				}

				cout << "Запись завершена. " << endl;
			}
			else if (choise2 == 2)
			{
				string::size_type n;
				cout << "Введите название файла для чтения: ";
				cin >> filename;	/** Введення назви файлу*/
				cout << endl;

				n = filename.find(".txt");
				if (n > 187) filename += string(".txt");

				try
				{
					list.ReadFile(filename);		/** Виклик методу читання даних з файлу */
				}
				catch (const std::exception & ex)
				{
					cout << ex.what() << endl;
				}

				cout << "Чтение файла завершено." << endl;

			}
			else if (choise2 == 3)
				cout << "Возвращение назад. " << endl;
			else
				cout << "Неверная команда. Повторите попытку." << endl;

			break;

		case 6:
			cout << "Сортировать по: " << endl;
			cout << "1) Возрастанию" << endl;
			cout << "2) Убыванию" << endl;
			cout << "3) Вернуться назад" << endl;
			cout << "==================" << endl;
			cout << "Ваш выбор: ";
			cin >> choise2;		/** Введення зміної напряму сортування*/
			cout << endl;

			if (choise2 == 1 || choise2 == 2)
			{
				cout << "По какому полю сортировать: " << endl;
				cout << "1) Название" << endl;
				cout << "2) Индекс" << endl;
				cout << "3) Количество строк кода" << endl;
				cout << "4) Размер программы" << endl;
				cout << "5) Время выполнения кода" << endl;
				cout << "6) Использует ли программа интернет или нет" << endl;
				cout << "=============================" << endl;
				cout << "Ваш выбор: ";
				cin >> value;
				cout << endl;

				if (value > 0 && value <= 6)
				{
					Functor funct(choise2 - 1, value);		/** Оголошення змінної класу Functor */
					list.Sort(funct);						/** Виклик методу сортування */

					cout << "Список отсортирован. " << endl;
				}
				else
					cout << "Неверный символ." << endl;
			}
			else if (choise2 == 3)
				cout << "Возвращение назад." << endl;
			else
				cout << "Ошибка. Неверная команда." << endl;

			break;
		case 7:
			cout << "Завершение работы." << endl;
			stop = false;
			break;

		default:
			cout << "Неверный символ. Повторите попытку." << endl;
			break;

		}
		
	}

	return;		/** Завершення роботи метода */
}

Menu::Menu() {}		/** Реалізація конструктора за замовчуванням */
Menu::~Menu() {}	/** Реалізація деструктора */
