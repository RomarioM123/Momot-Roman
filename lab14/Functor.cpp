#include "Functor.h"

bool Functor::operator() (const shared_ptr<CProgram>& program1, const shared_ptr<CProgram>& program2)
{
	if (value % 2 != 0)
		return program1->getID() < program2->getID();
	else
		return program1->getID() > program2->getID();
}

Functor::Functor(int value) :value(value) {}
Functor::~Functor() {}