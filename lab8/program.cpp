#include "program.h"

int CProgram::getTime() const 
{ 
	return timeOfWork; 
}
int CProgram::getSize() const 
{ 
	return size; 
}
int CProgram::getLines() const 
{ 
	return amountOfLines; 
}
int CProgram::getIndex() const 
{ 
	return index; 
}
bool CProgram::getInternet()const 
{ 
	return useInternet; 
}
string CProgram::getName()const 
{ 
	return name; 
}

CProgram::CProgram(bool internet, int time, int size, int lines, int index, string name, CAuthor author, sint day, sint month, sint year): useInternet(internet), timeOfWork(time), size(size), amountOfLines(lines), index(index), name(name), author(author), date(day, month, year)
{
	//cout << "\nВызвался конструктор с параметрами";
}
CProgram::CProgram() : useInternet(false), timeOfWork(0), size(0), amountOfLines(0), index(0101), name("Basic")
{
	//cout << "\nВызвался конструктор по умолчанию.";
}
CProgram::CProgram(const CProgram& other) : useInternet(other.useInternet), timeOfWork(other.timeOfWork), size(other.size), amountOfLines(other.amountOfLines), index(other.index), name(other.name), author(other.author), date(other.date)
{
	//cout << "\nВызвался конструктор копирования.";
}
CProgram::~CProgram()
{
	//cout << "\nВызвался деструктор";
}

ofstream& operator<< (ofstream& output, const CProgram& program)
{
	output << program.getInfo();
	return output;
}
ostream& operator<< (ostream& output, const CProgram& program)
{
	output << program.getInfo();
	return output;
}
istream& operator>> (istream& input, CProgram& program)
{
	program.input(input);
	return input;
}
bool CProgram::operator==(const string name) const
{
	return this->name == name;
}
CProgram& CProgram::operator= (CProgram& temp)
{
	if (this == &temp) return *this;
	
	int timeOfWork = temp.timeOfWork;
	int size = temp.size;
	int amountOfLines = temp.amountOfLines;
	int index = temp.index;
	bool useInternet = temp.useInternet;
	string name = temp.name;
	CAuthor author = temp.author;
	CDate date = temp.date;

	return *this;
}