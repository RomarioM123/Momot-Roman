#include "Header.h"
#include "program.h"
#include "malware.h"

CProgram* newProgram(int);
void VectorMenu();
void ListMenu();
void MapMenu();
void SetMenu();

int main()
{
	setlocale(LC_ALL, "Rus");	
	int choise = 0;
	bool stop = 1;

	while (stop)
	{
		cout << "Выберите STL контейнер:" << endl;
		cout << "1. Vector" << endl;
		cout << "2. List" << endl;
		cout << "3. Map" << endl;
		cout << "4. Set" << endl;
		cout << "5. Выход" << endl;
		cout << "=======================" << endl;
		cout << "Ваш выбор: ";
		cin >> choise;

		switch (choise)
		{
		case 1:
			VectorMenu();
			break;

		case 2:
			ListMenu();
			break;

		case 3:
			MapMenu();
			break;

		case 4:
			SetMenu();
			break;

		case 5:
			stop = 0;
			break;

		default:
			cout << "Ошибка. Неверная команда. Повторите попытку." << endl;
		}
	}

	if (_CrtDumpMemoryLeaks()) 
		cout << endl << "Есть утечка памяти." << endl;
	else 
		cout << endl << "Утечка памяти отсутствует." << endl;

	return 0;
}

CProgram* newProgram(int value)
{
	if (value % 2 == 0)
	{
		CProgram* temp = new CMalware(1, 5231, 505, 101, 56234, "KeySaver", "Keylogger");
		return temp;
	}
	else
	{
		CProgram* temp = new CProgram(0, 645, 634, 6745, 45678, "Photoshop");
		return temp;
	}
}

