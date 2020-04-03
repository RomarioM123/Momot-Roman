#include "programList.h"

void CList::createList(int value, CAuthor* authors)
{
	listSize = value;
	list = new C_Program[listSize];

	for (size_t i = 0; i < listSize; i++)
		list[i] = programs(i, authors);
}

void CList::setListSize(int size) { listSize = size; }
int CList::getListSize() const { return listSize; }

void CList::printAll() const
{
	cout << endl << setiosflags(ios::left);
	cout << setw(12) << "  �����" << setw(12) << "������";
	cout << setw(10) << "������" << setw(11) << "��������";
	cout << setw(14) << "������" << setw(21) << "��������";
	cout << setw(16) << "��� �������" << setw(11) << "�����";
	cout << endl;
	
	for (size_t i = 0; i < listSize; i++)
		printOneEl(i);

	cout << endl;
}
void CList::printOneEl(int number) const
{
	cout << setiosflags(ios::left) << setw(2) << number + 1 << ")";
	cout << setw(10) << list[number].getTime();
	cout << setw(12) << list[number].getSize();
	cout << setw(9) << list[number].getLines();
	cout << setw(12) << boolalpha << list[number].getInternet();
	cout << setw(11) << list[number].getIndex();
	cout << setw(26) << list[number].getName();
	cout << setw(14) << list[number].getYear();
	cout << setw(12) << list[number].getAuthor() << endl;
}
void CList::addEl(C_Program& newProgram)
{
	C_Program* newList = new C_Program[listSize + 1];

	for (size_t i = 0; i < listSize; i++)
		newList[i] = list[i];
	newList[listSize++] = newProgram;
	delete[] list;

	list = new C_Program[listSize];
	for (size_t i = 0; i < listSize; i++)
		list[i] = newList[i];

	delete[] newList;
	cout << "������� ��������." << endl;
}
void CList::deleteEl(int index)
{
	if (listSize == 0)
	{
		cout << "������ �������� ����. ����������� � ������ ��������." << endl;
		return;
	}
	if (index <= 0 || index > listSize)
	{
		cout << "������. �������� ����� ��������. ������������." << endl;
		return;
	}

	C_Program* newList = new C_Program[listSize - 1];

	for (size_t i = 0; i < index - 1; i++)
		newList[i] = list[i];
	for (size_t i = index - 1, j = index; j < listSize; i++, j++)
		newList[i] = list[j];
	delete[] list;

	list = new C_Program[listSize--];
	for (size_t i = 0; i < listSize; i++)
		list[i] = newList[i];
	delete[] newList;

	return;
}
int CList::task(int minimalSize)
{
	int size = 0;

	for (size_t i = 0; i < listSize; i++)
		if (list[i].getSize() > minimalSize && list[i].getInternet() == false)
		{
			printOneEl(i);
			size++;
		}
		
	return size;
}
int CList::linesInFile(string filename)
{
	int size = 0;
	string line;
	regex regular("([\\d]* [\\d]* [\\d]* [\\d]* [true|false]* [\\w]* [\\d]* [\\d]* [\\d]* [A-Z�-�]+[\\w�-��-�,.;:-]* [\\w�-��-�,.;:-]*)");

	ifstream fin(filename);
	if (!fin.is_open())
	{
		cout << "���������� ������� ����. ����������� � ����." << endl;
		return 0;
	}

	while (getline(fin, line))
	{
		if (regex_match(line, regular))	size++;
		else cout << "������ � ����� �� ������ ��������." << endl;
	}

	fin.close();
	return size;
}
void CList::readFile(string filename)
{
	ifstream fin(filename);
	if (!fin.is_open())
	{
		cout << "�������� �������� �����. ��������� �������." << endl;
		return;
	}

	string line, var;
	int size = CList::linesInFile(filename);
	regex regular("([\\d]* [\\d]* [\\d]* [\\d]* [true|false]* [\\w]* [\\d]* [\\d]* [\\d]* [A-Z�-�]+[\\w�-��-�,.;:-]* [\\w�-��-�,.;:-]*)");
	int i = 0, a = 0;
	bool b;

	delete[] list;
	list = new C_Program[size];
	while (getline(fin, line) && i < size)
	{
		if (regex_match(line.c_str(), regular))
		{
			int time, size, lines, index;
			sint day, month, year;
			string author;
			bool internet;
			string internet2;
			string name, name2;
			std::istringstream temp(line);

			temp >> index;
			temp >> time;
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

			C_Program newElement(internet, time, size, lines, index, name, author, day, month, year);
			list[i++] = newElement;
		}
	}

		setListSize(size);
	fin.close();
	cout << endl << "������ �� ����� ���������." << endl;
}
void CList::saveToFile(string filename)
{
	std::ofstream fout(filename);

	fout.setf(ios::left);
	fout << setw(12) << "  �����" << setw(12) << "������";
	fout << setw(13) << "������" << setw(11) << "��������";
	fout << setw(15) << "������" << setw(24) << "��������";
	fout << setw(16) << "��� �������" << setw(11) << "�����";
	fout << endl;

	for (size_t i = 0; i < getListSize(); i++)
	{
		fout << setiosflags(ios::left) << setw(2) << i + 1 << ")";
		fout << setw(10) << list[i].getTime();
		fout << setw(12) << list[i].getSize();
		fout << setw(12) << list[i].getLines();
		fout << setw(12) << boolalpha << list[i].getInternet();
		fout << setw(15) << list[i].getIndex();
		fout << setw(26) << list[i].getName();
		fout << setw(14) << list[i].getYear();
		fout << setw(12) << list[i].getAuthor() << endl;
	}

	cout << "������ � ���� ���������." << endl;
	fout.close();
}
stringstream CList::getOneEl(int value) const
{
	stringstream temp;
	
	temp << " " << list[value].getIndex() << " " << list[value].getTime() << " " << list[value].getSize() 
	<< " " << list[value].getLines() << " " << list[value].getInternet() << " " << list[value].getAuthor() 
	<< " " << list[value].getDay() << " " << list[value].getMonth() << " " << list[value].getYear()
	<< " " << list[value].getName();
	
	return temp;
}
void CList::showOneEl(stringstream& line) const
{
	int time, size, lines, index;
	sint day, month, year;
	string name, name2;
	string internet2;
	bool internet;
	string author;

	line >> index;
	line >> time;
	line >> size;
	line >> lines;
	line >> internet2;
	line >> author;
	line >> day;
	line >> month;
	line >> year;
	line >> name;
	line >> name2;
	
	if (internet2 == "1") internet = true;
	else internet = false;

	if (name2 == "") name = name + " ";
	else(name = name + " " + name2);

	cout << endl << setiosflags(ios::left);
	cout << setw(12) << "  �����" << setw(12) << "������";
	cout << setw(10) << "������" << setw(11) << "�����";
	cout << setw(14) << "������" << setw(21) << "��������";
	cout << setw(16) << "��� �������" << setw(11) << "�����";
	cout << endl << "   ";

	cout << setw(10) << time;
	cout << setw(12) << size;
	cout << setw(10) << lines;
	cout << setw(11) << boolalpha << internet;
	cout << setw(10) << index;
	cout << setw(27) << name;
	cout << setw(12) << year;
	cout << setw(15) << author;
	cout << endl;
}
C_Program CList::getProgramID(int id) const
{
	C_Program newProgram;

	for (size_t i = 0; i < listSize; i++)
		if (list[i].getIndex() == id)
		{
			printOneEl(i);
			newProgram = list[i];
			return newProgram;
		}
	cout << "\n��������� � ����� ID ����.\n" << endl;
	return newProgram;
}
C_Program CList::programs(int valueX, CAuthor* authors)
{
	C_Program standartProgram;

	if (valueX == 1)
	{
		C_Program Program1(true, 222, 222, 222, 1234, "Skype", *(authors), 2, 12, 2002);
		return Program1;

		return Program1;
	}
	else if (valueX == 2)
	{
		C_Program Program2(true, 333, 333, 666, 5678, "Standart Calculator", *(authors + 1), 13, 3, 1993);
		return Program2;
	}
	else if (valueX == 3)
	{
		C_Program Program3(false, 444, 444, 444, 9532, "Domino Super", *(authors + 2), 14, 4, 1944);
		return Program3;
	}
	else if (valueX == 4)
	{
		C_Program Program4(false, 555, 555, 555, 4356, "Text editor", *(authors + 3), 5, 5, 1995);
		return Program4;
	}
	return standartProgram;
}
void CList::enterNewEl()
{
	int time, size, lines, index;
	sint day, month, year;
	string name, name2;
	string internet2;
	bool internet;
	string author;
	string data;

	regex regular("([\\d]* [\\d]* [\\d]* [\\d]* [true|false]* [\\w]* [\\d]* [\\d]* [\\d]* [A-Z�-�]+[\\w�-��-�,.;:-]* [\\w�-��-�,.;:-]*)");

	cout << "������� ������ � ����� � ����� �������:";
	cout << "������ ����� ������ ������ �����(true/false) �������� ���� ����� ��� ��������" << endl;

	cin.ignore();
	getline(cin, data);

	data = data + " ";

	if (regex_match(data, regular))
	{
		std::istringstream temp(data);

		temp >> index;
		temp >> time;
		temp >> size;
		temp >> lines;
		temp >> internet2;
		temp >> author;
		temp >> day;
		temp >> month;
		temp >> year;
		temp >> name;
		temp >> name2;

		if (name2 == "") name = name + " ";
		else(name = name + " " + name2);

		if (internet2 == "true") internet = true;
		else internet = false;

		C_Program newProgram(internet, time, size, lines, index, name, author, day, month, year);
		addEl(newProgram);
	}
	else
	{
		cout << endl << "���� ������� ������������ ���. ������ �����:" << endl;
		cout << "������ ����� � �������� ��������� �� ������ ���������� � ��������� �����." << endl;
		cout << "�� ������ ��������� �������." << endl;
		cout << "���������� ������ �������." << endl;
	}
	

	return;
}
void CList::regexTask()
{
	regex regular("(^[A-Z�-�]+[\\w�-��-�,.;:-]* [\\w�-��-�,.;:-]+)");
	int listSize = getListSize();
	
	for (size_t i = 0; i < listSize; i++)
		if (regex_match(list[i].getName(), regular))
			printOneEl(i);

	cout << endl;
}

bool CList::sortAsc(const int& a, const int& b) { return a > b; }
bool CList::sortDesc(const int& a, const int& b) { return a < b; }
void CList::sort(comp condition)
{
	C_Program temp;
	int size = getListSize();
	bool pr;

	do {
		pr = 0;
		for (size_t i = 0; i < size-1; i++)
		{
			if (condition(list[i].getLines(), list[i+1].getLines()))
			{
				temp = list[i];
				list[i] = list[i + 1];
				list[i + 1] = temp;
				pr = 1;
			}
		}
	} while (pr == 1);
}

CList::~CList()
{
	//cout << "\n�������� ����������" << endl;
	delete[] list;
}