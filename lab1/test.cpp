#include "List.h"
#include "Program.h"

void Test_GetProgramID(C_List, int&);

void Test_AddEl(C_List&, int&);
void Test_DelEl(C_List&, int&);

int main() {
	setlocale(LC_ALL, "Rus");
	int count = 0;
	C_List List;
	List.setListSize(3);
	List.CreateList();

	Test_GetProgramID(List, count);
	Test_AddEl(List, count);
	Test_DelEl(List, count);

	if (count == 3) printf("��� ����� ��������.\n");
	else printf("�� ��� ����� ��������.\n");

	if (_CrtDumpMemoryLeaks()) printf("���� ������ ������.");
	else printf("������ ������ �����������.");

	return 0;
}
void Test_GetProgramID(C_List list, int& count)
{
	C_Program List = list.GetProgramID(2);
	
	if (List.getTime() == 25326)
	{
		printf("���� ���������� �������� �� ID �������� �������.\n");
		count++;
	}
	else printf("���� ���������� �������� �� ID �� �������� �������.\n");
}
void Test_AddEl(C_List& list, int& count)
{
	C_Program newProgram = list.Program2();
	int size = list.getListSize();
	list.AddEl(newProgram);

	if (list.List[size - 1].getTime() != list.List[size].getTime() && list.List[size].getTime() == 55555)
	{
		printf("���� ���������� �������� � ������ �������� �������.\n");
		count++;
	}
	else printf("���� ���������� �������� � ������ �� �������� �������.\n");
}
void Test_DelEl(C_List& list, int& count)
{
	int size = list.getListSize();
	list.DeleteEl(3);
	if (size > list.getListSize())
	{
		printf("���� ������� �������� �������� �������.\n");
		count++;
	}
	else printf("���� ������� �������� �� �������� �������.\n");
}

