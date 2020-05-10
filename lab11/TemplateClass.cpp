//#include "Header.h"
//#include "TemplateClass.h"
//
//template<typename T>
//inline void TemplateClass<T>::OutputArr(int size) const
//{
//	for (size_t i = 0; i < size; i++)
//	{
//		cout << array[i] << "  ";
//		cout << endl;
//	}
//	cout << endl;
//}
//
//template<typename T>
//inline T TemplateClass<T>::FindEl(T element, int size) const
//{
//	for (size_t i = 0; i < size; i++)
//	{
//		if (*array[i] == element)
//		{
//			return i;
//		}
//	}
//	return -1;
//}
//
//template<typename T>
//inline T* TemplateClass<T>::Sort(int size, bool choiseSort)
//{
//	bool sort;
//	T* temp;
//	bool pr;
//	TemplateClass<T> object(T);
//
//	do
//	{
//		pr = 0;
//		for (size_t i = 0; i < size - 1; i++)
//		{
//			if (choiseSort == 0)
//			{
//				sort = *array[i] > *array[i + 1];
//			}
//			else if (choiseSort == 1)
//			{
//				sort = *array[i] < * array[i + 1];
//			}
//			if (sort)
//			{
//				temp = *array[i];
//				*array[i] = *array[i + 1];
//				*array[i + 1] = temp;
//				pr = 1;
//			}
//		}
//	} while (pr);
//
//	return temp;
//}
//
//template<typename T>
//inline T TemplateClass<T>::FindMin(int size) const
//{
//	T temp = *array[0];
//	for (size_t i = 1; i < size; i++)
//	{
//		if (*array[i] < temp)
//		{
//			temp = *array[i];
//		}
//	}
//	//cout << endl << "����������� �������: " << temp << endl << endl;
//	return temp;
//}
//
//template<class T>
//inline T TemplateClass<T>::EnterEl(T choise) const
//{
//	cout << endl << "������� �������, ������ �������� ������ ��������: ";
//	cin >> choise;
//
//	return choise;
//}
//
//template<class T>
//inline T TemplateClass<T>::ChoiseSort(T choise) const
//{
//	choise = 0;
//	while (choise <= 0 || choise > 3)
//	{
//		cout << endl << "����������� ��:" << endl;
//		cout << "1) ��������\n2) �����������\n3) �� �����������\n";
//		cout << "��� �����: ";
//		cin >> choise;
//
//		if (choise <= 0 || choise > 3)
//			cout << "������. �������� �������. ��������� �������." << endl;
//	}
//
//	return choise;
//}
//
//template<typename T>
//TemplateClass<T>::TemplateClass(T** array):array(array){}
//
