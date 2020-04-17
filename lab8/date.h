#pragma once
#include <iostream>

using std::istream;
using std::ostream;
typedef short sint;

class CDate
{
private:
	sint day;
	sint month;
	sint year;

public:
	sint getDay() const;
	sint getMonth() const;
	sint getYear() const;

	CDate();
	CDate(sint, sint, sint);
	CDate(const CDate& other);
	~CDate();

	friend istream& operator>> (istream&, CDate&);
	friend ostream& operator<< (ostream&, const CDate&);
};