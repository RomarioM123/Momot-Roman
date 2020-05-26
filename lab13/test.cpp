#include "malware.h"

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
        cout << "\nЕсть утечка памяти.\n";
    else 
        cout << "\nУтечка памяти отсутствует.\n";

    return 0;
}
void VectorTest()
{
    cout << "Vector" << endl;
    vector <unique_ptr<CProgram>> vector;
    std::vector<unique_ptr<CProgram>>::const_iterator it;
    stringstream line;
    string data;
    int vectorSize;
    int value, result = 0, sum = 0;
    int i = 0;

    for (size_t i = 0; i < 4; i++)
    {
        if (i == 0)
            vector.emplace_back(new CProgram());
        else if (i == 1)
            vector.emplace_back(new CMalware(1, 8800, 555, 35, 35634, "BestMalware", "Exploit"));
        else if (i == 2)
            vector.emplace_back(new CProgram(0, 423, 523, 654, 53453, "Calculator"));
        else if (i == 3)
            vector.emplace_back(new CMalware(0, 345, 789, 423, 67456, "MoneyStealer", "Rootkit"));
    }
    
    vectorSize = vector.size();
    vector.emplace_back(new CMalware());
    if(vectorSize != vector.size())
        cout << "Тест добавления элемента\tвыполнен успешно.\n";
    else
        cout << "Тест добавления элемента\tне выполнен успешно.\n";

    it = vector.begin();
    advance(it, 2);
    vector.erase(it);
    if (vectorSize == vector.size())
        cout << "Тест удаления элемента\t\tвыполнен успешно.\n";
    else
        cout << "Тест удаления элемента\t\tне выполнен успешно.\n";

    line = vector[0]->getStr();
    data = line.str();
    if (data == "Basic 65 0 0 0 0")
        cout << "Тест получения элемента\t\tвыполнен успешно.\n";
    else
        cout << "Тест получения элемента\t\tне выполнен успешно.\n";

    it = vector.begin();
    data = "false";
    while (i < vector.size())
    {
        result = (*it)->countElement(6, data);
        i++;
        it++;
        sum += result;
    }
    if (sum == 3)
        cout << "Тест подсчёта элементов\t\tвыполнен успешно.\n";
    else
        cout << "Тест подсчёта элементов\t\tне выполнен успешно.\n";
}
void ListTest()
{
    cout << endl << "List" << endl;
    list <unique_ptr<CProgram>> list;
    std::list<unique_ptr<CProgram>>::const_iterator it;
    int listSize;
    int value, sum = 0, result = 0;
    int i = 0;
    stringstream line;
    string data;

    for (size_t i = 0; i < 4; i++)
    {
        if (i == 0)
            list.emplace_back(new CProgram());
        else if (i == 1)
            list.emplace_back(new CMalware(1, 8800, 555, 35, 35634, "BestMalware", "Exploit"));
        else if (i == 2)
            list.emplace_back(new CProgram(0, 423, 523, 654, 53453, "Calculator"));
        else if (i == 3)
            list.emplace_back(new CMalware(0, 345, 789, 423, 67456, "MoneyStealer", "Rootkit"));
    }
    
    listSize = list.size();
    list.emplace_back(new CMalware());
    if (listSize < list.size())
        cout << "Тест добавления элемента\tвыполнен успешно.\n";
    else
        cout << "Тест добавления элемента\tне выполнен успешно.\n";

    it = list.begin();
    list.erase(it);
    if (list.size() == listSize)
        cout << "Тест удаления элемента\t\tвыполнен успешно.\n";
    else
        cout << "Тест удаления элемента\t\tне выполнен успешно.\n";

    it = list.begin();
    line = (*it)->getStr();
    data = line.str();
    if(data == "BestMalware 35634 8800 555 35 1 Exploit")
        cout << "Тест получения элемента\t\tвыполнен успешно.\n";
    else
        cout << "Тест получения элемента\t\tне выполнен успешно.\n";

    it = list.begin();
    data = "false";
    while (i < list.size())
    {
        result = (*it)->countElement(6, data);
        i++;
        it++;
        sum += result;
    }
    if (sum == 3)
        cout << "Тест подсчёта элементов\t\tвыполнен успешно.\n";
    else
        cout << "Тест подсчёта элементов\t\tне выполнен успешно.\n";
}
void SetTest()
{
    cout << endl << "Set" << endl;
    set <unique_ptr<CProgram>> set;
    std::set<unique_ptr<CProgram>>::const_iterator it;
    stringstream line;
    string data;
    int setSize, sum = 0, i = 0;
    int value;
    
    for (size_t i = 0; i < 4; i++)
    {
        if (i == 0)
            set.emplace(new CProgram());
        else if (i == 1)
            set.emplace(new CMalware(1, 8800, 555, 35, 35634, "BestMalware", "Exploit"));
        else if (i == 2)
            set.emplace(new CProgram(0, 423, 523, 654, 53453, "Calculator"));
        else if (i == 3)
            set.emplace(new CMalware(0, 345, 789, 423, 67456, "MoneyStealer", "Rootkit"));
    }

    setSize = set.size();
    set.emplace(new CMalware());
    if (setSize < set.size())
        cout << "Тест добавления элемента\tвыполнен успешно.\n";
    else
        cout << "Тест добавления элемента\tне выполнен успешно.\n";

    it = set.begin();
    set.erase(it);
    if (set.size() == setSize)
        cout << "Тест удаления элемента\t\tвыполнен успешно.\n";
    else
        cout << "Тест удаления элемента\t\tне выполнен успешно.\n";

    it = set.begin();
    line = (*it)->getStr();
    data = line.str();
    if (data == "MoneyStealer 67456 345 789 423 0 Rootkit" || data == "BestMalware 35634 8800 555 35 1 Exploit" || data == "Basic 65 0 0 0 0 Exploit")
        cout << "Тест получения элемента\t\tвыполнен успешно.\n";
    else
        cout << "Тест получения элемента\t\tне выполнен успешно.\n";

    it = set.begin();
    data = "53453";
    while (i < set.size())
    {
        value = (*it)->countElement(5, data);
        i++;
        it++;
        sum += value;
    }
    if (sum == 1)
        cout << "Тест подсчёта элементов\t\tвыполнен успешно.\n";
    else
        cout << "Тест подсчёта элементов\t\tне выполнен успешно.\n";
}
void MapTest()
{
    cout << endl << "Map" << endl;
    std::map<int, unique_ptr<CProgram>>::const_iterator it;
    map <int, unique_ptr<CProgram>> map;
    stringstream line;
    string data;
    int number = 0, result, sum = 0;
    int mapSize;
    int i = 0;

    for (; i < 4; i++)
    {
        if (i == 0)
            map.emplace(i + 1, new CProgram());
        else if (i == 1)
            map.emplace(i + 1, new CMalware(1, 8800, 555, 35, 35634, "BestMalware", "Exploit"));
        else if (i == 2)
            map.emplace(i + 1, new CProgram(0, 423, 523, 654, 53453, "Calculator"));
        else if (i == 3)
            map.emplace(i + 1, new CMalware(0, 345, 789, 423, 67456, "MoneyStealer", "Rootkit"));
    }
    
    mapSize = map.size();
    map.emplace(++i, new CMalware);
    if (mapSize < map.size())
        cout << "Тест добавления элемента\tвыполнен успешно.\n";
    else
        cout << "Тест добавления элемента\tне выполнен успешно.\n";

    it = map.begin();
    map.erase(it);
    if (mapSize == map.size())
        cout << "Тест удаления элемента\t\tвыполнен успешно.\n";
    else
        cout << "Тест удаления элемента\t\tне выполнен успешно.\n";

    it = map.begin();
    line = it->second->getStr();
    data = line.str();
    if (data == "BestMalware 35634 8800 555 35 1 Exploit")
        cout << "Тест получения элемента\t\tвыполнен успешно.\n";
    else
        cout << "Тест получения элемента\t\tне выполнен успешно.\n";

    
    data = "53453";
    while (number < map.size())
    {
        result = it->second->countElement(5, data);
        number++;
        it++;
        sum += result;
    }
    if (sum == 1)
        cout << "Тест подсчёта элементов\t\tвыполнен успешно.\n";
    else
        cout << "Тест подсчёта элементов\t\tне выполнен успешно.\n";
}
