#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, FILE, __LINE)

#include <iostream>
#include <string>
#include <locale>
#include <fstream>
#include <sstream>
#include <algorithm>

using std::ifstream;
using std::ofstream;
using std::ostream;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::exception;
using std::istringstream;


class Array
{
public:
	int* array;

public:
	Array();
	~Array();
};

