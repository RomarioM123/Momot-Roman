#pragma once
#include "program.h"
class CProgramForSale final : public CProgram
{
private:
	int price;

public:
	string getInfo() const override final;
	stringstream getStr() const override final;
	void input(istream&) override final;

	CProgramForSale();
	CProgramForSale(bool, int, int, int, int, string, CAuthor, sint, sint, sint, int);
	CProgramForSale(const CProgramForSale&);
	~CProgramForSale() override final;

	CProgramForSale& operator= (CProgramForSale&);
	bool operator==(const string) const override final;
};

