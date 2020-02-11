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
	printf("\n������� ����� ������ ��������, ������� ������ ������� � �������: ");
	//scanf_s("%i\n", &PrintNumber);
	cin >> PrintNumber;

	
	if (PrintNumber <= 0 || PrintNumber > ProgramList.getListSize())
	{
		printf("������. �������� ����� ��������. ���������� ������ ���������.\n"); 
		
		return 0;
	}
	PrintNumber--;
	
	ProgramList.PrintOneEl(PrintNumber);
	
	//If you want to delete last element
	int DeleteAction;
	printf("\n������ �� �� ������� ���� ��������� �������(0-���,1-��): ");
	scanf_s("%i\n", &DeleteAction);
	if (DeleteAction == 1)
	{
		ProgramList.List = ProgramList.DeleteEl();
		printf("������� ���������� ��������.\n");
		ProgramList.PrintAll();
	}

	printf("\n���������� ������.");
	delete[] ProgramList.List;
	if (_CrtDumpMemoryLeaks())
		printf("\n\n���� ������ ������\n");
	else
		printf("\n��� ������ ������\n");
}