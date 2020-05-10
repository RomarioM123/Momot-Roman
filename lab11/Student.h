#pragma once
#include "Header.h"

class Student
{
protected:
	string name;
	int age;

public:
	virtual string getInfo() const;

	friend ostream& operator<<(ostream&, const Student&) noexcept;
	friend istream& operator>>(istream&, Student&) noexcept;
	
	bool operator==(const Student) const noexcept;
	bool operator<(const Student) const noexcept;
	bool operator>(const Student) const noexcept;
	
	Student();
	Student(string, int);
	Student(const Student&);
	virtual ~Student();
};

