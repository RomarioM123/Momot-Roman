#pragma once
#include "Header.h"
#include "PointerCount.h"

template <typename T>
class SmartPointer
{
private:
	T* object{ nullptr };
	PointerCount* pointerCount{ nullptr };

public:

	SmartPointer<T>& operator=(const SmartPointer<T>& pointer)
	{
		if (this != &pointer)
		{
			if (pointerCount && pointerCount->Decrement() == 0)
			{
				delete pointerCount;
				delete object;
			}

			object = pointer.object;
			pointerCount = pointer.pointerCount;
			pointerCount->Increment();
		}
		cout << "������������ ������������ ������ ���������. ���������� ������: " << pointerCount->GetPointerCount() << endl;

		return *this;
	}
	T& operator*()
	{
		return *object;
	}
	T* operator->()
	{
		return object;
	}
	
	SmartPointer();
	SmartPointer(T* object) : object{ object }, pointerCount{ new PointerCount() }
	{
		pointerCount->Increment();
		cout << "������ ����������� ����� ���������. ���������� ������ : " << pointerCount->GetPointerCount() << endl;
	}
	virtual ~SmartPointer()
	{
		if (pointerCount)
		{
			int decrementCount = pointerCount->Decrement();
			cout << "����������� ����� ��������� ���������. ���������� ������: " << decrementCount << endl;
			if (decrementCount <= 0)
			{
				delete pointerCount;
				delete object;
				pointerCount = nullptr;
				object = nullptr;
			}
			
		}
	}
	SmartPointer(const SmartPointer<T>& other) :object{ other.object }, pointerCount{ other.pointerCount }
	{
		pointerCount->Increment();
		cout << "����� ��������� ����������. ���������� ������: " << pointerCount->GetPointerCount();
	}
};

