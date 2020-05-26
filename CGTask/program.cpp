/**
* @file program.cpp
* ���� ��������� ������ �������� �����
* @author Momot Roman
* @version 1.0
* @date 2020.05.26
*/

#include "program.h"

int CProgram::getTime() const		/** ��������� ������� ���� ������ �������� */
{ 
	return timeOfWork;				/** ���������� ���� ������ �������� */
}
int CProgram::getSize() const		/** ��������� ������� ������ �������� */
{ 
	return size;					/** ���������� ������ �������� */
}
int CProgram::getLines() const		/** ��������� ������� ������� ����� ���� �������� */
{ 
	return amountOfLines;			/** ���������� ������� ����� ���� �������� */
}
int CProgram::getIndex() const		/** ��������� ������� ������� �������� */
{ 
	return index;					/** ���������� ������� �������� */
}
bool CProgram::getInternet()const	/** ��������� ������� ��������� */
{ 
	return useInternet;				/** ���������� ��������� */
}
string CProgram::getName()const		/** ��������� ������� ����� �������� */
{ 
	return name;					/** ���������� ����� �������� */
}

void CProgram::enter(istream& data)	/** ��������� ��������������� ��������� ����� */
{
	data >> index >> timeOfWork >> size >> amountOfLines >> useInternet >> name;	/** �������� ����� � ��'��� ���� istream */
}
string CProgram::getInfo() const	/** ��������� ������ ��������� ����� �������� */
{
	stringstream temp;				/** ��������� ����� ���� stringstream */
	temp.setf(ios::left);

	temp << setw(10) << timeOfWork << setw(12) << size
		<< setw(9) << amountOfLines << setw(12) << boolalpha << useInternet
		<< setw(11) << index << setw(16) << name;	/** ����� ����� � ��'��� ���� stringstream */

	return temp.str();				/** ���������� ����� � ������ string */
}


CProgram::CProgram(bool internet, int time, int size, int lines, int index, string name) : useInternet(internet), timeOfWork(time), size(size), amountOfLines(lines), index(index), name(name) {}	/** ��������� ������������ � ����������� */
CProgram::CProgram() : useInternet(false), timeOfWork(200), size(200), amountOfLines(200), index(0101), name("Basic") {}	/** ��������� ������������ �� ������������� */
CProgram::CProgram(const CProgram& other) : useInternet(other.useInternet), timeOfWork(other.timeOfWork), size(other.size), amountOfLines(other.amountOfLines), index(other.index), name(other.name) {}	/** ��������� ������������ ��������� */
CProgram::~CProgram() {}			/** ��������� ����������� */

ofstream& operator<< (ofstream& output, const CProgram& program)	/** ��������� ��������������� ��������� ������ ����� � ���� */
{
	output << program.getInfo();	/** ������ ������ ��������� ���������� */
	return output;					/** ���������� ���������� */
}
ostream& operator<< (ostream& output, const CProgram& program)		/** ��������� ��������������� ��������� ������ ����� � ������� */
{
	output << program.getInfo();	/** ������ ������ ��������� ���������� */
	return output;					/** ���������� ���������� */
}
istream& operator>> (istream& input, CProgram& program)			/** ��������� ��������������� ��������� ����� ����� � ������ */
{
	program.enter(input);			/** ������ ������ ����� ����� */
	return input;					/** ���������� ���������� */
}
bool CProgram::operator!=(const string type) const		/** ��������� ��������������� ��������� �������� */
{
	return true;		/** �������� ���������� �� ����� ����������� �� (�������� �������� �� ���� ���� ���������� ��) */
}
bool CProgram::operator==(const int index) const		/** ��������� ��������������� ��������� ��������� */
{
	return this->index == index;	/** �������� ���������� �� �������� */
}
CProgram& CProgram::operator= (CProgram& temp)			/** ��������� ��������������� ��������� ������������ */
{
	if (this == &temp)				/** �������� ���� ���� ������� */
		return *this;
	
	int timeOfWork = temp.timeOfWork;		/** ������������ ���� ���� ������ �������� */
	int size = temp.size;					/** ������������ ���� ������ �������� */
	int amountOfLines = temp.amountOfLines;	/** ������������ ���� ������� ����� �������� */
	int index = temp.index;					/** ������������ ���� ������� �������� */
	bool useInternet = temp.useInternet;	/** ������������ ���� ��������� */
	string name = temp.name;				/** ������������ ���� ����� �������� */

	return *this;				/** ���������� �������� */
}