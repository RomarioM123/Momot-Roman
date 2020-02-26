#include "List.h"

void CList::CreateList(int value)
{
    listSize = value;
    List = new C_Program[listSize];

    for (int i = 0; i < listSize; i++)
        List[i] = Programs(i);
}
void CList::setListSize(int size)
{
    listSize = size;
}
int CList::getListSize() const
{
    return listSize;
}
void CList::PrintAll() const
{
    printf("  \nВремя\t\tРазмер\t\tСтроки\t\tИндекс\t\tТроян");
    for (int i = 0; i < listSize; i++)
        PrintOneEl(i);
}
void CList::PrintOneEl(int number) const
{
    printf("\n%2i) %-10i\t %-10i\t ", number + 1, List[number].getTime(), List[number].getSize());
    printf("%-10i\t %-10i\t %-10s", List[number].getLines(), List[number].getIndex(), List[number].getTrojan());
}
void CList::AddEl(C_Program& newProgram)
{
    C_Program* newList = new C_Program[listSize + 1];

    for (int i = 0; i < listSize; i++)
        newList[i] = List[i];
    newList[listSize++] = newProgram;
    delete[] List;

    List = new C_Program[listSize];
    for (int i = 0; i < listSize; i++)
        List[i] = newList[i];

    printf("Элемент добавлен.\n");
    delete[] newList;
}
void CList::DeleteEl(int index)
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
void CList::Task(int minimalSize)
{
    char b[] = "Нет";
    for (int i = 0; i < listSize; i++)
        if (List[i].getSize() > minimalSize&& strcmp(List[i].getTrojan(), b) == 0)
            PrintOneEl(i);

}
void CList::GetProgramID(int id) const
{	
	int newListSize = 0;

	for (int i = 0; i < listSize; i++)
		if (List[i].getIndex() == id)
		{
			PrintOneEl(i);
			newListSize++;
		}
}
C_Program CList::Programs(int valueX)
{
    C_Program standartProgram;

    if (valueX == 1)
    {
        static char status[] = "Да";
        C_Program Program1(status, 222, 222, 222, 1234);
        return Program1;
    }
    else if (valueX == 2)
    {
        static char status[] = "Да";
        C_Program Program2(status, 333, 333, 666, 5678);
        return Program2;
    }
    else if (valueX == 3)
    {
        static char status[] = "Нет";
        C_Program Program3(status, 444, 444, 444, 9532);
        return Program3;
    }
    else if (valueX == 4)
    {
        static char status[] = "Нет";
        C_Program Program4(status, 555, 555, 555, 4356);
        return Program4;
    }
    return standartProgram;
}
CList::~CList()
{
    printf("\nВызвался деструктор");
    delete[] List;
}