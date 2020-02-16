#include "List.h"

void C_List::CreateList()
{
	List = new C_Program[listSize];

	for (int i = 0; i < listSize; i++)
		List[i] = Program1();
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
	printf("  Время\t\tРазмер\t\tСтроки");
	for (int i = 0; i < listSize; i++)
		PrintOneEl(i);
}
void C_List::PrintOneEl(int number) const
{
	printf("\n%2i) %-10i\t %-10i\t %-10i", number + 1, List[number].getTime(), List[number].getSize(), List[number].getLines());
}
void C_List::AddEl(C_Program& newProgram)
{
	newProgram = Program2();
	C_Program* newList = new C_Program[listSize+1];

	for (int i = 0; i < listSize; i++)
		newList[i] = List[i];
	newList[listSize++] = newProgram;
	delete[] List;
	
	List = new C_Program[listSize];
	for (int i = 0; i < listSize; i++)
		List[i] = newList[i];

	delete[] newList;
	printf("Элемент добавлен.\n");
}
void C_List::DeleteEl(int index)
{
	if (listSize == 0)
	{
		printf("Список программ пуст. Возвращение с выбору действий.\n");
		return;
	}
	if (index <= 0 || index > listSize)
	{
		printf("Ошибка. Неверный номер элемента. Вовзвращение.\n");
		return;
	}
	
	C_Program* newList = new C_Program[listSize-1];

	for (int i = 0; i < index - 1; i++)
		newList[i] = List[i];
	for (int i = index - 1, j = index; i < listSize; i++, j++)
		newList[i] = List[j];
	delete[] List;

	List = new C_Program[listSize--];
	for (int i = 0; i < listSize; i++)
		List[i] = newList[i];
	delete[] newList;

	return;
}
void C_List::FreeMemory()
{
	delete[] List;
}

C_Program C_List::Program1()
{
	C_Program Program1;
	Program1.setTime(25326);
	Program1.setSize(2000);
	Program1.setLines(500);
	return Program1;
}
C_Program C_List::Program2()
{
	C_Program Program2;
	Program2.setTime(55555);
	Program2.setSize(11111);
	Program2.setLines(22222);
	return Program2;
}