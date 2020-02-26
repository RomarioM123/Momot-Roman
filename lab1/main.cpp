#include "Program.h"
#include "List.h"

int main() 
{
	setlocale(LC_ALL, "Rus");   
	Menu();

	if (_CrtDumpMemoryLeaks()) printf("���� ������ ������.\n");
	else printf("��� ������ ������.\n");

	return 0;
}

void Menu()
{
	CList List;
	C_Program newProgram = List.Program2();
	int choise = 1, value = 0;
	List.setListSize(3);
	List.CreateList();
	printf("�������� ������� ��� ������ �� �������:\n");
	while (choise != 0)
	{
		printf("\n\n1)������� �� �� �����\n2)������� 1 ������� �� �����\n");
		printf("3)�������� �������(� �����)\n4)������� 1 �������\n5)���������� ������\n");
		printf("6)����� ��������� �� �������\n=============================\n��� �����: ");
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
		case 6:
			printf("������� ������ ��������, �������� �� ������ ��������: ");
			scanf("%i", &value);
			List.GetProgramID(value);
			break;
		default:
			printf("�������� ������. ��������� �������.\n");
			break;
		}
	}
	List.FreeMemory();
	return;
}