#include "Program.h"
#include "List.h"

void Test_GetProgramID(CList&, int&);
void Test_AddEl(CList&);
void Test_DelEl(CList&);
void Test_Task(CList&, int&);
void Test_Stringstream(CList&);
void Test_ReadFile(CList& list);

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
    Test_Stringstream(List);
    List.PrintAll();
    Test_ReadFile(List);
    List.PrintAll();
    
    if (_CrtDumpMemoryLeaks()) cout << "\n\n���� ������ ������.\n\n";
    else cout << "\n\n������ ������ �����������\n\n.";

    return 0;
}
void Test_GetProgramID(CList& list, int& value)
{
    cout << "\n\n����� ������ ���� ������� � ��������������� 5678:" << endl;
    list.GetProgramID(value);
}
void Test_AddEl(CList& list)
{
    C_Program newProgram;
    int size = list.getListSize();
    list.AddEl(newProgram);

    if (list.getListSize() > size) cout << "\n\n���� ���������� �������� � ������\t �������� �������.\n\n";
    else cout << "\n\n���� ���������� �������� � ������\t �� �������� �������.\n\n";
}
void Test_DelEl(CList& list)
{
    int size = list.getListSize();
    list.DeleteEl(3);

    if (size > list.getListSize()) cout << "\n\n���� ������� ��������\t\t �������� �������.\n\n";
    else cout << "\n\n���� ������� ��������\t\t �� �������� �������.\n\n";
}
void Test_Task(CList& list, int& value)
{
    cout << "\n\n����� ������ ���� �������� �������� ������ 200 � �� ������:\n";
    list.Task(value);
}
void Test_Stringstream(CList& list)
{
    string nameExpected = "�����";
    stringstream funcResult = list.GetOneEl(1);
    string nameReal;
    funcResult >> nameReal;

    if (nameExpected == nameReal) cout << "\n\n���� ������� stringstream\t\t �������� �������." << endl;
    else cout << "\n\n���� ������� stringstream\t\t �� �������� �������." << endl;
}
void Test_ReadFile(CList& list)
{
    string filename = "data.txt";
    list.ReadFile(filename);

    cout << "���� ������ ���� ������������� ������ � �����, �� ���� �������" << endl;
}