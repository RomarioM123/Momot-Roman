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

    if (_CrtDumpMemoryLeaks()) printf("\n\nЕсть утечка памяти.\n\n");
    else printf("\n\nУтечка памяти отсутствует\n\n.");

    return 0;
}
void Test_GetProgramID(CList& list, int& value)
{
    printf("\n\nЗдесь должен быть элемент с идентификатором 5678:\n");
    list.GetProgramID(value);
}
void Test_AddEl(CList& list)
{
    C_Program newProgram;
    int size = list.getListSize();
    list.AddEl(newProgram);

    if (list.getListSize() > size)
        printf("\n\nТест добавления элемента в список\t выполнен успешно.\n\n");
    else printf("\n\nТест добавления элемента в список\t не выполнен успешно.\n\n");
}
void Test_DelEl(CList& list)
{
    int size = list.getListSize();
    list.DeleteEl(3);

    if (size > list.getListSize())
        printf("\n\nТест функции удаления\t\t выполнен успешно.\n\n");
    else printf("\n\nТест функции удаления\t\t не выполнен успешно.\n\n");
}
void Test_Task(CList& list, int& value)
{
    printf("\n\nЗдесь должны быть элементы размером больше 200 и не трояны:\n");
    list.Task(value);
}



