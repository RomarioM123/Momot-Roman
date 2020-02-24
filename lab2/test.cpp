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

    if (_CrtDumpMemoryLeaks()) printf("\n\nЕсть утечка памяти.\n\n");
    else printf("\n\nУтечка памяти отсутствует\n\n.");
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
	
	if (_CrtDumpMemoryLeaks()) printf("\n\nЕсть утечка памяти.\n\n");
	else printf("\n\nУтечка памяти отсутствует\n\n.");
>>>>>>> 042bc953d2b5e7240b67c16e27875c0f044d9563

    return 0;
}
void Test_GetProgramID(C_List& list, int& value)
{
<<<<<<< HEAD
    printf("\n\nЗдесь должен быть элемент с идентификатором 5678:\n");
    list.GetProgramID(value);
}
void Test_AddEl(C_List& list)
{
    C_Program newProgram;
    int size = list.getListSize();
    list.AddEl(newProgram);

    if (list.getListSize() > size)
        printf("\n\nТест добавления элемента в список\t выполнен успешно.\n\n");
    else printf("\n\nТест добавления элемента в список\t не выполнен успешно.\n\n");
}
void Test_DelEl(C_List& list)
{
    int size = list.getListSize();
    list.DeleteEl(3);

    if (size > list.getListSize())
        printf("\n\nТест функции удаления\t\t выполнен успешно.\n\n");
    else printf("\n\nТест функции удаления\t\t не выполнен успешно.\n\n");
}
void Test_Task(C_List& list, int& value)
{
    printf("\n\nЗдесь должны быть элементы размером больше 200 и не трояны:\n");
    list.Task(value);
}
=======
	printf("\n\nЗдесь должен быть элемент с идентификатором 5678:\n");
	list.GetProgramID(value);
	
	/*if (list.list->gettime() == 333)
		printf("\n\nтест нахождения элемента по id\t\t выполнен успешно.\n\n");
	else printf("\n\nтест нахождения элемента по id\t\t не выполнен успешно.\n\n");*/
}
void Test_AddEl(C_List& list)
{
	C_Program newProgram;
	int size = list.getListSize();
	list.AddEl(newProgram);

	if (list.getListSize() > size)
		printf("\n\nТест добавления элемента в список\t выполнен успешно.\n\n");
	else printf("\n\nТест добавления элемента в список\t не выполнен успешно.\n\n");
}
void Test_DelEl(C_List& list)
{
	int size = list.getListSize();
	list.DeleteEl(3);
	
	if (size > list.getListSize())
		printf("\n\nТест функции удаления\t\t выполнен успешно.\n\n");
	else printf("\n\nТест функции удаления\t\t не выполнен успешно.\n\n");
}
void Test_Task(C_List& list, int& value)
{
	printf("\n\nЗдесь должны быть элементы размером больше 200 и не трояны:\n");
	list.Task(value);
}
>>>>>>> 042bc953d2b5e7240b67c16e27875c0f044d9563
