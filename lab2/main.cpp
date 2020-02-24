#include "Program.h"
#include "List.h"

void Menu();

int main()
{
    setlocale(LC_ALL, "Rus");
    Menu();

    if (_CrtDumpMemoryLeaks()) printf("\nЕсть утечка памяти.\n");
    else printf("\nНет утечки памяти.\n");

    return 0;
}

void Menu()
{
    C_List List;
    C_Program newProgram;
    int choise = 1, value = 0, stop = 1;
    List.CreateList(4);
    printf("\nВыберите команду для работы со списком:\n");
    while (stop != 0)
    {
        if (List.getListSize() == 0)
        {
            printf("Список пуст. Добавить элемент(1) или закончить работу(0): ");
            scanf("%i\n", &choise);

            if (choise == 1) choise = 3;
            else if (choise == 0) choise = 5;
            else(printf("Неверный символ.\n"));
        }
        else
        {
            printf("\n\n1)Вывести всё на экран\n2)Вывести 1 элемент на экран\n");
            printf("3)Добавить элемент(в конец)\n4)Удалить 1 элемент\n5)Завершение работы\n");
            printf("6)Вывести программы по индексу\n7)Получить список программ больше ");
            printf("определённого размера и не трояны\n=============================\nВаш выбор: ");
            scanf("%i", &choise);
        }

        switch (choise)
        {
        case 1:
            List.PrintAll();
            break;
        case 2:
            printf("Введите номер элемента, который надо вывести: ");
            scanf("%i", &value);
            if (value <= 0 || value > List.getListSize())
            {
                printf("Неверный номер элемента. Повторите попытку.\n");
                break;
            }
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
            stop = 0;
            break;
        case 6:
            printf("Введите индекс элемента, которого вы хотите получить: ");
            scanf("%i", &value);
            List.GetProgramID(value);
            break;
        case 7:
            printf("Введите минимальный размер программ: ");
            scanf("%i", &value);
            List.Task(value);
            break;
        default:
            printf("Неверный символ. Повторите попытку.\n");
            break;
        }
    }
    return;
}