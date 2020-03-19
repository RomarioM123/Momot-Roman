#pragma once
#include <iostream>
#include <string>

using std::string;

class CAuthor {
private:
	int listSize;
	string companyName;

public:
	string* list;

	void setAuthor(const string);
	string getAuthor()const;
	string* createList(int size);
	string authors(int value);

	CAuthor();
	CAuthor(string author);
	CAuthor(const CAuthor& other);
	~CAuthor();
};