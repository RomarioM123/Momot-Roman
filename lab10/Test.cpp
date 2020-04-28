#include "MyClass.h"
#include "Header.h"
#include "Student.h"

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
	
	return 0;
}

void Func()
{
	MyClass element;
	int size = 10;
	int* array = new int[size] { 1, -5, 0 , 22, 236, -523, 56423, -5634, -4235, 1000};

	Test_FindEl(element, array, size);
	Test_Sort(element, array, size);
	Test_FindMin(element, array, size);

	return;
}

void Test_FindEl(MyClass element,int* array, int size)
{
	int expected = 3;
	element.FindEl(array, size, 22);

	//if (expected == real) cout << "���� ���������� ��������� \t �������� �������.\n";
	//else cout << "���� ���������� ��������� \t �� �������� �������.\n";
}
void Test_Sort(MyClass element, int* array, int size)
{
	int beforeSort = array[0];
	array = element.Sort(array, size, 1);
	int afterSort = array[0];

	if (beforeSort != afterSort && afterSort == 56423) cout << "���� ����������\t\t\t\t �������� �������.\n";
	else cout << "���� ����������\t\t\t\t �� �������� �������.\n";
}
void Test_FindMin(MyClass element, int* array, int size)
{
	int temp = element.FindMin(array, size);

	if (temp == -5634) cout << "���� ���������� ������������ ��������\t �������� �������.\n";
	else cout << "���� ���������� ������������ ��������\t �� �������� �������.\n";
}