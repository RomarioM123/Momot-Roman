/**
* @file programForSale.cpp
* ���� ��������� ������ �����-���������
* @author Momot Roman
* @version 1.0
* @date 2020.05.26
*/

#include "programForSale.h"				/** ϳ��������� ����� programForSale.h */

int CProgramForSale::getTime() const	/** ��������� ������� ���� ������ �������� */
{
	return timeOfWork;					/** ���������� ���� ������ �������� */
}
int CProgramForSale::getSize() const	/** ��������� ������� ������ �������� */
{
	return size;						/** ���������� ������ �������� */
}
int CProgramForSale::getLines() const	/** ��������� ������� ������� ����� ���� �������� */
{
	return amountOfLines;				/** ���������� ������� ����� ���� �������� */
}
int CProgramForSale::getIndex() const	/** ��������� ������� ������� �������� */
{
	return index;						/** ���������� ������� �������� */
}
bool CProgramForSale::getInternet()const/** ��������� ������� ��������� */
{
	return useInternet;					/** ���������� ��������� */
}
string CProgramForSale::getName()const	/** ��������� ������� ����� �������� */
{
	return name;						/** ���������� ����� �������� */
}

string CProgramForSale::getInfo() const	/** ��������� ������ ��������� ����� �������� */
{
	stringstream temp;					/** ��������� ����� ���� stringstream */
	temp.setf(ios::left);

	temp << setw(10) << timeOfWork << setw(12) << size
		<< setw(9) << amountOfLines << setw(12) << boolalpha << useInternet
		<< setw(11) << index << setw(20) << name
		<< setw(14) << price;			/** ����� ����� � ��'��� ���� stringstream */

	return temp.str();					/** ���������� ����� � ������ string */
}
void CProgramForSale::enter(istream& data)	/** ��������� ��������������� ��������� ����� */
{
	data >> index >> timeOfWork >> price >> size >> amountOfLines >> useInternet >> name;	/** �������� ����� � ��'��� ���� istream */
}

CProgramForSale::CProgramForSale(bool internet, int time, int size, int lines, int index, string name, int price) : CProgram(internet, time, size, lines, index, name), price(price) {}	/** ��������� ������������ � ����������� */
CProgramForSale::CProgramForSale() : CProgram(), price(2000) {}		/** ��������� ������������ �� ������������� */
CProgramForSale::CProgramForSale(const CProgramForSale& other) : CProgram(other), price(other.price) {}		/** ��������� ������������ ��������� */
CProgramForSale::~CProgramForSale() {}		/** ��������� ����������� */

CProgramForSale& CProgramForSale::operator=(CProgramForSale& temp)	/** ��������� ��������������� ��������� ������������ */
{
	if (this == &temp)					/** �������� ���� ���� ������� */
		return *this;

	CProgramForSale::operator=(temp);	/** ������������ ���� �������� ����� */
	int price = temp.price;				/** ������������ ���� ���� */

	return *this;
}
bool CProgramForSale::operator!=(const string type) const	/** ��������� ��������������� ��������� �������� */
{
	return true;	/** �������� ���������� �� ����� ����������� �� (�������� �������� �� ���� ���� ���������� ��) */
}
bool CProgramForSale::operator==(const int index) const		/** ��������� ��������������� ��������� ��������� */
{
	return this->index == index;							/** �������� ���������� �� �������� */
}