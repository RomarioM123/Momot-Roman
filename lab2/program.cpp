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
void C_Program::setTime(int valueTime)
{
	TimeOfWork = valueTime;
}
void C_Program::setSize(int valueSize)
{
	size = valueSize;
}
void C_Program::setLines(int valueLines)
{
	AmountOfLines = valueLines;
}
