#include "program.h"

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
bool C_Program::getInternet()const 
{ 
	return useInternet; 
}
string C_Program::getName()const 
{ 
	return name; 
}
sint C_Program::getDay()const 
{ 
	return date.getDay();
}
sint C_Program::getMonth()const 
{ 
	return date.getMonth();
}
sint C_Program::getYear()const 
{ 
	return date.getYear(); 
}
string C_Program::getAuthor() const 
{ 
	return author.getAuthor(); 
}


C_Program::C_Program(bool internet, int time, int size, int lines, int index, string name, CAuthor author, sint day, sint month, sint year): useInternet(internet), timeOfWork(time), size(size), amountOfLines(lines), index(index), name(name), author(author), date(day, month, year)
{
	//cout << "\nВызвался конструктор с параметрами";
}
C_Program::C_Program() : useInternet(false), timeOfWork(0), size(0), amountOfLines(0), index(0101), name("Basic")
{
	//cout << "\nВызвался конструктор по умолчанию.";
}
C_Program::C_Program(const C_Program& other) : useInternet(other.useInternet), timeOfWork(other.timeOfWork), size(other.size), amountOfLines(other.amountOfLines), index(other.index), name(other.name), author(other.author), date(other.date)
{
	//cout << "\nВызвался конструктор копирования.";
}
C_Program::~C_Program()
{
	//cout << "\nВызвался деструктор";
}