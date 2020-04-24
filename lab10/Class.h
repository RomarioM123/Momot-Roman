#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, FILE, __LINE)

#include <clocale>
#include <iostream>
#include <string>
#include <regex>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::regex;
using std::regex_search;

typedef bool (comp)(const float&, const float&);

class MyClass
{
private:

public:
	template<class T> void OutputArr(T array, int size) const
	{
		for (size_t i = 0; i < size; i++)
		{
			cout << array[i] << "  ";
		}
		cout << endl;
	}
	
	template<class T> int FindEl(T array, int size, float value) const
	{
		for (size_t i = 0; i < size; i++)
		{
			if (array[i] == value)
			{
				return i;
			}
			
		}
		return -1;
	}

	template<class T> T Sort(T array, int size, comp condition)
	{
		char temp;
		bool pr;

		do {
			pr = 0;
			for (size_t i = 0; i < size - 1; i++)
			{	
				if (condition((float)array[i], (float)array[i+1]))
				{
					temp = array[i];
					array[i] = array[i + 1];
					array[i + 1] = temp;
					pr = 1;
				}
			}
		} while (pr);

		return array;
	}

	template<class T> void FindMin(T array, int size, comp condition) const
	{
		float temp = array[0];
		for (size_t i = 1; i < size; i++)
		{
			if (condition((float)array[i], (float)temp))
			{
				temp = array[i];
			}
		}
		cout << endl << "Минимальный элемент: " << temp << endl;
	}


	static bool sortAsc(const float&, const float&);
	static bool sortDesc(const float&, const float&);

	~MyClass();
};
