#include "ArrayList.h"
void ArrayList::ReadFile(string filename)
{
	ifstream file;
	file.exceptions(ifstream::badbit | ifstream::failbit);
	string line;
	int arrAmount;				//���������� �������� � �����
	int arrLength;				//������ �������
	int intTemp;
	int count = 0;
	size_t i, j;

	try
	{
		file.open(filename);

		getline(file, line);
		arrAmount = std::stoi(line);
		if (arrAmount <= 0 || arrAmount != (LinesInFile(filename) - 1))	//�������� �� ���������� ���-�� ��������
		{
			throw "�������� ���������� �������� � �����.";
		}

		for (i = 0; i < arrAmount; i++)		//�������� ������������ �������� � �����
		{
			getline(file, line);
			istringstream temp(line);
			temp >> arrLength;
			
			if (std::count(line.begin(), line.end(), ' ') != arrLength || arrLength == 0)
			{
				arrAmount--;
				i--;
			}
		}
		arrayList = new Array[arrAmount];		//�������� ������ ��� ������ ��������

		file.clear();							//������� �����
		file.seekg(0, std::ios_base::beg);		//���������� ��������� � ������ �����
		getline(file, line);
		arrAmount = std::stoi(line);

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

				arrayList[i].array = new int[arrLength + 1];
				arrayList[i].array[0] = arrLength;

				for (j = 1; j <= arrLength; j++)
				{
					temp >> intTemp;
					arrayList[i].array[j] = intTemp;
				}
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
		file.close();
		return;
	}
	
	file.close();
	listSize = arrAmount;
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
void ArrayList::OutputArr() const
{
	cout << endl << "�������� � �������: " << endl;
	for (size_t i = 0; i < listSize; i++)
	{
		cout << arrayList[i].array[0];
		
		cout << "    ";
		for (size_t j = 1; j <= arrayList[i].array[0]; j++)
		{
			cout << arrayList[i].array[j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void ArrayList::Task()
{
	float sum = 0;									//����� ���������
	task = new float[listSize];

	cout << "������� �������� ��������: " << endl;
	for (size_t i = 0; i < listSize; i++)
	{
		for (size_t j = 1; j <= arrayList[i].array[0]; j++)
		{
			sum += arrayList[i].array[j];
		}
		task[i] = sum / arrayList[i].array[0];
		cout << task[i] << endl;

		sum = 0;
	}
}
void ArrayList::SaveToFile(string filename) const
{	
	try
	{
		ofstream fout(filename);
		fout.exceptions(ifstream::badbit | ifstream::failbit);

		for (size_t i = 0; i < listSize; i++)
		{
			fout << task[i] << endl;
		}

		fout.close();

		cout << "������ � ���� ��������." << endl;
	}
	catch (const char* error)
	{
		cout << error << endl;
		return;
	}
}
void ArrayList::DeleteArr()
{
	for (size_t i = 0; i < listSize; i++)
	{
		delete arrayList[i].array;
	}
	delete[] arrayList;
	delete[] task;
}
void ArrayList::CheckArr(int Arr, int Element)
{
	try
	{
		if (Arr > listSize || Arr <= 0)
		{
			throw exception("�������� ����� �������.");
		}
		else if (Element > arrayList[Arr-1].array[0])
		{
			throw exception("�������� ����� ��������.");
		}
		else
		{
			cout << "�������: " << arrayList[Arr-1].array[Element] << endl;
		}
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
		return;
	}
		
}

ArrayList::~ArrayList() {}