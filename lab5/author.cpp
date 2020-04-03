#include "author.h"

string CAuthor::getAuthor() const
{
	return companyName;
}
void CAuthor::setAuthor(string name)
{
	companyName = name;
}

CAuthor* CAuthor::createList(int size)
{
	list = new CAuthor[size];
	listSize = size;

	for (size_t i = 0; i < size; i++)
	{
		list[i] = authors(i);
	}

	return list;
}

void CAuthor::deleteList()
{
	delete[] list;
}

CAuthor CAuthor::authors(int value)
{
	if (value == 0)
	{
		CAuthor author("Oracle");
		return author;
	} 
	else if (value == 1) 
	{
		CAuthor author2("Lambda");
		return author2;
	} 
	else if (value == 2) 
	{
		CAuthor author3("AMD");
		return author3;
	}
	else if (value == 3) 
	{
		CAuthor author4("Logitech");
		return author4;
	}
}

CAuthor::CAuthor() : companyName("IBM") {}
CAuthor::CAuthor(string author) : companyName(author) {}
CAuthor::CAuthor(const CAuthor& other) : companyName(other.companyName) {}
CAuthor::~CAuthor() {}