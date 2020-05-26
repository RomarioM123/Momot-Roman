#include "programList.h"

int CList::getListSize() const 
{ 
	return listSize; 
}

void CList::createList(int value, CAuthor* authors)
{
	listSize = value;
	programList = new CProgram * [value];

	for (size_t i = 0; i < value; i++)
	{
		if (i == 0)
		{
			*(programList + i) = new CMalware();
		}
		else if (i == 1)
		{
			*(programList + i) = new CProgramForSale(true, 121, 222, 532, 1234, "Skype", *(authors + 1), 2, 12, 2002, 3000);
		}
		else if (i == 2)
		{
			*(programList + i) = new CMalware(true, 1445, 532, 745, 7896, "Spider", *(authors + 2), 6, 9, 1995, "Keylogger");
		}
		else if (i == 3)
		{
			*(programList + i) = new CProgramForSale(false, 333, 444, 555, 6745, "Calculator", *(authors + 3), 1, 11, 2001, 200);
		}
		if (i == 4)
		{
			*(programList + i) = new CProgramForSale();
		}
	}
}
void CList::addProgram(CProgram* program)
{
	CProgram** newList = new CProgram * [listSize + 1];
	CProgram** temp = programList;

	for (size_t i = 0; i < listSize; i++)
	{
		*(newList + i) = *(programList + i);
	}	
	newList[listSize++] = program;
	programList = newList;
	newList = temp;
	
	delete newList;
}
void CList::delProgram(int value)
{
	if (listSize == 0)
	{
		cout << "список программ пуст. возвращение с выбору действий." << endl;
		return;
	}
	if (value <= 0 || value > listSize)
	{
		cout << "ошибка. неверный номер элемента. вовзвращение." << endl;
		return;
	}

	CProgram** newList = new CProgram * [listSize - 1];
	CProgram** temp = programList;

	for (size_t i = 0; i < value; i++)
		*(newList + i) = *(programList + i);
	for (size_t i = value, j = value + 1; j < listSize; i++, j++)
		*(newList + i) = *(programList + j);
	
	programList = newList;
	newList = temp;
	listSize--;
	delete* (newList + value);
	delete newList;
}
CProgram* CList::newProgram(CAuthor* list, int value) const
{
	if (value == 1)
	{
		CProgram* Program = new CMalware(true, 444, 555, 666, 6734, "Stealer", *(list + 4), 30, 11, 1967, "Trojan");
		return Program;
	}
	else 
	{
		CProgram* Program = new CProgramForSale(false, 34, 69, 534, 5378, "Randomizer", *(list + 5), 15, 15, 2015, 1000000);
		return Program;
	}
}
void CList::printAll() const
{
	auto i = 0;
	if (listSize == 0)
	{
		cout << "Список пуст." << endl << endl;
		return;
	}
	else if (listSize < i || i < 0)
	{
		cout << "Неверный номер элемента." << endl << endl;
	}
	
	cout << endl << setiosflags(ios::left);
	cout << setw(12) << "  Время" << setw(12) << "Размер";
	cout << setw(10) << "Строки" << setw(11) << "Интернет";
	cout << setw(14) << "Индекс" << setw(21) << "Название";
	cout << setw(16) << "Год выпуска" << setw(14) << "Автор";
	cout << setw(14) << "Тип/Цена" << endl;

	for (; i < listSize; i++)
	{
		cout << setiosflags(ios::left) << setw(2) << i + 1 << ")";
		cout << *programList[i];
		cout << endl;
	}
	cout << endl;
}
void CList::getOneEl(int value) const
{
	stringstream temp = programList[value]->getStr();
	
	int time, size, lines, index;
	sint day, month, year;
	string name, name2;
	string internet2;
	bool internet;
	string author;
	string data;

	temp >> time;
	temp >> size;
	temp >> lines;
	temp >> boolalpha >> internet2;
	temp >> index;
	temp >> year;
	temp >> author;
	temp >> data;
	temp >> name;
	temp >> name2;

	if (internet2 == "1") internet = true;
	else internet = false;

	if (name2 == "") name = name + " ";
	else(name = name + " " + name2);

	cout << endl << setiosflags(ios::left);
	cout << setw(12) << "  Время" << setw(12) << "Размер";
	cout << setw(10) << "Строки" << setw(11) << "Интернет";
	cout << setw(14) << "Индекс" << setw(21) << "Название";
	cout << setw(16) << "Год выпуска" << setw(15) << "Автор";
	cout << setw(13) << "Тип/Цена" << endl << "   ";

	cout << setw(10) << time;
	cout << setw(12) << size;
	cout << setw(10) << lines;
	cout << setw(10) << internet;
	cout << setw(14) << index;
	cout << setw(25) << name;
	cout << setw(12) << year;
	cout << setw(15) << author;
	cout << setw(14) << data;
	cout << endl;
}
sint CList::task(int minimalSize)const
{
	int size = 0;

	for (size_t i = 0; i < listSize; i++)
	{
		if (programList[i]->getSize() > minimalSize && programList[i]->getName() == "Notepad")
		{
			cout << *programList[i];
			size++;
		}
	}
		
	if (size == 0)
	{
		cout << "Программы с такими параметрами отсутствуют." << endl;
	}

	return size;
}
void CList::saveFile(string filename) const
{
	std::ofstream fout(filename);
	if (!fout.is_open())
	{
		cout << "Невозможно открыть файл." << endl;
	}

	fout.setf(ios::left);
	fout << setw(12) << "  Время" << setw(12) << "Размер";
	fout << setw(13) << "Строки" << setw(11) << "Интернет";
	fout << setw(15) << "Индекс" << setw(24) << "Название";
	fout << setw(16) << "Год выпуска" << setw(14) << "Автор";
	fout << setw(12) << "Тип/Цена" << endl;

	for (size_t i = 0; i < listSize; i++)
	{
		fout << setiosflags(ios::left) << setw(2) << i + 1 << ")";
		fout << *programList[i];
		fout << endl;
	}

	cout << "Запись в файл завершена." << endl;
	fout.close();
}
int CList::linesInFile(string filename) const
{
	int size = 0;
	string line;
	regex expressionMalware("([\\d]* [\\d]* [a-zA-ZА-Яа-я]* [\\d]* [\\d]* [1|0]* [\\w]* [\\d]* [A-ZА-Я]+[\\wА-Яа-я,.;:-]* [\\wА-Яа-я,.;:-]*)");
	regex expressionProgramForSelling("([\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [1|0]* [\\w]* [\\d]* [A-ZА-Я]+[\\wА-Яа-я,.;:-]* [\\wА-Яа-я,.;:-]*)");

	ifstream fin(filename);
	if (!fin.is_open())
	{
		cout << "Невозможно открыть файл. Возвращение в меню." << endl;
		return 0;
	}

	while (getline(fin, line))
	{
		if (regex_match(line, expressionMalware) || regex_match(line, expressionProgramForSelling))
			size++;
		else cout << "Строка в файле не прошла проверку." << endl;
	}

	fin.close();
	return size;
}
void CList::readFile(string filename)
{
	regex expressionMalware("([\\d]* [\\d]* [a-zA-ZА-Яа-я]* [\\d]* [\\d]* [1|0]* [\\w]* [\\d]* [A-ZА-Я]+[\\wА-Яа-я,.;:-]* [\\wА-Яа-я,.;:-]*)");
	regex expressionProgramForSelling("([\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [1|0]* [\\w]* [\\d]* [A-ZА-Я]+[\\wА-Яа-я,.;:-]* [\\wА-Яа-я,.;:-]*)");
	string data, line;
	int size = CList::linesInFile(filename);
	int i = 0, j = 0, a = 0;
	bool b;
	ifstream fin(filename);
	if (!fin.is_open())
	{
		cout << "Неверное название файла. Повторите попытку." << endl;
		return;
	}
	
	for (size_t i = 0; i < size; i++)
	{
		delete* (programList + i);
	}
	delete[] programList;
	programList = new CProgram * [size];

	while (getline(fin, line) && j < size)
	{	
		b = 1;
		if (regex_match(line.c_str(), expressionMalware))
		{
			do {
				b = 0;

				a = line.find("--");
				if (a != -1)
				{
					line.erase(a, 1);
					b = 1;
				}

				a = line.find("  ");
				if (a != -1)
				{
					line.erase(a, 1);
					b = 1;
				}

				a = line.find(",,");
				if (a != -1)
				{
					line.erase(a, 1);
					b = 1;
				}

				a = line.find("::");
				if (a != -1)
				{
					line.erase(a, 1);
					b = 1;
				}

				a = line.find(";;");
				if (a != -1)
				{
					line.erase(a, 1);
					b = 1;
				}

				a = line.find("_");
				if (a != -1)
				{
					line.erase(a, 1);
					b = 1;
				}

			} while (b == 1);

			std::istringstream temp(line);
			programList[i] = new CMalware;
			temp >> *programList[i];
			i++;
		}
		else if (regex_match(line.c_str(), expressionProgramForSelling))
		{
			do {
				b = 0;

				a = line.find("--");
				if (a != -1)
				{
					line.erase(a, 1);
					b = 1;
				}

				a = line.find("  ");
				if (a != -1)
				{
					line.erase(a, 1);
					b = 1;
				}

				a = line.find(",,");
				if (a != -1)
				{
					line.erase(a, 1);
					b = 1;
				}

				a = line.find("::");
				if (a != -1)
				{
					line.erase(a, 1);
					b = 1;
				}

				a = line.find(";;");
				if (a != -1)
				{
					line.erase(a, 1);
					b = 1;
				}

				a = line.find("_");
				if (a != -1)
				{
					line.erase(a, 1);
					b = 1;
				}

			} while (b == 1);

			std::istringstream temp(line);

			programList[i] = new CProgramForSale;
			temp >> *programList[i];
			i++;
		}
		
	}

	listSize = size;
	fin.close();
	cout << endl << "Чтение из файла завершено." << endl;
}
void CList::enterNewProgram()
{
	string data;
	regex expressionMalware("([\\d]* [\\d]* [a-zA-ZА-Яа-я]* [\\d]* [\\d]* [1|0]* [\\w]* [\\d]* [A-ZА-Я]+[\\wА-Яа-я,.;:-]* [\\wА-Яа-я,.;:-]*)");
	regex expressionProgramForSelling("([\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [1|0]* [\\w]* [\\d]* [A-ZА-Я]+[\\wА-Яа-я,.;:-]* [\\wА-Яа-я,.;:-]*)");

	cout << "Введите данные в линию в таком порядке:" << endl;
	cout << "Индекс Время Тип/Цена Размер Строки Интернет(1/0) Компания Год Название" << endl;

	cin.ignore();
	getline(cin, data);

	data = data + " ";

	if (regex_match(data, expressionMalware))
	{
		std::istringstream temp(data);
		CProgram* newProgram = new CMalware;
		temp >> *newProgram;
		cout << endl;
		addProgram(newProgram);
	}
	else if (regex_match(data, expressionProgramForSelling))
	{
		std::istringstream temp(data);
		CProgram* newProgram = new CProgramForSale;
		temp >> *newProgram;
		cout << endl;
		addProgram(newProgram);
	}
	else
	{
		cout << endl << "Было введено неправильное имя." << endl;
		cout << "Завершение работы функции. " << endl;
	}
}
int CList::regexTask() const
{
	int value = 0;
	regex regular("(^[A-ZА-Я]+[\\wА-Яа-я,.;:-]* [\\wА-Яа-я,.;:-]+)");

	for (size_t i = 0; i < listSize; i++)
	{
		if (regex_match(programList[i]->getName(), regular))
		{
			cout << *programList[i] << endl;
			value++;
		}
	}
	cout << endl;

	return value;
}
int CList::getProgramID(int id) const
{
	int size = 0;

	for (size_t i = 0; i < listSize; i++)
		if (programList[i]->getIndex() == id)
		{
			return i;
		}
	
	if (size == 0)
	{
		return size = -5;
		cout << "\nПрограммы с таким ID нету.\n" << endl;
	}
}
void CList::sort(comp condition) const
{
	CProgram* temp;
	bool pr;

	do {
		pr = 0;
		for (size_t i = 0; i < listSize - 1; i++)
		{
			if (condition(programList[i]->getLines(), programList[i + 1]->getLines()))
			{
				temp = *(programList + i);
				*(programList + i) = *(programList + i + 1);
				*(programList + i + 1) = temp;
				pr = 1;
			}
		}
	} while (pr);
}
bool CList::sortAsc(const int& a, const int& b) { return a > b; }
bool CList::sortDesc(const int& a, const int& b) { return a < b; }

int CList::testID() const
{
	return programList[0]->getIndex();
}
stringstream CList::testStringstream(int value)
{
	stringstream temp = programList[value]->getStr();
	return temp;
}
CProgram* CList::copyTest()
{
	CProgram* newProgram = programList[0];
	return newProgram;
}

CList::~CList()
{
	for (size_t i = 0; i < listSize; i++)
	{
		delete programList[i];
	}

	delete[] programList;
}

CProgram* CList::operator[] (int i)
{
	if (listSize > i)
		return programList[i];
}