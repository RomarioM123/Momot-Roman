#pragma once
#include <iostream>
#include <string>

using std::string;
using std::ostream;
using std::istream;

class CAuthor {
private:
	string companyName;
	int listSize;
	CAuthor* list;

public:
	CAuthor* createList(int size);
	void deleteList();
	string getAuthor();

	CAuthor authors(int value);

	CAuthor();
	CAuthor(string author);
	CAuthor(const CAuthor& other);
	~CAuthor();

	friend istream& operator>> (istream&, CAuthor&);
	friend ostream& operator<< (ostream&, const CAuthor&);
	bool operator==(const string) const;
};