#include "Program.h"

int C_Program::getTime() const
{
	return TimeOfWork;
}
int C_Program::getSize() const
{
	return size;
}
int C_Program::getLines() const
{
	return AmountOfLines;
}
int C_Program::getIndex() const
{
	return index;
}
const char* C_Program::getTrojan()const
{
	return trojan;
}
void C_Program::setTime(const int valueTime)
{
	TimeOfWork = valueTime;
}
void C_Program::setSize(const int valueSize)
{
	size = valueSize;
}
void C_Program::setLines(const int valueLines)
{
	AmountOfLines = valueLines;
}
void C_Program::setTrojan(const char* trojanStatus)
{
	trojan = trojanStatus;
}
void C_Program::setIndex(int valueIndex)
{
	index = valueIndex;
}

C_Program::C_Program(char* trojan, int time, int size, int lines, int index)
{
	printf("\nВызвался конструктор с параметрами");
	this->trojan = trojan;
	TimeOfWork = time;
	this->size = size;
	this->index = index;
	AmountOfLines = lines;
}
C_Program::C_Program()		//конструктор по умолчанию
{
	printf("\nВызвался конструктор по умолчанию.");
	trojan = "Да";
	TimeOfWork = 0000;
	size = 0000;
	index = 0000;
	AmountOfLines = 0000;
}
C_Program::~C_Program()	//деструктор
{
	printf("\nВызвался деструктор");
}
C_Program::C_Program(const C_Program& other)	//конструктор копирования
{
	printf("\nВызвался конструктор копирования.");
	this->trojan = other.trojan;
	this->TimeOfWork = other.TimeOfWork;
	this->size = other.size;
	this->AmountOfLines = other.AmountOfLines;
	this->index = other.index;
}