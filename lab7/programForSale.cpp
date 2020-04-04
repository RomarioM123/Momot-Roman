#include "programForSale.h"

void ProgramForSale::setPrice(int price)
{
	this->price = price;
}
int ProgramForSale::getPrice() const
{
	return price;
}

void ProgramForSale::print() const
{
	cout << setw(10) << timeOfWork;
	cout << setw(12) << size;
	cout << setw(9) << amountOfLines;
	cout << setw(12) << boolalpha << useInternet;
	cout << setw(11) << index;
	cout << setw(26) << name;
	cout << setw(14) << date.getYear();
	cout << setw(12) << author.getAuthor();
	cout << setw(14) << price << endl;
}
stringstream ProgramForSale::getStr() const
{
	stringstream temp;

	temp << " " << index << " " << price << " " << timeOfWork << " " << size << " " << amountOfLines
		<< " " << useInternet << " " << author.getAuthor() << " " << date.getDay()
		<< " " << date.getMonth() << " " << date.getYear() << " " << name;

	return temp;
}
void ProgramForSale::writeInFile(ofstream& el)
{
	el << setw(10) << timeOfWork << setw(12) << size << setw(12) << amountOfLines
		<< setw(12) << useInternet << setw(15) << index << setw(26) << name
		<< setw(14) << date.getYear() << setw(12) << author.getAuthor()
		<< setw(12) << price << endl;
}

ProgramForSale::ProgramForSale() : C_Program(), price(2000) {}
ProgramForSale::ProgramForSale(bool internet, int time, int size, int lines, int index, string name, CAuthor author, sint day, sint month, sint year, int price) : C_Program(internet, time, size, lines, index, name, author, day, month, year), price(price) {}
ProgramForSale::ProgramForSale(const ProgramForSale& other) : C_Program(other), price(other.price) {}
ProgramForSale::~ProgramForSale() {}