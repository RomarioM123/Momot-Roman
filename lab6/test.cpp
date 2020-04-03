#include "programList.h"
#include "malwareList.h"

#pragma region Program
void Test_GetProgramID(CList&);
void Test_AddEl(CList&);
void Test_DelEl(CList&);
void Test_Task(CList&);
void Test_Stringstream(CList&);
void Test_ReadFile(CList&);
void Test_RegexTask(CList&);
void Test_Sort(CList&);
#pragma endregion Program

#pragma region Malware
void Test_GetProgramID(MalwareList&);
void Test_AddEl(MalwareList&);
void Test_DelEl(MalwareList&);
void Test_Task(MalwareList&);
void Test_Stringstream(MalwareList&);
void Test_ReadFile(MalwareList&);
void Test_RegexTask(MalwareList&);
void Test_Sort(MalwareList&);
#pragma endregion Malware

void Test_Aggregation(CAuthor*);

int main() {
    setlocale(LC_ALL, "Rus");
    int value;
    cout << "Выберите класс для тестирования:" << endl;
    cout << "1) Основной класс" << endl;
    cout << "2) Класс наследник" << endl;
    cout << "Ваш выбор: ";
    cin >> value;
    cout << endl;

    CAuthor authors;
    CAuthor* authorsList;
    authorsList = authors.createList(4);

    if (value == 1)
    {
        CList list;
        list.createList(4, authorsList);

        Test_GetProgramID(list);
        Test_AddEl(list);
        Test_DelEl(list);
        Test_Task(list);
        Test_Stringstream(list);
        Test_ReadFile(list);
        Test_RegexTask(list);
        Test_Sort(list);
    }
    else if (value == 2)
    {
        MalwareList list2;
        list2.createList(4, authorsList);

        Test_GetProgramID(list2);
        Test_AddEl(list2);
        Test_DelEl(list2);
        Test_Task(list2);
        Test_Stringstream(list2);
        Test_ReadFile(list2);
        Test_RegexTask(list2);
        Test_Sort(list2);
    }
    else { cout << "Неверный символ. Завершение работы." << endl; }
    
    Test_Aggregation(authorsList);

    if (_CrtDumpMemoryLeaks()) cout << "\n\nЕсть утечка памяти.\n\n";
    else cout << "\n\nУтечка памяти отсутствует.\n\n";

    return 0;
}

#pragma region ProgramTests
void Test_GetProgramID(CList& list)
{
    int expected = 5678;
    int real = list.list[2].getIndex();

    if(expected == real) cout << "Тест получения элемента по ID\t\t выполнен успешно.\n";
    else cout << "Тест получения элемента по ID\t\t не выполнен успешно.\n";
}
void Test_AddEl(CList& list)
{
    C_Program newProgram;
    int size = list.getListSize();
    list.addEl(newProgram);

    if (list.getListSize() > size) cout << "Тест добавления элемента в список\t выполнен успешно.\n";
    else cout << "Тест добавления элемента в список\t не выполнен успешно.\n";
}
void Test_DelEl(CList& list)
{
    int size = list.getListSize();
    list.deleteEl(3);

    if (size > list.getListSize()) cout << "Тест функции удаления\t\t\t выполнен успешно.\n\n";
    else cout << "Тест функции удаления\t\t\t не выполнен успешно.\n\n";
}
void Test_Task(CList& list)
{
    int expected = 1;
    int real = list.task(200);

    cout << endl;
    if(expected == real) cout << "Тест нахождения элементов по параметру\t выполнен успешно.\n";
    else cout << "Тест нахождения элементов по параметру\t не выполнен успешно.\n";
}
void Test_Stringstream(CList& list)
{
    string nameExpected = "1234";
    stringstream funcResult = list.getOneEl(1);
    string nameReal;
    funcResult >> nameReal;

    if (nameExpected == nameReal) cout << "Тест функции stringstream\t\t выполнен успешно." << endl;
    else cout << "Тест функции stringstream\t\t не выполнен успешно." << endl;
}
void Test_ReadFile(CList& list)
{
    string filename = "data.txt";
    list.readFile(filename);

    string expected = "Notepad ";
    string real = list.list[0].getName();

    if (expected == real) cout << "Тест функции чтения из файла\t\t выполнен успешно.\n" << endl;
    else cout << "Тест функции чтения из файла\t\t не выполнен успешно.\n" << endl;
}
void Test_RegexTask(CList& list)
{
    cout << "Здесь должны быть программы, содержащие в названии больше 2 слов:" << endl;
    list.regexTask();
}
void Test_Sort(CList& list)
{
    int beforeSorting = list.list[0].getLines();
    list.sort(list.sortDesc);
    int afterSorting = list.list[0].getLines();
    int expected = 666;

    if (beforeSorting != afterSorting && afterSorting == expected) cout << "Тест функции сортировки\t\t\t выполнен успешно." << endl;
    else cout << "Тест функции сортировки\t\t\t не выполнен успешно." << endl;
 
}
#pragma endregion ProgramTests

