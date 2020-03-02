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
	cout << "\n   Время   Размер\tСтроки\t    Троян\tИндекс\t     Название";
	for (int i = 0; i < listSize; i++)
		printOneEl(i);
}
void CList::printOneEl(int number) const
{
	cout << endl << std::setiosflags(std::ios::left) << setw(2) << number + 1 << ")";
	cout << setw(10) << list[number].getTime();
	cout << setw(12) << list[number].getSize();
	cout << setw(12) << list[number].getLines();
	cout << setw(12) << boolalpha << list[number].getTrojan();
	cout << setw(12) << list[number].getIndex();
	cout << setw(15) << list[number].getName();
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
	cout << "Элемент добавлен." << endl;
}
void CList::deleteEl(int index)
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
void CList::task(int minimalSize)
{
	for (int i = 0; i < listSize; i++)
		if (list[i].getSize() > minimalSize&& list[i].getTrojan() == false)
			printOneEl(i);
}
int CList::linesInFile(string filename)
{
	int size = 0;
	string line;
	regex regular("([\\d]* [\\d]* [\\d]* [\\d]* [true|false]* [A-Z]+[\\w]* [\\w]*)");

	ifstream fin(filename);
	if (!fin.is_open())
	{
		cout << "Невозможно открыть файл. Возвращение в меню." << endl;
		return 0;
	}

	while (getline(fin, line))
	{
		if(regex_match(line, regular))
		size++;
	}

	fin.close();
	return size;
}
void CList::readFile(string filename)
{
	ifstream fin(filename);
	if (!fin.is_open()) return;

	string line, var;
	int size = CList::linesInFile(filename);
	regex regular("([\\d]* [\\d]* [\\d]* [\\d]* [true|false]* [A-Z]+[\\w]* [\\w]*)");
	int i = 0;
	
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

			fin >> index;
			fin >> time;
			fin >> size;
			fin >> lines;
			fin >> trueFalse;
			fin >> name;
			fin >> name2;

			if (trueFalse == "true") trojan = true;
			else trojan = false;

			if (name2 == "") name = name + " ";
			else(name = name + " " + name2);

			C_Program newElement(trojan, time, size, lines, index, name);
			list[i++] = newElement;
		}
	}

	setListSize(size);
	fin.close();
	cout << endl << "Чтение из файла завершено." << endl;
}
void CList::saveToFile(string filename)
{
	std::ofstream fout(filename);

	fout.setf(std::ios::left);
	fout << "\tВремя\tРазмер\t    Строки\tТроян\t    Индекс\tНазвание" << endl;
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
	string name;
	string trueFalse;

	line >> name;
	line >> trueFalse;
	line >> index;
	line >> AmountOfLines;
	line >> size;
	line >> TimeOfWork;
	
	if (trueFalse == "1")
	{
		trojan = true;
	}
	else
	{
		trojan = false;
	}

	cout << "\n   Время   Размер\tСтроки\t    Троян\tИндекс\t     Название";
	cout << endl << std::setiosflags(std::ios::left) << setw(2) << 1 << ")";
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
	cout << "\nПрограммы с таким ID нету.\n" << endl;
	return newProgram;
}
C_Program CList::programs(int valueX)
{
	C_Program standartProgram;

	if (valueX == 1)
	{
		C_Program Program1(true, 222, 222, 222, 1234, "Скайп");
		return Program1;
	}
	else if (valueX == 2)
	{
		C_Program Program2(true, 333, 333, 666, 5678, "Калькулятор Стандартный");
		return Program2;
	}
	else if (valueX == 3)
	{
		C_Program Program3(false, 444, 444, 444, 9532, "Домино Супер");
		return Program3;
	}
	else if (valueX == 4)
	{
		C_Program Program4(false, 555, 555, 555, 4356, "Редактор Текста");
		return Program4;
	}
	return standartProgram;
}
void CList::enterNewEl()
{
	int time, size, lines, index;
	bool trojan;
	string name, name2, trojan2, data;

	cout << "Введите данные в линию в таком порядке:";
	cout << "Время Размер Строки Троян(true/false) Индекс Название" << endl;

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
	
	bool value = checkName(name);
	if (value == false)
	{
		cout << "Завершение работы функции. Повторите попытку.";
		return;
	}

	if (trojan2 == "true") trojan = true;
	else trojan = false;

	C_Program el(trojan, time, size, lines, index, name);
	addEl(el);
}
bool CList::checkName(const string name)
{
	regex regular("(^[A-Z]+[\\w]* [\\w]*)");
	if (!regex_search(name.c_str(), regular))
	{
		cout << "Было введено неправильное имя. Формат имени:" << endl;
		cout << "Первое слово не должно начинаться с маленькой буквы." << endl;
		cout << "Не должно содержать символы." << endl;
		return false;
	}

	return true;
}

CList::~CList()
{
	//cout << "\nВызвался деструктор" << endl;
	delete[] list;
}