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

C_Program::C_Program(char* trojan, int time, int size, int lines, int index) : trojan(trojan), TimeOfWork(time), size(size), AmountOfLines(lines), index(index)
{
    printf("\nВызвался конструктор с параметрами");
}
C_Program::C_Program() : trojan("Да"), TimeOfWork(0), size(0), AmountOfLines(0), index(0101)
{
    printf("\nВызвался конструктор по умолчанию.");
}
C_Program::C_Program(const C_Program& other) : trojan(other.trojan), TimeOfWork(other.TimeOfWork), size(other.size), AmountOfLines(other.AmountOfLines), index(other.index)
{
    printf("\nВызвался конструктор копирования.");
}
C_Program::~C_Program()  //деструктор
{
    printf("\nВызвался деструктор");
}