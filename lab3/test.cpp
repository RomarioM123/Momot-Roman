#include "Program.h"
#include "List.h"

void Test_GetProgramID(C_List&, int&);
void Test_AddEl(C_List&);
void Test_DelEl(C_List&);
void Test_Task(C_List&, int&);
void Test_Stringstream(C_List&);
void Test_ReadFile(C_List& list);

int main() {
    setlocale(LC_ALL, "Rus");
    C_List List;
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
void Test_GetProgramID(C_List& list, int& value)
{
    cout << "\n\n����� ������ ���� ������� � ��������������� 5678:" << endl;
    list.GetProgramID(value);
}
void Test_AddEl(C_List& list)
{
    C_Program newProgram;
    int size = list.getListSize();
    list.AddEl(newProgram);

    if (list.getListSize() > size) cout << "\n\n���� ���������� �������� � ������\t �������� �������.\n\n";
    else cout << "\n\n���� ���������� �������� � ������\t �� �������� �������.\n\n";
}
void Test_DelEl(C_List& list)
{
    int size = list.getListSize();
    list.DeleteEl(3);

    if (size > list.getListSize()) cout << "\n\n���� ������� ��������\t\t �������� �������.\n\n";
    else cout << "\n\n���� ������� ��������\t\t �� �������� �������.\n\n";
}
void Test_Task(C_List& list, int& value)
{
    cout << "\n\n����� ������ ���� �������� �������� ������ 200 � �� ������:\n";
    list.Task(value);
}
void Test_Stringstream(C_List& list)
{
    string nameExpected = "�����";
    stringstream funcResult = list.GetOneEl(1);
    string nameReal;
    funcResult >> nameReal;

    if (nameExpected == nameReal) cout << "\n\n���� ������� stringstream\t\t �������� �������." << endl;
    else cout << "\n\n���� ������� stringstream\t\t �� �������� �������." << endl;
}
void Test_ReadFile(C_List& list)
{
    string filename = "data.txt";
    list.ReadFile(filename);

    cout << "���� ������ ���� ������������� ������ � �����, �� ���� �������" << endl;
}