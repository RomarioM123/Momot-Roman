#include "Program.h"
#include "List.h"

int main() 
{
	setlocale(LC_ALL, "Rus");   
	C_List ProgramList;
	ProgramList.List = new C_Program[1];
	ProgramList.setListSize(0);
	

	C_Program ProgramInfo = ProgramList.Program1();
	ProgramList.List = ProgramList.AddEl(ProgramInfo);

	ProgramInfo = ProgramList.Program2();
	ProgramList.List = ProgramList.AddEl(ProgramInfo);

	ProgramList.PrintAll();
	
	//If you want to print only 1 element in console
	int PrintNumber;
	printf("\n������� ����� ������ ��������, ������� ������ ������� � �������: ");
	scanf("%i\n", &PrintNumber, 1);
	
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
	scanf("%i\n", &DeleteAction, 1);
	if (DeleteAction == 1)
	{
		ProgramList.List = ProgramList.DeleteEl();
		printf("������� ���������� ��������.\n");
		ProgramList.PrintAll();
	}

	printf("\n���������� ������.");
	delete[] ProgramList.List;
	if (_CrtDumpMemoryLeaks())
		printf("\n\n���� ������ ������.\n");
	else
		printf("\n��� ������ ������.\n");
}