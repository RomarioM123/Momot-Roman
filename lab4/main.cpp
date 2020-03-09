#include "Program.h"
#include "List.h"

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
	C_Program getProgram;		//���������, ������� ������� ��� ��������� ID
	C_Program newProgram;		//��������� ��� ���������� � ������
	int choise = 1, value = 0, stop = 1;
	string fileName;			//�������� �����
	string::size_type n;
	stringstream str;
	int size;					//���������� ��������� ������ ������������ �������
	list.createList(4);
	cout << endl << "�������� ������� ��� ������ �� �������: ";

	while (stop != 0)
	{
		if (list.getListSize() == 0)
		{
			cout << "������ ����. �������� �������(1) ��� ��������� ������(0): " << endl;
			cin >> choise;
			cout << endl;

			if (choise == 1) choise = 11;
			else if (choise == 0) choise = 9;
			else cout << "�������� ������." << endl;
		}
		else
		{
			cout << endl;
			cout << "1)������� �� �� �����" << endl;
			cout << "2)������� 1 ������� �� �����" << endl;
			cout << "3)����� ��������� �� �������" << endl;
			cout << "4)�������� ������� (� �����)" << endl;
			cout << "5)������� �������" << endl;
			cout << "6)�������� ������ �������� ������ ������������ ������� � �� ������" << endl;
			cout << "7)�������� ������ �� �����" << endl;
			cout << "8)�������� ������ � ����" << endl;
			cout << "9)���������� ������" << endl;
			cout << "10)�������� ������� ������ �� ������" << endl;
			cout << "11)���� ������ � ����������" << endl;
			cout << "12)�������� ������ ��������, �������� ������� ������� �� 2 ����" << endl;
			cout << "=============================" << endl << "��� �����: ";
			cin >> choise;
			cout << endl;
		}

		switch (choise)
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
			cout << "������� id ��������, �������� �� ������ ��������: ";
			cin >> value;
			cout << endl;

			getProgram = list.getProgramID(value);
			break;
		case 4:
			list.addEl(newProgram);
			break;
		case 5:
			cout << "������� ����� ��������, ������� ������ �������: ";
			cin >> value;
			cout << endl;

			list.deleteEl(value);
			break;
		case 6:
			cout << "������� ����������� ������ ��������: ";
			cin >> value;
			cout << endl;

			size = list.task(value);
			break;
		case 7:
			cout << "������� �������� ����� ��� ������ ������: ";
			cin >> fileName;
			cout << endl;

			n = fileName.find(".txt");
			if (n > 187) fileName += string(".txt");

			list.readFile(fileName);
			break;
		case 8:
			cout << "������� �������� ����� ��� ������ ������: ";
			cin >> fileName;
			cout << endl;

			n = fileName.find(".txt");
			if (n > 187) fileName += string(".txt");

			list.saveToFile(fileName);
			break;
		case 9:
			cout << "���������� ������." << endl;
			stop = 0;
			break;
		case 10:
			cout << "������� ����� ��������, ������� �� ������ ��������: ";
			cin >> value;
			cout << endl;

			str = list.getOneEl(value-1);
			list.showOneEl(str);
			break;
		case 11:
			list.enterNewEl();
			break;
		case 12:
			list.regexTask();
			break;
		default:
			cout << "�������� ������. ��������� �������." << endl;
			break;
		}
	}
	return;
}