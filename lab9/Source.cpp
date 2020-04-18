#include "ArrayList.h"

string InputFileName();
string OutputFileName();
void Func();

int main()
{
	setlocale(LC_ALL, "Rus");
	
	Func();

	if (_CrtDumpMemoryLeaks()) cout << endl << "Есть утечка памяти." << endl;
	else cout << endl << "Утечка памяти отсутствует." << endl;

	return 0;
}

void Func()
{
	string filename;
	Array arr;
	ArrayList arrList;
	int i = 0;

	arrList.createArr();

	while (filename != "\\exit")
	{
		filename = InputFileName();
		
		try
		{
			arrList.ReadFile(filename, i);
			arrList.OutputArr(i);
			arrList.Task(i);
			filename = OutputFileName();
			arrList.SaveToFile(filename, i);

			i++;
		}
		catch (const std::exception&)
		{
			cout << "Невозможно открыть файл с названием " << filename << "." << endl;
		}
	}

	return;
}
string InputFileName()
{
	string filename;

	cout << "Введите название файла для чтения: ";
	cin >> filename;
	cout << endl;

	return filename;
}
string OutputFileName()
{
	string filename;

	cout << "Введите название файла для записи результата: ";
	cin >> filename;
	cout << endl;

	return filename;
}

