#include "Program.h"
#include "List.h"
#include <iostream>

using namespace std;

int main() 
{
	setlocale(LC_ALL, "Rus");   
	List ProgramList;
	ProgramList.List = new Program[1];
	ProgramList.setListSize(0);
	

	Program ProgramInfo = ProgramList.Program1();
	ProgramList.List = ProgramList.AddEl(ProgramInfo);

	ProgramInfo = ProgramList.Program2();
	ProgramList.List = ProgramList.AddEl(ProgramInfo);

	ProgramList.PrintAll();
	
	//If you want to print only 1 element in console
	int PrintNumber;
	printf("\nВведите номер одного элемента, который хотите вывести в консоль: ");
	//scanf_s("%i\n", &PrintNumber);
	cin >> PrintNumber;

	
	if (PrintNumber <= 0 || PrintNumber > ProgramList.getListSize())
	{
		printf("Ошибка. Неверный номер элемента. Завершение работы программы.\n"); 
		
		return 0;
	}
	PrintNumber--;
	
	ProgramList.PrintOneEl(PrintNumber);
	
	//If you want to delete last element
	int DeleteAction;
	printf("\nХотите ли вы удалить один последний элемент(0-нет,1-да): ");
	scanf_s("%i\n", &DeleteAction);
	if (DeleteAction == 1)
	{
		ProgramList.List = ProgramList.DeleteEl();
		printf("Выводим оставшиеся элементы.\n");
		ProgramList.PrintAll();
	}

	printf("\nЗавершение работы.");
	delete[] ProgramList.List;
	if (_CrtDumpMemoryLeaks())
		printf("\n\nЕсть утечка памяти\n");
	else
		printf("\nНет утечки памяти\n");
}