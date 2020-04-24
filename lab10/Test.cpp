#include "Class.h"

void Test_FindEl(MyClass, int*, int);
void Test_Sort(MyClass, int*, int);
void Test_FindMin(MyClass, int*, int);
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
	MyClass element;
	int size = 10;

	int* array = new int[size] { 1, -5, 0 , 22, 236, -523, 56423, -5634, -4235, 1000};

	Test_FindEl(element, array, size);
	Test_Sort(element, array, size);
	Test_FindMin(element, array, size);
}

void Test_FindEl(MyClass element,int* array, int size)
{
	int expected = 3;
	int real = element.FindEl(array, size, 22);

	if (expected == real) cout << "���� ���������� ��������� \t �������� �������.\n";
	else cout << "���� ���������� ��������� \t �� �������� �������.\n";
}
void Test_Sort(MyClass element, int* array, int size)
{
	int beforeSort = array[0];
	array = element.Sort(array, size, element.sortAsc);
	int afterSort = array[2];

	if (beforeSort != afterSort && afterSort == -20) cout << "���� ����������\t\t\t �������� �������.\n";
	else cout << "���� ����������\t\t\t �� �������� �������.\n";
}
void Test_FindMin(MyClass element, int* array, int size)
{
	element.FindMin(array, size, element.sortDesc);
}