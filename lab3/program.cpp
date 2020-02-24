#include "Program.h"

int C_Program::getTime() const
{
	return timeOfWork;
}
int C_Program::getSize() const
{
	return size;
}
int C_Program::getLines() const
{
	return amountOfLines;
}
int C_Program::getIndex() const
{
	return index;
}
bool C_Program::getTrojan()const
{
	return trojan;
}
string C_Program::getName()const
{
	return name;
}

void C_Program::setTime(const int valueTime)
{
	timeOfWork = valueTime;
}
void C_Program::setSize(const int valueSize)
{
	size = valueSize;
}
void C_Program::setLines(const int valueLines)
{
	amountOfLines = valueLines;
}
void C_Program::setTrojan(const bool trojanStatus)
{
	trojan = trojanStatus;
}
void C_Program::setIndex(int valueIndex)
{
	index = valueIndex;
}
void C_Program::setName(string valueName)
{
	name = valueName;
}

C_Program::C_Program(bool trojan, int time, int size, int lines, int index, string name)
{
	cout << "Вызвался конструктор с параметрами." << endl;
	this->trojan = trojan;
	timeOfWork = time;
	this->size = size;
	this->index = index;
	amountOfLines = lines;
	this->name = name;
}
C_Program::C_Program()    //конструктор по умолчанию
{
	cout << "Вызвался конструктор по умолчанию." << endl;
	trojan = true;
	timeOfWork = 0000;
	size = 0000;
	index = 0000;
	amountOfLines = 0000;
	name = "Калькулятор";
}
C_Program::~C_Program()  //деструктор
{
	cout << "Вызвался деструктор." << endl;
}
C_Program::C_Program(const C_Program& other)  //конструктор копирования
{
	cout << "Вызвался конструктор копирования." << endl;
	this->trojan = other.trojan;
	this->timeOfWork = other.timeOfWork;
	this->size = other.size;
	this->amountOfLines = other.amountOfLines;
	this->index = other.index;
	this->name = other.name;
}