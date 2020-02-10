#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#define CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, FILE, __LINE)

#include <stdio.h> 
#include <locale.h>	    

class Program {
private:
	int TimeOfWork;		//average time of program execution
	int size;			//size of program
	int AmountOfLines;	//number of lines in code

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

	Program* AddEl(Program NewProgram)
	{
		int NewListSize = getListSize();
		NewListSize++;
		setListSize(NewListSize);

		Program* NewList = new Program[NewListSize];


		for (int i = 0; i < NewListSize-1; i++)
			NewList[i] = List[i];
		NewList[NewListSize - 1] = NewProgram;

		delete [] List;
		return NewList;
	}
	
	Program* DeleteEl()
	{
		int NewListSize = getListSize();
		NewListSize--;
		setListSize(NewListSize);

		Program* NewList = new Program[NewListSize+1];
		
		for (int i = 0; i <= NewListSize; i++)
			NewList[i] = List[i];

		delete [] List;
		return NewList;
	}

	void PrintAll() const
	{
		printf("  Время\t\tРазмер\t\tСтроки");
		for (int i = 0; i < ListSize; i++)
			PrintOneEl(i);
	}

	void PrintOneEl(int number) const
	{
		printf("\n%2i) %-10i\t %-10i\t %-10i", number+1, List[number].getTime(), List[number].getSize(), List[number].getLines());
	}

	Program Program1()
	{
		Program Program1;
		Program1.setTime(25326);
		Program1.setSize(2000);
		Program1.setLines(500);
		return Program1;
	}
	
	Program Program2()
	{
		Program Program2;
		Program2.setTime(55555);
		Program2.setSize(11111);
		Program2.setLines(22222);
		return Program2;
	}
};

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
	scanf_s("%i\n", &PrintNumber);
	if (PrintNumber <= 0 || PrintNumber > ProgramList.getListSize())
	{
		printf("Ошибка. Неверный номер элемента. Завершение работы программы.\n"); 
		
		return 0;
	}
	PrintNumber++;
	
	ProgramList.PrintOneEl(0);
	
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