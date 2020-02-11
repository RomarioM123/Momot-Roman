#include "Program.h"
#include "List.h"

int Program::getTime() const
{
	return TimeOfWork;
}
int Program::getSize() const
{
	return size;
}
int Program::getLines() const
{
	return AmountOfLines;
}
void Program::setTime(int valueTime)
{
	TimeOfWork = valueTime;
}
void Program::setSize(int valueSize)
{
	size = valueSize;
}
void Program::setLines(int valueLines)
{
	AmountOfLines = valueLines;
}