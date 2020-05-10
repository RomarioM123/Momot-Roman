#pragma once
#include "Header.h"

template <typename T>
class TemplateClass
{
private:
	T** array;

public:
	void OutputArr(int size) const
	{
		for (size_t i = 0; i < size; i++)
			cout << *array[i] << endl;
		cout << endl;
	}

	int FindEl(T element, int size) const
	{
		for (size_t i = 0; i < size; i++)
			if (*array[i] == element)
				return i;
		return -1;
	}

	T* Sort(int size, bool choiseSort)
	{
		TemplateClass<T> object(T);
		bool sort = 0, pr = 0;
		T* temp = 0;

		do
		{
			pr = 0;
			for (size_t i = 0; i < size - 1; i++)
			{
				if (choiseSort == 0)
					sort = *array[i] < *array[i + 1];
				else if (choiseSort == 1)
					sort = *array[i] > * array[i + 1];
				if (sort)
				{
					temp = *(array + i);
					*(array + i) = *(array + i + 1);
					*(array + i + 1) = temp;
					pr = 1;
				}
			}
		} while (pr);

		return temp;
	}

	T FindMin(int size) const
	{
		T temp = *array[0];
		for (size_t i = 1; i < size; i++)
			if (*array[i] < temp)
				temp = *array[i];
		return temp;
	}

	T EnterEl(T choise) const
	{
		cout << "Введите элемент, индекс которого хотите получить: ";
		cin >> choise;

		return choise;
	}

	T ChoiseSort(T choise) const
	{
		choise = -1;
		while (choise <= 0 || choise > 3)
		{
			cout << endl << "Сортировать по:" << endl;
			cout << "1) Убыванию\n2) Возрастанию\n3) Не сортировать\n";
			cout << "Ваш выбор: ";
			cin >> choise;

			if (choise <= 0 || choise > 3)
				cout << "Ошбика. Неверная команда. Повторите попытку." << endl;
		}

		return choise;
	}

	TemplateClass(T** array) :array(array) {}
	~TemplateClass() {};
};





