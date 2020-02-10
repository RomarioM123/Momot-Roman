#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#define CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, FILE, __LINE)

#include <stdio.h>
#include <locale.h>	    

class Program {
private:
	int TimeOfWork;		//среднее время работы программы
	int size;			//размер программы
	int AmountOfLines;	//количество строк кода	

public:
	int getTime() const
	{
		return TimeOfWork;
	}
	int getSize() const
	{
		return size;
	}
	int getLines() const
	{
		return AmountOfLines;
	}
	void setTime(int valueTime)
	{
		TimeOfWork = valueTime;
	}
	void setSize(int valueSize)
	{
		size = valueSize;
	}
	void setLines(int valueLines)
	{
		AmountOfLines = valueLines;
	}
};

class List {
private:
	int ListSize;

public:
	Program* List;

	void setListSize(int size)
	{
		ListSize = size;
	}

	int getListSize()const
	{
		return ListSize;
	}

	bool DeleteEl(int number)
	{
		for(int i = 0;i < ListSize; i++)
		{
			if (i == number)
			{
				for (; i < ListSize - 1; i++)
				{
					List[i] = List[i+1];
				}

				List[ListSize - 1] = 0;
				List = ListSize - 1;

				return true;
			}
		}
		return false;
	}

	void PrintAll() const
	{
		printf("Время/t/tРазмер/t/tСтроки/t/t");
		for (int i = 0; i < ListSize; i++)
			PrintOneEl(i);
	}

	void PrintOneEl(int number) const
	{
		printf("%i) %i %i %i\n", number+1, List[number].getTime(), List[number].getSize(), List[number].getLines());
	}
};

int main() 
{
	setlocale(LC_ALL, "Rus");   
	List ProgramList;
	int a = 2;

	ProgramList.setListSize(a);

	ProgramList.CreateList(5);
	ProgramList.DeleteEl(3);
	ProgramList.PrintAll();

	if (_CrtDumpMemoryLeaks())
		printf("\n\nЕсть утечка памяти\n");
	else
		printf("\nНет утечки памяти\n");
}