#include "Program.h"
#include "List.h"

int main() 
{
	setlocale(LC_ALL, "Rus");   
	Menu();

	if (_CrtDumpMemoryLeaks()) printf("Есть утечка памяти.\n");
	else printf("Нет утечки памяти.\n");

	return 0;
}

void Menu()
{
	CList List;
	C_Program newProgram = List.Program2();
	int choise = 1, value = 0;
	List.setListSize(3);
	List.CreateList();
	printf("Выберите команду для работы со списком:\n");
	while (choise != 0)
	{
		printf("\n\n1)Вывести всё на экран\n2)Вывести 1 элемент на экран\n");
		printf("3)Добавить элемент(в конец)\n4)Удалить 1 элемент\n5)Завершение работы\n");
		printf("6)Найти программу по индексу\n=============================\nВаш выбор: ");
		scanf("%i", &choise);
		
		switch (choise)
		{
		case 1:
			List.PrintAll();
			break;
		case 2:
			printf("Введите номер элемента, который надо вывести: ");
			scanf("%i", &value);
			List.PrintOneEl(value - 1);
			break;
		case 3:
			List.AddEl(newProgram);
			break;
		case 4:
			printf("Введите номер элемента, который хотите удалить: ");
			scanf("%i", &value);
			List.DeleteEl(value);
			break;
		case 5:
			printf("Завершение работы.\n");
			choise = 0;
			break;
		case 6:
			printf("Введите индекс элемента, которого вы хотите получить: ");
			scanf("%i", &value);
			List.GetProgramID(value);
			break;
		default:
			printf("Неверный символ. Повторите попытку.\n");
			break;
		}
	}
	List.FreeMemory();
	return;
}