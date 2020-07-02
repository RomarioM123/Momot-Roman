/**
* @file programList.cpp
* ���� ��������� ������ ����� CList
* @author Momot Roman
* @version 1.0
* @date 2020.05.26
*/

#include "programList.h"	/** ϳ��������� ����� programList.h */

CList::~CList()				/** ��������� ����������� */
{
	programList.clear();	/** �������� ���'�� ������ ������� */
}
CList::CList()				/** ��������� ������������ �� ������������� */
{
	for (size_t i = 0; i < 5; i++)		/** �����, ���� �������� ������ ���������� */
	{
		if (i == 0)
			programList.emplace_back(new CProgram());
		else if (i == 1)
			programList.emplace_back(new CMalware(1, 8800, 555, 35, 35634, "BestMalware", "Exploit"));
		else if (i == 2)
			programList.emplace_back(new CProgram(0, 423, 20, 654, 53453, "Calculator"));
		else if (i == 3)
			programList.emplace_back(new CProgramForSale(0, 345, 789, 423, 67456, "MoneyStealer", 99999));
		else
			programList.emplace_back(new CMalware());
	}
}
void CList::PrintList() const noexcept		/** ��������� ������ ��������� ������ �� ����� */
{	
	try
	{
		if (programList.size() == 0)		/** �������� ������ ������ */
			throw exception("������ ����.");

		int value = 1;

		cout << endl << setiosflags(ios::left);
		cout << setw(12) << "  �����" << setw(12) << "������";
		cout << setw(10) << "������" << setw(11) << "��������";
		cout << setw(14) << "������" << setw(17) << "��������";
		cout << setw(14) << "���/����" << endl;			/** ��������� ���� ���� ����� */

		for_each(programList.begin(), programList.end(), [&value](const unique_ptr<CProgram>& program)	/** ����, ���� �������� ������ �������� */
			{
				cout << value << ". " << *program << endl;	/** ��������� ������ �� ���� �������� */
				value++;		/** ��������� ���� ����������� */
			});

		cout << endl;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}
int CList::Task(int minimalSize) const		/** ��������� ������ ��������� �������������� �������� */
{
	int value = 1;				/** ���������� ����� ������� ��������� �������� */
	
	for (const auto& program : programList)		/** ���� ���� �������� �� �������� ������ */
	{
		if (program->getLines() > minimalSize && *program != "Trojan")	/** �������� ���� �������� */
		{
			cout << value << ". " << *program << endl;	/** ��������� �������� �� ����� */
			value++;	/** ��������� ����� ����������� ������ */
		}
	}

	if (value == 0)		/** ���� �������� ���� */
		throw exception("��������� � ������ ����������� �����������.");

	return value;		/** ���������� ������� ��������� �������� */
}
int CList::AddProgram(int value)	/** ��������� ������ ��������� ���� �������� */
{
	if (value == 1)
	{
		CProgram* temp = new CProgram;	/** ��������� �������� ����� CProgram */
		programList.emplace_back(temp);	/** ������� �������� � ����� */
	}
	else if (value == 2)
	{
		CProgram* temp = new CMalware;	/** ��������� �������� ����� CMalware */
		programList.emplace_back(temp);	/** ������� �������� � ����� */
	}
	else if (value == 3)
	{
		CProgram* temp = new CProgramForSale;	/** ��������� �������� ����� CProgramForSale */
		programList.emplace_back(temp);			/** ������� �������� � ����� */
	}
	else
		throw exception("�������� �������.");

	return programList.size();			/** ���������� ������ ������ */
}
int CList::DeleteProgram(int value)		/** ��������� ������ ��������� �������� */
{
	if (programList.size() == 0)		/** �������� ������ ������ */
		throw exception("C����� �������� ����.");

	int number = -1;
	bool findEl = false;	
	std::vector<unique_ptr<CProgram>>::iterator it;	/** ��������� ��������� */

	for (const auto& program : programList)		/** ����, ���� �������� �� �������� �������� */
	{
		if (program->getIndex() == value)		/** ���� �������� �� �������� ������ */
		{
			number++;				/** ��������� ����� ������ �������� */
			findEl = true;			/** ������� ���� ����������� �������� */
			break;					/** ������� ������ ����� */
		}
		else
			number++;				/** ��������� ����� ������ �������� */
	}

	if (findEl)		/** ���� ������� � �������� �������� ��� ������ */
	{
		it = programList.begin();	/** ������������ ��������� �� ������� ������ */
		advance(it, number);		/** ���������� ��������� �� �������� ������� */
		programList.erase(it);		/** ��������� ��������� �������� */

		cout << "�������� ���������." << endl;
	}
	else
		throw exception("������� �� ������.");

	return programList.size();		/** ���������� ����� ������ ������ */
}
void CList::Sort(Functor& choise) noexcept	/** ��������� ������ ���������� ������ */
{
	std::sort(programList.begin(), programList.end(), choise);	/** ���������� ������ */
}
int CList::SaveFile(string filename) const	/** ��������� ������ ������ ����� � ���� */
{
	if (programList.size() == 0)	/** �������� ������ ������ */
		throw exception("������ ����.");
	
	ofstream fout(filename);		/** ³������� ����� */
	if (!fout.is_open())			/** �������� �� �������� ���� */
		throw exception("���������� ������� ����.");
	
	fout << setiosflags(ios::left);
	fout << setw(12) << "  �����" << setw(12) << "������";
	fout << setw(10) << "������" << setw(11) << "��������";
	fout << setw(14) << "������" << setw(17) << "��������";
	fout << setw(14) << "���/����" << endl;	/** ��������� ���� ���� */

	int value = 1;
	for (const auto& program : programList)	/** ����, ���� �������� �� �������� ������ */
	{
		fout << setiosflags(ios::left) << setw(2) << value << ". ";	/** ��������� ����������� �������� */
		fout << *program << endl;	/** ��������� ���� �������� */
		value++;
	}

	fout.close();		/** �������� ����� */
	return value - 1;	/** ���������� ������� ��������, �� ���� �������� � ���� */
}
int CList::ReadFile(string filename)	/** ��������� ������ ������� ����� � ����� */
{
	regex expressionProgram("([\\d]* [\\d]* [\\d]* [\\d]* [1|0]* [A-Z�-�]+[\\w�-��-�,.;:-]* [\\w�-��-�,.;:-]*)");	/** ���������� ����� ��� ����� CProgram */
	regex expressionMalware("([\\d]* [\\d]* [a-zA-Z�-��-�]* [\\d]* [\\d]* [1|0]* [A-Z�-�]+[\\w�-��-�,.;:-]* [\\w�-��-�,.;:-]*)");	/** ���������� ����� ��� ����� CMalware */
	regex expressionProgramForSelling("([\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [1|0]* [A-Z�-�]+[\\w�-��-�,.;:-]* [\\w�-��-�,.;:-]*)");	/** ���������� ����� ��� ����� CProgramForSale */
	regex replaceSymbols("[;:-]");	/** ���������� ����� ��� �������, �� ����� ������� */

	string temp, data, replacement = "";
	int value = 0;
	ifstream fin(filename);		/** ³������� ����� */
	istringstream ss;
	
	if (!fin.is_open())			/** �������� �� �������� ���� */
	{
		throw exception("���������� ������� ���� ��� ������.");
		return programList.size();
	}

	while (!fin.eof())			/** ����, ���� ������ �� ���� ����� */
	{	
		getline(fin, data);		/** ��������� ������ � ����� */
		temp = regex_replace(data, replaceSymbols, replacement);	/** ��������� ������� �� �� �������� */
		temp += " ";

		if (regex_match(temp, expressionProgram))	/** �������� �� ���������� �� ����� CProgram */
		{
			istringstream ss(temp);
			CProgram* program = new CProgram();		/** ��������� ����� ����� CProgram */
			
			ss >> *program;
			programList.emplace_back(program);		/** ������� �������� � ����� */
			value++;								/** ��������� ����� ������� ����� �������� */
		}
		else if (regex_match(temp, expressionMalware))	/** �������� �� ���������� �� ����� CProgram */
		{
			istringstream ss(temp);
			CMalware* program = new CMalware();			/** ��������� ����� ����� CMalware */

			ss >> *program;
			programList.emplace_back(program);			/** ������� �������� � ����� */
			value++;									/** ��������� ����� ������� ����� �������� */
		}
		else if (regex_match(temp, expressionProgramForSelling))	/** �������� �� ���������� �� ����� CProgram */
		{
			istringstream ss(temp);
			CProgramForSale* program = new CProgramForSale();		/** ��������� ����� ����� CProgramForSale */

			ss >> *program;
			programList.emplace_back(program);						/** ������� �������� � ����� */
			value++;												/** ��������� ����� ������� ����� �������� */
		}
	}

	fin.close();		/** �������� ����� */
	return value;		/** ���������� ����� ������� ����� �������� */
}
int CList::GetIndex(int value) const	/** ��������� ������ ��������� ������� �������� */
{
	return programList[value]->getIndex();	/** ���������� ������� */
}





