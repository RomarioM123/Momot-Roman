#pragma once
#include <iostream>
#include <string>

using std::string;

class CAuthor {
private:
	string companyName;
	int listSize;
	string* list;

public:
	void setAuthor(const string);
	string getAuthor()const;

	string* createList(int size);
	void deleteList();

	string authors(int value);

	CAuthor();
	CAuthor(string author);
	CAuthor(const CAuthor& other);
	~CAuthor();
};