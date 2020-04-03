#include "program.h"
#include "list.h"
#include "author.h"
#include "date.h"

void menu();

int main()
{
	setlocale(LC_ALL, "Rus");
	menu();

	if (_CrtDumpMemoryLeaks()) cout << endl << "���� ������ ������." << endl;
	else cout << endl << "������ ������ �����������." << endl;

	return 0;
}

void menu()
{
	CList list;					//������ ���������
	CAuthor author;				//���������� ���� �����
	CAuthor* listAuthors;		//������ �������
	C_Program getProgram;		//���������, ������� ������� ��� ��������� ID
	C_Program newProgram;		//��������� ��� ���������� � ������
	auto choise = 1, choise2 = 0;
	auto value = 0, stop = 1;
	string fileName;			//�������� �����
	string::size_type n;
	stringstream str;
	int size;					//���������� ��������� ������ ������������ �������
	listAuthors = author.createList(4);
	list.createList(4, listAuthors);

	cout << endl << "�������� ������� ��� ������ �� �������: ";
	while (stop != 0)
	{
		if (list.getListSize() == 0)
		{
			cout << "������ ����. ��� �� ������ �������?" << endl;
			cout << "1) �������� ������� �������" << endl;
			cout << "2) ��������� ������ �� �����" << endl;
			cout << "3) ���������� ������" << endl;
			cout << "======================================" << endl;
			cout << "��� �����: ";
			cin >> choise;
			cout << endl;

			switch (choise)
			{
			case 1:
				list.enterNewEl();
				break;

			case 2:
				cout << "������� �������� ����� ��� ������ ������: ";
				cin >> fileName;
				cout << endl;

				n = fileName.find(".txt");
				if (n > 187) fileName += string(".txt");

				list.readFile(fileName);
				break;

			case 3:
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
			cout << "2)������ � �������" << endl;
			cout << "3)���������� ������" << endl;
			cout << "4)�������� ��������" << endl;
			cout << "5)���������� ���������" << endl;
			cout << "6)���������� ������" << endl;
			cout << "======================================" << endl;
			cout << "��� �����: ";
			cin >> choise;
			cout << endl;
		}

		switch (choise)
		{
		case 1:
			cout << "�������� �������:" << endl;
			cout << "1) ������� ���� ������ �� �����" << endl;
			cout << "2) ������� ���� ������� �� ����� �� ������" << endl;
			cout << "3) ������� ������ �������� ������ ������������ ������� � �� ������" << endl;
			cout << "4) ������� ������ ��������, �������� ������� ������� �� 2 ����" << endl;
			cout << "5) �������� ������ � �������" << endl;
			cout << "6) ������� ��������� �� ID" << endl;
			cout << "7) ��������� � ������ ��������" << endl;
			cout << "======================================" << endl;
			cout << "��� �����: ";
			cin >> choise2;
			cout << endl;

			switch (choise2)
			{
			case 1:
				list.printAll();

				break;

			case 2:
				cout << "������� ����� ��������, ������� ���� �������: ";
				cin >> value;
				cout << endl;

				if (value <= 0 || value > list.getListSize())
				{
					cout << "�������� ����� ��������. ��������� �������." << endl;
					break;
				}

				list.printOneEl(value - 1);
				break;

			case 3:
				cout << "������� ����������� ������ ��������: ";
				cin >> value;
				cout << endl;

				size = list.task(value);
				break;

			case 4:
				list.regexTask();
				break;

			case 5:
				cout << "������� ����� ��������, ������� �� ������ ��������: ";
				cin >> value;
				cout << endl;

				str = list.getOneEl(value - 1);
				list.showOneEl(str);
				break;

			case 6:
				cout << "������� id ��������, �������� �� ������ ��������: ";
				cin >> value;
				cout << endl;

				getProgram = list.getProgramID(value);
				break;

			case 7:
				break;

			default:
				cout << "�������� ������. ��������� �������." << endl;
				break;
			}
			break;
		case 2:
			cout << "�������� �������:" << endl;
			cout << "1) ��������� ������ � ����" << endl;
			cout << "2) ������ ������ �� �����" << endl;
			cout << "3) ��������� � ������" << endl;
			cout << "======================================" << endl;
			cout << "��� �����: ";
			cin >> choise2;
			cout << endl;
			
			switch (choise2)
			{
			case 1:
				cout << "������� �������� ����� ��� ������ ������: ";
				cin >> fileName;
				cout << endl;

				n = fileName.find(".txt");
				if (n > 187) fileName += string(".txt");

				list.saveToFile(fileName);
				break;
			case 2:
				cout << "������� �������� ����� ��� ������ ������: ";
				cin >> fileName;
				cout << endl;

				n = fileName.find(".txt");
				if (n > 187) fileName += string(".txt");

				list.readFile(fileName);
				break;
			case 3:
				break;
			default:
				cout << "�������� ������. ��������� �������." << endl;
				break;
			}
			break;
		case 3:
			cout << "����������� ���������� ����� ��:" << endl;
			cout << "1) �����������" << endl;
			cout << "2) ��������" << endl;
			cout << "��� �����: ";
			cin >> value;
			cout << endl;

			if (value == 1) list.sort(list.sortAsc);
			else if (value == 2) list.sort(list.sortDesc);
			else cout << "������. �������� ����� �������." << endl;

			break;

		case 4:
			cout << "������� ����� ��������, ������� ������ �������: ";
			cin >> value;
			cout << endl;

			list.deleteEl(value);
			break;

		case 5:
			cout << "�������� �������:" << endl;
			cout << "1) �������� ����������� ���������" << endl;
			cout << "2) ������ ������ � ����������" << endl;
			cout << "3) ��������� � ������" << endl;
			cout << "======================================" << endl;
			cout << "��� �����: ";
			cin >> choise2;
			cout << endl;

			switch (choise2)
			{
			case 1:
				list.addEl(newProgram);
				break;

			case 2:
				list.enterNewEl();
				break;

			case 3:
				break;

			default:
				cout << "�������� ������. ��������� �������." << endl;
				break;
			}

			break;

		case 6:
			cout << "���������� ������." << endl;
			stop = 0;
			break;

		default:
			cout << "�������� ������. ��������� �������." << endl;
			break;

		}
	}

	author.deleteList();
	return;
}