#include "programForSale.h"
#include "malware.h"
#define SIZE 4
int main()
{
	setlocale(LC_ALL, "Rus");

	CProgram* list[SIZE];

	list[0] = new CProgram();
	list[1] = new CMalware(1, 8800, 555, 35, 35634, "BestMalware", "Exploit");
	list[2] = new CProgram(0, 423, 523, 654, 53453, "Calculator");
	list[3] = new CProgramForSale(0, 345, 789, 423, 67456, "MoneyStealer", 54545);

	cout << endl;
	for (size_t i = 0; i < SIZE; i++)
		cout << *list[i] << endl;
	cout << endl;

	CProgram* list2 = new CProgram[SIZE];

	cout << endl;
	for (size_t i = 0; i < SIZE; i++)
		cout << list2[i] << endl;
	cout << endl;

	for (size_t i = 0; i < SIZE; i++)
		delete list[i];
	
	delete[] list2;

	if (_CrtDumpMemoryLeaks())
		cout << endl << "Есть утечка памяти." << endl;
	else
		cout << endl << "Утечка памяти отсутствует." << endl;

	return 0;
}