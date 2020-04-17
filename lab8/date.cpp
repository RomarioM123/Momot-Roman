#include "date.h"

sint CDate::getDay() const
{
	return day;
}
sint CDate::getMonth() const
{
	return month;
}
sint CDate::getYear() const
{
	return year;
}

CDate::CDate() : day(1), month(1), year(1999) {}
CDate::CDate(sint day, sint month, sint year) : day(day), month(month), year(year) {}
CDate::CDate(const CDate& other) : day(other.day), month(other.month), year(other.year) {}
CDate::~CDate() {}

istream& operator>> (istream& input, CDate& date)
{
	input >> date.year;

	return input;
}
ostream& operator<< (ostream& output, const CDate& date)
{
	output << date.year;

	return output;
}