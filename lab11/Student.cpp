#include "Student.h"
#include "Header.h"

string Student::getInfo() const
{
	stringstream temp;
	temp.setf(std::ios::left);
	temp << setw(11) << name << setw(6) << age;

	return temp.str();
}

ostream& operator<<(ostream& output, const Student& stud) noexcept
{
	output.setf(std::ios::left);
	output << stud.getInfo();
	
	return output;
}
istream& operator>>(istream& input, Student& stud) noexcept
{
	input >> stud.age;

	return input;
}

bool Student::operator<(const Student stud) const noexcept
{
	return this->age < stud.age;
}
bool Student::operator>(const Student stud) const noexcept
{
	return this->age > stud.age;
}
bool Student::operator==(const Student stud) const noexcept
{
	return this->age == stud.age;
}

Student::Student(): name("Петров"), age(18){}
Student::Student(string name, int age):name(name), age(age){}
Student::Student(const Student& other):name(other.name), age(other.age){}
Student::~Student() {}