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
void C_Program::setIndex(int valueIndex)
{
	index = valueIndex;
}

C_Program::C_Program(char* trojan, int time, int size, int lines, int index)
{
<<<<<<< HEAD
    printf("\n�������� ����������� � �����������");
    this->trojan = trojan;
    TimeOfWork = time;
    this->size = size;
    this->index = index;
    AmountOfLines = lines;
=======
	printf("\n�������� ����������� � �����������");
	this->trojan = trojan;
	TimeOfWork = time;
	this->size = size;
	this->index = index;
	AmountOfLines = lines;
>>>>>>> 042bc953d2b5e7240b67c16e27875c0f044d9563
}
C_Program::C_Program()    //����������� �� ���������
{
<<<<<<< HEAD
    printf("\n�������� ����������� �� ���������.");
    trojan = "��";
    TimeOfWork = 0000;
    size = 0000;
    index = 0000;
    AmountOfLines = 0000;
=======
	printf("\n�������� ����������� �� ���������.");
	trojan = "��";
	TimeOfWork = 0000;
	size = 0000;
	index = 0000;
	AmountOfLines = 0000;
>>>>>>> 042bc953d2b5e7240b67c16e27875c0f044d9563
}
C_Program::~C_Program()  //����������
{
    printf("\n�������� ����������");
}
C_Program::C_Program(const C_Program& other)  //����������� �����������
{
<<<<<<< HEAD
    printf("\n�������� ����������� �����������.");
    this->trojan = other.trojan;
    this->TimeOfWork = other.TimeOfWork;
    this->size = other.size;
    this->AmountOfLines = other.AmountOfLines;
    this->index = other.index;
=======
	printf("\n�������� ����������� �����������.");
	this->trojan = other.trojan;
	this->TimeOfWork = other.TimeOfWork;
	this->size = other.size;
	this->AmountOfLines = other.AmountOfLines;
	this->index = other.index;
>>>>>>> 042bc953d2b5e7240b67c16e27875c0f044d9563
}