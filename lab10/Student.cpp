#include "Student.h"
#include "Header.h"

Student* Student::createArray(int size) noexcept
{
	array = new Student[size];

	for (size_t i = 0; i < size; i++)
	{
		array[i] = students(i);
	}

	return array;
}
Student Student::students(int value) const noexcept
{
	if (value == 0)
	{
		Student defaultStud;
		return defaultStud;
	}
	else if (value == 1)
	{
		Student stud("Ivan", 20);
		return stud;
	}
	else if (value == 2)
	{
		Student stud("John", 24);
		return stud;
	}
	else if (value == 3)
	{
		Student stud("Roman", 21);
		return stud;
	}
	else if (value == 4)
	{
		Student stud("Susan", 26);
		return stud;
	}
}

ostream& operator<<(ostream& output, const Student stud) noexcept
{
	output.setf(std::ios::left);
	output << setw(12) << stud.name << setw(14) << stud.age;
	
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

Student::Student(): name("Petrov"), age(18){}
Student::Student(string name, int age):name(name), age(age){}
Student::Student(const Student& other):name(other.name), age(other.age){}
Student::~Student() {}