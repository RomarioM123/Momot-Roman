#include "programList.h"

void Test_GetProgramID(C_Program**);
C_Program** Test_AddEl(CList&, CAuthor*, C_Program**);
C_Program** Test_DelEl(C_Program**, CList&);
void Test_Task(CList&);
void Test_Stringstream(C_Program**, CList&);
void Test_ReadFile(CList&, C_Program**);
void Test_RegexTask(CList&);
void Test_Sort(C_Program**, CList&);
void Test_Aggregation(CAuthor*);

void funcTest();

int main()
{
    setlocale(LC_ALL, "Rus");

    funcTest();
    
    if (_CrtDumpMemoryLeaks())
    {
        cout << "\n\n���� ������ ������.\n\n";
    }
    else cout << "\n\n������ ������ �����������.\n\n";

    return 0;
}

void funcTest() {
    
    CList list;
    CAuthor author;
    CAuthor* authorsList;
    C_Program** programList;

    authorsList = author.createList(6);
    programList = list.createList(4, authorsList);

    Test_GetProgramID(programList);
    programList = Test_AddEl(list, authorsList, programList);
    programList = Test_DelEl(programList, list);    
    Test_Task(list);
    Test_Stringstream(programList, list);
    Test_ReadFile(list, programList);
    Test_RegexTask(list);
    Test_Sort(programList, list);
    Test_Aggregation(authorsList);
}

void Test_GetProgramID(C_Program** list)
{
    int expected = 7896;
    int real = list[2]->getIndex();

    if(expected == real) cout << "���� ��������� �������� �� ID\t\t �������� �������.\n";
    else cout << "���� ��������� �������� �� ID\t\t �� �������� �������.\n";
}
C_Program** Test_AddEl(CList& list, CAuthor* listAuthors, C_Program** programList)
{
    int value = list.getListSize();
    C_Program* newProgram = list.newProgram(listAuthors, 1);
    programList = list.addProgram(newProgram, programList);


    if (list.getListSize() > value&& programList[4]->getIndex() == 6734)
    {
        cout << "���� ���������� �������� � ������\t �������� �������.\n";
    }
    else cout << "���� ���������� �������� � ������\t �� �������� �������.\n";

    return programList;
}
C_Program** Test_DelEl(C_Program** programList, CList& list)
{
    int size = list.getListSize();
    programList = list.delProgram(1, programList);
    int newSize = list.getListSize();

    if (size > list.getListSize() && programList[1]->getIndex() == 7896)
    {
        cout << "���� ������� ��������\t\t\t �������� �������.\n\n";
    }
    else cout << "���� ������� ��������\t\t\t �� �������� �������.\n\n";

    return programList;
}
void Test_Task(CList& list)
{
    int expected = 0;
    int real = list.task(200);

    cout << endl;
    if(expected == real) cout << "���� ���������� ��������� �� ���������\t �������� �������.\n";
    else cout << "���� ���������� ��������� �� ���������\t �� �������� �������.\n";
}
void Test_Stringstream(C_Program** programList, CList& list)
{
    string nameExpected = "65";
    stringstream funcResult = programList[0]->getStr();
    string nameReal;
    funcResult >> nameReal;

    if (nameExpected == nameReal) cout << "���� ������� stringstream\t\t �������� �������." << endl;
    else cout << "���� ������� stringstream\t\t �� �������� �������." << endl;
}
void Test_ReadFile(CList& list, C_Program** programList)
{
    int expected = 3;
    int real = list.linesInFile("data.txt");

    if (expected == real) cout << "���� ������� ������ �� �����\t\t �������� �������." << endl;
    else cout << "���� ������� ������ �� �����\t\t �� �������� �������." << endl;
}
void Test_RegexTask(CList& list)
{
    int expected = 0;
    int real = list.regexTask(list);

    if (real == expected) cout << "���� ������� regex\t\t\t �������� �������." << endl;
    else cout << "���� ������� regex\t\t\t �� �������� �������." << endl;
}
void Test_Sort(C_Program** programList, CList& list)
{
    int beforeSorting = programList[0]->getLines();
    list.sort(list.sortDesc);
    int afterSorting = programList[0]->getLines();
    int expected = 745;

    if (beforeSorting != afterSorting && afterSorting == expected) cout << "���� ������� ����������\t\t\t �������� �������." << endl;
    else cout << "���� ������� ����������\t\t\t �� �������� �������." << endl;
 
}
void Test_Aggregation(CAuthor* list)
{
    string expected = "Lambda";
    string real = (list + 1)->getAuthor();

    if (expected == real) cout << "���� ���������\t\t\t\t �������� �������." << endl;
    else cout << "���� ���������\t\t\t\t �� �������� �������." << endl;
}