#include "TemplateClass.h"
#include "Student.h"
#include "Header.h"
#include "Foreigner.h"

void ArrayInt(int);
void ArrayFloat(int);
void ArrayClass(int);
Student** CreateArray(int);

int main()
{
	setlocale(LC_ALL, "Rus");
	const int SIZE = 5;
	int choise = 0;

	while (choise != 4)
	{
		cout << "� �������� ������ ���� ������ ��������?" << endl;
		cout << "1. int\n2. float\n3. ���������������� ��� ������\n4. ��������� ������\n";
		cout << "===================\n��� �����: ";
		cin >> choise;

		if (choise == 1)
			ArrayInt(SIZE);
		else if (choise == 2)
			ArrayFloat(SIZE);
		else if (choise == 3)
			ArrayClass(SIZE);
		else if (choise > 4 || choise < 1)
			cout << endl << "�������� �����. ��������� �������." << endl;
		else
			choise = 4;
	}

	if (_CrtDumpMemoryLeaks()) cout << endl << "���� ������ ������." << endl;
	else cout << endl << "������ ������ �����������." << endl;

	return 0;
}
void ArrayInt(int SIZE)
{
	int* arraySize = new int[SIZE];
	int** arrayInt = new int* [SIZE];
	int choise = 0, result = 0;

	for (size_t i = 0; i < SIZE; i++)
	{
		arraySize[i] = rand();
		arrayInt[i] = &arraySize[i];
	}

	TemplateClass<int> element(arrayInt);
	cout << endl << "������ ��������� ���� int:" << endl;
	element.OutputArr(SIZE);
	
	choise = element.EnterEl(choise);
	result = element.FindEl(choise, SIZE);
	if (result == -1)
		cout << "������� � �������� " << choise << " �����������." << endl;
	else
		cout << "������ �������� " << choise << " : " << result << endl;

	choise = element.ChoiseSort(choise);
	element.Sort(SIZE, choise - 1);
	cout << endl << "��������� ����������:" << endl;
	element.OutputArr(SIZE);

 	result = element.FindMin(SIZE);
	cout << "����������� ������� � �������: " << result << endl;

	delete[] arraySize;
	delete[] arrayInt;
}
void ArrayFloat(int SIZE)
{
	float* arraySize = new float[SIZE];
	float** arrayFloat = new float* [SIZE];
	float choise = 0, result = 0;

	for (size_t i = 0; i < SIZE; i++)
	{
		arraySize[i] = (rand() % 101 - 50) / 10.0;
		arrayFloat[i] = &arraySize[i];
	}

	TemplateClass<float> element(arrayFloat);
	cout << endl << "������ ��������� ���� float:" << endl;
	element.OutputArr(SIZE);

	choise = element.EnterEl(choise);
	result = element.FindEl(choise, SIZE);
	if (result == -1)
		cout << "������� � �������� " << choise << " �����������." << endl;
	else
		cout << "������ �������� " << choise << " : " << result << endl;

	choise = element.ChoiseSort(choise);
	element.Sort(SIZE, choise - 1);
	cout << endl << "��������� ����������:" << endl;
	element.OutputArr(SIZE);

	result = element.FindMin(SIZE);
	cout << "����������� ������� � �������: " << result << endl;

	delete[] arraySize;
	delete[] arrayFloat;
}
void ArrayClass(int SIZE)
{
	Student guy;
	Student** ArrayClass = CreateArray(SIZE);
	TemplateClass<Student> element(ArrayClass);
	int choise = 0, result = 0;

	cout << setw(6) << "���" << setw(10) << "�������" << setw(10) << "������" << endl;
	element.OutputArr(SIZE);

	cout << "������� �������, ������ �������� ������ ��������: ";
	cin >> guy;

	result = element.FindEl(guy, SIZE);
	if (result == -1)
		cout << "������� � �������� " << guy << " �����������." << endl;
	else
		cout << "������ ��������: " << result << endl;

	while (choise <= 0 || choise > 3)
	{
		cout << endl << "����������� ��:" << endl;
		cout << "1) �����������\n2) ��������\n3) �� �����������\n";
		cout << "��� �����: ";
		cin >> choise;

		if (choise <= 0 || choise > 3)
			cout << "������. �������� �������. ��������� �������." << endl;
	}

	if (choise == 1) choise = 1;
	else if (choise == 2) choise = 0;

	element.Sort(SIZE, choise);
	cout << endl << "��������� ����������:" << endl;
	element.OutputArr(SIZE);

	guy = element.FindMin(SIZE);
	cout << "����������� ������� � �������: " << guy << endl;

	for (size_t i = 0; i < SIZE; i++)
	{
		delete ArrayClass[i];
	}
	delete[] ArrayClass;
}

Student** CreateArray(int size)
{
	Student** array = new Student * [size];

	for (size_t i = 0; i < size; i++)
	{
		if (i == 0)
		{
			*(array + i) = new Student();
		}
		else if (i == 1)
		{
			*(array + i) = new Foreigner("���", "����", 22);
		}
		else if (i == 2)
		{
			*(array + i) = new Student("�������", 17);
		}
		else if (i == 3)
		{
			*(array + i) = new Foreigner("����������", "�����", 20);
		}
		else
		{
			*(array + i) = new Student("�����", 28);
		}
	}

	return array;
}