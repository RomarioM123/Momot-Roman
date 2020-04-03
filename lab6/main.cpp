#include "programList.h"
#include "malwareList.h"

void menu();

int main()
{
	setlocale(LC_ALL, "Rus");
	menu();

	if (_CrtDumpMemoryLeaks()) cout << endl << "Есть утечка памяти." << endl;
	else cout << endl << "Утечка памяти отсутствует." << endl;

	return 0;
}

void menu()
{
	auto choise = 1, choise2 = 0;
	string fileName;			//название файла
	auto value = 0, stop = 1;
	string::size_type n;
	
#pragma region Authors
	CAuthor author;				//переменная поля автор
	CAuthor* listAuthors;		//список авторов
	listAuthors = author.createList(4);
#pragma endregion Authors

#pragma region Program
	CList list;					//список программ
	C_Program getProgram;		//программа, которая вернётся при получении ID
	C_Program newProgram;		//программа для добавления в список
	int size;					//количество элементов больше определённого размера
	stringstream str;
	list.createList(4, listAuthors);
#pragma endregion Program

#pragma region Malware
	MalwareList list2;			//список вредоносного ПО
	CMalware getProgram2;
	CMalware newProgram2;
	int size2;
	stringstream str2;
	list2.createList(4, listAuthors);
#pragma endregion Malware

	cout << endl << "Выберите команду для работы со списком: ";
	while (stop != 0)
	{
		if (list.getListSize() == 0)
		{
			cout << "Список пуст. Что вы хотите сделать?" << endl;
			cout << "1) Добавить элемент вручную" << endl;
			cout << "2) Прочитать данные из файла" << endl;
			cout << "3) Завершение работы" << endl;
			cout << "======================================" << endl;
			cout << "Ваш выбор: ";
			cin >> choise;
			cout << endl;

			switch (choise)
			{
			case 1:
				cout << "Базовый класс" << endl;
				list.enterNewEl();
				cout << "Класс наследник" << endl;
				list2.enterNewEl();
				break;

			case 2:
				cout << "Введите название файла для чтения данных для базового класса: ";
				cin >> fileName;
				cout << endl;

				n = fileName.find(".txt");
				if (n > 187) fileName += string(".txt");

				cout << "Базовый класс" << endl;
				list.readFile(fileName);

				cout << "Введите название файла для чтения данных для базового класса: ";
				cin >> fileName;
				cout << endl;

				n = fileName.find(".txt");
				if (n > 187) fileName += string(".txt");

				cout << "Класс наследник" << endl;
				list2.readFile(fileName);

				break;

			case 3:
				cout << "Завершение работы." << endl;
				stop = 0;
				break;

			default:
				cout << "Неверный номер элемента. Повторите попытку." << endl;
				break;
			}
		}
		else
		{
			cout << endl;
			cout << "1)Вывод на экран" << endl;
			cout << "2)Работа с файлами" << endl;
			cout << "3)Сортировка данных" << endl;
			cout << "4)Удаление элемента" << endl;
			cout << "5)Добавление элементов" << endl;
			cout << "6)Завершение работы" << endl;
			cout << "======================================" << endl;
			cout << "Ваш выбор: ";
			cin >> choise;
			cout << endl;
		}

		switch (choise)
		{
		case 1:
			cout << "Выберите команду:" << endl;
			cout << "1) Вывести весь список на экран" << endl;
			cout << "2) Вывести один элемент на экран по номеру" << endl;
			cout << "3) Вывести список программ меньше определённого размера и не трояны" << endl;
			cout << "4) Вывести список программ, названия которых состоят из 2 слов" << endl;
			cout << "5) Получить строку с данными" << endl;
			cout << "6) Вывести программу по ID" << endl;
			cout << "7) Вернуться к выбору действий" << endl;
			cout << "======================================" << endl;
			cout << "Ваш выбор: ";
			cin >> choise2;
			cout << endl;

			switch (choise2)
			{
			case 1:
				cout << "Базовый класс" << endl;
				list.printAll();
				cout << "Класс наследник" << endl;
				list2.printAll();

				break;

			case 2:
				cout << "Введите номер элемента, который надо вывести: ";
				cin >> value;
				cout << endl;

				if (value <= 0 || value > list.getListSize())
				{
					cout << "Неверный номер элемента. Повторите попытку." << endl;
					break;
				}

				cout << "Базовый класс" << endl;
				list.printOneEl(value - 1);
				cout << "Класс наследник" << endl;
				list2.printOneEl(value - 1);

				break;

			case 3:
				cout << "Введите минимальный размер программ: ";
				cin >> value;
				cout << endl;
				
				cout << "Базовый класс" << endl;
				size = list.task(value);
				cout << "Класс наследник" << endl;
				size2 = list2.task(value);
				break;

			case 4:
				cout << "Базовый класс" << endl;
				list.regexTask();
				cout << "Класс наследник" << endl;
				list2.regexTask();
				break;

			case 5:
				cout << "Введите номер элемента, который вы хотите получить: ";
				cin >> value;
				cout << endl;

				cout << "Базовый класс" << endl;
				str = list.getOneEl(value - 1);
				list.showOneEl(str);
				cout << "Класс наследник" << endl;
				str2 = list2.getOneEl(value - 1);
				list2.showOneEl(str2);
				break;

			case 6:
				cout << "Введите id элемента, которого вы хотите получить: ";
				cin >> value;
				cout << endl;

				cout << "Базовый класс" << endl;
				getProgram = list.getProgramID(value);
				cout << "Класс наследник" << endl;
				getProgram2 = list2.getProgramID(value);
				break;

			case 7:
				break;

			default:
				cout << "Неверный символ. Повторите попытку." << endl;
				break;
			}
			break;
		case 2:
			cout << "Выберите команду:" << endl;
			cout << "1) Сохранить данные в файл" << endl;
			cout << "2) Читать данные из файла" << endl;
			cout << "3) Вернуться к выбору" << endl;
			cout << "======================================" << endl;
			cout << "Ваш выбор: ";
			cin >> choise2;
			cout << endl;
			
			switch (choise2)
			{
			case 1:
				cout << "Введите название файла для записи данных программ: ";
				cin >> fileName;
				cout << endl;

				n = fileName.find(".txt");
				if (n > 187) fileName += string(".txt");

				list.saveToFile(fileName);

				cout << "Введите название файла для записи данных вредоносного ПО: ";
				cin >> fileName;
				cout << endl;

				n = fileName.find(".txt");
				if (n > 187) fileName += string(".txt");

				list2.saveToFile(fileName);
				break;
			case 2:
				cout << "Введите название файла для чтения данных программ: ";
				cin >> fileName;
				cout << endl;

				n = fileName.find(".txt");
				if (n > 187) fileName += string(".txt");

				list.readFile(fileName);

				cout << "Введите название файла для чтения данных вредоносного ПО: ";
				cin >> fileName;
				cout << endl;

				n = fileName.find(".txt");
				if (n > 187) fileName += string(".txt");

				list2.readFile(fileName);
				break;
			case 3:
				break;
			default:
				cout << "Неверный символ. Повторите попытку." << endl;
				break;
			}
			break;
		case 3:
			cout << "Сортировать количество строк по:" << endl;
			cout << "1) Возрастанию" << endl;
			cout << "2) Убыванию" << endl;
			cout << "Ваш выбор: ";
			cin >> value;
			cout << endl;

			if (value == 1){
				list.sort(list.sortAsc);
				list2.sort(list.sortAsc);
			} else if (value == 2) {
				list.sort(list.sortDesc);
				list2.sort(list.sortDesc);
			} else cout << "Ошибка. Неверный номер команды." << endl;

			break;

		case 4:
			cout << "Введите номер элемента, который хотите удалить: ";
			cin >> value;
			cout << endl;

			list.deleteEl(value);
			list2.deleteEl(value);
			break;

		case 5:
			cout << "Выберите команду:" << endl;
			cout << "1) Добавить стандартную программу" << endl;
			cout << "2) Ввести данные с клавиатуры" << endl;
			cout << "3) Вернуться к выбору" << endl;
			cout << "======================================" << endl;
			cout << "Ваш выбор: ";
			cin >> choise2;
			cout << endl;

			switch (choise2)
			{
			case 1:
				list.addEl(newProgram);
				list2.addEl(newProgram2);
				break;

			case 2:
				list.enterNewEl();
				list2.enterNewEl();
				break;

			case 3:
				break;

			default:
				cout << "Неверный символ. Повторите попытку." << endl;
				break;
			}

			break;

		case 6:
			cout << "Завершение работы." << endl;
			stop = 0;
			break;

		default:
			cout << "Неверный символ. Повторите попытку." << endl;
			break;

		}
	}

	author.deleteList();
	return;
}