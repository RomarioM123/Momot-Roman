#include "First_Inheritor.h"
stringstream CMalware::getStr() const
{
	stringstream data;
	
	data << name << " " << timeOfWork << " " << size << " " << index << " " << amountOfLines << " " << amountOfLines;
	
	return data;
}

string CMalware::getInfo() const
{
	stringstream data;
	
	data.setf(std::ios::left);
	data << setw(13) << name << setw(10) << timeOfWork << setw(10) << size << setw(13) << index << setw(9) << amountOfLines << setw(10) << amountOfLines;
	
	return data.str();
}

CMalware::CMalware() : CProgram(), type("Trojan") {}
CMalware::CMalware(string name, int timeOfWork, int size, int index, int amountOfLines, string data) : CProgram(name, timeOfWork, size, index, amountOfLines), type(data) {}
CMalware::CMalware(const CMalware& other) : CProgram(other), type(other.type) {}
CMalware:: ~CMalware() {}