#include "MyClass.h"
#include "Student.h"
#include "Header.h"

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
	const int SIZE = 5;
	regex expresion("([\\d]+)");
	MyClass element;
	Student student1;
	Student* arrayStud = student1.createArray(SIZE);

	float elementToFind = 0;
	int command = 0;
	int choiseSort = 0;
	char charToFind = '*';
	
	int* arrayInt = new int[SIZE] { 5, 0, -1, 255, 100 };
	float* arrayFloat = new float[SIZE] {0.55, 100, 36.66, 14.69, 5};

	while (command != 4)
	{
		cout << "\n� ����� �������� �� ��������?\n1) int\n2) float\n";
		cout << "3) ����������� ��� ������\n4) ����� �� ���������.\n";
		cout << "��� �����: ";
		cin >> command;
		cout << endl;

		if (command == 1)
		{
			element.OutputArr(arrayInt, SIZE);
			elementToFind = element.EnterEl(elementToFind);
			element.FindEl(arrayInt, SIZE, (int)elementToFind);
			choiseSort = element.ChoiseSort(choiseSort);
			if (choiseSort == 1)
			{
				arrayInt = element.Sort(arrayInt, SIZE, true);
				element.OutputArr(arrayInt, SIZE);
			}
			else if (choiseSort == 2)
			{
				arrayInt = element.Sort(arrayInt, SIZE, false);
				element.OutputArr(arrayInt, SIZE);
			}
			cout << "����������� �������: " << element.FindMin(arrayInt, SIZE);
		}
		else if (command == 2)
		{
			element.OutputArr(arrayFloat, SIZE);
			elementToFind = element.EnterEl(elementToFind);
			element.FindEl(arrayFloat, SIZE, elementToFind);
			choiseSort = element.ChoiseSort(choiseSort);
			if (choiseSort == 1)
			{
				arrayFloat = element.Sort(arrayFloat, SIZE, true);
				element.OutputArr(arrayFloat, SIZE);
			}
			else if (choiseSort == 2)
			{
				arrayFloat = element.Sort(arrayFloat, SIZE, false);
				element.OutputArr(arrayFloat, SIZE);
			}
			cout << "����������� �������: " << element.FindMin(arrayFloat, SIZE);
		}
		else if (command == 3)
		{
			element.OutputArr(arrayStud, SIZE);
			elementToFind = element.EnterEl(elementToFind);
			Student student1("Ivanov", elementToFind);
			element.FindEl(arrayStud, SIZE, student1);
			choiseSort = element.ChoiseSort(choiseSort);
			
			if (choiseSort == 1)
			{
				arrayStud = element.Sort(arrayStud, SIZE, true);
				element.OutputArr(arrayStud, SIZE);
			}
			else if (choiseSort == 2)
			{
				arrayStud = element.Sort(arrayStud, SIZE, false);
				element.OutputArr(arrayStud, SIZE);
			}
			cout << "����������� �������: " << element.FindMin(arrayStud, SIZE);
		}
		if(command >= 5)
		{
			cout << "�������� �������. ��������� �������." << endl;
		}
	}

	
	delete[] arrayInt;
	delete[] arrayFloat;
	delete[] arrayStud;

	return;
}