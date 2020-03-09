#include "List.h"

void CList::createList(int value)
{
	listSize = value;
	list = new C_Program[listSize];

	for (int i = 0; i < listSize; i++)
		list[i] = programs(i);
}
void CList::setListSize(int size)
{
	listSize = size;
}
int CList::getListSize() const
{
	return listSize;
}

void CList::printAll() const
{
	cout << endl;
	cout << "  �����\t    ������\t������\t    �����\t������\t\t��������";
	cout << endl;
	for (int i = 0; i < listSize; i++)
		printOneEl(i);

	cout << endl;
}
void CList::printOneEl(int number) const
{
	cout << setiosflags(ios::left) << setw(2) << number + 1 << ")";
	cout << setw(10) << list[number].getTime();
	cout << setw(12) << list[number].getSize();
	cout << setw(12) << list[number].getLines();
	cout << setw(12) << boolalpha << list[number].getTrojan();
	cout << setw(12) << list[number].getIndex();
	cout << setw(15) << list[number].getName() << endl;
}
void CList::addEl(C_Program& newProgram)
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
int CList::task(int minimalSize)
{
	int size = 0;

	for (int i = 0; i < listSize; i++)
		if (list[i].getSize() > minimalSize&& list[i].getTrojan() == false)
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
	regex regular("([\\d]* [\\d]* [\\d]* [\\d]* [true|false]* [A-Z�-�]+[\\w�-��-�,.;:-]* [\\w�-��-�,.;:-]*)");

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
	regex regular("([\\d]* [\\d]* [\\d]* [\\d]* [true|false]* [A-Z�-�]+[\\w�-��-�,.;:-]* [\\w�-��-�,.;:-]*)");
	int i = 0, a = 0, b;

	delete[] list;
	list = new C_Program[size];
	while (getline(fin, line) && i < size)
	{
		if (regex_match(line.c_str(), regular))
		{
			int time, size, lines, index;
			bool trojan;
			string name, name2;
			string trueFalse;
			std::istringstream temp(line);
			temp >> index;
			temp >> time;
			temp >> size;
			temp >> lines;
			temp >> trueFalse;
			temp >> name;
			temp >> name2;

			if (trueFalse == "true") trojan = true;
			else trojan = false;

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

			C_Program newElement(trojan, time, size, lines, index, name);
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
	fout << "\t�����\t������\t    ������\t�����\t    ������\t��������" << endl;
	for (int i = 0; i < getListSize(); i++)
	{
		fout << setw(2) << i + 1 << ")\t " << setw(9) << list[i].getTime() << setw(12);
		fout << list[i].getSize() << setw(11) << list[i].getLines() << setw(12);
		fout << boolalpha << list[i].getTrojan() << setw(11) << list[i].getIndex() << setw(15);
		fout << list[i].getName() << endl;
	}

	cout << "������ � ���� ���������." << endl;
	fout.close();
}
stringstream CList::getOneEl(int value) const
{
	stringstream temp;
	temp << " " << list[value].getName() << " " << list[value].getTrojan() << " " << list[value].getIndex() << " " << list[value].getLines() << " " << list[value].getSize() << " " << list[value].getTime();
	return temp;
}
void CList::showOneEl(stringstream& line) const
{
	int TimeOfWork, size, AmountOfLines, index;
	bool trojan;
	string name, name2;
	string trueFalse;

	line >> name;
	line >> name2;
	line >> trueFalse;
	line >> index;
	line >> AmountOfLines;
	line >> size;
	line >> TimeOfWork;
	
	if (trueFalse == "1") trojan = true;
	else trojan = false;

	if (name2 == "") name = name + " ";
	else(name = name + " " + name2);

	cout << "\n   �����   ������\t������\t    �����\t������\t     ��������";
	cout << endl << setiosflags(ios::left) << setw(2) << 1 << ")";
	cout << setw(10) << TimeOfWork;
	cout << setw(12) << size;
	cout << setw(12) << AmountOfLines;
	cout << setw(12) << boolalpha << trojan;
	cout << setw(12) << index;
	cout << setw(15) << name;
	cout << endl;
}
C_Program CList::getProgramID(int id) const
{
	C_Program newProgram;

	for (int i = 0; i < listSize; i++)
		if (list[i].getIndex() == id)
		{
			printOneEl(i);
			newProgram = list[i];
			return newProgram;
		}
	cout << "\n��������� � ����� ID ����.\n" << endl;
	return newProgram;
}
C_Program CList::programs(int valueX)
{
	C_Program standartProgram;

	if (valueX == 1)
	{
		C_Program Program1(true, 222, 222, 222, 1234, "Skype");
		return Program1;
	}
	else if (valueX == 2)
	{
		C_Program Program2(true, 333, 333, 666, 5678, "Standart Calculator");
		return Program2;
	}
	else if (valueX == 3)
	{
		C_Program Program3(false, 444, 444, 444, 9532, "Domino Super");
		return Program3;
	}
	else if (valueX == 4)
	{
		C_Program Program4(false, 555, 555, 555, 4356, "Text editor");
		return Program4;
	}
	return standartProgram;
}
void CList::enterNewEl()
{
	int time, size, lines, index;
	bool trojan;
	string name, name2, trojan2, data;
	regex regular("(^[A-Z]+[\\w]* [\\w]*)");

	cout << "������� ������ � ����� � ����� �������:";
	cout << "����� ������ ������ �����(true/false) ������ ��������" << endl;

	cin.ignore();
	getline(cin, data);
	std::istringstream temp(data);

	temp >> time;
	temp >> size;
	temp >> lines;
	temp >> trojan2;
	temp >> index;
	temp >> name;
	temp >> name2;

	if (name2 == "") name = name + " ";
	else(name = name + " " + name2);

	if (!regex_match(name.c_str(), regular))
	{
		cout << "���� ������� ������������ ���. ������ �����:" << endl;
		cout << "������ ����� �� ������ ���������� � ��������� �����." << endl;
		cout << "�� ������ ��������� �������." << endl;
		cout << "���������� ������ �������. ��������� �������.";
		return;
	}

	if (trojan2 == "true") trojan = true;
	else trojan = false;

	C_Program el(trojan, time, size, lines, index, name);
	addEl(el);
}
void CList::regexTask()
{
	regex regular("(^[A-Z�-�]+[\\w�-��-�,.;:-]* [\\w�-��-�,.;:-]+)");
	int listSize = getListSize();
	
	for (int i = 0; i < listSize; i++)
		if (regex_match(list[i].getName(), regular))
			printOneEl(i);

	cout << endl;
}

CList::~CList()
{
	//cout << "\n�������� ����������" << endl;
	delete[] list;
}