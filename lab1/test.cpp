#include "List.h"
#include "Program.h"

C_Program* Test_AddEl(C_List, int*);
C_Program* Test_DelEl(C_List, int*);

int main() {
	setlocale(LC_ALL, "Rus");
	C_List ProgramList;
	ProgramList.List = new C_Program[1];
	ProgramList.setListSize(0);
	int count = 0;

	ProgramList.List = Test_AddEl(ProgramList, &count);
	ProgramList.setListSize(3);
	ProgramList.List = Test_DelEl(ProgramList, &count);


	if (count == 2) printf("Все тесты выполнены успешно.\n");
	else printf("Не все тесты выполнены удачно.\n");

	return 0;
}

C_Program* Test_AddEl(C_List ProgramList, int *count)
{
	C_Program ProgramInfo = ProgramList.Program1();
	ProgramList.List = ProgramList.AddEl(ProgramInfo);
	
	ProgramInfo = ProgramList.Program2();
	ProgramList.List = ProgramList.AddEl(ProgramInfo);

	ProgramInfo = ProgramList.TestProgram3();
	ProgramList.List = ProgramList.AddEl(ProgramInfo);

	int expected = 3;
	int real = ProgramList.getListSize();
	
	if (expected == real)
	{
		printf("Тест 1 выполнен удачно.\n");
		(*count)++;
	}
	else printf("Тест 1 пройден с ошибкой.\n");

	return ProgramList.List;
}
C_Program* Test_DelEl(C_List ProgramList, int *count)
{
	ProgramList.List = ProgramList.DeleteEl();
	ProgramList.List = ProgramList.DeleteEl();

	int expected = 1;
	int real = ProgramList.getListSize();

	if (expected == real)
	{
		printf("Тест 2 выполнен удачно.\n");
		(*count)++;
	}
	else printf("Тест 2 пройден с ошибкой.\n");

	return ProgramList.List;
}

C_Program C_List::TestProgram3()
{
	C_Program Program3;
	Program3.setTime(33333);
	Program3.setSize(33333);
	Program3.setLines(33333);
	return Program3;
}
