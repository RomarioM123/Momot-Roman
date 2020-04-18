#include "Array.h"
using std::ofstream;
using std::ostream;

int& Array::operator[](const int index)
{
    int sizeArr = sizeof(array) / 4;

    if (index < 0 || index >= sizeArr)
        throw exception("Invalid index");

    return array[index];
}
Array& Array::operator=(int arr2[])    //перегрузка =
{
    int sizeArr2 = _msize(arr2) / sizeof(int);
    //int sizeArr2 = sizeof(arr2) / 4;
    //delete[] array;

    array = new int[sizeArr2];
    for (int i = 0; i < sizeArr2; i++)
    {
        array[i] = arr2[i];
    }

    return *this;
}
ostream& operator<<(ostream& output, const Array& arr)
{
    int arrSize = sizeof(arr) / 4;
    for (size_t i = 0; i < arrSize; i++)
    {
        output << arr.array[i];
    }
    return output;
}

Array::Array(): array(0){}
Array::Array(const Array& other) : array(other.array) {}
Array::~Array() 
{
    delete array;
};


