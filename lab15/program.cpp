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
int CProgram::countElement(int value, string data)
{
	try
	{
		if (value == 1)
		{
			if (this->name == data)
				return 1;
			else
				return 0;
		}
		else if (value == 2)
		{
			int number = stoi(data);
			if (this->timeOfWork == number)
				return 1;
			else
				return 0;
		}
		else if (value == 3)
		{
			int number = stoi(data);
			if (this->size == number)
				return 1;
			else
				return 0;
		}
		else if (value == 4)
		{
			int number = stoi(data);
			if (this->amountOfLines == number)
				return 1;
			else
				return 0;
		}
		else if (value == 5)
		{
			int number = stoi(data);
			if (this->index == number)
				return 1;
			else
				return 0;
		}
		else if (value == 6)
		{
			int number = 0;
			if (data == "true" || data == "true" || data == "1")
				number = 1;
			else
				number = 0;
			
			if (this->useInternet == number)
				return 1;
			else
				return 0;
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
		return 0;
	}
		
	return 0;
}
bool CProgram::elementOutput(int value, string data)
{
	try
	{
		if (value == 1)
		{
			if (this->name == data)
				cout << *this << endl;
			return true;
		}
		else if (value == 2)
		{
			int number = stoi(data);
			if (this->timeOfWork == number)
				cout << *this << endl;
			return true;
		}
		else if (value == 3)
		{
			int number = stoi(data);
			if (this->size == number)
				cout << *this << endl;
			return true;
		}
		else if (value == 4)
		{
			int number = stoi(data);
			if (this->amountOfLines == number)
				cout << *this << endl;
			return true;
		}
		else if (value == 5)
		{
			int number = stoi(data);
			if (this->index == number)
				cout << *this << endl;
			return true;
		}
		else if (value == 6)
		{
			int number = 0;
			if (data == "true" || data == "true" || data == "1")
				number = 1;
			else
				number = 0;

			if (this->useInternet == number)
				return 1;
			else
				return 0;
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
		return 0;
	}

	return 0;
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

CProgram::CProgram(bool internet, int time, int size, int lines, int index, string name) : useInternet(internet), timeOfWork(time), size(size), amountOfLines(lines), index(index), name(name) {}
CProgram::CProgram() : useInternet(false), timeOfWork(0), size(0), amountOfLines(0), index(0101), name("Basic") {}
CProgram::CProgram(const CProgram& other) : useInternet(other.useInternet), timeOfWork(other.timeOfWork), size(other.size), amountOfLines(other.amountOfLines), index(other.index), name(other.name) {}
CProgram::~CProgram() {}