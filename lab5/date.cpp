#include "date.h"

void CDate::setDay(sint day)
{
	this->day = day;
}
void CDate::setMonth(sint month)
{
	this->month = month;
}
void CDate::setYear(sint year)
{
	this->year = year;
}

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
