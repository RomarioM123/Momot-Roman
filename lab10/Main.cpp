#include "Class.h"

void Func();

int main()
{
	setlocale(LC_ALL, "Rus");
	Func();

	if (_CrtDumpMemoryLeaks()) cout << endl << "���� ������ ������." << endl;
	else cout << endl << "������ ������ �����������." << endl;
}

void Func()
{
	const int SIZE = 5;
	MyClass element;
	regex expresion("([\\d]+)");
	string choise;
	float value;
	float result;
	
	//int* array = new int[SIZE] { 5, 0, -1, 255, 100 };
	float* array = new float[SIZE] {0.55, 100, 36.66, 14.69, 5};
	//string array = "Kings";

	element.OutputArr(array, SIZE);
	cout << endl << "������� �������, ������ �������� ������ ��������: ";
	cin >> choise;
	if (regex_search(choise, expresion))
	{
		setlocale(LC_ALL, "Eng");
		value = stof(choise);
		setlocale(LC_ALL, "Rus");
	}
	else
	{
		value = choise[0];
	}

	result = element.FindEl(array, SIZE, value);
	if (result == -1)
	{
		cout << "������� �������� � ������� ���." << endl;
	}
	else
	{
		cout << "������ ������� ��������: " << result << endl;
	}

	cout << endl << "����������� ��:" << endl;
	cout << "1) ��������" << endl << "2) �����������" << endl;
	cout << "��� �����: ";
	cin >> choise;
	if (choise[0] == '1')
	{
		if (typeid(array).name() == typeid(string).name())
			array = element.Sort(array, SIZE, element.sortAsc);
		else
			array = element.Sort(array, SIZE, element.sortDesc);
		
		element.OutputArr(array, SIZE);
	}
	else if (choise[0] == '2')
	{
		if (typeid(array).name() == typeid(string).name())
			array = element.Sort(array, SIZE, element.sortDesc);
		else
			array = element.Sort(array, SIZE, element.sortAsc);

		element.OutputArr(array, SIZE);
	}
	else
	{
		cout << "�������� �����." << endl;
	}

	if (typeid(array).name() == typeid(string).name())
	{
		element.FindMin(array, SIZE, element.sortAsc);
	}
	else
	{
		element.FindMin(array, SIZE, element.sortDesc);
		delete[] array;
	}

	return;
}