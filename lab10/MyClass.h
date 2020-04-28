#pragma once
#include "Header.h"

class MyClass
{
public:
	template<class T> 
	void OutputArr(T, int) const;
	
	template<class T> 
	void FindEl(T*, int, T) const;
	
	template<class T>
	T* Sort(T*, int, bool);
	
	template<class T>
	T FindMin(T*, int) const;
	
	template<class T> 
	T EnterEl(T) const;
	
	template<class T>				
	T ChoiseSort(T) const;
	
	template <typename T>
	static bool SortAsc(const T& a, const T& b) noexcept
	{
		return a > b;
	}

	template <typename T>
	static bool SortDesc(const T& a, const T& b) noexcept
	{
		return a < b;
	}

	~MyClass();
};

template<class T>
inline void MyClass::OutputArr(T array, int size) const
{
	for (size_t i = 0; i < size; i++)
	{
		cout << array[i] << "  ";
		cout << endl;
	}
	cout << endl;
}

template<class T>
inline T MyClass::EnterEl(T choise) const
{
	cout << endl << "Введите элемент, индекс которого хотите получить: ";
	cin >> choise;

	return choise;
}

template<class T>
inline T MyClass::ChoiseSort(T choise) const
{
	choise = 0;
	while (choise <= 0 || choise > 3)
	{
		cout << endl << "Сортировать по:" << endl;
		cout << "1) Убыванию\n2) Возрастанию\n3) Не сортировать\n";
		cout << "Ваш выбор: ";
		cin >> choise;
	}
	
	return choise;
}

template<class T>
inline void MyClass::FindEl(T* array, int size, T value) const
{
	bool FindEl = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (array[i] == value)
		{
			cout << "Индекс нужного элемента: " << i << endl;
			FindEl = 1;
		}
	}
	if (FindEl == 0)
	{
		cout << "Нужного элемента в массиве нет." << endl;
	}
	
}

template<class T>
inline T* MyClass::Sort(T* array, int size, bool choiseSort)
{
	bool sort;
	T temp;
	bool pr;
	MyClass object;

	do
	{
		pr = 0;
		for (size_t i = 0; i < size - 1; i++)
		{
			if (choiseSort == 0)
			{
				sort = object.SortAsc(array[i], array[i + 1]);
			}
			else if (choiseSort == 1)
			{
				sort = object.SortDesc(array[i], array[i + 1]);
			}
			if (sort)
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				pr = 1;
			}
		}
	} while (pr);

	return array;
}

template<class T>
inline T MyClass::FindMin(T* array, int size) const
{
	T temp = array[0];
	for (size_t i = 1; i < size; i++)
	{
		if (array[i] < temp)
		{
			temp = array[i];
		}
	}
	//cout << endl << "Минимальный элемент: " << temp << endl << endl;

	return temp;
}



MyClass::~MyClass() {}



