#pragma once
#include "Student.h"
class Foreigner final: public Student
{
private:
	string country;
	
public:
	string getInfo() const override final;
	friend ostream& operator<<(ostream&, const Foreigner) noexcept;

	Foreigner();
	Foreigner(string, string, int);
	Foreigner(const Foreigner&);
	~Foreigner() override final;
};

