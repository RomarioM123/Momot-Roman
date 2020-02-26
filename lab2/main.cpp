#include "Program.h"
#include "List.h"

void Menu();

int main()
{
    setlocale(LC_ALL, "Rus");
    Menu();

    if (_CrtDumpMemoryLeaks()) printf("\n���� ������ ������.\n");
    else printf("\n��� ������ ������.\n");

    return 0;
}

void Menu()
{
    CList list;
    C_Program newProgram;
    int choise = 1, value = 0, stop = 1;
    list.CreateList(4);
    printf("\n�������� ������� ��� ������ �� �������:\n");
    while (stop != 0)
    {
        if (list.getListSize() == 0)
        {
            printf("������ ����. �������� �������(1) ��� ��������� ������(0): ");
            scanf("%i\n", &choise);

            if (choise == 1) choise = 3;
            else if (choise == 0) choise = 5;
            else(printf("�������� ������.\n"));
        }
        else
        {
            printf("\n\n1)������� �� �� �����\n2)������� 1 ������� �� �����\n");
            printf("3)�������� �������(� �����)\n4)������� 1 �������\n5)���������� ������\n");
            printf("6)������� ��������� �� �������\n7)�������� ������ �������� ������ ");
            printf("������������ ������� � �� ������\n=============================\n��� �����: ");
            scanf("%i", &choise);
        }

        switch (choise)
        {
        case 1:
            list.PrintAll();
            break;
        case 2:
            printf("������� ����� ��������, ������� ���� �������: ");
            scanf("%i", &value);
            if (value <= 0 || value > list.getListSize())
            {
                printf("�������� ����� ��������. ��������� �������.\n");
                break;
            }
            list.PrintOneEl(value - 1);
            break;
        case 3:
            list.AddEl(newProgram);
            break;
        case 4:
            printf("������� ����� ��������, ������� ������ �������: ");
            scanf("%i", &value);
            list.DeleteEl(value);
            break;
        case 5:
            printf("���������� ������.\n");
            stop = 0;
            break;
        case 6:
            printf("������� ������ ��������, �������� �� ������ ��������: ");
            scanf("%i", &value);
            list.GetProgramID(value);
            break;
        case 7:
            printf("������� ����������� ������ ��������: ");
            scanf("%i", &value);
            list.Task(value);
            break;
        default:
            printf("�������� ������. ��������� �������.\n");
            break;
        }
    }
    return;
}