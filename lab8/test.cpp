#include "programList.h"

void Test_GetProgramID(CList&);
void Test_AddEl(CList&, CAuthor*);
void Test_DelEl(CList&);
void Test_Task(CList&);
void Test_Stringstream(CList&);
void Test_ReadFile(CList&);
void Test_RegexTask(CList&);
void Test_Sort(CList&);
void Test_Aggregation(CAuthor*);
void funcTest();

int main()
{
    setlocale(LC_ALL, "Rus");

    funcTest();
    
    if (_CrtDumpMemoryLeaks())
        cout << "\nЕсть утечка памяти.\n";
    else cout << "\nУтечка памяти отсутствует.\n";

    return 0;
}
void funcTest() 
{
    CList list;
    CAuthor author;
    CAuthor* authorsList;

    authorsList = author.createList(6);
    list.createList(4, authorsList);

    Test_GetProgramID(list);
    Test_AddEl(list, authorsList);
    Test_DelEl(list);    
    Test_Task(list);
    Test_Stringstream(list);
    Test_ReadFile(list);
    Test_RegexTask(list);
    Test_Sort(list);    
    Test_Aggregation(authorsList);
}

void Test_GetProgramID(CList& list)
{
    int expected = 7896;
    int real = list[2]->getIndex();

    if(expected == real) cout << "Тест получения элемента по ID\t\t выполнен успешно.\n";
    else cout << "Тест получения элемента по ID\t\t не выполнен успешно.\n";
}
void Test_AddEl(CList& list, CAuthor* listAuthors)
{
    int value = list.getListSize();
    CProgram* newProgram = list.newProgram(listAuthors, 1);
    list.addProgram(newProgram);


    if (list.getListSize() > value)
        cout << "Тест добавления элемента в список\t выполнен успешно.\n";
    else cout << "Тест добавления элемента в список\t не выполнен успешно.\n";
}
void Test_DelEl(CList& list)
{
    int size = list.getListSize();
    list.delProgram(1);
    int newSize = list.getListSize();

    if (size > list.getListSize())
        cout << "Тест функции удаления\t\t\t выполнен успешно.\n\n";
    else cout << "Тест функции удаления\t\t\t не выполнен успешно.\n\n";

}
void Test_Task(CList& list)
{
    int expected = 0;
    int real = list.task(200);

    cout << endl;
    if(expected == real) cout << "Тест нахождения элементов по параметру\t выполнен успешно.\n";
    else cout << "Тест нахождения элементов по параметру\t не выполнен успешно.\n";
}
void Test_Stringstream(CList& list)
{
    string nameExpected = "1445";
    stringstream funcResult = list.testStringstream(1);
    string nameReal;
    funcResult >> nameReal;

    if (nameExpected == nameReal) cout << "Тест функции stringstream\t\t выполнен успешно." << endl;
    else cout << "Тест функции stringstream\t\t не выполнен успешно." << endl;
}
void Test_ReadFile(CList& list)
{
    int expected = 3;
    int real = list.linesInFile("data.txt");

    if (expected == real) cout << "Тест функции чтения из файла\t\t выполнен успешно." << endl;
    else cout << "Тест функции чтения из файла\t\t не выполнен успешно." << endl;
}
void Test_RegexTask(CList& list)
{
    int expected = 0;
    int real = list.regexTask();

    if (real == expected) cout << "Тест функции regex\t\t\t выполнен успешно." << endl;
    else cout << "Тест функции regex\t\t\t не выполнен успешно." << endl;
}
void Test_Sort(CList& list)
{
    stringstream str1 = list.testStringstream(0);
    string beforeSorting;
    str1 >> beforeSorting;

    list.sort(list.sortDesc);
    
    stringstream str2 = list.testStringstream(0);
    string afterSorting;
    str2 >> afterSorting;

    if (beforeSorting != afterSorting && afterSorting == "1445") 
        cout << "Тест функции сортировки\t\t\t выполнен успешно." << endl;
    else cout << "Тест функции сортировки\t\t\t не выполнен успешно." << endl;
 
}
void Test_Aggregation(CAuthor* list)
{
    string expected = "Lambda";
    string real = (list + 1)->getAuthor();

    if (expected == real) cout << "Тест агрегации\t\t\t\t выполнен успешно." << endl;
    else cout << "Тест агрегации\t\t\t\t не выполнен успешно." << endl;
}