#pragma once
#include <iostream>
#include <string>

using std::string;

class CAuthor {
private:
	string companyName;
	int listSize;
	CAuthor* list;

public:
	void setAuthor(const string);
	string getAuthor()const;

	CAuthor* createList(int size);
	void deleteList();

	CAuthor authors(int value);

	CAuthor();
	CAuthor(string author);
	CAuthor(const CAuthor& other);
	~CAuthor();
};