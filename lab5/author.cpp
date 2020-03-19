#include "author.h"

string CAuthor::getAuthor() const
{
	return companyName;
}
void CAuthor::setAuthor(string name)
{
	companyName = name;
}

string* CAuthor::createList(int size)
{
	listSize = size;
	list = new string[size];

	for (size_t i = 0; i < size; i++)
	{
		list[i] = authors(i);
	}
	
	return list;
}

string CAuthor::authors(int value)
{
	string author;

	switch (value)
	{
	case 1:
		author = { "Microsoft" };
		break;
	case 2:
		author = { "Lambda" };
		break;
	case 3:
		author = { "AMD" };
		break;
	case 4:
		author = { "Logitech" };
		break;
	default:
		string standartAuthor;
		return standartAuthor;
	}

	return author;
}

CAuthor::CAuthor() : companyName("IBM") {}
CAuthor::CAuthor(string author) : companyName(author) {}
CAuthor::CAuthor(const CAuthor& other) : companyName(other.companyName) {}
CAuthor::~CAuthor() {}