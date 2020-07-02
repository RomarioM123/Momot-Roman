#include "BaseClass.h"
stringstream CProgram::getStr() const
{
	stringstream data;
	
	data << name << " " << timeOfWork << " " << size << " " << index << " " << amountOfLines;
	
	return data;
}

string CProgram::getInfo() const
{
	stringstream data;
	
	data.setf(std::ios::left);
	data << setw(13) << name << setw(10) << timeOfWork << setw(10) << size << setw(13) << index << setw(9) << amountOfLines;
	
	return data.str();
}

ostream& operator<< (ostream& output, const CProgram& program)
{
	output << program.getInfo();
	
	return output;
}

CProgram::CProgram() : name("Calculator"), timeOfWork(1980), size(220), index(345001), amountOfLines(523) {}
CProgram::CProgram(string name, int timeOfWork, int size, int index, int amountOfLines) : name(name), timeOfWork(timeOfWork), size(size), index(index), amountOfLines(amountOfLines) {}
CProgram::CProgram(const CProgram& object) : name(object.name), timeOfWork(object.timeOfWork), size(object.size), index(object.index), amountOfLines(object.amountOfLines) {}
CProgram:: ~CProgram() {}