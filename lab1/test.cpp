#include "List.h"
#include "Program.h"

void Test_GetProgramID(CList);
void Test_AddEl(CList&);
void Test_DelEl(CList&);

int main() {
	setlocale(LC_ALL, "Rus");
	CList List;
	List.setListSize(3);
	List.CreateList();

	
	Test_AddEl(List);
	List.PrintAll();
	printf("\n\n");
	Test_GetProgramID(List);
	Test_DelEl(List);

	List.FreeMemory();
	if (_CrtDumpMemoryLeaks()) printf("���� ������ ������.");
	else printf("������ ������ �����������.");

	return 0;
}
void Test_GetProgramID(CList list)
{
	list.GetProgramID(123);
}
void Test_AddEl(CList& list)
{
	C_Program newProgram = list.Program2();
	int size = list.getListSize();
	list.AddEl(newProgram);

	if (list.List[size-1].getTime() != list.List[size].getTime() && list.List[size].getTime() == 55555)
		printf("\n���� ���������� �������� � ������\t �������� �������.\n");
	else printf("\n���� ���������� �������� � ������\t �� �������� �������.\n");
}
void Test_DelEl(CList& list)
{
	int size = list.getListSize();
	list.DeleteEl(3);
	if (size > list.getListSize())
		printf("\n���� ������� ��������\t\t\t �������� �������.\n");
	else printf("\n���� ������� ��������\t\t\t �� �������� �������.\n");
}

