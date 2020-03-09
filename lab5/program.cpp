#include "program.h"

int C_Program::getTime() const { return timeOfWork; }
int C_Program::getSize() const { return size; }
int C_Program::getLines() const { return amountOfLines; }
int C_Program::getIndex() const { return index; }
bool C_Program::getTrojan()const { return trojan; }
string C_Program::getName()const { return name; }

void C_Program::setTime(const int valueTime) { timeOfWork = valueTime; }
void C_Program::setSize(const int valueSize) { size = valueSize; }
void C_Program::setLines(const int valueLines) { amountOfLines = valueLines; }
void C_Program::setTrojan(const bool trojanStatus) { trojan = trojanStatus; }
void C_Program::setIndex(int valueIndex) { index = valueIndex; }
void C_Program::setName(string valueName) { name = valueName; }

C_Program::C_Program(bool trojan, int time, int size, int lines, int index, string name) : trojan(trojan), timeOfWork(time), size(size), amountOfLines(lines), index(index), name(name)
{
	//cout << "\nВызвался конструктор с параметрами";
}
C_Program::C_Program() : trojan(true), timeOfWork(0), size(0), amountOfLines(0), index(0101), name("Basic")
{
	//cout << "\nВызвался конструктор по умолчанию.";
}
C_Program::C_Program(const C_Program& other) : trojan(other.trojan), timeOfWork(other.timeOfWork), size(other.size), amountOfLines(other.amountOfLines), index(other.index), name(other.name)
{
	//cout << "\nВызвался конструктор копирования.";
}
C_Program::~C_Program()
{
	//cout << "\nВызвался деструктор";
}