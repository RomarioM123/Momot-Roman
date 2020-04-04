#pragma once
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
};