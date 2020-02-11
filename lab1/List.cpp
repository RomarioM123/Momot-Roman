#include "List.h"

void List::setListSize(int size)
{
	ListSize = size;
}
int List::getListSize() const
{
	return ListSize;
}
Program* List::AddEl(Program NewProgram)
{
	int NewListSize = getListSize();
	NewListSize++;
	setListSize(NewListSize);

	Program* NewList = new Program[NewListSize];


	for (int i = 0; i < NewListSize - 1; i++)
		NewList[i] = List[i];
	NewList[NewListSize - 1] = NewProgram;

	delete[] List;
	return NewList;
}
Program* List::DeleteEl()
{
	int NewListSize = getListSize();
	NewListSize--;
	setListSize(NewListSize);

	Program* NewList = new Program[NewListSize + 1];

	for (int i = 0; i <= NewListSize; i++)
		NewList[i] = List[i];

	delete[] List;
	return NewList;
}
void List::PrintAll() const
{
	printf("  Время\t\tРазмер\t\tСтроки");
	for (int i = 0; i < ListSize; i++)
		PrintOneEl(i);
}
void List::PrintOneEl(int number) const
{
	printf("\n%2i) %-10i\t %-10i\t %-10i", number + 1, List[number].getTime(), List[number].getSize(), List[number].getLines());
}
Program List::Program1()
{
	Program Program1;
	Program1.setTime(25326);
	Program1.setSize(2000);
	Program1.setLines(500);
	return Program1;
}
Program List::Program2()
{
	Program Program2;
	Program2.setTime(55555);
	Program2.setSize(11111);
	Program2.setLines(22222);
	return Program2;
}