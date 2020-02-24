#include "Program.h"
#include "List.h"

void Menu();

int main()
{
	setlocale(LC_ALL, "Rus");
	Menu();

	if (_CrtDumpMemoryLeaks()) cout << endl << "���� ������ ������." << endl;
	else cout << endl << "������ ������ �����������." << endl;

	return 0;
}

void Menu()
{
	C_List list;
	C_Program getProgram;		//���������, ������� ������� ��� ��������� ID
	C_Program newProgram;		//��������� ��� ���������� � ������
	int choise = 1, value = 0, stop = 1;
	string fileName;			//���������� ��� �������� �����
	string::size_type n;		
	list.CreateList(4);
	cout << endl << "�������� ������� ��� ������ �� �������: " << endl;

	while (stop != 0)
	{
		if (list.getListSize() == 0)
		{
			cout << "������ ����. �������� �������(1) ��� ��������� ������(0): " << endl;
			cin >> choise;
			cout << endl;

			if (choise == 1) choise = 3;
			else if (choise == 0) choise = 5;
			else cout << "�������� ������." << endl;
		}
		else
		{
			cout << endl << endl;
			cout << "1)������� �� �� �����" << endl;
			cout << "2)������� 1 ������� �� �����" << endl;
			cout << "3)����� ��������� �� �������" << endl;
			cout << "4)�������� ������� (� �����)" << endl;
			cout << "5)������� �������" << endl;
			cout << "6)�������� ������ �������� ������ ������������ ������� � �� ������" << endl;
			cout << "7)�������� ������ �� �����" << endl;
			cout << "8)�������� ������ � ����" << endl;
			cout << "9)���������� ������" << endl;
			cout << "=============================" << endl << "��� �����: ";
			cin >> choise;
			cout << endl;
		}

		switch (choise)
		{
		case 1:
			list.PrintAll();
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
			list.PrintOneEl(value - 1);
			break;
		case 3:
			cout << "������� id ��������, �������� �� ������ ��������: ";
			cin >> value;
			cout << endl;

			getProgram = list.GetProgramID(value);
			break;
		case 4:
			list.AddEl(newProgram);
			break;
		case 5:
			cout << "������� ����� ��������, ������� ������ �������: ";
			cin >> value;
			cout << endl;

			list.DeleteEl(value);
			break;
		case 6:
			cout << "������� ����������� ������ ��������: ";
			cin >> value;
			cout << endl;

			list.Task(value);
			break;
		case 7:
			cout << "������� �������� ����� ��� ������ ������: ";
			cin >> fileName;
			cout << endl;

			n = fileName.find(".txt");
			if (n > 187) fileName += string(".txt");

			list.ReadFile(fileName);
			break;
		case 8:
			cout << "������� �������� ����� ��� ������ ������: ";
			cin >> fileName;
			cout << endl;

			n = fileName.find(".txt");
			if (n > 187) fileName += string(".txt");

			list.SaveToFile(fileName);
			break;
		case 9:
			cout << "���������� ������." << endl;
			stop = 0;
			break;
		default:
			cout << "�������� ������. ��������� �������." << endl;
			break;
		}
	}
	return;
}