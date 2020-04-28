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
	ArrayList arrList;
	int value, value2;

	while (filename != "\\exit")
	{
		filename = InputFileName();
		
		try
		{
			arrList.ReadFile(filename);
			arrList.OutputArr();
			arrList.Task();
			filename = OutputFileName();
			arrList.SaveToFile(filename);
			
			cout << endl << "Введите номер массива, элемент которого хотите получить: ";
			cin >> value;
			cout << "Введите номер элемента, который хотите получить: ";
			cin >> value2;

			arrList.CheckArr(value, value2);
			arrList.DeleteArr();
		}
		catch (const exception& ex)
		{
			if (filename == "\\exit")
			{
				cout << "Завершение работы программы." << endl;
			}
			else
			{
				cout << ex.what() << endl;
				cout << "Невозможно открыть файл с названием " << filename << endl;
			}
		}
	}

	return;
}
string InputFileName()
{
	string filename;

	cout << endl << "Введите название файла для чтения: ";
	cin >> filename;
	cout << endl;

	return filename;
}
string OutputFileName()
{
	string filename;

	cout << endl << "Введите название файла для записи результата: ";
	cin >> filename;

	return filename;
}

