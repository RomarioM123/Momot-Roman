#include "programForSale.h"

stringstream CProgramForSale::getStr() const
{
	stringstream temp;

	temp << timeOfWork << " " << size << " " << amountOfLines << " "
		<< useInternet << " " << index << " " << name << " "
		<< date.getDay() << " " << date.getMonth() << " "
		<< date.getYear() << " " << author << " " << price;

	return temp;
}
string CProgramForSale::getInfo() const
{
	stringstream temp;
	temp.setf(ios::left);

	temp << setw(10) << timeOfWork << setw(12) << size
		<< setw(9) << amountOfLines << setw(12) << boolalpha << useInternet
		<< setw(11) << index << setw(26) << name
		<< setw(14) << date.getYear() << setw(12) << author
		<< setw(14) << price;

	return temp.str();
}
void CProgramForSale::input(istream& input)
{
	input >> index >> timeOfWork >> price >> size >> amountOfLines >> useInternet >> author >> date >> name;
}

CProgramForSale::CProgramForSale(bool internet, int time, int size, int lines, int index, string name, CAuthor author, sint day, sint month, sint year, int price) : CProgram(internet, time, size, lines, index, name, author, day, month, year), price(price) {}
CProgramForSale::CProgramForSale() : CProgram(), price(2000) {}
CProgramForSale::CProgramForSale(const CProgramForSale& other) : CProgram(other), price(other.price) {}
CProgramForSale::~CProgramForSale() {}

CProgramForSale& CProgramForSale::operator=(CProgramForSale& temp)
{
	if (this == &temp) return *this;

	CProgram::operator=(temp);
	int price = temp.price;

	return *this;
}
bool CProgramForSale::operator==(const string name) const
{
	return this->name == name;
}