#pragma region MalwareTests
void Test_GetProgramID(MalwareList& list)
{
    if (list.list[2].getIndex() == 5678) cout << "Тест получения элемента по ID\t\t выполнен успешно.\n";
    else cout << "Тест получения элемента по ID\t\t не выполнен успешно.\n";
}
void Test_AddEl(MalwareList& list)
{
    CMalware newProgram;
    int size = list.getListSize();
    list.addEl(newProgram);

    if (list.getListSize() > size) cout << "Тест добавления элемента в список\t выполнен успешно.\n";
    else cout << "Тест добавления элемента в список\t не выполнен успешно.\n";
}
void Test_DelEl(MalwareList& list)
{
    int size = list.getListSize();
    list.deleteEl(3);

    if (size > list.getListSize()) cout << "Тест функции удаления\t\t\t выполнен успешно.\n\n";
    else cout << "Тест функции удаления\t\t\t не выполнен успешно.\n\n";
}
void Test_Task(MalwareList& list)
{
    int expected = 0;
    int real = list.task(200);

    cout << endl;
    if (expected == real) cout << "Тест нахождения элементов по параметру\t выполнен успешно.\n";
    else cout << "Тест нахождения элементов по параметру\t не выполнен успешно.\n";
}
void Test_Stringstream(MalwareList& list)
{
    string nameExpected = "1234";
    stringstream funcResult = list.getOneEl(1);
    string nameReal;
    funcResult >> nameReal;

    if (nameExpected == nameReal) cout << "Тест функции stringstream\t\t выполнен успешно." << endl;
    else cout << "Тест функции stringstream\t\t не выполнен успешно." << endl;
}
void Test_ReadFile(MalwareList& list)
{
    string filename = "dataM.txt";
    list.readFile(filename);

    string expected = "Exploit";
    string real = list.list[0].getType();

    if (expected == real) cout << "Тест функции чтения из файла\t\t выполнен успешно." << endl;
    else cout << "Тест функции чтения из файла\t\t не выполнен успешно." << endl;
}
void Test_RegexTask(MalwareList& list)
{
    cout << "Здесь должны быть программы, содержащие в названии больше 2 слов:" << endl;
    list.regexTask();
}
void Test_Sort(MalwareList& list)
{
    int beforeSorting = list.list[0].getLines();
    list.sort(list.sortDesc);
    int afterSorting = list.list[0].getLines();
    int expected = 666;

    if (beforeSorting != afterSorting && afterSorting == expected) cout << "Тест функции сортировки\t\t\t выполнен успешно." << endl;
    else cout << "Тест функции сортировки\t\t\t не выполнен успешно." << endl;

}
#pragma endregion MalwareTests

void Test_Aggregation(CAuthor* list)
{
    string expected = "Lambda";
    string real = (list + 1)->getAuthor();

    if (expected == real) cout << "Тест агрегации\t\t\t\t выполнен успешно." << endl;
    else cout << "Тест агрегации\t\t\t\t не выполнен успешно." << endl;
}