void VectorMenu()
{
	vector <unique_ptr<CProgram>> vector;
	std::vector<unique_ptr<CProgram>>::iterator it;
	stringstream temp;
	string data;
	bool stop = 1, findEl = 0;
	int choise = 0, choise2 = 0, choise3 = 0;
	int value = 0, number = 0, result = 0, sum = 0;
	
	for (size_t i = 0; i < 4; i++)
	{
		if (i == 0)
			vector.emplace_back(new CProgram());
		else if (i == 1)
			vector.emplace_back(new CMalware(1, 8800, 555, 35, 35634, "BestMalware", "Exploit"));
		else if (i == 2)
			vector.emplace_back(new CProgram(0, 423, 523, 654, 53453, "Calculator"));
		else if (i == 3)
			vector.emplace_back(new CMalware(0, 345, 789, 423, 67456, "MoneyStealer", "Rootkit"));
	}

	while (stop != 0)
	{
		if (vector.size() == 0)
		{
			cout << "Вектор пуст. Что вы хотите сделать?" << endl;
			cout << "1) Добавить элемент" << endl;
			cout << "2) Завершение работы" << endl;
			cout << "======================================" << endl;
			cout << "Ваш выбор: ";
			cin >> choise;
			cout << endl;

			switch (choise)
			{
			case 1:
				cout << "Выберите программу, которую хотите добавить:" << endl;
				cout << "1. Элемент класса CProgram" << endl;
				cout << "2. Элемент класса CMalware" << endl;
				cout << "============================================" << endl;
				cout << "Ваш выбор: ";
				cin >> value;

				try
				{
					vector.at(value);

					if (value == 1 || value == 2)
					{
						vector.emplace_back(newProgram(value));
						cout << "Элемент добавлен." << endl;
					}
					else
						cout << "Ошибка. Неверный номер." << endl;
				}
				catch (const std::exception& ex)
				{
					cout << ex.what() << endl;
				}

				break;

			case 2:
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
			cout << "2)Удаление элемента" << endl;
			cout << "3)Добавление элементов" << endl;
			cout << "4)Завершение работы" << endl;
			cout << "======================" << endl;
			cout << "Ваш выбор: ";
			cin >> choise;
			cout << endl;
		}

		switch (choise)
		{
		case 1:
			cout << "Выберите команду:" << endl;
			cout << "1) Вывести весь список на экран" << endl;
			cout << "2) Вывести программу по ID" << endl;
			cout << "3) Вывести количество элементов по критерию" << endl;
			cout << "4) Найти элемент по критерию" << endl;
			cout << "5) Вернуться к выбору действий" << endl;
			cout << "======================================" << endl;
			cout << "Ваш выбор: ";
			cin >> choise2;
			cout << endl;

			switch (choise2)
			{
			case 1:
				cout << setw(12) << "Название" << setw(14) << "Индекс";
				cout << setw(14) << "Время работы" << setw(8) << "Размер";
				cout << setw(18) << "Количество линий" << setw(10) << "Интернет";
				cout << setw(10) << "Тип" << endl;
				
				number = 1;
				for_each(vector.begin(), vector.end(), [&number](const unique_ptr<CProgram>& program)
					{
						cout << number << ". " << *program << endl;
						number++;
					});
				number = 1;
				break;

			case 2:
				cout << "Введите id элемента, которого вы хотите получить: ";
				cin >> value;
				cout << endl;

				findEl = 0, number = -1;
				for (const auto& element: vector)
				{
					if (element->getID() == value)
					{
						number++;
						findEl = 1;
						break;
					}
					else
						number++;
				}

				if (findEl)
				{
					temp = vector[number]->getStr();
					data = temp.str();
					cout << "Ваш элемент: " << endl;
					cout << data << endl << endl;
				}
				else
					cout << "Элемент с таким ID не найден." << endl;
				
				break;
			case 3:
				cout << "Выберите критерий, по которому надо искать: " << endl;
				cout << "1) Название" << endl;
				cout << "2) Время работы" << endl;
				cout << "3) Размер" << endl;
				cout << "4) Количество строк кода" << endl;
				cout << "5) Индекс" << endl;
				cout << "6) Использует ли интернет" << endl;
				cout << "7) Вернуться назад" << endl;
				cout << "======================================" << endl;
				cout << "Ваш выбор: ";
				cin >> choise3;
				cout << endl;

				if (choise3 < 1 || choise3 >= 7)
				{
					cout << "Возвращение назад." << endl;
					break;
				}

				it = vector.begin();

				cout << "Введите критерий: ";
				cin.ignore();
				getline(cin, data);
				number = 0, value = 0;

				while (number < vector.size())
				{
					result = (*it)->countElement(choise3, data);
					number++;
					it++;
					sum += result;
				}
				if (sum != 0)
					cout << "Количество элементов с данным параметром: " << sum << endl;

				break;

			case 4:
				cout << "Выберите критерий, по которому надо искать: " << endl;
				cout << "1) Название" << endl;
				cout << "2) Время работы" << endl;
				cout << "3) Размер" << endl;
				cout << "4) Количество строк кода" << endl;
				cout << "5) Индекс" << endl;
				cout << "6) Использует ли интернет" << endl;
				cout << "7) Вернуться назад" << endl;
				cout << "======================================" << endl;
				cout << "Ваш выбор: ";
				cin >> choise3;
				cout << endl;

				if (choise3 < 1 || choise3 >= 7)
				{
					cout << "Возвращение назад." << endl;
					break;
				}

				it = vector.begin();
				cout << "Введите критерий: ";
				cin.ignore();
				getline(cin, data);
				number = 0, value = 0;

				while (number < vector.size())
				{
					result = (*it)->elementOutput(choise3, data);
					number++;
					it++;
				}

				break;
			case 5:
				cout << "Возвращение назад." << endl;
				break;

			default:
				cout << "Неверный символ. Повторите попытку." << endl;
				break;

			}
			break;
		
		case 2:
			cout << "Введите ID элемента, который хотите удалить: ";
			cin >> value;
			cout << endl;

			findEl = 0, number = -1;
			for (const auto& element:vector)
			{
				if (element->getID() == value)
				{
					number++;
					findEl = 1;
					break;
				}
				else
					number++;
			}

			if (findEl)
			{
				it = vector.begin();
				advance(it, number);
				vector.erase(it);

				cout << "Удаление выполнено." << endl;
			}
			else
				cout << "Элемент не найден." << endl;

			break;

		case 3:
			cout << "Выберите программу, которую хотите добавить:" << endl;
			cout << "1. Элемент класса CProgram" << endl;
			cout << "2. Элемент класса CMalware" << endl;
			cout << "============================================" << endl;
			cout << "Ваш выбор: ";
			cin >> value;

			try
			{
				vector.at(value);

				if (value == 1 || value == 2)
				{
					vector.emplace_back(newProgram(value));
					cout << "Элемент добавлен." << endl;
				}
				else
					cout << "Ошибка. Неверный номер." << endl;
			}
			catch (const std::exception & ex)
			{
				cout << ex.what() << endl;
			}

			break;

		case 4:
			cout << "Завершение работы." << endl << endl;
			stop = 0;
			break;

		default:
			cout << "Неверный символ. Повторите попытку." << endl;
			break;

		}
	}
}
void ListMenu()
{
	list <unique_ptr<CProgram>> list;
	stringstream temp;
	string data;
	bool stop = 1, findEl = 0;
	int choise = 0, choise2 = 0, choise3 = 0;
	int value = 0;
	int number = 0;
	int result = 0, sum = 0;
	auto it = list.begin();

	for (size_t i = 0; i < 4; i++)
	{
		if (i == 0)
			list.emplace_back(new CProgram());
		else if (i == 1)
			list.emplace_back(new CMalware(1, 8800, 555, 35, 35634, "BestMalware", "Exploit"));
		else if (i == 2)
			list.emplace_back(new CProgram(0, 423, 523, 654, 53453, "Calculator"));
		else if (i == 3)
			list.emplace_back(new CMalware(0, 345, 789, 423, 67456, "MoneyStealer", "Rootkit"));
	}

	while (stop != 0)
	{
		if (list.size() == 0)
		{
			cout << "Вектор пуст. Что вы хотите сделать?" << endl;
			cout << "1) Добавить элемент" << endl;
			cout << "2) Завершение работы" << endl;
			cout << "======================================" << endl;
			cout << "Ваш выбор: ";
			cin >> choise;
			cout << endl;

			switch (choise)
			{
			case 1:
				cout << "Выберите программу, которую хотите добавить:" << endl;
				cout << "1. Элемент класса CProgram" << endl;
				cout << "2. Элемент класса CMalware" << endl;
				cout << "============================================" << endl;
				cout << "Ваш выбор: ";
				cin >> value;

				try
				{
					if (value == 1 || value == 2)
					{
						list.emplace_front(newProgram(value));
						cout << "Элемент добавлен." << endl;
					}
					else
						cout << "Ошибка. Неверный номер." << endl;
				}
				catch (const std::exception & ex)
				{
					cout << ex.what() << endl;
				}

				break;

			case 2:
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
			cout << "2)Удаление элемента" << endl;
			cout << "3)Добавление элементов" << endl;
			cout << "4)Завершение работы" << endl;
			cout << "======================" << endl;
			cout << "Ваш выбор: ";
			cin >> choise;
			cout << endl;
		}

		switch (choise)
		{
		case 1:
			cout << "Выберите команду:" << endl;
			cout << "1) Вывести весь список на экран" << endl;
			cout << "2) Вывести программу по ID" << endl;
			cout << "3) Вывести количество элементов по критерию" << endl;
			cout << "4) Найти элемент по критерию" << endl;
			cout << "5) Вернуться к выбору действий" << endl;
			cout << "======================================" << endl;
			cout << "Ваш выбор: ";
			cin >> choise2;
			cout << endl;

			switch (choise2)
			{
			case 1:
				cout << setw(12) << "Название" << setw(14) << "Индекс";
				cout << setw(14) << "Время работы" << setw(8) << "Размер";
				cout << setw(18) << "Количество линий" << setw(10) << "Интернет";
				cout << setw(10) << "Тип" << endl;

				number = 1;
				for_each(list.begin(), list.end(), [&number](const unique_ptr<CProgram>& program)
					{
						cout << number << ". " << *program << endl;
						number++;
					});
				number = 1;
				break;

			case 2:
				cout << "Введите id элемента, которого вы хотите получить: ";
				cin >> value;
				cout << endl;

				findEl = 0, number = -1;
				for (const auto& element : list)
				{
					if (element->getID() == value)
					{
						number++;
						findEl = 1;
						break;
					}
					else
						number++;
				}

				if (findEl)
				{
					it = list.begin();
					advance(it, number);

					temp = (*it)->getStr();
					data = temp.str();

					cout << "Ваш элемент: " << endl;
					cout << data << endl << endl;
				}
				else
					cout << "Элемент с таким ID не найден." << endl;

				break;

			case 3:
				cout << "Выберите критерий, по которому надо искать: " << endl;
				cout << "1) Название" << endl;
				cout << "2) Время работы" << endl;
				cout << "3) Размер" << endl;
				cout << "4) Количество строк кода" << endl;
				cout << "5) Индекс" << endl;
				cout << "6) Использует ли интернет" << endl;
				cout << "7) Вернуться назад" << endl;
				cout << "======================================" << endl;
				cout << "Ваш выбор: ";
				cin >> choise3;
				cout << endl;

				if (choise3 < 1 || choise3 >= 7)
				{
					cout << "Возвращение назад." << endl;
					break;
				}

				it = list.begin();
				result = 0, sum = 0;
				cout << "Введите критерий: ";
				cin.ignore();
				getline(cin, data);
				number = 0, value = 0;

				while (number < list.size())
				{
					result = (*it)->countElement(choise3, data);
					number++;
					it++;
					sum += result;
				}
				if (sum != 0)
					cout << "Количество элементов с данным параметром: " << sum << endl;

				break;

			case 4:
				cout << "Выберите критерий, по которому надо искать: " << endl;
				cout << "1) Название" << endl;
				cout << "2) Время работы" << endl;
				cout << "3) Размер" << endl;
				cout << "4) Количество строк кода" << endl;
				cout << "5) Индекс" << endl;
				cout << "6) Использует ли интернет" << endl;
				cout << "7) Вернуться назад" << endl;
				cout << "======================================" << endl;
				cout << "Ваш выбор: ";
				cin >> choise3;
				cout << endl;

				if (choise3 < 1 || choise3 >= 7)
				{
					cout << "Возвращение назад." << endl;
					break;
				}

				it = list.begin();
				cout << "Введите критерий: ";
				cin.ignore();
				getline(cin, data);
				number = 0, value = 0;

				while (number < list.size())
				{
					result = (*it)->elementOutput(choise3, data);
					number++;
					it++;
				}

				break;
			case 5:
				cout << "Возвращение назад." << endl;
				break;

			default:
				cout << "Неверный символ. Повторите попытку." << endl;
				break;

			}
			break;

		case 2:
			cout << "Введите ID элемента, который хотите удалить: ";
			cin >> value;
			cout << endl;

			findEl = 0, number = -1;
			for (const auto& element : list)
			{
				if (element->getID() == value)
				{
					number++;
					findEl = 1;
					break;
				}
				else
					number++;
			}

			if (findEl)
			{
				it = list.begin();
				advance(it, number);
				list.erase(it);

				cout << "Удаление выполнено." << endl;
			}
			else
				cout << "Элемент не найден." << endl;

			break;

		case 3:
			cout << "Выберите программу, которую хотите добавить:" << endl;
			cout << "1. Элемент класса CProgram" << endl;
			cout << "2. Элемент класса CMalware" << endl;
			cout << "============================================" << endl;
			cout << "Ваш выбор: ";
			cin >> value;

			try
			{
				if (value == 1 || value == 2)
				{
					list.emplace_front(newProgram(value));
					cout << "Элемент добавлен." << endl;
				}
				else
					cout << "Ошибка. Неверный номер." << endl;
			}
			catch (const std::exception & ex)
			{
				cout << ex.what() << endl;
			}

			break;

		case 4:
			cout << "Завершение работы." << endl << endl;
			stop = 0;
			break;

		default:
			cout << "Неверный символ. Повторите попытку." << endl;
			break;

		}
	}
}
void MapMenu()
{
	map <int, unique_ptr<CProgram>> map;
	stringstream temp;
	string data;
	bool stop = 1, findEl = 0;
	int choise = 0, choise2 = 0, choise3 = 0;
	int value = 0;
	int i = 0;
	int number = 0, sum = 0, result = 0;
	auto it = map.begin();

	for (; i < 4; i++)
	{
		if (i == 0)
			map.emplace(i + 1, new CProgram());
		else if (i == 1)
			map.emplace(i + 1, new CMalware(1, 8800, 555, 35, 35634, "BestMalware", "Exploit"));
		else if (i == 2)
			map.emplace(i + 1, new CProgram(0, 423, 523, 654, 53453, "Calculator"));
		else if (i == 3)
			map.emplace(i + 1, new CMalware(0, 345, 789, 423, 67456, "MoneyStealer", "Rootkit"));
	}

	while (stop != 0)
	{
		if (map.size() == 0)
		{
			cout << "Вектор пуст. Что вы хотите сделать?" << endl;
			cout << "1) Добавить элемент" << endl;
			cout << "2) Завершение работы" << endl;
			cout << "======================================" << endl;
			cout << "Ваш выбор: ";
			cin >> choise;
			cout << endl;

			switch (choise)
			{
			case 1:
				cout << "Выберите программу, которую хотите добавить:" << endl;
				cout << "1. Элемент класса CProgram" << endl;
				cout << "2. Элемент класса CMalware" << endl;
				cout << "============================================" << endl;
				cout << "Ваш выбор: ";
				cin >> value;

				try
				{
					if (value == 1 || value == 2)
					{
						map.emplace(++i, newProgram(value));
						cout << "Элемент добавлен." << endl;
					}
					else
						cout << "Ошибка. Неверный номер." << endl;
				}
				catch (const std::exception & ex)
				{
					cout << ex.what() << endl;
				}

				break;

			case 2:
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
			cout << "2)Удаление элемента" << endl;
			cout << "3)Добавление элементов" << endl;
			cout << "4)Завершение работы" << endl;
			cout << "======================" << endl;
			cout << "Ваш выбор: ";
			cin >> choise;
			cout << endl;
		}

		switch (choise)
		{
		case 1:
			cout << "Выберите команду:" << endl;
			cout << "1) Вывести весь список на экран" << endl;
			cout << "2) Вывести программу по ID" << endl;
			cout << "3) Вывести количество элементов по критерию" << endl;
			cout << "4) Найти элемент по критерию" << endl;
			cout << "5) Вернуться к выбору действий" << endl;
			cout << "======================================" << endl;
			cout << "Ваш выбор: ";
			cin >> choise2;
			cout << endl;

			switch (choise2)
			{
			case 1:
				cout << setw(12) << "Название" << setw(14) << "Индекс";
				cout << setw(14) << "Время работы" << setw(8) << "Размер";
				cout << setw(18) << "Количество линий" << setw(10) << "Интернет";
				cout << setw(10) << "Тип" << endl;

				for_each(map.begin(), map.end(), [](const std::pair<const int, unique_ptr<CProgram>>& program)
					{
						cout << program.first << ". " << *program.second << endl;
					});
				
				break;

			case 2:
				cout << "Введите номер элемента, которого вы хотите получить: ";
				cin >> value;
				cout << endl;

				findEl = 0;
				it = map.find(value);

				if (it != map.end())
				{
					temp = (*it).second->getStr();
					data = temp.str();

					cout << "Ваш элемент: " << endl;
					cout << data << endl << endl;
				}
				else
					cout << "Элемент с таким ID не найден." << endl;

				break;

			case 3:
				cout << "Выберите критерий, по которому надо искать: " << endl;
				cout << "1) Название" << endl;
				cout << "2) Время работы" << endl;
				cout << "3) Размер" << endl;
				cout << "4) Количество строк кода" << endl;
				cout << "5) Индекс" << endl;
				cout << "6) Использует ли интернет" << endl;
				cout << "7) Вернуться назад" << endl;
				cout << "======================================" << endl;
				cout << "Ваш выбор: ";
				cin >> choise3;
				cout << endl;

				if (choise3 < 1 || choise3 >= 7)
				{
					cout << "Возвращение назад." << endl;
					break;
				}

				it = map.begin();
				result = 0, sum = 0;
				cout << "Введите критерий: ";
				cin.ignore();
				getline(cin, data);
				number = 0, value = 0;

				while (number < map.size())
				{
					result = it->second->countElement(choise3, data);
					number++;
					it++;
					sum += result;
				}
				if (sum != 0)
					cout << "Количество элементов с данным параметром: " << sum << endl;

				break;

			case 4:
				cout << "Выберите критерий, по которому надо искать: " << endl;
				cout << "1) Название" << endl;
				cout << "2) Время работы" << endl;
				cout << "3) Размер" << endl;
				cout << "4) Количество строк кода" << endl;
				cout << "5) Индекс" << endl;
				cout << "6) Использует ли интернет" << endl;
				cout << "7) Вернуться назад" << endl;
				cout << "======================================" << endl;
				cout << "Ваш выбор: ";
				cin >> choise3;
				cout << endl;

				if (choise3 < 1 || choise3 >= 7)
				{
					cout << "Возвращение назад." << endl;
					break;
				}

				it = map.begin();
				cout << "Введите критерий: ";
				cin.ignore();
				getline(cin, data);
				number = 0, value = 0;

				while (number < map.size())
				{
					result = it->second->elementOutput(choise3, data);
					number++;
					it++;
				}

				break;
			case 5:
				cout << "Возвращение назад." << endl;
				break;

			default:
				cout << "Неверный символ. Повторите попытку." << endl;
				break;

			}
			break;

		case 2:
			cout << "Введите номер элемента, который хотите удалить: ";
			cin >> value;
			cout << endl;

			findEl = 0;
			it = map.find(value);

			if (it != map.end())
			{
				map.erase(it);
				cout << "Удаление выполнено." << endl;
			}
			else
				cout << "Элемент не найден." << endl;

			break;

		case 3:
			cout << "Выберите программу, которую хотите добавить:" << endl;
			cout << "1. Элемент класса CProgram" << endl;
			cout << "2. Элемент класса CMalware" << endl;
			cout << "============================================" << endl;
			cout << "Ваш выбор: ";
			cin >> value;

			try
			{
				if (value == 1 || value == 2)
				{
					map.emplace(++i, newProgram(value));
					cout << "Элемент добавлен." << endl;
				}
				else
					cout << "Ошибка. Неверный номер." << endl;
			}
			catch (const std::exception & ex)
			{
				cout << ex.what() << endl;
			}

			break;

		case 4:
			cout << "Завершение работы." << endl << endl;
			stop = 0;
			break;

		default:
			cout << "Неверный символ. Повторите попытку." << endl;
			break;

		}
	}
}
void SetMenu()
{
	set <unique_ptr<CProgram>> set;
	stringstream temp;
	string data;
	bool stop = 1, findEl = 0;
	int choise = 0, choise2 = 0, choise3 = 0;
	int value = 0, number = 0, result = 0, sum = 0;
	auto it = set.begin();

	for (size_t i = 0; i < 4; i++)
	{
		if (i == 0)
			set.emplace(new CProgram());
		else if (i == 1)
			set.emplace(new CMalware(1, 8800, 555, 35, 35634, "BestMalware", "Exploit"));
		else if (i == 2)
			set.emplace(new CProgram(0, 423, 523, 654, 53453, "Calculator"));
		else if (i == 3)
			set.emplace(new CMalware(0, 345, 789, 423, 67456, "MoneyStealer", "Rootkit"));
	}

	while (stop != 0)
	{
		if (set.size() == 0)
		{
			cout << "Вектор пуст. Что вы хотите сделать?" << endl;
			cout << "1) Добавить элемент" << endl;
			cout << "2) Завершение работы" << endl;
			cout << "======================================" << endl;
			cout << "Ваш выбор: ";
			cin >> choise;
			cout << endl;

			switch (choise)
			{
			case 1:
				cout << "Выберите программу, которую хотите добавить:" << endl;
				cout << "1. Элемент класса CProgram" << endl;
				cout << "2. Элемент класса CMalware" << endl;
				cout << "============================================" << endl;
				cout << "Ваш выбор: ";
				cin >> value;

				try
				{
					if (value == 1 || value == 2)
					{
						set.emplace(newProgram(value));
						cout << "Элемент добавлен." << endl;
					}
					else
						cout << "Ошибка. Неверный номер." << endl;
				}
				catch (const std::exception & ex)
				{
					cout << ex.what() << endl;
				}

				break;

			case 2:
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
			cout << "2)Удаление элемента" << endl;
			cout << "3)Добавление элементов" << endl;
			cout << "4)Завершение работы" << endl;
			cout << "======================" << endl;
			cout << "Ваш выбор: ";
			cin >> choise;
			cout << endl;
		}

		switch (choise)
		{
		case 1:
			cout << "Выберите команду:" << endl;
			cout << "1) Вывести весь список на экран" << endl;
			cout << "2) Вывести программу по ID" << endl;
			cout << "3) Вывести количество элементов по критерию" << endl;
			cout << "4) Найти элемент по критерию" << endl;
			cout << "5) Вернуться к выбору действий" << endl;
			cout << "======================================" << endl;
			cout << "Ваш выбор: ";
			cin >> choise2;
			cout << endl;

			switch (choise2)
			{
			case 1:
				cout << setw(12) << "Название" << setw(14) << "Индекс";
				cout << setw(14) << "Время работы" << setw(8) << "Размер";
				cout << setw(18) << "Количество линий" << setw(10) << "Интернет";
				cout << setw(10) << "Тип" << endl;

				number = 1;
				for_each(set.begin(), set.end(), [&number](const unique_ptr<CProgram>& program)
					{
						cout << number << ". " << *program << endl;
						number++;
					});
				number = 1;
				break;

			case 2:
				cout << "Введите id элемента, которого вы хотите получить: ";
				cin >> value;
				cout << endl;

				findEl = 0, number = -1;
				for (const auto& element : set)
				{
					if (element->getID() == value)
					{
						number++;
						findEl = 1;
						break;
					}
					else
						number++;
				}

				if (findEl)
				{
					it = set.begin();
					advance(it, number);

					temp = (*it)->getStr();
					data = temp.str();

					cout << "Ваш элемент: " << endl;
					cout << data << endl << endl;
				}
				else
					cout << "Элемент с таким ID не найден." << endl;

				break;

			case 3:
				cout << "Выберите критерий, по которому надо искать: " << endl;
				cout << "1) Название" << endl;
				cout << "2) Время работы" << endl;
				cout << "3) Размер" << endl;
				cout << "4) Количество строк кода" << endl;
				cout << "5) Индекс" << endl;
				cout << "6) Использует ли интернет" << endl;
				cout << "7) Вернуться назад" << endl;
				cout << "======================================" << endl;
				cout << "Ваш выбор: ";
				cin >> choise3;
				cout << endl;

				if (choise3 < 1 || choise3 >= 7)
				{
					cout << "Возвращение назад." << endl;
					break;
				}

				it = set.begin();
				result = 0, sum = 0;
				cout << "Введите критерий: ";
				cin.ignore();
				getline(cin, data);
				number = 0, value = 0;

				while (number < set.size())
				{
					result = (*it)->countElement(choise3, data);
					number++;
					it++;
					sum += result;
				}
				if (sum != 0)
					cout << "Количество элементов с данным параметром: " << sum << endl;

				break;

			case 4:
				cout << "Выберите критерий, по которому надо искать: " << endl;
				cout << "1) Название" << endl;
				cout << "2) Время работы" << endl;
				cout << "3) Размер" << endl;
				cout << "4) Количество строк кода" << endl;
				cout << "5) Индекс" << endl;
				cout << "6) Использует ли интернет" << endl;
				cout << "7) Вернуться назад" << endl;
				cout << "======================================" << endl;
				cout << "Ваш выбор: ";
				cin >> choise3;
				cout << endl;

				if (choise3 < 1 || choise3 >= 7)
				{
					cout << "Возвращение назад." << endl;
					break;
				}

				it = set.begin();
				cout << "Введите критерий: ";
				cin.ignore();
				getline(cin, data);
				number = 0, value = 0;

				while (number < set.size())
				{
					result = (*it)->elementOutput(choise3, data);
					number++;
					it++;
				}

				break;
			case 5:
				cout << "Возвращение назад." << endl;
				break;

			default:
				cout << "Неверный символ. Повторите попытку." << endl;
				break;

			}
			break;

		case 2:
			cout << "Введите ID элемента, который хотите удалить: ";
			cin >> value;
			cout << endl;

			findEl = 0, number = -1;
			for (const auto& element : set)
			{
				if (element->getID() == value)
				{
					number++;
					findEl = 1;
					break;
				}
				else
					number++;
			}

			if (findEl)
			{
				it = set.begin();
				advance(it, number);
				set.erase(it);

				cout << "Удаление выполнено." << endl;
			}
			else
				cout << "Элемент не найден." << endl;

			break;

		case 3:
			cout << "Выберите программу, которую хотите добавить:" << endl;
			cout << "1. Элемент класса CProgram" << endl;
			cout << "2. Элемент класса CMalware" << endl;
			cout << "============================================" << endl;
			cout << "Ваш выбор: ";
			cin >> value;

			try
			{
				if (value == 1 || value == 2)
				{
					set.emplace(newProgram(value));
					cout << "Элемент добавлен." << endl;
				}
				else
					cout << "Ошибка. Неверный номер." << endl;
			}
			catch (const std::exception & ex)
			{
				cout << ex.what() << endl;
			}

			break;

		case 4:
			cout << "Завершение работы." << endl << endl;
			stop = 0;
			break;

		default:
			cout << "Неверный символ. Повторите попытку." << endl;
			break;

		}
	}
}

