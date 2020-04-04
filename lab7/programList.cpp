#include "programList.h"

int CList::getListSize() const 
{ 
	return listSize; 
}

C_Program** CList::createList(int value, CAuthor* authors)
{
	listSize = value;
	programList = new C_Program * [value];

	for (size_t i = 0; i < value; i++)
	{
		if (i == 0)
		{
			*(programList + i) = new CMalware();
		}
		else if (i == 1)
		{
			*(programList + i) = new ProgramForSale(true, 121, 222, 532, 1234, "Skype", *(authors + 1), 2, 12, 2002, 3000);
		}
		else if (i == 2)
		{
			*(programList + i) = new CMalware(true, 1445, 532, 745, 7896, "Spider", *(authors + 2), 6, 9, 1995, "Keylogger");
		}
		else if (i == 3)
		{
			*(programList + i) = new ProgramForSale(false, 333, 444, 555, 6745, "Calculator", *(authors + 3), 1, 11, 2001, 200);
		}
		if (i == 4)
		{
			*(programList + i) = new ProgramForSale();
		}
	}

	return programList;
}
C_Program** CList::addProgram(C_Program* program, C_Program** list)
{
	C_Program** newList = new C_Program * [listSize + 1];

	for (size_t i = 0; i < listSize; i++)
	{
		*(newList + i) = *(list + i);
	}	
	newList[listSize++] = program;
	programList = newList;

	delete list;
	cout << "������� ��������." << endl;

	return programList;
}
C_Program** CList::delProgram(int value, C_Program** list)
{
	if (listSize == 0)
	{
		cout << "������ �������� ����. ����������� � ������ ��������." << endl;
		return NULL;
	}
	if (value <= 0 || value > listSize)
	{
		cout << "������. �������� ����� ��������. ������������." << endl;
		return NULL;
	}

	C_Program** newList = new C_Program * [listSize - 1];

	for (size_t i = 0; i < value; i++)
		*(newList + i) = *(list + i);
	for (size_t i = value, j = value+1; j < listSize; i++, j++)
		*(newList + i) = *(list + j);
	
	delete* (programList + value);
	listSize--;
	programList = newList;
	delete list;
	return programList;
}
C_Program* CList::newProgram(CAuthor* list, int value)
{
	if (value == 1)
	{
		C_Program* Program = new CMalware(true, 444, 555, 666, 6734, "Stealer", *(list + 4), 30, 11, 1967, "Trojan");
		return Program;
	}
	else 
	{
		C_Program* Program = new ProgramForSale(false, 34, 69, 534, 5378, "Randomizer", *(list + 5), 15, 15, 2015, 1000000);
		return Program;
	}
}
void CList::printAll(C_Program** program) const
{
	auto i = 0;
	if (listSize == 0)
	{
		cout << "������ ����." << endl << endl;
		return;
	}
	else if (listSize < i || i < 0)
	{
		cout << "�������� ����� ��������." << endl << endl;
	}
	
	cout << endl << setiosflags(ios::left);
	cout << setw(12) << "  �����" << setw(12) << "������";
	cout << setw(10) << "������" << setw(11) << "��������";
	cout << setw(14) << "������" << setw(21) << "��������";
	cout << setw(16) << "��� �������" << setw(14) << "�����";
	cout << setw(14) << "���/����" << endl;

	for (; i < listSize; i++)
	{
		cout << setiosflags(ios::left) << setw(2) << i + 1 << ")";
		program[i]->print();
	}
		

	cout << endl;
}
stringstream CList::getOneEl(int value) const
{
	stringstream temp = programList[value]->getStr();
	
	int time, size, lines, index;
	sint day, month, year;
	string name, name2;
	string internet2;
	bool internet;
	string author;
	string data;

	temp >> index;
	temp >> data;
	temp >> time;
	temp >> size;
	temp >> lines;
	temp >> boolalpha >> internet2;
	temp >> author;
	temp >> day;
	temp >> month;
	temp >> year;
	temp >> name;
	temp >> name2;

	if (internet2 == "1") internet = true;
	else internet = false;

	if (name2 == "") name = name + " ";
	else(name = name + " " + name2);

	cout << endl << setiosflags(ios::left);
	cout << setw(12) << "  �����" << setw(12) << "������";
	cout << setw(10) << "������" << setw(11) << "��������";
	cout << setw(14) << "������" << setw(21) << "��������";
	cout << setw(16) << "��� �������" << setw(15) << "�����";
	cout << setw(13) << "���/����" << endl << "   ";

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

	return temp;
}
sint CList::task(int minimalSize)
{
	int size = 0;

	for (size_t i = 0; i < listSize; i++)
	{
		if (programList[i]->getSize() > minimalSize&& programList[i]->getName() == "Microsoft")
		{
			programList[i]->print();
			size++;
		}
	}
		
	if (size == 0)
	{
		cout << "��������� � ������ ����������� �����������." << endl;
	}

	return size;
}
void CList::saveToFile(string filename)
{
	std::ofstream fout(filename);

	fout.setf(ios::left);
	fout << setw(12) << "  �����" << setw(12) << "������";
	fout << setw(13) << "������" << setw(11) << "��������";
	fout << setw(15) << "������" << setw(24) << "��������";
	fout << setw(16) << "��� �������" << setw(14) << "�����";
	fout << setw(12) << "���/����" << endl;

	for (size_t i = 0; i < getListSize(); i++)
	{
		fout << setiosflags(ios::left) << setw(2) << i + 1 << ")";
		programList[i]->writeInFile(fout);
	}

	cout << "������ � ���� ���������." << endl;
	fout.close();
}
int CList::linesInFile(string filename)
{
	int size = 0;
	string line;
	regex expressionMalware("([\\d]* [\\d]* [\\w�-��-�]* [\\d]* [\\d]* [true|false]* [\\w]* [\\d]* [\\d]* [\\d]* [A-Z�-�]+[\\w�-��-�,.;:-]* [\\w�-��-�,.;:-]*)");
	regex expressionProgramForSelling("([\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [true|false]* [\\w]* [\\d]* [\\d]* [\\d]* [A-Z�-�]+[\\w�-��-�,.;:-]* [\\w�-��-�,.;:-]*)");

	ifstream fin(filename);
	if (!fin.is_open())
	{
		cout << "���������� ������� ����. ����������� � ����." << endl;
		return 0;
	}

	while (getline(fin, line))
	{
		if (regex_match(line, expressionMalware) || regex_match(line, expressionProgramForSelling))
			size++;
		else cout << "������ � ����� �� ������ ��������." << endl;
	}

	fin.close();
	return size;
}
C_Program** CList::readFile(string filename)
{
	ifstream fin(filename);
	if (!fin.is_open())
	{
		cout << "�������� �������� �����. ��������� �������." << endl;
		return NULL;
	}

	string line, var;
	int size = CList::linesInFile(filename);
	regex expressionMalware("([\\d]* [\\d]* [A-Za-z�-��-�]* [\\d]* [\\d]* [true|false]* [\\w]* [\\d]* [\\d]* [\\d]* [A-Z�-�]+[\\w�-��-�,.;:-]* [\\w�-��-�,.;:-]*)");
	regex expressionProgramForSelling("([\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [true|false]* [\\w]* [\\d]* [\\d]* [\\d]* [A-Z�-�]+[\\w�-��-�,.;:-]* [\\w�-��-�,.;:-]*)");
	int i = 0, a = 0;
	bool b;

	int time, size2, lines, index;
	sint day, month, year;
	string name, name2;
	string internet2;
	bool internet;
	string author;
	string type;
	int price;

	delete[] programList;
	programList = new C_Program * [size];
	while (getline(fin, line))
	{	
		if (regex_match(line.c_str(), expressionMalware))
		{
			std::istringstream temp(line);

			temp >> index;
			temp >> time;
			temp >> type;
			temp >> size2;
			temp >> lines;
			temp >> internet2;
			temp >> author;
			temp >> day;
			temp >> month;
			temp >> year;
			temp >> name;
			temp >> name2;

			if (internet2 == "true") internet = true;
			else internet = false;

			if (name2 == "") name = name + " ";
			else(name = name + " " + name2);

			do {
				b = 0;

				a = name.find("--");
				if (a != -1)
				{
					name.erase(a, 1);
					b = 1;
				}

				a = name.find("  ");
				if (a != -1)
				{
					name.erase(a, 1);
					b = 1;
				}

				a = name.find(",,");
				if (a != -1)
				{
					name.erase(a, 1);
					b = 1;
				}

				a = name.find("::");
				if (a != -1)
				{
					name.erase(a, 1);
					b = 1;
				}

				a = name.find(";;");
				if (a != -1)
				{
					name.erase(a, 1);
					b = 1;
				}

				a = name.find("_");
				if (a != -1)
				{
					name.erase(a, 1);
					b = 1;
				}

			} while (b == 1);

			programList[i] = new CMalware(internet, time, size2, lines, index, name, author, day, month, year, type);
			i++;
		}
		if (regex_match(line.c_str(), expressionProgramForSelling))
		{
			std::istringstream temp(line);

			temp >> index;
			temp >> time;
			temp >> price;
			temp >> size2;
			temp >> lines;
			temp >> internet2;
			temp >> author;
			temp >> day;
			temp >> month;
			temp >> year;
			temp >> name;
			temp >> name2;

			if (internet2 == "true") internet = true;
			else internet = false;

			if (name2 == "") name = name + " ";
			else(name = name + " " + name2);

			do {
				b = 0;

				a = name.find("--");
				if (a != -1)
				{
					name.erase(a, 1);
					b = 1;
				}

				a = name.find("  ");
				if (a != -1)
				{
					name.erase(a, 1);
					b = 1;
				}

				a = name.find(",,");
				if (a != -1)
				{
					name.erase(a, 1);
					b = 1;
				}

				a = name.find("::");
				if (a != -1)
				{
					name.erase(a, 1);
					b = 1;
				}

				a = name.find(";;");
				if (a != -1)
				{
					name.erase(a, 1);
					b = 1;
				}

				a = name.find("_");
				if (a != -1)
				{
					name.erase(a, 1);
					b = 1;
				}

			} while (b == 1);

			programList[i] = new ProgramForSale(internet, time, size2, lines, index, name, author, day, month, year, price);
			i++;
		}
		
	}

	listSize = size;
	fin.close();
	cout << endl << "������ �� ����� ���������." << endl;

	return programList;
}
C_Program** CList::enterNewProgram()
{
	int time, size, lines, index;
	sint day, month, year;
	string name, name2;
	string internet2;
	bool internet;
	string author;
	string data;

	regex expressionMalware("([\\d]* [\\d]* [\\w�-��-�]* [\\d]* [\\d]* [true|false]* [\\w]* [\\d]* [\\d]* [\\d]* [A-Z�-�]+[\\w�-��-�,.;:-]* [\\w�-��-�,.;:-]*)");
	regex expressionProgramForSelling("([\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [true|false]* [\\w]* [\\d]* [\\d]* [\\d]* [A-Z�-�]+[\\w�-��-�,.;:-]* [\\w�-��-�,.;:-]*)");

	cout << "������� ������ � ����� � ����� �������:" << endl;
	cout << "������ ����� ���/���� ������ ������ ��������(true/false) �������� ���� ����� ��� ��������" << endl;

	cin.ignore();
	getline(cin, data);

	data = data + " ";

	if (regex_match(data, expressionMalware))
	{
		string type;
		std::istringstream temp(data);

		temp >> index;
		temp >> time;
		temp >> type;
		temp >> size;
		temp >> lines;
		temp >> internet2;
		temp >> author;
		temp >> day;
		temp >> month;
		temp >> year;
		temp >> name;
		temp >> name2;

		if (internet2 == "true") internet = true;
		else internet = false;

		if (name2 == "") name = name + " ";
		else(name = name + " " + name2);

		C_Program* Program = new CMalware(internet, time, size, lines, index, name, author, day, month, year, type);
		addProgram(Program, programList);
	}
	else if (regex_match(data, expressionProgramForSelling))
	{
		int price;
		std::istringstream temp(data);

		temp >> index;
		temp >> time;
		temp >> price;
		temp >> size;
		temp >> lines;
		temp >> internet2;
		temp >> author;
		temp >> day;
		temp >> month;
		temp >> year;
		temp >> name;
		temp >> name2;

		if (internet2 == "true") internet = true;
		else internet = false;

		if (name2 == "") name = name + " ";
		else(name = name + " " + name2);

		C_Program* Program = new ProgramForSale(internet, time, size, lines, index, name, author, day, month, year, price);
		addProgram(Program, programList);
	}
	else
	{
		cout << endl << "���� ������� ������������ ���." << endl;
		cout << "���������� ������ �������. " << endl;
	}

	return programList;
}
int CList::regexTask(CList& program)
{
	int value = 0;
	regex regular("(^[A-Z�-�]+[\\w�-��-�,.;:-]* [\\w�-��-�,.;:-]+)");

	for (size_t i = 0; i < listSize; i++)
	{
		if (regex_match(program.programList[i]->getName(), regular))
		{
			program.programList[i]->print();
			value++;
		}
	}
	cout << endl;

	return value;
}
int CList::getProgramID(int id, C_Program** programList) const
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
		cout << "\n��������� � ����� ID ����.\n" << endl;
	}
}
void CList::sort(comp condition)
{
	C_Program* temp;
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

CList::~CList()
{
	for (size_t i = 0; i < listSize; i++)
	{
		delete programList[i];
	}

	delete[] programList;
}