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
	Array arr;
	ArrayList arrList;
	int i = 0;

	arrList.createArr();

	while (filename != "\\exit")
	{
		filename = InputFileName();
		
		try
		{
			arrList.ReadFile(filename, i);
			arrList.OutputArr(i);
			arrList.Task(i);
			filename = OutputFileName();
			arrList.SaveToFile(filename, i);

			i++;
		}
		catch (const std::exception&)
		{
			cout << "���������� ������� ���� � ��������� " << filename << "." << endl;
		}
	}

	return;
}
string InputFileName()
{
	string filename;

	cout << "������� �������� ����� ��� ������: ";
	cin >> filename;
	cout << endl;

	return filename;
}
string OutputFileName()
{
	string filename;

	cout << "������� �������� ����� ��� ������ ����������: ";
	cin >> filename;
	cout << endl;

	return filename;
}

