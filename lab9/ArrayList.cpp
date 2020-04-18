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
	int arrAmount;				//���������� �������� � �����
	int arrLength;				//������ �������
	int intTemp;
	int fullSize = 0;			//����� ���-�� ��������� � �����
	int value2 = 0;
	int* newArray;				//����� ������ ���������
	size_t i, j;

	try
	{
		file.open(filename);
		if (!file)				//�������� �� �������� �����
		{
			throw "������ �������� �����.";
		}
		
		getline(file, line);
		istringstream temp(line);
		temp >> arrAmount;
		if (arrAmount <= 0 || arrAmount != (LinesInFile(filename) - 1))	//�������� �� ���������� ���-�� ��-�� � �������
		{
			throw "�������� ���������� �������� � �����.";
		}

		while (!file.eof())		//���������� ������������� ���-�� ���������
		{
			getline(file, line);
			istringstream temp(line);
			temp >> arrLength;
			if (arrLength > 0) fullSize += arrLength;
		}
		newArray = new int[fullSize];			//��������� ������ ��� ������ �������

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
					throw exception("������ � ������ �����. ���������� ������� � ����������� ������ ������ �� �������� �� ���������. ");
				}
				if (arrLength == 0)
				{
					throw exception("������ ������ ������.");
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

	cout << endl << "���������� ��������� � �������: " << arrSize << endl;
	for (size_t i = 0; i < arrSize; i++)
	{
		cout << arrayList[value].array[i] << " ";
	}
	cout << endl;
}
void ArrayList::Task(int value)
{
	int arrSize = _msize(arrayList[value].array) / sizeof(int);	//������ �������
	int amountOfEl = 0;											//���������� ���������
	int sum = 0;												//����� ���������
	int* temp = new int[value + 1];								//��������� ���������� ������� ���������������� �������

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
	cout << "������� �������� ���������: " << task[value] << endl;
}
void ArrayList::SaveToFile(string filename, int value) const
{
	try
	{
		ofstream fout(filename);
		fout.exceptions(ifstream::badbit | ifstream::failbit);

		if (!fout.is_open())				//�������� �� �������� �����
		{
			throw "������ �������� �����.";
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