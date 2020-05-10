#include "TemplateClass.h"
#include "Header.h"
#include "Student.h"

void Test_FindEl(TemplateClass<int>&, int);
void Test_Sort(TemplateClass<int>&, int);
void Test_FindMin(TemplateClass<int>&, int);
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
	const int size = 5;
	int values[size] = { 1, -5, 0, 22, 236};
	int** array = new int* [size]; 
	for (size_t i = 0; i < size; i++)
	{
		array[i] = &values[i];
	}
	TemplateClass<int> element(array);

	Test_FindEl(element, size);
	Test_Sort(element, size);
	Test_FindMin(element, size);

	delete[] array;

	return;
}

void Test_FindEl(TemplateClass<int>& element, int size)
{
	if (element.FindEl(22, size) == 3)
		cout << "���� ���������� ���������\t\t�������� �������.\n";
	else 
		cout << "���� ���������� ���������\t\t�� �������� �������.\n";
}
void Test_Sort(TemplateClass<int>& element, int size)
{
	if (element.FindEl(-5, size) == 1) 
		cout << "���� ����������\t\t\t\t�������� �������.\n";
	else 
		cout << "���� ����������\t\t\t\t�� �������� �������.\n";
}
void Test_FindMin(TemplateClass<int>& element, int size)
{
	if (element.FindMin(size) == -5)
		cout << "���� ���������� ������������ ��������\t�������� �������.\n";
	else 
		cout << "���� ���������� ������������ ��������\t�� �������� �������.\n";
}