#include "ArrayList.h"

string InputFileName();
string OutputFileName();
void Func();

int main()
{
	setlocale(LC_ALL, "Rus");

	Func();

	if (_CrtDumpMemoryLeaks()) cout << endl << "���� ������ ������." << endl;
	else cout << endl << "������ ������ �����������." << endl;

	return 0;
}

void Func()
{
	string filename;
	ArrayList arrList;
	int value, value2;

	while (filename != "\\exit")
	{
		filename = InputFileName();
		
		try
		{
			arrList.ReadFile(filename);
			arrList.OutputArr();
			arrList.Task();
			filename = OutputFileName();
			arrList.SaveToFile(filename);
			
			cout << endl << "������� ����� �������, ������� �������� ������ ��������: ";
			cin >> value;
			cout << "������� ����� ��������, ������� ������ ��������: ";
			cin >> value2;

			arrList.CheckArr(value, value2);
			arrList.DeleteArr();
		}
		catch (const exception& ex)
		{
			if (filename == "\\exit")
			{
				cout << "���������� ������ ���������." << endl;
			}
			else
			{
				cout << ex.what() << endl;
				cout << "���������� ������� ���� � ��������� " << filename << endl;
			}
		}
	}

	return;
}
string InputFileName()
{
	string filename;

	cout << endl << "������� �������� ����� ��� ������: ";
	cin >> filename;
	cout << endl;

	return filename;
}
string OutputFileName()
{
	string filename;

	cout << endl << "������� �������� ����� ��� ������ ����������: ";
	cin >> filename;

	return filename;
}

