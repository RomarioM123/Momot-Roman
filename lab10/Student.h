#pragma once
#include "Header.h"

class Student
{
private:
	string name;
	int age;
	Student* array;

public:
	Student* createArray(int) noexcept;
	Student students(int) const noexcept;

	friend ostream& operator<<(ostream&, const Student) noexcept;
	friend istream& operator>>(istream&, Student&) noexcept;
	
	bool operator==(const Student) const noexcept;
	bool operator<(const Student) const noexcept;
	bool operator>(const Student) const noexcept;
	
	Student();
	Student(string, int);
	Student(const Student&);
	~Student();
};

