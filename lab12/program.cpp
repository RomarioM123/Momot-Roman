#include "program.h"

string CProgram::getInfo() const
{
	stringstream temp;

	temp.setf(std::ios::left);
	temp << setw(18) << name << setw(12) << index << setw(11)
		<< timeOfWork << setw(13) << size << setw(12)
		<< amountOfLines << setw(8) << boolalpha << useInternet;

	return temp.str();
}
int CProgram::getID() const
{
	return index;
}
stringstream CProgram::getStr() const
{
	stringstream temp;
	temp << name << " " << index << " " << timeOfWork << " " 
		<< size << " " << amountOfLines << " " << useInternet;

	return temp;
}

ostream& operator<< (ostream& output, const CProgram& program)
{
	output << program.getInfo();
	return output;
}
bool CProgram::operator==(const int id) const
{
	return this->index == id;
}

CProgram::CProgram(bool internet, int time, int size, int lines, int index, string name) : useInternet(internet), timeOfWork(time), size(size), amountOfLines(lines), index(index), name(name)
{
	//cout << "\nВызвался конструктор с параметрами";
}
CProgram::CProgram() : useInternet(false), timeOfWork(0), size(0), amountOfLines(0), index(0101), name("Basic")
{
	//cout << "\nВызвался конструктор по умолчанию.";
}
CProgram::CProgram(const CProgram& other) : useInternet(other.useInternet), timeOfWork(other.timeOfWork), size(other.size), amountOfLines(other.amountOfLines), index(other.index), name(other.name)
{
	//cout << "\nВызвался конструктор копирования.";
}
CProgram::~CProgram()
{
	//cout << "\nВызвался деструктор";
}