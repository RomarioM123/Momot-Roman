#include "programList.h"
#include "malwareList.h"

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
	auto choise = 1, choise2 = 0;
	string fileName;			//�������� �����
	auto value = 0, stop = 1;
	string::size_type n;
	
#pragma region Authors
	CAuthor author;				//���������� ���� �����
	CAuthor* listAuthors;		//������ �������
	listAuthors = author.createList(4);
#pragma endregion Authors

#pragma region Program
	CList list;					//������ ��������
	C_Program getProgram;		//���������, ������� ������� ��� ��������� ID
	C_Program newProgram;		//��������� ��� ���������� � ������
	int size;					//���������� ��������� ������ ������������ �������
	stringstream str;
	list.createList(4, listAuthors);
#pragma endregion Program

#pragma region Malware
	MalwareList list2;			//������ ������������ ��
	CMalware getProgram2;
	CMalware newProgram2;
	int size2;
	stringstream str2;
	list2.createList(4, listAuthors);
#pragma endregion Malware

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
				cout << "������� �����" << endl;
				list.enterNewEl();
				cout << "����� ���������" << endl;
				list2.enterNewEl();
				break;

			case 2:
				cout << "������� �������� ����� ��� ������ ������ ��� �������� ������: ";
				cin >> fileName;
				cout << endl;

				n = fileName.find(".txt");
				if (n > 187) fileName += string(".txt");

				cout << "������� �����" << endl;
				list.readFile(fileName);

				cout << "������� �������� ����� ��� ������ ������ ��� �������� ������: ";
				cin >> fileName;
				cout << endl;

				n = fileName.find(".txt");
				if (n > 187) fileName += string(".txt");

				cout << "����� ���������" << endl;
				list2.readFile(fileName);

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
				cout << "������� �����" << endl;
				list.printAll();
				cout << "����� ���������" << endl;
				list2.printAll();

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

				cout << "������� �����" << endl;
				list.printOneEl(value - 1);
				cout << "����� ���������" << endl;
				list2.printOneEl(value - 1);

				break;

			case 3:
				cout << "������� ����������� ������ ��������: ";
				cin >> value;
				cout << endl;
				
				cout << "������� �����" << endl;
				size = list.task(value);
				cout << "����� ���������" << endl;
				size2 = list2.task(value);
				break;

			case 4:
				cout << "������� �����" << endl;
				list.regexTask();
				cout << "����� ���������" << endl;
				list2.regexTask();
				break;

			case 5:
				cout << "������� ����� ��������, ������� �� ������ ��������: ";
				cin >> value;
				cout << endl;

				cout << "������� �����" << endl;
				str = list.getOneEl(value - 1);
				list.showOneEl(str);
				cout << "����� ���������" << endl;
				str2 = list2.getOneEl(value - 1);
				list2.showOneEl(str2);
				break;

			case 6:
				cout << "������� id ��������, �������� �� ������ ��������: ";
				cin >> value;
				cout << endl;

				cout << "������� �����" << endl;
				getProgram = list.getProgramID(value);
				cout << "����� ���������" << endl;
				getProgram2 = list2.getProgramID(value);
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
				cout << "������� �������� ����� ��� ������ ������ ��������: ";
				cin >> fileName;
				cout << endl;

				n = fileName.find(".txt");
				if (n > 187) fileName += string(".txt");

				list.saveToFile(fileName);

				cout << "������� �������� ����� ��� ������ ������ ������������ ��: ";
				cin >> fileName;
				cout << endl;

				n = fileName.find(".txt");
				if (n > 187) fileName += string(".txt");

				list2.saveToFile(fileName);
				break;
			case 2:
				cout << "������� �������� ����� ��� ������ ������ ��������: ";
				cin >> fileName;
				cout << endl;

				n = fileName.find(".txt");
				if (n > 187) fileName += string(".txt");

				list.readFile(fileName);

				cout << "������� �������� ����� ��� ������ ������ ������������ ��: ";
				cin >> fileName;
				cout << endl;

				n = fileName.find(".txt");
				if (n > 187) fileName += string(".txt");

				list2.readFile(fileName);
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
				list2.sort(list.sortAsc);
			} else if (value == 2) {
				list.sort(list.sortDesc);
				list2.sort(list.sortDesc);
			} else cout << "������. �������� ����� �������." << endl;

			break;

		case 4:
			cout << "������� ����� ��������, ������� ������ �������: ";
			cin >> value;
			cout << endl;

			list.deleteEl(value);
			list2.deleteEl(value);
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
				list2.addEl(newProgram2);
				break;

			case 2:
				list.enterNewEl();
				list2.enterNewEl();
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