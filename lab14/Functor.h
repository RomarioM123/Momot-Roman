#pragma once
#include "Program.h"

class Functor
{
private:
	int value;

public:
	bool operator()(const shared_ptr<CProgram>&, const shared_ptr<CProgram>&);
	Functor(int);
	~Functor();
};

