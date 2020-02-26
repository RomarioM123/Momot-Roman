#include "Program.h"
#include "List.h"

void Test_GetProgramID(CList&, int&);
void Test_AddEl(CList&);
void Test_DelEl(CList&);
void Test_Task(CList&, int&);

int main() {
    setlocale(LC_ALL, "Rus");
    CList List;
    List.CreateList(5);

    int values[] = { 5678, 200 };

    Test_GetProgramID(List, values[0]);
    Test_AddEl(List);
    Test_DelEl(List);
    List.PrintAll();
    Test_Task(List, values[1]);

    if (_CrtDumpMemoryLeaks()) printf("\n\n���� ������ ������.\n\n");
    else printf("\n\n������ ������ �����������\n\n.");

    return 0;
}
void Test_GetProgramID(CList& list, int& value)
{
    printf("\n\n����� ������ ���� ������� � ��������������� 5678:\n");
    list.GetProgramID(value);
}
void Test_AddEl(CList& list)
{
    C_Program newProgram;
    int size = list.getListSize();
    list.AddEl(newProgram);

    if (list.getListSize() > size)
        printf("\n\n���� ���������� �������� � ������\t �������� �������.\n\n");
    else printf("\n\n���� ���������� �������� � ������\t �� �������� �������.\n\n");
}
void Test_DelEl(CList& list)
{
    int size = list.getListSize();
    list.DeleteEl(3);

    if (size > list.getListSize())
        printf("\n\n���� ������� ��������\t\t �������� �������.\n\n");
    else printf("\n\n���� ������� ��������\t\t �� �������� �������.\n\n");
}
void Test_Task(CList& list, int& value)
{
    printf("\n\n����� ������ ���� �������� �������� ������ 200 � �� ������:\n");
    list.Task(value);
}



