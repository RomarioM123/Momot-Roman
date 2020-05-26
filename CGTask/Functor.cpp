/**
* @file Functor.cpp
* ���� ��������� ������ ����� Functor
* @author Momot Roman
* @version 1.0
* @date 2020.05.26
*/

#include "Functor.h"			/** ϳ��������� ����� Functor.h */

bool Functor::operator()(const unique_ptr<CProgram>& first, const unique_ptr<CProgram>& second) const	/** ��������� ������������ ��������� () */
{
	if (choise == 1)			/** ���� ����� ��������� �� ���� */
	{
		if (direction == true)	/** ���� ������� ���������� */
			return first->getName() > second->getName();
		else
			return first->getName() < second->getName();
	}
	else if (choise == 2)		/** ���� ����� ��������� �� ������� */
	{
		if (direction == true)	/** ���� ������� ���������� */
			return first->getIndex() > second->getIndex();
		else
			return first->getIndex() < second->getIndex();
	}
	else if (choise == 3)		/** ���� ����� ��������� �� ������� ����� ���� */
	{
		if (direction == true)	/** ���� ������� ���������� */
			return first->getLines() > second->getLines();
		else
			return first->getLines() < second->getLines();
	}
	else if (choise == 4)		/** ���� ����� ��������� �� ������ �������� */
	{
		if (direction == true)	/** ���� ������� ���������� */
			return first->getSize() > second->getSize();
		else
			return first->getSize() < second->getSize();
	}
	else if (choise == 5)		/** ���� ����� ��������� �� ���� ��������� ������ �������� */
	{
		if (direction == true)	/** ���� ������� ���������� */
			return first->getTime() > second->getTime();
		else
			return first->getTime() < second->getTime();
	}
	else if (choise == 6)		/** ���� ����� ��������� �� ��������� */
	{
		if (direction == true)	/** ���� ������� ���������� */
			return first->getInternet() > second->getInternet();
		else
			return first->getInternet() < second->getInternet();
	}
}

Functor::Functor(bool direction, int choise) :direction(direction), choise(choise) {}	/** ��������� ������������ � ����������� */
Functor::~Functor() {}			/** ��������� ����������� */