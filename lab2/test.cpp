#include "Program.h"
#include "List.h"

void Test_GetProgramID(C_List&, int&);
void Test_AddEl(C_List&);
void Test_DelEl(C_List&);
void Test_Task(C_List&, int&);

int main() {
<<<<<<< HEAD
    setlocale(LC_ALL, "Rus");
    C_List List;
    List.CreateList(5);

    int values[] = { 5678, 200 };

    Test_GetProgramID(List, values[0]);
    Test_AddEl(List);
    Test_DelEl(List);
    List.PrintAll();
    Test_Task(List, values[1]);

    if (_CrtDumpMemoryLeaks()) printf("\n\n���� ������ ������.\n\n");
    else printf("\n\n������ ������ �����������\n\n.");
=======
	setlocale(LC_ALL, "Rus");
	C_List List;
	List.CreateList(5);

	int values[] = { 5678, 200 };

	Test_GetProgramID(List, values[0]);
	Test_AddEl(List);
	Test_DelEl(List);
	List.PrintAll();
	Test_Task(List, values[1]);
	
	if (_CrtDumpMemoryLeaks()) printf("\n\n���� ������ ������.\n\n");
	else printf("\n\n������ ������ �����������\n\n.");
>>>>>>> 042bc953d2b5e7240b67c16e27875c0f044d9563

    return 0;
}
void Test_GetProgramID(C_List& list, int& value)
{
<<<<<<< HEAD
    printf("\n\n����� ������ ���� ������� � ��������������� 5678:\n");
    list.GetProgramID(value);
}
void Test_AddEl(C_List& list)
{
    C_Program newProgram;
    int size = list.getListSize();
    list.AddEl(newProgram);

    if (list.getListSize() > size)
        printf("\n\n���� ���������� �������� � ������\t �������� �������.\n\n");
    else printf("\n\n���� ���������� �������� � ������\t �� �������� �������.\n\n");
}
void Test_DelEl(C_List& list)
{
    int size = list.getListSize();
    list.DeleteEl(3);

    if (size > list.getListSize())
        printf("\n\n���� ������� ��������\t\t �������� �������.\n\n");
    else printf("\n\n���� ������� ��������\t\t �� �������� �������.\n\n");
}
void Test_Task(C_List& list, int& value)
{
    printf("\n\n����� ������ ���� �������� �������� ������ 200 � �� ������:\n");
    list.Task(value);
}
=======
	printf("\n\n����� ������ ���� ������� � ��������������� 5678:\n");
	list.GetProgramID(value);
	
	/*if (list.list->gettime() == 333)
		printf("\n\n���� ���������� �������� �� id\t\t �������� �������.\n\n");
	else printf("\n\n���� ���������� �������� �� id\t\t �� �������� �������.\n\n");*/
}
void Test_AddEl(C_List& list)
{
	C_Program newProgram;
	int size = list.getListSize();
	list.AddEl(newProgram);

	if (list.getListSize() > size)
		printf("\n\n���� ���������� �������� � ������\t �������� �������.\n\n");
	else printf("\n\n���� ���������� �������� � ������\t �� �������� �������.\n\n");
}
void Test_DelEl(C_List& list)
{
	int size = list.getListSize();
	list.DeleteEl(3);
	
	if (size > list.getListSize())
		printf("\n\n���� ������� ��������\t\t �������� �������.\n\n");
	else printf("\n\n���� ������� ��������\t\t �� �������� �������.\n\n");
}
void Test_Task(C_List& list, int& value)
{
	printf("\n\n����� ������ ���� �������� �������� ������ 200 � �� ������:\n");
	list.Task(value);
}
>>>>>>> 042bc953d2b5e7240b67c16e27875c0f044d9563
