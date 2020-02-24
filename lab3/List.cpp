#include "List.h"

void C_List::CreateList(int value)
{
	listSize = value;
	list = new C_Program[listSize];

	for (int i = 0; i < listSize; i++)
		list[i] = Programs(i);
}
void C_List::setListSize(int size)
{
	listSize = size;
}
int C_List::getListSize() const
{
	return listSize;
}

void C_List::PrintAll() const
{
	cout << "\n\tВремя\t\tРазмер\t\tСтроки\t\tТроян\t\tИндекс\t\tНазвание";
	for (int i = 0; i < listSize; i++)
		PrintOneEl(i);
}
void C_List::PrintOneEl(int number) const
{
	

	cout << endl << std::setiosflags(std::ios::left) << setw(2) << number + 1 << ")\t";
	cout << setw(17) << list[number].getTime();
	cout << setw(17) << list[number].getSize();
	cout << setw(14) << list[number].getLines();
	cout << setw(17) << std::boolalpha << list[number].getTrojan();
	cout << setw(14) << list[number].getIndex();
	cout << setw(20) << list[number].getName();
}
void C_List::AddEl(C_Program& newProgram)
{
	C_Program* newList = new C_Program[listSize + 1];

	for (int i = 0; i < listSize; i++)
		newList[i] = list[i];
	newList[listSize++] = newProgram;
	delete[] list;

	list = new C_Program[listSize];
	for (int i = 0; i < listSize; i++)
		list[i] = newList[i];

	delete[] newList;
	cout << "Элемент добавлен." << endl;
}
void C_List::DeleteEl(int index)
{
	if (listSize == 0)
	{
		cout << "список программ пуст. возвращение с выбору действий." << endl;
		return;
	}
	if (index <= 0 || index > listSize)
	{
		cout << "ошибка. неверный номер элемента. вовзвращение." << endl;
		return;
	}

	C_Program* newList = new C_Program[listSize - 1];

	for (int i = 0; i < index - 1; i++)
		newList[i] = list[i];
	for (int i = index - 1, j = index; j < listSize; i++, j++)
		newList[i] = list[j];
	delete[] list;

	list = new C_Program[listSize--];
	for (int i = 0; i < listSize; i++)
		list[i] = newList[i];
	delete[] newList;

	return;
}
void C_List::Task(int minimalSize)
{
	for (int i = 0; i < listSize; i++)
		if (list[i].getSize() > minimalSize&& list[i].getTrojan() == false)
			PrintOneEl(i);
}
int C_List::LinesInFile(string filename)
{
	int size = 0;
	string line;

	std::ifstream fin(filename);
	if (!fin.is_open())
	{
		cout << "Невозможно открыть файл. Возвращение в меню." << endl;
		return 0;
	}

	while (getline(fin, line)) size++;

	fin.close();
	return size;
}
void C_List::ReadFile(string filename)
{
	std::ifstream fin(filename);
	int size = C_List::LinesInFile(filename);

	if (!fin.is_open()) return;

	delete[] list;
	list = new C_Program[size];
	for (int i = 0; i < size; i++)
	{
		int TimeOfWork, size, AmountOfLines, index;
		bool trojan;
		string name;

		fin >> name;
		fin >> index;
		fin >> size;
		fin >> TimeOfWork;
		fin >> AmountOfLines;
		fin >> trojan;

		C_Program newElement(trojan, TimeOfWork, size, AmountOfLines, index, name);
		list[i] = newElement;
	}
	setListSize(size);
	fin.close();
	cout << endl << "Чтение из файла завершено." << endl;
}
void C_List::SaveToFile(string filename)
{
	std::ofstream fout(filename);

	fout.setf(std::ios::left);
	fout << "\tВремя\tРазмер\t\tСтроки\t\tТроян\t\tИндекс\t\tНазвание" << endl;
	for (int i = 0; i < getListSize(); i++)
	{
		fout << setw(2) << i + 1 << ")\t " << setw(9) << list[i].getTime() << setw(12);
		fout << list[i].getSize() << setw(11) << list[i].getLines() << setw(12);
		fout << std::boolalpha << list[i].getTrojan() << setw(11) << list[i].getIndex() << setw(15);
		fout << list[i].getName() << endl;
	}

	cout << "Запись в файл завершена." << endl;
	fout.close();
}
stringstream C_List::GetOneEl(int value) const
{
	stringstream temp;
	temp << " " << list[value].getName() << " " << list[value].getTrojan() << " " << list[value].getIndex() << " " << list[value].getLines() << " " << list[value].getSize() << " " << list[value].getTime();
	return temp;
}

C_Program C_List::GetProgramID(int id) const
{
	C_Program newProgram;

	for (int i = 0; i < listSize; i++)
		if (list[i].getIndex() == id)
		{
			PrintOneEl(i);
			newProgram = list[i];
			return newProgram;
		}
	cout << "\nПрограммы с таким ID нету.\n" << endl;
	return newProgram;
}
C_Program C_List::Programs(int valueX)
{
	C_Program standartProgram;

	if (valueX == 1)
	{
		C_Program Program1(true, 222, 222, 222, 1234, "Скайп");
		return Program1;
	}
	else if (valueX == 2)
	{
		C_Program Program2(true, 333, 333, 666, 5678, "Калькулятор");
		return Program2;
	}
	else if (valueX == 3)
	{
		C_Program Program3(false, 444, 444, 444, 9532, "Домино");
		return Program3;
	}
	else if (valueX == 4)
	{
		C_Program Program4(false, 555, 555, 555, 4356, "Редактор Текста");
		return Program4;
	}
	return standartProgram;
}
C_List::~C_List()
{
	cout << "\nВызвался деструктор" << endl;
	delete[] list;
}