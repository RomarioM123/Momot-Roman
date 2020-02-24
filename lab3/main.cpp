#include "Program.h"
#include "List.h"

void Menu();

int main()
{
	setlocale(LC_ALL, "Rus");
	Menu();

	if (_CrtDumpMemoryLeaks()) cout << endl << "Есть утечка памяти." << endl;
	else cout << endl << "Утечка памяти отсутствует." << endl;

	return 0;
}

void Menu()
{
	C_List list;
	C_Program getProgram;		//программа, которая вернётся при получении ID
	C_Program newProgram;		//программа для добавления в список
	int choise = 1, value = 0, stop = 1;
	string fileName;			//переменная для названия файла
	string::size_type n;		
	list.CreateList(4);
	cout << endl << "Выберите команду для работы со списком: " << endl;

	while (stop != 0)
	{
		if (list.getListSize() == 0)
		{
			cout << "Список пуст. Добавить элемент(1) или закончить работу(0): " << endl;
			cin >> choise;
			cout << endl;

			if (choise == 1) choise = 3;
			else if (choise == 0) choise = 5;
			else cout << "Неверный символ." << endl;
		}
		else
		{
			cout << endl << endl;
			cout << "1)Вывести всё на экран" << endl;
			cout << "2)Вывести 1 элемент на экран" << endl;
			cout << "3)Найти программу по индексу" << endl;
			cout << "4)Добавить элемент (в конец)" << endl;
			cout << "5)Удалить элемент" << endl;
			cout << "6)Получить список программ меньше определённого размера и не трояны" << endl;
			cout << "7)Получить данные из файла" << endl;
			cout << "8)Записать данные в файл" << endl;
			cout << "9)Завершение работы" << endl;
			cout << "=============================" << endl << "Ваш выбор: ";
			cin >> choise;
			cout << endl;
		}

		switch (choise)
		{
		case 1:
			list.PrintAll();
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
			list.PrintOneEl(value - 1);
			break;
		case 3:
			cout << "Введите id элемента, которого вы хотите получить: ";
			cin >> value;
			cout << endl;

			getProgram = list.GetProgramID(value);
			break;
		case 4:
			list.AddEl(newProgram);
			break;
		case 5:
			cout << "Введите номер элемента, который хотите удалить: ";
			cin >> value;
			cout << endl;

			list.DeleteEl(value);
			break;
		case 6:
			cout << "Введите минимальный размер программ: ";
			cin >> value;
			cout << endl;

			list.Task(value);
			break;
		case 7:
			cout << "Введите название файла для чтения данных: ";
			cin >> fileName;
			cout << endl;

			n = fileName.find(".txt");
			if (n > 187) fileName += string(".txt");

			list.ReadFile(fileName);
			break;
		case 8:
			cout << "Введите название файла для записи данных: ";
			cin >> fileName;
			cout << endl;

			n = fileName.find(".txt");
			if (n > 187) fileName += string(".txt");

			list.SaveToFile(fileName);
			break;
		case 9:
			cout << "Завершение работы." << endl;
			stop = 0;
			break;
		default:
			cout << "Неверный символ. Повторите попытку." << endl;
			break;
		}
	}
	return;
}