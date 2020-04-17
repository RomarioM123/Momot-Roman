#include "programList.h"

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
	CProgram** programList;
	string fileName;			//�������� �����
	CList list;					//������ ��������
	CAuthor* listAuthors;		//������ �������
	CAuthor author;				//���������� ���� �����
	auto choise = 1;
	auto choise2 = 0;
	auto choise3 = 0;
	auto value = 0, stop = 1;
	int result = 0, b, size;
	string::size_type n;
	stringstream str;
	
	listAuthors = author.createList(6);
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
				list.enterNewProgram();
				break;

			case 2:
				cout << "������� �������� ����� ��� ������ ������ ��� �������� ������: ";
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
			cout << "2) ������� ������ �������� ������ ������������ ������� �� ���������� Microsoft" << endl;
			cout << "3) ������� ������ ��������, �������� ������� ������� �� 2 ����" << endl;
			cout << "4) ������� ��������� �� ID" << endl;
			cout << "5) ��������� � ������ ��������" << endl;
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
				cout << "������� ����������� ������ ��������: ";
				cin >> value;
				cout << endl;
				
				size = list.task(value);
				break;

			case 3:
				list.regexTask();

				if (size == 0) 
					cout << "����������� ���������, ���������� 2 ����� � ��������." << endl;

				break;

			case 4:
				cout << "������� id ��������, �������� �� ������ ��������: ";
				cin >> value;
				cout << endl;

				result = list.getProgramID(value);
				if (result == -5)
				{
					cout << "������� � ����� ID �����������." << endl;
					break;
				}
				
				list.getOneEl(result);
				break;

			case 5:
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
				cout << "������� �������� ����� ��� ������ ������ ��������: ";
				cin >> fileName;
				cout << endl;

				n = fileName.find(".txt");
				if (n > 187) fileName += string(".txt");

				list.saveFile(fileName);
				break;

			case 2:
				cout << "������� �������� ����� ��� ������ ������ ��������: ";
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

			if (value == 1){
				list.sort(list.sortAsc);
			} else if (value == 2) {
				list.sort(list.sortDesc);
			} else cout << "������. �������� ����� �������." << endl;

			break;

		case 4:
			cout << "������� ID ��������, ������� ������ �������: ";
			cin >> value;
			cout << endl;

			result = list.getProgramID(value);
			list.delProgram(result);

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
				cout << "1) �������� ��������� ������������ ��" << endl;
				cout << "2) �������� ��������� �� �������" << endl;
				cout << "======================================" << endl;
				cout << "��� �����: ";
				cin >> choise3;
				cout << endl;

				if (choise3 == 1)
				{
					CProgram* newProgram = list.newProgram(listAuthors, 1);
					list.addProgram(newProgram);
					cout << "��������� ���������." << endl;
					break;
				}
				else if (choise3 == 2)
				{
					CProgram* newProgram = list.newProgram(listAuthors, 2);
					list.addProgram(newProgram);
					cout << "��������� ���������." << endl;
				}
				else 
				{
					cout << "�������� ����� ������." << endl;
				}

				break;

			case 2:
				list.enterNewProgram();
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