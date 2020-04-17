#include "programList.h"

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
	CProgram** programList;
	string fileName;			//название файла
	CList list;					//список программ
	CAuthor* listAuthors;		//список авторов
	CAuthor author;				//переменная поля автор
	auto choise = 1;
	auto choise2 = 0;
	auto choise3 = 0;
	auto value = 0, stop = 1;
	int result = 0, b, size;
	string::size_type n;
	stringstream str;
	
	listAuthors = author.createList(6);
	list.createList(4, listAuthors);

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
				list.enterNewProgram();
				break;

			case 2:
				cout << "Введите название файла для чтения данных для базового класса: ";
				cin >> fileName;
				cout << endl;

				n = fileName.find(".txt");
				if (n > 187) fileName += string(".txt");

				list.readFile(fileName);

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
			cout << "2) Вывести список программ больше определённого размера за авторством Microsoft" << endl;
			cout << "3) Вывести список программ, названия которых состоят из 2 слов" << endl;
			cout << "4) Вывести программу по ID" << endl;
			cout << "5) Вернуться к выбору действий" << endl;
			cout << "======================================" << endl;
			cout << "Ваш выбор: ";
			cin >> choise2;
			cout << endl;

			switch (choise2)
			{
			case 1:
				list.printAll();
				break;

			case 2:
				cout << "Введите минимальный размер программ: ";
				cin >> value;
				cout << endl;
				
				size = list.task(value);
				break;

			case 3:
				list.regexTask();

				if (size == 0) 
					cout << "Отсутствуют программы, содержащие 2 слова в названии." << endl;

				break;

			case 4:
				cout << "Введите id элемента, которого вы хотите получить: ";
				cin >> value;
				cout << endl;

				result = list.getProgramID(value);
				if (result == -5)
				{
					cout << "Элемент с таким ID отсутствует." << endl;
					break;
				}
				
				list.getOneEl(result);
				break;

			case 5:
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

				list.saveFile(fileName);
				break;

			case 2:
				cout << "Введите название файла для чтения данных программ: ";
				cin >> fileName;
				cout << endl;

				n = fileName.find(".txt");
				if (n > 187) fileName += string(".txt");

				list.readFile(fileName);
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
			} else if (value == 2) {
				list.sort(list.sortDesc);
			} else cout << "Ошибка. Неверный номер команды." << endl;

			break;

		case 4:
			cout << "Введите ID элемента, который хотите удалить: ";
			cin >> value;
			cout << endl;

			result = list.getProgramID(value);
			list.delProgram(result);

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
				cout << "1) Добавить программу вредоносного ПО" << endl;
				cout << "2) Добавить программу на продажу" << endl;
				cout << "======================================" << endl;
				cout << "Ваш выбор: ";
				cin >> choise3;
				cout << endl;

				if (choise3 == 1)
				{
					CProgram* newProgram = list.newProgram(listAuthors, 1);
					list.addProgram(newProgram);
					cout << "Программа добавлена." << endl;
					break;
				}
				else if (choise3 == 2)
				{
					CProgram* newProgram = list.newProgram(listAuthors, 2);
					list.addProgram(newProgram);
					cout << "Программа добавлена." << endl;
				}
				else 
				{
					cout << "Неверный номер выбора." << endl;
				}

				break;

			case 2:
				list.enterNewProgram();
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