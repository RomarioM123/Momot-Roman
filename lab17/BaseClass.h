#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cereal/types/vector.hpp>
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/json.hpp>
#include <cereal/types/base_class.hpp>
#include <cereal/archives/xml.hpp>

#include <iostream>
#include <iomanip>
#include <ostream>
#include <fstream>
#include <vector>
#include <memory>
#include <regex>
#include <clocale>

using std::regex_search;
using std::regex;
using std::ostream;
using std::string;
using std::ifstream;
using std::stringstream;
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::ofstream;
using std::istream;
using std::vector;
using std::shared_ptr;
using std::getline;

class CProgram
{
protected:
	string name;
	int timeOfWork;
	int size;
	int index;
	int amountOfLines;

public:
	virtual string getInfo() const;
	virtual stringstream getStr() const;
	
	friend ostream& operator<< (ostream&, const CProgram&);
	
	template<typename T>
	void serialize(T& serialize)
	{
		serialize(cereal::make_nvp("Name", name));
		serialize(cereal::make_nvp("Time of work", timeOfWork));
		serialize(cereal::make_nvp("Size of program", size));
		serialize(cereal::make_nvp("Index", index));
		serialize(cereal::make_nvp("Amount of code lines", amountOfLines));
	}

	CProgram();
	CProgram(string, int, int, int, int);
	CProgram(const CProgram&);
	virtual ~CProgram();
};