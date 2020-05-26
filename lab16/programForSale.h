/**
* @file programForSale.h
* ���� ���������� �����-����������.
* @author Momot Roman
* @version 1.0
* @date 2020.05.26
*/

#pragma once
#include "program.h"					/** ϳ��������� ����� program.h */
class CProgramForSale final : public CProgram	/** ���������� ����� ��������� */
{
private:
	int price;		/** ֳ�� �������� */				

public:
	int getTime() const override;		/** ���������� ��������������� ������ ��������� ���� ��������� �������� */
	int getSize() const override;		/** ���������� ��������������� ������ ��������� ������ �������� */
	int getLines() const override;		/** ���������� ��������������� ������ ��������� ������� ����� ���� �������� */
	int getIndex()const override;		/** ���������� ��������������� ������ ��������� ������� �������� */
	bool getInternet()const override;	/** ���������� ��������������� ������ ��������� ���� ��������� �������� */
	string getName() const override;	/** ���������� ��������������� ������ ��������� ����� �������� */
	
	string getInfo() const override;	/** ���������� ��������������� ������ ��������� ���������� �������� */
	void enter(istream&) override;		/** ���������� ��������������� ������ ����� ���������� �������� */

	CProgramForSale();											/** ���������� ������������ �� ������������� */
	CProgramForSale(bool, int, int, int, int, string, int);		/** ���������� ������������ � ����������� */
	CProgramForSale(const CProgramForSale&);					/** ���������� ������������ ��������� */
	~CProgramForSale() override;								/** ���������� ��������������� ����������� */

	void* operator new(size_t);
	void* operator new[](size_t);
	void operator delete(void*);
	void operator delete[](void*);
};

