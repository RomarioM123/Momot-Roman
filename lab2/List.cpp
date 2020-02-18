#include "List.h"

void C_List::CreateList(int value)
{
	listSize = value;
	List = new C_Program[listSize];

	for (int i = 0; i < listSize; i++)
		List[i] = Programs(i);
}
void C_List::setListSize(int size)
{
	listSize = size;
}
int C_List::getListSize() const
{
	return listSize;
}
void C_List::PrintAll() const
{
	printf("  \n�����\t\t������\t\t������\t\t�����");
	for (int i = 0; i < listSize; i++)
		PrintOneEl(i);
}
void C_List::PrintOneEl(int number) const
{
	printf("\n%2i) %-10i\t %-10i\t ", number + 1, List[number].getTime(), List[number].getSize());
	printf("%-10i\t %-10s\t", List[number].getLines(), List[number].getTrojan());
}
void C_List::AddEl(C_Program& newProgram)
{
	C_Program* newList = new C_Program[listSize+1];

	for (int i = 0; i < listSize; i++)
		newList[i] = List[i];
	newList[listSize++] = newProgram;
	delete[] List;
	
	List = new C_Program[listSize];
	for (int i = 0; i < listSize; i++)
		List[i] = newList[i];

	delete[] newList;
	printf("������� ��������.\n");
}
void C_List::DeleteEl(int index)
{
	if (listSize == 0)
	{
		printf("������ �������� ����. ����������� � ������ ��������.\n");
		return;
	}
	if (index <= 0 || index > listSize)
	{
		printf("������. �������� ����� ��������. ������������.\n");
		return;
	}

	C_Program* newList = new C_Program[listSize - 1];

	for (int i = 0; i < index - 1; i++)
		newList[i] = List[i];
	for (int i = index - 1, j = index; j < listSize; i++, j++)
		newList[i] = List[j];
	delete[] List;

	List = new C_Program[listSize--];
	for (int i = 0; i < listSize; i++)
		List[i] = newList[i];
	delete[] newList;

	return;
}
void C_List::Task(int minimalSize)
{
	C_Program* newList = new C_Program[listSize];
	
	char b[] = "���";
	for (int i = 0; i < listSize; i++)
	{
		if (List[i].getSize() > minimalSize && strcmp(List[i].getTrojan(), b) == 0)
		{
			newList[i] = List[i];
			PrintOneEl(i);
		}
	}
	delete[] newList;
	//� �� ����� ������������ "�������� ������". � ����� � ������� � �������, � �������� � ����������
	//��, ��������� ����������, ������ � ����� �� ������� �� ���� �� �������. �� � ����� ���������� ��� ��������
}
C_Program C_List::GetProgramID(int id) const
{
	C_Program temp = List[id];
	return temp;
}
C_Program C_List::Programs(int valueX)
{
	C_Program standartProgram;

	if (valueX == 1)
	{
		static char status[] = "��";
		C_Program Program1(status, 222, 222, 222);
		return Program1;
	}
	else if (valueX == 2)
	{
		static char status[] = "��";
		C_Program Program2(status, 333, 333, 666);
		return Program2;
	}
	else if (valueX == 3)
	{
		static char status[] = "���";
		C_Program Program3(status, 444, 444, 444);
		return Program3;
	}
	else if (valueX == 4)
	{
		static char status[] = "���";
		C_Program Program4(status, 555, 555, 555);
		return Program4;
	}
	return standartProgram;
}
C_List::~C_List()
{
	printf("\n�������� ����������");
	delete[] List;
}
