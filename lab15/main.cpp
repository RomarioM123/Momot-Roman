#include "malware.h"
#include "SmartPointer.h"
void func();

int main()
{
	setlocale(LC_ALL, "Rus");	
	
	func();

	if (_CrtDumpMemoryLeaks()) 
		cout << endl << "������!!!! ���� ������ ������." << endl;
	else 
		cout << endl << "������ ������ �����������." << endl;

	return 0;
}

void func()
{
	int value;
	vector <CProgram*> vector;

	try
	{
		auto_ptr<CMalware> autoptr(new CMalware);
		shared_ptr<CProgram> sharedptr = make_shared<CProgram>(0, 423, 523, 654, 53453, "Calculator");
		unique_ptr<CMalware> uniqueptr = make_unique<CMalware>(1, 8800, 555, 35, 35634, "BestMalware", "Exploit");
		SmartPointer<CMalware> MyPointer = new CMalware;
		weak_ptr<CProgram> weakptr = sharedptr;
		shared_ptr<CProgram> sharedptr2 = weakptr.lock();
		SmartPointer<CMalware> MyPointer2 = MyPointer;

		cout << endl << endl;
		cout << "����� �������, ���������� ����� ����������: " << MyPointer.operator->() << endl;
		cout << "����� ����� ���������� �������: " << MyPointer2.operator->() << endl;
		cout << endl;

		cout << setw(12) << "��������" << setw(14) << "������";
		cout << setw(14) << "����� ������" << setw(8) << "������";
		cout << setw(18) << "���������� �����" << setw(10) << "��������";
		cout << setw(10) << "���" << endl;

		vector.emplace_back(autoptr.get());
		vector.emplace_back(sharedptr.get());
		vector.emplace_back(uniqueptr.get());
		vector.emplace_back(MyPointer.operator->());
		vector.emplace_back(sharedptr2.get());

		value = 1;
		for_each(vector.begin(), vector.end(), [&value](const CProgram* program)
			{
				cout << value << ". " << *program << endl;
				value++;
			});
		cout << endl;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl << endl;
	}
}
