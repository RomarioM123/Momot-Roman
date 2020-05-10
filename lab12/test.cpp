#include "Header.h"

void VectorTest();
void ListTest();
void MapTest();
void SetTest();

int main()
{
    setlocale(LC_ALL, "Rus");

    VectorTest();
    ListTest();
    MapTest();
    SetTest();
    
    if (_CrtDumpMemoryLeaks())
        cout << "\n���� ������ ������.\n";
    else 
        cout << "\n������ ������ �����������.\n";

    return 0;
}
void VectorTest()
{
    vector<int> vector = { 1, -5, 20, 555, 0 };
    int vectorSize = vector.size();
    int newVectorSize;
    int value;
    std::vector<int>::iterator it;
    cout << "Vector" << endl;
    
    vector.push_back(155);
    newVectorSize = vector.size();
    if(vectorSize != newVectorSize && vector[newVectorSize - 1] == 155)
        cout << "���� ���������� ��������\t�������� �������.\n";
    else
        cout << "���� ���������� ��������\t�� �������� �������.\n";

    it = vector.begin();
    value = vector[2];
    vector.erase(it + 2);
    newVectorSize = vector.size();
    if (vectorSize == newVectorSize && vector[2] != value)
        cout << "���� �������� ��������\t\t�������� �������.\n";
    else
        cout << "���� �������� ��������\t\t�� �������� �������.\n";

    if (vector[0] == 1)
        cout << "���� ��������� ��������\t\t�������� �������.\n";
    else
        cout << "���� ��������� ��������\t\t�� �������� �������.\n";
}
void ListTest()
{
    list<int> list = { 1, -5, 20, 555, 0 };
    int listSize = list.size();
    int value;
    std::list<int>::iterator it;
    std::list<int>::iterator it2;
    cout << endl << "List" << endl;

    list.push_back(155);
    list.push_front(228);
    it = list.begin();
    it2 = list.begin();
    std::advance(it2, list.size() - 1);
    if (listSize != list.size() && *it == 228 && *it2 == 155)
        cout << "���� ���������� ��������\t�������� �������.\n";
    else
        cout << "���� ���������� ��������\t�� �������� �������.\n";

    it2 = list.begin();
    std::advance(it2, 2);
    list.erase(it2);
    it = list.begin();
    std::advance(it, 2);
    if (list.size() == listSize+1 && it != it2)
        cout << "���� �������� ��������\t\t�������� �������.\n";
    else
        cout << "���� �������� ��������\t\t�� �������� �������.\n";

    if (*it == 20)
        cout << "���� ��������� ��������\t\t�������� �������.\n";
    else
        cout << "���� ��������� ��������\t\t�� �������� �������.\n";
}
void SetTest()
{
    set<int> set = { 1, -5, 20, 555, 0 };
    int setSize = set.size();
    int value;
    std::set<int>::iterator it;
    std::set<int>::iterator it2;
    cout << endl << "Set" << endl;

    set.insert(155);
    it2 = set.begin();
    std::advance(it2, 4);
    if (setSize != set.size() && *it2 == 155)
        cout << "���� ���������� ��������\t�������� �������.\n";
    else
        cout << "���� ���������� ��������\t�� �������� �������.\n";

    it2 = set.begin();
    set.erase(it2);
    it = set.begin();
    if (set.size() == setSize && it != it2 && *it == 0)
        cout << "���� �������� ��������\t\t�������� �������.\n";
    else
        cout << "���� �������� ��������\t\t�� �������� �������.\n";

    if (*it == 0)
        cout << "���� ��������� ��������\t\t�������� �������.\n";
    else
        cout << "���� ��������� ��������\t\t�� �������� �������.\n";
}
void MapTest()
{
    map <int, int> map = { {1, 1}, {-5,2}, {20, 3}, {555, 4}, {0, 5} };
    int mapSize = map.size();
    std::map<int, int>::iterator it;
    std::map<int, int>::iterator it2;
    cout << endl << "Map" << endl;

    map.insert(std::pair<int, int>(155, 6));
    if (mapSize < map.size())
        cout << "���� ���������� ��������\t�������� �������.\n";
    else
        cout << "���� ���������� ��������\t�� �������� �������.\n";

    it = map.begin();
    map.erase(it);
    if (mapSize == map.size())
        cout << "���� �������� ��������\t\t�������� �������.\n";
    else
        cout << "���� �������� ��������\t\t�� �������� �������.\n";

    it = map.begin();
    if (map.find(0) == it)
        cout << "���� ��������� ��������\t\t�������� �������.\n";
    else
        cout << "���� ��������� ��������\t\t�� �������� �������.\n";
}
