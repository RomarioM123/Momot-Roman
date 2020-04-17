#include <iostream>
#include <string>
#include <locale>
#include <fstream>
#include <sstream>
#include <algorithm>

using std::ifstream;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::exception;
using std::istringstream;


bool ReadFile(string, int**);
int LinesInFile(string);
string InputFileName();
void OutputArr(int**);
void Task(int**, float*);

class MyException :public exception
{
private:
	string error;

public:
	MyException(string error) :error(error)
	{
	}
	const string getError() { return error; }
};

int main()
{
	setlocale(LC_ALL, "Rus");
	string filename = "data.txt";
	int*** arr = new int** [1];
	float* result = new float[1];
	result[0] = 0;
	result = new float[1];
	result[1] = 5;

	int i = 0;

	while (filename != "\exit")
	{
		filename = InputFileName();
		
		try
		{
			arr[i] = new int* [1];
			ReadFile(filename, arr[i]);
			OutputArr(arr[i]);
			
			Task(arr[i], result);

			i++;
		}
		catch (const std::exception&)
		{
			cout << "Невозможно открыть файл с названием " << filename << "." << endl;
		}
		

	}
	
	return 0;
}
bool ReadFile(string filename, int** arr)
{
	ifstream file;
	file.exceptions(ifstream::badbit | ifstream::failbit);
	string line;
	int arrLength;

	try
	{
		file.open(filename);
		if (!file) 
		{ 
			throw "Ошибка открытия файла.";
		}
		arr[0] = new int[1];
		getline(file, line);
		istringstream temp(line);

		temp >> arr[0][0];
		if (arr[0][0] <= 0 || arr[0][0] != (LinesInFile(filename)-1))
		{ 
			throw "Неверное количество массивов в файле."; 
		}
		

		for (size_t i = 1; i <= arr[0][0]; i++)
		{
			getline(file, line);
			istringstream temp(line);
			temp >> arrLength;
			
			try
			{
				if (arrLength < 0)
				{
					throw exception("Ошибка в данных файла. Размер массива не может быть меньше 0.");
				}
				if (std::count(line.begin(), line.end(), ' ') != arrLength)
				{
					throw exception("Ошибка в данных файла. Переменная размера и фактический размер одного из массивов не совпадают. ");
				}

				arr[i] = new int[arrLength + 1];
				arr[i][0] = arrLength;

				for (size_t j = 1; j < arrLength + 1; j++)
				{
					temp >> arr[i][j];
				}
			}
			catch (const exception& ex)
			{
				cout << ex.what() << endl;
				i--;
				arr[0][0]--;
			}
		}
	}
	catch (const char* error)
	{
		cout << error << endl;
		return NULL;
	}
	file.close();
}
int LinesInFile(string filename)
{
	ifstream fin(filename);
	string line;
	int size = 0;

	while (getline(fin, line))
	{
		size++;
	}

	fin.close();
	return size;
}
string InputFileName()
{
	string filename;

	cout << "Введите название файла: ";
	cin >> filename;
	cout << endl;

	return filename;
}
void OutputArr(int** arr)
{
	cout << endl << arr[0][0] << endl;
	for (size_t i = 1; i <= arr[0][0]; i++)
	{
		for (size_t j = 0; j <= arr[i][0]; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void Task(int** arr, float* result)
{
	int value = 0;


	for (size_t i = 1; i <= arr[0][0]; i++)
	{
		for (size_t j = 0; j <= arr[i][0]; j++)
		{
			value++;
			result += arr[i][j];
		}
	}
}