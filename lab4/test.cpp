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
    
    if (_CrtDumpMemoryLeaks()) cout << "\n\nЕсть утечка памяти.\n\n";
    else cout << "\n\nУтечка памяти отсутствует\n\n.";

    return 0;
}
void Test_GetProgramID(CList& list, int& value)
{
    cout << "\n\nЗдесь должен быть элемент с идентификатором 5678:" << endl;
    list.GetProgramID(value);
}
void Test_AddEl(CList& list)
{
    C_Program newProgram;
    int size = list.getListSize();
    list.AddEl(newProgram);

    if (list.getListSize() > size) cout << "\n\nТест добавления элемента в список\t выполнен успешно.\n\n";
    else cout << "\n\nТест добавления элемента в список\t не выполнен успешно.\n\n";
}
void Test_DelEl(CList& list)
{
    int size = list.getListSize();
    list.DeleteEl(3);

    if (size > list.getListSize()) cout << "\n\nТест функции удаления\t\t выполнен успешно.\n\n";
    else cout << "\n\nТест функции удаления\t\t не выполнен успешно.\n\n";
}
void Test_Task(CList& list, int& value)
{
    cout << "\n\nЗдесь должны быть элементы размером больше 200 и не трояны:\n";
    list.Task(value);
}
void Test_Stringstream(CList& list)
{
    string nameExpected = "Скайп";
    stringstream funcResult = list.GetOneEl(1);
    string nameReal;
    funcResult >> nameReal;

    if (nameExpected == nameReal) cout << "\n\nТест функции stringstream\t\t пройдена успешно." << endl;
    else cout << "\n\nТест функции stringstream\t\t не пройдена успешно." << endl;
}
void Test_ReadFile(CList& list)
{
    string filename = "data.txt";
    list.ReadFile(filename);

    cout << "Если данные ниже соответствуют данным в файле, то тест пройден" << endl;
}