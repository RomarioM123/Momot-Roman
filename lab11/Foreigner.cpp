#include "Foreigner.h"

string Foreigner::getInfo() const
{
	stringstream temp;
	temp.setf(std::ios::left);
	temp << setw(11) << name << setw(10) << age << setw(6) << country;

	return temp.str();
}

Foreigner::Foreigner():Student(), country("ַטלבאבגו") {}
Foreigner::Foreigner(string country, string name, int age): country(country), Student(name, age){}
Foreigner::Foreigner(const Foreigner& other): Student(other), country(other.country){}
Foreigner::~Foreigner() {}
