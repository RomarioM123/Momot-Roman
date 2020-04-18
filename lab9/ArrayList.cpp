#include "ArrayList.h"
int ArrayList::getListSize() const
{
	return listSize;
}

void ArrayList::createArr()
{
	listSize = 1;
	arrayList = new Array[1];
	task = new int[1];
}
bool ArrayList::ReadFile(string filename, int value)
{
	ifstream file;
	file.exceptions(ifstream::badbit | ifstream::failbit);
	string line;
	int arrAmount;				//количество массивов в файле
	int arrLength;				//длинна массива
	int intTemp;
	int fullSize = 0;			//общее кол-во элементов в файле
	int value2 = 0;
	int* newArray;				//новый массив элементов
	size_t i, j;

	try
	{
		file.open(filename);
		if (!file)				//проверка на открытие файла
		{
			throw "Ошибка открытия файла.";
		}
		
		getline(file, line);
		istringstream temp(line);
		temp >> arrAmount;
		if (arrAmount <= 0 || arrAmount != (LinesInFile(filename) - 1))	//проверка на правильное кол-во эл-ов в массиве
		{
			throw "Неверное количество массивов в файле.";
		}

		while (!file.eof())		//нахождение максимального кол-ва элементов
		{
			getline(file, line);
			istringstream temp(line);
			temp >> arrLength;
			if (arrLength > 0) fullSize += arrLength;
		}
		newArray = new int[fullSize];			//выделение памяти для нового массива

		file.seekg(0, file.beg);
		getline(file, line);

		for (i = 0; i < arrAmount; i++)
		{
			getline(file, line);
			istringstream temp(line);
			temp >> arrLength;

			try
			{
				if (std::count(line.begin(), line.end(), ' ') != arrLength)
				{
					throw exception("Ошибка в данных файла. Переменная размера и фактический размер одного из массивов не совпадают. ");
				}
				if (arrLength == 0)
				{
					throw exception("Пустой массив данных.");
				}

				for (j = 0; j < arrLength; j++)
				{
					temp >> intTemp;
					newArray[j + value2] = intTemp;
				}
				value2 = value2 + j;
			}
			catch (const exception & ex)
			{
				cout << ex.what() << endl;
				arrAmount--;
				i--;
			}
		}
	}
	catch (const char* error)
	{
		cout << error << endl;
		return NULL;
	}
	
	file.close();

	newArray = (int*)realloc(newArray, sizeof(int) * value2);
	arrayList[value].array = new int[value2];
	arrayList[value].array = newArray;
}
int ArrayList::LinesInFile(string filename) const
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
void ArrayList::OutputArr(int value) const
{
	int arrSize = _msize(arrayList[value].array) / sizeof(int);

	cout << endl << "Количество элементов в массиве: " << arrSize << endl;
	for (size_t i = 0; i < arrSize; i++)
	{
		cout << arrayList[value].array[i] << " ";
	}
	cout << endl;
}
void ArrayList::Task(int value)
{
	int arrSize = _msize(arrayList[value].array) / sizeof(int);	//размер массива
	int amountOfEl = 0;											//количество элементов
	int sum = 0;												//сумма элементов
	int* temp = new int[value + 1];								//временная переменная массива индиввидуального задания

	for (size_t i = 0; i < value; i++)
	{
		temp[i] = task[i];
	}
	delete[] task;

	for (size_t i = 0; i < arrSize; i++)
	{
		sum += arrayList[value].array[i];
		amountOfEl++;
	}

	task = new int[value + 1];
	for (size_t i = 0; i < value+1; i++)
	{
		task[i] = temp[i];
	}
	task[value] = sum / amountOfEl;
	cout << "Среднее значение элементов: " << task[value] << endl;
}
void ArrayList::SaveToFile(string filename, int value) const
{
	try
	{
		ofstream fout(filename);
		fout.exceptions(ifstream::badbit | ifstream::failbit);

		if (!fout.is_open())				//проверка на открытие файла
		{
			throw "Ошибка открытия файла.";
		}

		for (size_t i = 0; i < value+1; i++)
		{
			fout << task[i] << " ";
		}

		fout.close();
	}
	catch (const char* error)
	{
		cout << error << endl;
		return;
	}
}

ArrayList::~ArrayList()
{
	
	for (size_t i = 0; i < (_msize(task) / sizeof(int)); i++)
	{
		delete arrayList[i].array;
		//arrayList[i].~Array();
	}
	
	//delete[] arrayList;
	delete[] task;
}