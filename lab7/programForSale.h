#pragma once
#include "program.h"
class ProgramForSale : public C_Program
{
private:
	int price;

public:
	int getPrice() const;
	void setPrice(int price);

	void print() const override;
	stringstream getStr() const override;
	void writeInFile(ofstream& el) override;

	ProgramForSale();
	ProgramForSale(bool, int, int, int, int, string, CAuthor, sint, sint, sint, int price);
	ProgramForSale(const ProgramForSale& other);
	~ProgramForSale();
};

