#include "program.h"
#include "list.h"
#include "author.h"
#include "date.h"

void Test_GetProgramID(CList&);
void Test_AddEl(CList&);
void Test_DelEl(CList&);
void Test_Task(CList&);
void Test_Stringstream(CList&);
void Test_ReadFile(CList&);
void Test_RegexTask(CList&);
void Test_Sort(CList&);

int main() {
    setlocale(LC_ALL, "Rus");
    CList list;
    list.createList(5);

    Test_GetProgramID(list);
    Test_AddEl(list);
    Test_DelEl(list);
    Test_Task(list);
    Test_Stringstream(list);
    Test_ReadFile(list);
    Test_RegexTask(list);
    Test_Sort(list);

    if (_CrtDumpMemoryLeaks()) cout << "\n\n���� ������ ������.\n\n";
    else cout << "\n\n������ ������ �����������.\n\n";

    return 0;
}
void Test_GetProgramID(CList& list)
{
    int expected = 5678;
    int real = list.list[2].getIndex();

    if(expected == real) cout << "���� ��������� �������� �� ID\t\t �������� �������.\n";
    else cout << "���� ��������� �������� �� ID\t\t �� �������� �������.\n";
}
void Test_AddEl(CList& list)
{
    C_Program newProgram;
    int size = list.getListSize();
    list.addEl(newProgram);

    if (list.getListSize() > size) cout << "���� ���������� �������� � ������\t �������� �������.\n";
    else cout << "���� ���������� �������� � ������\t �� �������� �������.\n";
}
void Test_DelEl(CList& list)
{
    int size = list.getListSize();
    list.deleteEl(3);

    if (size > list.getListSize()) cout << "���� ������� ��������\t\t\t �������� �������.\n\n";
    else cout << "���� ������� ��������\t\t\t �� �������� �������.\n\n";
}
void Test_Task(CList& list)
{
    int expected = 2;
    int real = list.task(200);

    cout << endl;
    if(expected == real) cout << "���� ������� ���������� ��������� �� ���������\t\t �������� �������.\n";
    else cout << "���� ������� ���������� ��������� �� ���������\t\t �� �������� �������.\n";
}
void Test_Stringstream(CList& list)
{
    string nameExpected = "1234";
    stringstream funcResult = list.getOneEl(1);
    string nameReal;
    funcResult >> nameReal;

    if (nameExpected == nameReal) cout << "���� ������� stringstream\t\t �������� �������." << endl;
    else cout << "���� ������� stringstream\t\t �� �������� �������." << endl;
}
void Test_ReadFile(CList& list)
{
    string filename = "data.txt";
    list.readFile(filename);

    string expected = "Notepad ";
    string real = list.list[0].getName();

    if (expected == real) cout << "���� ������� ������ �� �����\t\t �������� �������." << endl;
    else cout << "���� ������� ������ �� �����\t\t �� �������� �������." << endl;
}
void Test_RegexTask(CList& list)
{
    cout << "����� ������ ���� ���������, ���������� � �������� ������ 2 ����:" << endl;
    list.regexTask();
}
void Test_Sort(CList& list)
{
    int beforeSorting = list.list[0].getLines();
    list.sort(list.sortDesc);
    int afterSorting = list.list[0].getLines();
    int expected = 666;

    if (beforeSorting != afterSorting && afterSorting == expected) cout << "���� ������� ����������\t\t\t �������� �������." << endl;
    else cout << "���� ������� ����������\t\t\t �� �������� �������." << endl;
 
}