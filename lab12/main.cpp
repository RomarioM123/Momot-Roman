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
		cout << "�������� STL ���������:" << endl;
		cout << "1. Vector" << endl;
		cout << "2. List" << endl;
		cout << "3. Map" << endl;
		cout << "4. Set" << endl;
		cout << "5. �����" << endl;
		cout << "=======================" << endl;
		cout << "��� �����: ";
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
			cout << "������. �������� �������. ��������� �������." << endl;
		}
	}

	if (_CrtDumpMemoryLeaks()) cout << endl << "���� ������ ������." << endl;
	else cout << endl << "������ ������ �����������." << endl;

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
	stringstream temp;
	string data;
	bool stop = 1, findEl = 0;
	int choise = 0, choise2 = 0;
	int value = 0;
	int number = 0;
	auto it = vector.begin();

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
			cout << "������ ����. ��� �� ������ �������?" << endl;
			cout << "1) �������� �������" << endl;
			cout << "2) ���������� ������" << endl;
			cout << "======================================" << endl;
			cout << "��� �����: ";
			cin >> choise;
			cout << endl;

			switch (choise)
			{
			case 1:
				cout << "�������� ���������, ������� ������ ��������:" << endl;
				cout << "1. ������� ������ CProgram" << endl;
				cout << "2. ������� ������ CMalware" << endl;
				cout << "============================================" << endl;
				cout << "��� �����: ";
				cin >> value;

				try
				{
					vector.at(value);

					if (value == 1 || value == 2)
					{
						vector.emplace_back(newProgram(value));
						cout << "������� ��������." << endl;
					}
					else
						cout << "������. �������� �����." << endl;
				}
				catch (const std::exception& ex)
				{
					cout << ex.what() << endl;
				}

				break;

			case 2:
				cout << "���������� ������." << endl;
				stop = 0;
				break;

			default:
				cout << "�������� ����� ��������. ��������� �������." << endl;
				break;
			}
		}
		else
		{
			cout << endl;
			cout << "1)����� �� �����" << endl;
			cout << "2)�������� ��������" << endl;
			cout << "3)���������� ���������" << endl;
			cout << "4)���������� ������" << endl;
			cout << "======================" << endl;
			cout << "��� �����: ";
			cin >> choise;
			cout << endl;
		}

		switch (choise)
		{
		case 1:
			cout << "�������� �������:" << endl;
			cout << "1) ������� ���� ������ �� �����" << endl;
			cout << "2) ������� ��������� �� ID" << endl;
			cout << "3) ��������� � ������ ��������" << endl;
			cout << "======================================" << endl;
			cout << "��� �����: ";
			cin >> choise2;
			cout << endl;

			switch (choise2)
			{
			case 1:
				cout << setw(12) << "��������" << setw(14) << "������";
				cout << setw(14) << "����� ������" << setw(8) << "������";
				cout << setw(18) << "���������� �����" << setw(10) << "��������";
				cout << setw(10) << "���" << endl;

				for (const auto& element:vector)
				{
					cout << number << ". " << *element << endl;
					number++;
				}
				number = 1;
				break;

			case 2:
				cout << "������� id ��������, �������� �� ������ ��������: ";
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
					cout << "��� �������: " << endl;
					cout << data << endl << endl;
				}
				else
					cout << "������� � ����� ID �� ������." << endl;
				
				break;

			case 3:
				break;

			default:
				cout << "�������� ������. ��������� �������." << endl;
				break;

			}
			break;
		
		case 2:
			cout << "������� ID ��������, ������� ������ �������: ";
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

				cout << "�������� ���������." << endl;
			}
			else
				cout << "������� �� ������." << endl;

			break;

		case 3:
			cout << "�������� ���������, ������� ������ ��������:" << endl;
			cout << "1. ������� ������ CProgram" << endl;
			cout << "2. ������� ������ CMalware" << endl;
			cout << "============================================" << endl;
			cout << "��� �����: ";
			cin >> value;

			try
			{
				vector.at(value);

				if (value == 1 || value == 2)
				{
					vector.emplace_back(newProgram(value));
					cout << "������� ��������." << endl;
				}
				else
					cout << "������. �������� �����." << endl;
			}
			catch (const std::exception & ex)
			{
				cout << ex.what() << endl;
			}

			break;

		case 4:
			cout << "���������� ������." << endl << endl;
			stop = 0;
			break;

		default:
			cout << "�������� ������. ��������� �������." << endl;
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
	int choise = 0, choise2 = 0;
	int value = 0;
	int number = 0;
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
			cout << "������ ����. ��� �� ������ �������?" << endl;
			cout << "1) �������� �������" << endl;
			cout << "2) ���������� ������" << endl;
			cout << "======================================" << endl;
			cout << "��� �����: ";
			cin >> choise;
			cout << endl;

			switch (choise)
			{
			case 1:
				cout << "�������� ���������, ������� ������ ��������:" << endl;
				cout << "1. ������� ������ CProgram" << endl;
				cout << "2. ������� ������ CMalware" << endl;
				cout << "============================================" << endl;
				cout << "��� �����: ";
				cin >> value;

				try
				{
					if (value == 1 || value == 2)
					{
						list.emplace_front(newProgram(value));
						cout << "������� ��������." << endl;
					}
					else
						cout << "������. �������� �����." << endl;
				}
				catch (const std::exception & ex)
				{
					cout << ex.what() << endl;
				}

				break;

			case 2:
				cout << "���������� ������." << endl;
				stop = 0;
				break;

			default:
				cout << "�������� ����� ��������. ��������� �������." << endl;
				break;
			}
		}
		else
		{
			cout << endl;
			cout << "1)����� �� �����" << endl;
			cout << "2)�������� ��������" << endl;
			cout << "3)���������� ���������" << endl;
			cout << "4)���������� ������" << endl;
			cout << "======================" << endl;
			cout << "��� �����: ";
			cin >> choise;
			cout << endl;
		}

		switch (choise)
		{
		case 1:
			cout << "�������� �������:" << endl;
			cout << "1) ������� ���� ������ �� �����" << endl;
			cout << "2) ������� ��������� �� ID" << endl;
			cout << "3) ��������� � ������ ��������" << endl;
			cout << "======================================" << endl;
			cout << "��� �����: ";
			cin >> choise2;
			cout << endl;

			switch (choise2)
			{
			case 1:
				cout << setw(12) << "��������" << setw(14) << "������";
				cout << setw(14) << "����� ������" << setw(8) << "������";
				cout << setw(18) << "���������� �����" << setw(10) << "��������";
				cout << setw(10) << "���" << endl;

				for (const auto& element : list)
				{
					cout << number << ". " << *element << endl;
					number++;
				}
				number = 1;
				break;

			case 2:
				cout << "������� id ��������, �������� �� ������ ��������: ";
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

					cout << "��� �������: " << endl;
					cout << data << endl << endl;
				}
				else
					cout << "������� � ����� ID �� ������." << endl;

				break;

			case 3:
				break;

			default:
				cout << "�������� ������. ��������� �������." << endl;
				break;

			}
			break;

		case 2:
			cout << "������� ID ��������, ������� ������ �������: ";
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

				cout << "�������� ���������." << endl;
			}
			else
				cout << "������� �� ������." << endl;

			break;

		case 3:
			cout << "�������� ���������, ������� ������ ��������:" << endl;
			cout << "1. ������� ������ CProgram" << endl;
			cout << "2. ������� ������ CMalware" << endl;
			cout << "============================================" << endl;
			cout << "��� �����: ";
			cin >> value;

			try
			{
				if (value == 1 || value == 2)
				{
					list.emplace_front(newProgram(value));
					cout << "������� ��������." << endl;
				}
				else
					cout << "������. �������� �����." << endl;
			}
			catch (const std::exception & ex)
			{
				cout << ex.what() << endl;
			}

			break;

		case 4:
			cout << "���������� ������." << endl << endl;
			stop = 0;
			break;

		default:
			cout << "�������� ������. ��������� �������." << endl;
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
	int choise = 0, choise2 = 0;
	int value = 0;
	int i = 0;
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
			cout << "������ ����. ��� �� ������ �������?" << endl;
			cout << "1) �������� �������" << endl;
			cout << "2) ���������� ������" << endl;
			cout << "======================================" << endl;
			cout << "��� �����: ";
			cin >> choise;
			cout << endl;

			switch (choise)
			{
			case 1:
				cout << "�������� ���������, ������� ������ ��������:" << endl;
				cout << "1. ������� ������ CProgram" << endl;
				cout << "2. ������� ������ CMalware" << endl;
				cout << "============================================" << endl;
				cout << "��� �����: ";
				cin >> value;

				try
				{
					if (value == 1 || value == 2)
					{
						map.emplace(++i, newProgram(value));
						cout << "������� ��������." << endl;
					}
					else
						cout << "������. �������� �����." << endl;
				}
				catch (const std::exception & ex)
				{
					cout << ex.what() << endl;
				}

				break;

			case 2:
				cout << "���������� ������." << endl;
				stop = 0;
				break;

			default:
				cout << "�������� ����� ��������. ��������� �������." << endl;
				break;
			}
		}
		else
		{
			cout << endl;
			cout << "1)����� �� �����" << endl;
			cout << "2)�������� ��������" << endl;
			cout << "3)���������� ���������" << endl;
			cout << "4)���������� ������" << endl;
			cout << "======================" << endl;
			cout << "��� �����: ";
			cin >> choise;
			cout << endl;
		}

		switch (choise)
		{
		case 1:
			cout << "�������� �������:" << endl;
			cout << "1) ������� ���� ������ �� �����" << endl;
			cout << "2) ������� ��������� �� ID" << endl;
			cout << "3) ��������� � ������ ��������" << endl;
			cout << "======================================" << endl;
			cout << "��� �����: ";
			cin >> choise2;
			cout << endl;

			switch (choise2)
			{
			case 1:
				cout << setw(12) << "��������" << setw(14) << "������";
				cout << setw(14) << "����� ������" << setw(8) << "������";
				cout << setw(18) << "���������� �����" << setw(10) << "��������";
				cout << setw(10) << "���" << endl;

				for (const auto& element : map)
					cout << element.first << ". " << *element.second << endl;
				
				break;

			case 2:
				cout << "������� ����� ��������, �������� �� ������ ��������: ";
				cin >> value;
				cout << endl;

				findEl = 0;
				it = map.find(value);

				if (it != map.end())
				{
					temp = (*it).second->getStr();
					data = temp.str();

					cout << "��� �������: " << endl;
					cout << data << endl << endl;
				}
				else
					cout << "������� � ����� ID �� ������." << endl;

				break;

			case 3:
				break;

			default:
				cout << "�������� ������. ��������� �������." << endl;
				break;

			}
			break;

		case 2:
			cout << "������� ����� ��������, ������� ������ �������: ";
			cin >> value;
			cout << endl;

			findEl = 0;
			it = map.find(value);

			if (it != map.end())
			{
				map.erase(it);
				cout << "�������� ���������." << endl;
			}
			else
				cout << "������� �� ������." << endl;

			break;

		case 3:
			cout << "�������� ���������, ������� ������ ��������:" << endl;
			cout << "1. ������� ������ CProgram" << endl;
			cout << "2. ������� ������ CMalware" << endl;
			cout << "============================================" << endl;
			cout << "��� �����: ";
			cin >> value;

			try
			{
				if (value == 1 || value == 2)
				{
					map.emplace(++i, newProgram(value));
					cout << "������� ��������." << endl;
				}
				else
					cout << "������. �������� �����." << endl;
			}
			catch (const std::exception & ex)
			{
				cout << ex.what() << endl;
			}

			break;

		case 4:
			cout << "���������� ������." << endl << endl;
			stop = 0;
			break;

		default:
			cout << "�������� ������. ��������� �������." << endl;
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
	int choise = 0, choise2 = 0;
	int value = 0;
	int number = 0;
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
			cout << "������ ����. ��� �� ������ �������?" << endl;
			cout << "1) �������� �������" << endl;
			cout << "2) ���������� ������" << endl;
			cout << "======================================" << endl;
			cout << "��� �����: ";
			cin >> choise;
			cout << endl;

			switch (choise)
			{
			case 1:
				cout << "�������� ���������, ������� ������ ��������:" << endl;
				cout << "1. ������� ������ CProgram" << endl;
				cout << "2. ������� ������ CMalware" << endl;
				cout << "============================================" << endl;
				cout << "��� �����: ";
				cin >> value;

				try
				{
					if (value == 1 || value == 2)
					{
						set.emplace(newProgram(value));
						cout << "������� ��������." << endl;
					}
					else
						cout << "������. �������� �����." << endl;
				}
				catch (const std::exception & ex)
				{
					cout << ex.what() << endl;
				}

				break;

			case 2:
				cout << "���������� ������." << endl;
				stop = 0;
				break;

			default:
				cout << "�������� ����� ��������. ��������� �������." << endl;
				break;
			}
		}
		else
		{
			cout << endl;
			cout << "1)����� �� �����" << endl;
			cout << "2)�������� ��������" << endl;
			cout << "3)���������� ���������" << endl;
			cout << "4)���������� ������" << endl;
			cout << "======================" << endl;
			cout << "��� �����: ";
			cin >> choise;
			cout << endl;
		}

		switch (choise)
		{
		case 1:
			cout << "�������� �������:" << endl;
			cout << "1) ������� ���� ������ �� �����" << endl;
			cout << "2) ������� ��������� �� ID" << endl;
			cout << "3) ��������� � ������ ��������" << endl;
			cout << "======================================" << endl;
			cout << "��� �����: ";
			cin >> choise2;
			cout << endl;

			switch (choise2)
			{
			case 1:
				cout << setw(12) << "��������" << setw(14) << "������";
				cout << setw(14) << "����� ������" << setw(8) << "������";
				cout << setw(18) << "���������� �����" << setw(10) << "��������";
				cout << setw(10) << "���" << endl;

				for (const auto& element : set)
				{
					cout << number << ". " << *element << endl;
					number++;
				}
				number = 1;
				break;

			case 2:
				cout << "������� id ��������, �������� �� ������ ��������: ";
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

					cout << "��� �������: " << endl;
					cout << data << endl << endl;
				}
				else
					cout << "������� � ����� ID �� ������." << endl;

				break;

			case 3:
				break;

			default:
				cout << "�������� ������. ��������� �������." << endl;
				break;

			}
			break;

		case 2:
			cout << "������� ID ��������, ������� ������ �������: ";
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

				cout << "�������� ���������." << endl;
			}
			else
				cout << "������� �� ������." << endl;

			break;

		case 3:
			cout << "�������� ���������, ������� ������ ��������:" << endl;
			cout << "1. ������� ������ CProgram" << endl;
			cout << "2. ������� ������ CMalware" << endl;
			cout << "============================================" << endl;
			cout << "��� �����: ";
			cin >> value;

			try
			{
				if (value == 1 || value == 2)
				{
					set.emplace(newProgram(value));
					cout << "������� ��������." << endl;
				}
				else
					cout << "������. �������� �����." << endl;
			}
			catch (const std::exception & ex)
			{
				cout << ex.what() << endl;
			}

			break;

		case 4:
			cout << "���������� ������." << endl << endl;
			stop = 0;
			break;

		default:
			cout << "�������� ������. ��������� �������." << endl;
			break;

		}
	}
}

