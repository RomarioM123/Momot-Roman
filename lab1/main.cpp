#include "Program.h"
#include "List.h"

int main() 
{
	setlocale(LC_ALL, "Rus");   
	C_Program Program;
	
	Menu();

	if (_CrtDumpMemoryLeaks()) printf("���� ������ ������.\n");
	else printf("��� ������ ������.\n");

	return 0;
}

void Menu()
{
	C_List List;
	C_Program getProgram;
	C_Program newProgram = List.Program2();
	int choise = 1, value = 0;
	List.setListSize(3);
	List.CreateList();
	printf("�������� ������� ��� ������ �� �������:\n");
	while (choise != 0)
	{
		printf("\n1)������� �� �� �����\n2)������� 1 ������� �� �����\n");
		printf("3)�������� �������(� �����)\n4)������� 1 �������\n5)���������� ������\n");
		printf("=============================\n��� �����: ");
		scanf("%i", &choise);
		
		switch (choise)
		{
		case 1:
			List.PrintAll();
			break;
		case 2:
			printf("������� ����� ��������, ������� ���� �������: ");
			scanf("%i", &value);
			List.PrintOneEl(value - 1);
			break;
		case 3:
			List.AddEl(newProgram);
			break;
		case 4:
			printf("������� ����� ��������, ������� ������ �������: ");
			scanf("%i", &value);
			List.DeleteEl(value);
			break;
		case 5:
			printf("���������� ������.\n");
			choise = 0;
			break;
		default:
			printf("�������� ������. ��������� �������.\n");
			break;
		}
	}
	List.FreeMemory();
	return;
}